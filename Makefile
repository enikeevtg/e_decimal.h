.PHONY: all clean test e_decimal.a gcov_report

# UTILITIES
CC = gcc
AR = ar rs
RAN = ranlib
MK = mkdir -p
MAKE = make

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra #-g
DEBUG = #-DDEBUG

# FILENAMES
TARGET = e_decimal.a

### source code directories:
ARITHMDIR = arithmetic/
COMPDIR = comparison/
CONVERTDIR = converters/
ANOTHERDIR = another/
INTERNALDIR = internal/

### source code files
SRC = $(wildcard $(ARITHMDIR)*.c)
SRC += $(wildcard $(COMPDIR)*.c)
SRC += $(wildcard $(CONVERTDIR)*.c)
SRC += $(wildcard $(ANOTHERDIR)*.c)
SRC += $(wildcard $(INTERNALDIR)*.c)

### object files
OBJDIR = obj/
OBJ = $(patsubst $(ARITHMDIR)%.c, $(OBJDIR)%.o, $(SRC))
OBJ += $(patsubst $(COMPDIR)%.c, $(OBJDIR)%.o, $(SRC))
OBJ += $(patsubst $(ANOTHERDIR)%.c, $(OBJDIR)%.o, $(SRC))
OBJ += $(patsubst $(INTERNALDIR)%.c, $(OBJDIR)%.o, $(SRC))

TESTDIR = tests/


# MAIN TARGET
lib: $(TARGET)

$(TARGET): objects
	@$(AR) $@ $(OBJ)
	@$(RAN) $@
	@echo "$(AR): creating library $(TARGET) \033[0;32msuccess\033[0m"

objects: makeobjdir $(OBJ) OBJ_SUCCESS

makeobjdir:
	@$(MK) $(OBJDIR)

$(OBJDIR)%.o: $(ARITHMDIR)%.c
	@$(CC) $(CF) -c $^ -o $@ $(DEBUG)

$(OBJDIR)%.o: $(COMPDIR)%.c
	@$(CC) $(CF) -c $^ -o $@ $(DEBUG)

$(OBJDIR)%.o: $(ANOTHERDIR)%.c
	@$(CC) $(CF) -c $^ -o $@ $(DEBUG)

$(OBJDIR)%.o: $(INTERNALDIR)%.c
	@$(CC) $(CF) -c $^ -o $@ $(DEBUG)

OBJ_SUCCESS:
	@echo "$(CC): objects compilation \033[0;32msuccess\033[0m"


# TESTS
test: lib
	cd $(TESTDIR) && $(MAKE) test


# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h $(TESTDIR)*.c
	
gost:
	clang-format --style=google -i $(SRCDIR)*.c *.h $(TESTDIR)*.c

clean:
	rm -rf $(TARGET) $(OBJDIR) *.out *.gch *.dSYM

update:
	sh ../scripts/update_gitlab_test.sh

get:
	sh ../scripts/get_test_from_gitlab.sh

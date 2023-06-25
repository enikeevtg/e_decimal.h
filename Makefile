.PHONY: all clean test e_decimal.a gcov_report

# UTILITIES
CC = gcc
AR = ar rs
RAN = ranlib
MK = mkdir -p

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra
TEST_FLAGS = -lcheck
DEBUG = #-DDEBUG

# FILENAMES
TARGET = e_decimal.a

### source code directories:
ARITHMDIR = arithmetic/
COMPDIR = comparison/
CONVERTDIR = converters/
INTERNALDIR = internal/

SRC = $(wildcard $(ARITHMDIR)*.c)
SRC += $(wildcard $(COMPDIR)*.c)
SRC += $(wildcard $(CONVERTDIR)*.c)
SRC += $(wildcard $(INTERNALDIR)*.c)

OBJDIR = obj/
OBJ = $(patsubst $(ARITHMDIR)%.c, $(OBJDIR)%.o, $(SRC))
OBJ += $(patsubst $(INTERNALDIR)%.c, $(OBJDIR)%.o, $(SRC))

TESTDIR = tests/
TEST_TARGETS = test_addition test_subtruction test_get_bit test_set_bit test_get_scale test_shift

# LOG = test_e_decimal.log
# WRITELOG = >> $(LOG)
# OPENLOG = open $(LOG)


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
	@$(CC) $(CF) -c $< -o $@ $(DEBUG)

$(OBJDIR)%.o: $(INTERNALDIR)%.c
	@$(CC) $(CF) -c $< -o $@ $(DEBUG)

OBJ_SUCCESS:
	@echo "$(CC): objects compilation \033[0;32msuccess\033[0m"


# TESTS
test: log_remove lib UT_start_msg $(TEST_TARGETS)
	$(OPENLOG)

UT_start_msg:
	@echo "\n\033[0;32m>>>>>>>>SET OF UNIT TESTS LAUNCHED<<<<<<<<\033[0m" $(WRITELOG)

### main functions tests
test_add: log_remove test_addition
	$(OPENLOG)

test_addition: $(TESTDIR)test_add.c lib
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_sub: log_remove test_subtruction
	$(OPENLOG)

test_subtruction: $(TESTDIR)test_sub.c lib
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET) $(DEBUG)
	@./$@ $(WRITELOG)
	@rm -f $@

### internal functions tests
test_get: log_remove test_get_bit test_get_scale
	$(OPENLOG)

test_get_bit: $(TESTDIR)test_get_bit.c lib
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_set: log_remove test_set_bit
	$(OPENLOG)

test_set_bit: $(TESTDIR)test_set_bit.c lib
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_get_scale: $(TESTDIR)test_get_scale.c lib
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_shift: $(TESTDIR)test_shift.c lib
	@echo "\n\033[0;33m$<\033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@


# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h $(TESTDIR)*.c
	
gost:
	clang-format --style=google -i $(SRCDIR)*.c *.h $(TESTDIR)*.c

clean: log_remove
	rm -rf $(TARGET) $(OBJDIR) *.out *.gch

log_remove:
	rm -rf $(LOG)

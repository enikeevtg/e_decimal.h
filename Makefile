.PHONY: all clean test e_decimal.a gcov_report

# UTILITIES
CC = gcc
AR = ar rs
RAN = ranlib
MK = mkdir -p

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra
TEST_FLAGS = -lcheck

# FILENAMES
TARGET = e_decimal.a
SRCDIR = src/
OBJDIR = obj/
SRC = $(wildcard $(SRCDIR)*.c)
OBJ = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRC))
TESTDIR = tests_int/


# MAIN TARGET
lib: $(TARGET)

$(TARGET): objects
	@$(AR) $@ $(OBJ)
	@$(RAN) $@
	@echo "$(AR): creating library $(TARGET) \033[0;32msuccess\033[0m"

objects: makeobjdir $(OBJ) OBJ_SUCCESS

makeobjdir:
	@$(MK) $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CF) -c $^ -o $@

OBJ_SUCCESS:
	@echo "$(CC): objects compilation \033[0;32msuccess\033[0m"


# TESTS
test: test_getbit test_int2bin test_setbit test_add
	@echo

test_getbit: $(TESTDIR)test_get_bit.c lib
	@echo "\n\033[0;33m$<\033[0m"
	@$(CC) $(CF) $(TEST_FLAGS) $< -o test_get_bit -L. $(TARGET)
	@./test_get_bit
	@rm -f test_get_bit

test_int2bin: $(TESTDIR)test_int_to_bin.c lib
	@echo "\n\033[0;33m$<\033[0m"
	@$(CC) $(CF) $(TEST_FLAGS) $< -o test_int_to_bin  -L. $(TARGET)
	@./test_int_to_bin
	@rm -f test_int_to_bin

test_setbit: $(TESTDIR)test_set_bit.c lib
	@echo "\n\033[0;33m$<\033[0m"
	@$(CC) $(CF) $(TEST_FLAGS) $< -o test_set_bit -L. $(TARGET)
	@./test_set_bit
	@rm -f test_set_bit

test_add: $(TESTDIR)test_add.c lib
	@echo "\n\033[0;33m$<\033[0m"
	@$(CC) $(CF) $(TEST_FLAGS) $< -o test_add -L. $(TARGET)
	@./test_add
	@rm -f test_add

# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h $(TESTDIR)*.c
	
tostyle:
	clang-format --style=google -i $(SRCDIR)*.c *.h $(TESTDIR)*.c

clean:
	rm -rf $(TARGET) $(OBJDIR) *.out *.gch

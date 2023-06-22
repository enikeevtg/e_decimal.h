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
TARGET = e_integer.a
# TARGET = e_decimal.a
SRCDIR = src_int/
# SRCDIR = src/
OBJDIR = obj/
SRC = $(wildcard $(SRCDIR)*.c)
OBJ = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRC))
TESTDIR = tests_int/
# TESTDIR = tests_dec/


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
test: lib UT_start_msg test_getbit test_setbit test_add test_shift

UT_start_msg:
	@echo "\n\033[0;32m>>>>>>>>SET OF UNIT TESTS LAUNCHED<<<<<<<<\033[0m"

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

test_shift: $(TESTDIR)test_shift.c lib
	@echo "\n\033[0;33m$<\033[0m"
	@$(CC) $(CF) $(TEST_FLAGS) $< -o test_shift -L. $(TARGET)
	@./test_shift
	@rm -f test_shift

# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h $(TESTDIR)*.c
	
gost:
	clang-format --style=google -i $(SRCDIR)*.c *.h $(TESTDIR)*.c

clean:
	rm -rf $(TARGET) $(OBJDIR) *.out *.gch

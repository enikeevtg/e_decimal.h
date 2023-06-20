.PHONY: all clean test s21_decimal.a gcov_report

# UTILITIES
CC = gcc

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra
TEST_FLAGS = -lcheck

# FILENAMES
SRCDIR = src/
OBJDIR = obj/
TESTDIR = tests/

# MAIN TARGETS
# TESTS
test_getbit: $(TESTDIR)test_get_bit.c $(SRCDIR)*.c
	@$(CC) $(CF) $(TEST_FLAGS) $^ -o test_get_bit
	@./test_get_bit
	@rm -f test_get_bit

test_int2bin: $(TESTDIR)test_int_to_bin.c $(SRCDIR)*.c
	@$(CC) $(CF) $(TEST_FLAGS) $^ -o test_int_to_bin
	@./test_int_to_bin
	@rm -f test_int_to_bin




# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h $(TESTDIR)*.c
	
tostyle:
	clang-format --style=google -i $(SRCDIR)*.c *.h $(TESTDIR)*.c

clean:
	rm -f *.o *.out *.gch

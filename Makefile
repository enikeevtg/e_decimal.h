.PHONY: all clean test e_decimal.a gcov_report

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
test_get: $(TESTDIR)test_get_bit.c $(SRCDIR)e_get_bit.c
	$(CC) $(CF) $(TEST_FLAGS) $^ -o test_get_bit
	./test_get_bit
	rm -f test_get_bit





# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h
	
tostyle:
	clang-format --style=google -i $(SRCDIR)*.c *.h

clean:
	rm -f *.o *.out *.gch

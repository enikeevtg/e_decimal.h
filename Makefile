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

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CF) -c $< -o $@

OBJ_SUCCESS:
	@echo "$(CC): objects compilation \033[0;32msuccess\033[0m"


# TESTS
test: lib UT_start_msg test_get test_set test_add test_sub #test_shift

UT_start_msg:
	@echo "\n\033[0;32m>>>>>>>>SET OF UNIT TESTS LAUNCHED<<<<<<<<\033[0m"

test_get: test_get_bit

test_get_bit: $(TESTDIR)test_get_bit.c lib
	@echo "\n\033[0;33m$<\033[0m"
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@
	@rm -f $@

test_set: test_set_bit

test_set_bit: $(TESTDIR)test_set_bit.c lib
	@echo "\n\033[0;33m$<\033[0m"
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@
	@rm -f $@

test_add: $(TESTDIR)test_add.c lib
	@echo "\n\033[0;33m$<\033[0m"
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@
	@rm -f $@

test_sub: $(TESTDIR)test_sub.c lib
	@echo "\n\033[0;33m$<\033[0m"
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@
	@rm -f $@

test_shift: $(TESTDIR)test_shift.c lib
	@echo "\n\033[0;33m$<\033[0m"
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@
	@rm -f $@

# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h $(TESTDIR)*.c
	
gost:
	clang-format --style=google -i $(SRCDIR)*.c *.h $(TESTDIR)*.c

clean:
	rm -rf $(TARGET) $(OBJDIR) *.out *.gch

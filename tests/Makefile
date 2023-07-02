.PHONY: all clean test e_decimal.a gcov_report

# UTILITIES
CC = gcc
OPEN = open -e
# -e option is for TextEdit.app

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra #-g
TEST_FLAGS = -lcheck
DEBUG = #-DDEBUG

# FILENAMES
LIB = ../e_decimal.a
TEST_TARGETS = test_get_funcs test_set_funcs test_shifts
TEST_TARGETS += test_addition test_subtruction
TEST_TARGETS += test_is_less test_is_less_or_equal test_is_greater test_is_greater_or_equal test_is_equal test_is_not_equal

### log file
LOG = _test_e_decimal.log
WRITELOG = >> $(LOG)
OPENLOG = $(OPEN) $(LOG)


# TESTS
test: clean UT_start_msg $(TEST_TARGETS)
	$(OPENLOG)

UT_start_msg:
	@echo "\n\033[0;32m  >>>>>>>>SET OF UNIT TESTS LAUNCHED<<<<<<<<  \033[0m" $(WRITELOG)

### internal functions tests
test_gets: log_remove test_get_funcs
	$(OPENLOG)

test_get_funcs: test_gets.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_sets: log_remove test_set_funcs
	$(OPENLOG)

test_set_funcs: test_sets.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_shifts: test_shifts.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

### arithmetic functions tests
test_add: log_remove test_addition
	$(OPENLOG)

test_addition: test_add.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_sub: log_remove test_subtruction
	$(OPENLOG)

test_subtruction: test_sub.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB) $(DEBUG)
	@./$@ $(WRITELOG)
	@rm -f $@

test_mul: log_remove test_multiplication
	$(OPENLOG)

test_multiplication: test_mul.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

### comparison functions tests
test_comp: log_remove test_is_less test_is_less_or_equal test_is_greater test_is_greater_or_equal test_is_equal test_is_not_equal
	$(OPENLOG)

test_is_less: test_is_less.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_is_less_or_equal: test_is_less_or_equal.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_is_greater: test_is_greater.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_is_greater_or_equal: test_is_greater_or_equal.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_is_equal: test_is_equal.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

test_is_not_equal: test_is_not_equal.c
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ $(LIB)
	@./$@ $(WRITELOG)
	@rm -f $@

# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h *.c
	
gost:
	clang-format --style=google -i $(SRCDIR)*.c *.h *.c

clean:
	rm -rf $(LOG)

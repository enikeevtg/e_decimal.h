.PHONY: all clean test e_decimal.a gcov_report

# UTILITIES
CC = gcc
AR = ar rs
RAN = ranlib
MK = mkdir -p
OPEN = open -e  # -e option is for TextEdit.app

# UTILITIES OPTIONS
CF = -Wall -Werror -Wextra #-g
TEST_FLAGS = -lcheck
DEBUG = #-DDEBUG

# FILENAMES
TARGET = e_decimal.a

### source code directories:
ARITHMDIR = arithmetic/
COMPDIR = comparison/
CONVERTDIR = converters/
ANOTHERDIR = another/
INTERNALDIR = internal/

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
TEST_TARGETS = test_get_funcs test_set_funcs test_shifts
TEST_TARGETS += test_addition test_subtruction
TEST_TARGETS += test_is_less test_is_less_or_equal test_is_greater test_is_greater_or_equal test_is_equal test_is_not_equal

### log file
LOG = test_e_decimal.log
# WRITELOG = >> $(LOG)
# OPENLOG = $(OPEN) $(LOG)


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

$(OBJDIR)%.o: $(COMPDIR)%.c
	@$(CC) $(CF) -c $< -o $@ $(DEBUG)

$(OBJDIR)%.o: $(ANOTHERDIR)%.c
	@$(CC) $(CF) -c $< -o $@ $(DEBUG)

$(OBJDIR)%.o: $(INTERNALDIR)%.c
	@$(CC) $(CF) -c $< -o $@ $(DEBUG)

OBJ_SUCCESS:
	@echo "$(CC): objects compilation \033[0;32msuccess\033[0m"


# TESTS
test: log_remove lib UT_start_msg $(TEST_TARGETS)
	$(OPENLOG)

UT_start_msg:
	@echo "\n\033[0;32m  >>>>>>>>SET OF UNIT TESTS LAUNCHED<<<<<<<<  \033[0m" $(WRITELOG)

### internal functions tests
test_gets: log_remove test_get_funcs
	$(OPENLOG)

test_get_funcs: $(TESTDIR)test_gets.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_sets: log_remove test_set_funcs
	$(OPENLOG)

test_set_funcs: $(TESTDIR)test_sets.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_shifts: $(TESTDIR)test_shifts.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

### arithmetic functions tests
test_add: log_remove test_addition
	$(OPENLOG)

test_addition: $(TESTDIR)test_add.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_sub: log_remove test_subtruction
	$(OPENLOG)

test_subtruction: $(TESTDIR)test_sub.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET) $(DEBUG)
	@./$@ $(WRITELOG)
	@rm -f $@

test_mul: log_remove test_multiplication
	$(OPENLOG)

test_multiplication: $(TESTDIR)test_mul.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

### comparison functions tests
test_comp: log_remove test_is_less test_is_less_or_equal test_is_greater test_is_greater_or_equal test_is_equal test_is_not_equal
	$(OPENLOG)

test_is_less: $(TESTDIR)test_is_less.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_is_less_or_equal: $(TESTDIR)test_is_less_or_equal.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_is_greater: $(TESTDIR)test_is_greater.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_is_greater_or_equal: $(TESTDIR)test_is_greater_or_equal.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_is_equal: $(TESTDIR)test_is_equal.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

test_is_not_equal: $(TESTDIR)test_is_not_equal.c lib
	@echo "\n\033[0;33m  $<  \033[0m" $(WRITELOG)
	@$(CC) $(CF) $(TEST_FLAGS) $< -o $@ -L. $(TARGET)
	@./$@ $(WRITELOG)
	@rm -f $@

# SERVICES
style:
	clang-format --style=google -n $(SRCDIR)*.c *.h $(TESTDIR)*.c
	
gost:
	clang-format --style=google -i $(SRCDIR)*.c *.h $(TESTDIR)*.c

clean: log_remove
	rm -rf $(TARGET) $(OBJDIR) *.out *.gch *.dSYM

log_remove:
	rm -rf $(LOG)

update:
	sh ../scripts/update_gitlab_test.sh

get:
	sh ../scripts/get_test_from_gitlab.sh

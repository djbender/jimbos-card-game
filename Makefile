# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -Wpedantic
REL_CFLAGS = -O3
TEST_CFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lcriterion -Wno-unused-command-line-argument

EXE := cards

# dirs
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Target executable
TARGET = $(BIN_DIR)/$(EXE)

# Object files (derived from source files)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c) $(wildcard lib/**/*.c))
TEST_OBJS := $(wildcard $(TEST_DIR)/*.c) $(OBJS)

# debug
DBG_DIR := debug
DBG_EXE = $(DBG_DIR)/$(EXE)
DBG_OBJS = $(patsubst $(SRC_DIR)/, $(DBG_DIR)/, $(OBJS))
DBG_CFLAGS = -g -O0 -DDEBUG

# test
TEST_DIR := test
TEST_EXE := $(TEST_DIR)/test

# Default rule
all: debug $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(REL_CFLAGS) -o $@ $(OBJS)

# Rule to compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(REL_CFLAGS) -o $@ -c $(SRC_DIR)/$*.c

debug: $(DBG_EXE)

$(DBG_EXE): $(DBG_OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DBG_CFLAGS) -o $(DBG_EXE) $^

$(DBG_DIR)/%.o: $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) $(DBGC_CFLAGS) -o $@ $<

test: $(TEST_EXE)

test-program := test/test
test-sources := $(wildcard test/*_test.c)
test-objects := $(test-sources:.c=.o)
test-target-sources := $(filter-out src/cards.c, $(wildcard $(SRC_DIR)/*.c))
test-target-objects := $(test-target-sources:.c=.o)

$(test-program): $(test-objects) $(test-target-objects)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(TEST_CFLAGS) -o $(TEST_EXE) $^

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@echo "test_dir/*.o"
	$(CC) -c $(CFLAGS) $(TEST_CFLAGS) -o $@ $<

test-run: test
	@./$(test-program) --verbose

# Clean rule to remove generated files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(DBG_DIR) test/test

# Phony targets (not actual files)
.PHONY: all clean dir test test-run

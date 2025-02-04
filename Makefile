# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -Wpedantic

EXE := cards

# dirs
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Target executable
TARGET = $(BIN_DIR)/$(EXE)

# Object files (derived from source files)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c) $(wildcard lib/**/*.c))

# debug
DBG_DIR := debug
DBG_EXE = $(DBG_DIR)/$(EXE)
DBG_OBJS = $(patsubst $(SRC_DIR)/, $(DBG_DIR)/, $(OBJS))
DBG_CFLAGS = -g -O0 -DDEBUG

# Default rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $(SRC_DIR)/$*.c

debug: $(DBG_EXE)

$(DBG_EXE): $(DBG_OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DBG_CFLAGS) -o $(DBG_EXE) $^

$(DBG_DIR)/%.o: $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) $(DBGC_FLAGS) -o $@ $<

# Clean rule to remove generated files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(DBG_DIR)

# Phony targets (not actual files)
.PHONY: all clean dir

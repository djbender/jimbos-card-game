# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -Wpedantic -g

# dirs
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Target executable
TARGET = $(BIN_DIR)/cards

SOURCES  := $(wildcard $(SRC_DIR)/*.c)
# Object files (derived from source files)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c) $(wildcard lib/**/*.c))

# Default rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to compile source files into object files
# $(OBJS): $(SRC_DIR)/$*
.SECONDARYEXPANSION:
$(OBJS): $($$@:$(BUILD_DIR)/%.o=$(SRC_DIR)/%.c)
	@echo $(patsubst $(BUILD_DIR)/%.o, $(SRC_DIR)/%.c, $@)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $(patsubst $(BUILD_DIR)/%, $(SRC_DIR)/%.c, $*)

# Clean rule to remove generated files
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Phony targets (not actual files)
.PHONY: all clean dir

# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -g

# Target executable
TARGET = cards.out

# Source files
SRCS = cards.c

# Object files (derived from source files)
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (not actual files)
.PHONY: all clean

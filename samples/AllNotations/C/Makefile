SRC_DIR=.

# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall $(addprefix -I,$(shell find $(SRC_DIR) -type d)) -I./include

# Source files
SRC_FILES = $(shell find $(SRC_DIR) -name "*.c")
# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Target executable
TARGET = my_program

# Default target
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(TARGET)

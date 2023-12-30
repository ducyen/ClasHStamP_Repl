SRC_DIR = .

# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall $(addprefix -I,$(shell find $(SRC_DIR) -type d))

# Source files
SRC_FILES = $(shell find $(SRC_DIR) -name "*.cpp")
# Object files
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Target executable
TARGET = my_program

# Default target
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(TARGET)

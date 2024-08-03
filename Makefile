# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = test

# Object files
OBJ = priority.o main.o

# Default target
all: $(TARGET)

# Rule for compiling priority.c into priority.o
priority.o:
	$(CC) $(CFLAGS) -c priority.c

# Rule for compiling test.c into test.o
main.o:
	$(CC) $(CFLAGS) -c main.c

# Rule for building the target executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean

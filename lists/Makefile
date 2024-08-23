# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = test

# Object files
OBJ = node.o list.o main.o

# Default target
all: $(TARGET)

# Rule for compiling node.c into node.o
node.o:
	$(CC) $(CFLAGS) -c node.c

# Rule for compiling list.c into list.o
list.o:
	$(CC) $(CFLAGS) -c list.c

# Rule for compiling main.c into main.o
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

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = test

# Object files
OBJ = utilities.o list.o mis.o main.o node.o

# Default target
all: $(TARGET)

# Rule for compiling utilities.c into utilities.o
utilities.o:
	$(CC) $(CFLAGS) -c ../utilities/utilities.c

# Rule for compiling node.c into node.o
node.o:
	$(CC) $(CFLAGS) -c ../../lists/utilities/node.c

# Rule for compiling list.c into list.o
list.o:
	$(CC) $(CFLAGS) -c ../../lists/simple/list.c

# Rule for compiling mis.c into mis.o
mis.o:
	$(CC) $(CFLAGS) -c mis.c

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

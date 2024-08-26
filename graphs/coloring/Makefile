# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = test

# Object files
OBJ = utilities.o node.o list.o mis.o coloring.o main.o

# Default target
all: $(TARGET)

# Rule for compiling utilities.c into utilities.o
utilities.o:
	$(CC) $(CFLAGS) -c ../utilities/utilities.c

# rule for compiling node.c into node.o
node.o:
	$(CC) $(CFLAGS) -c ../../lists/utilities/node.c

# Rule for compiling list.c into list.o
list.o: node.o
	$(CC) $(CFLAGS) -c ../../lists/simple/list.c

# rule for compiling mis.c into mis.o
mis.o: utilities.o node.o list.o
	$(CC) $(CFLAGS) -c ../MIS/mis.c

# Rule for compiling coloring.c into coloring.o
coloring.o:
	$(CC) $(CFLAGS) -c coloring.c

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

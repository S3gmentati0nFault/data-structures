# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = test

# Object files
OBJ = utilities.o main.o

# Default target
all: $(TARGET)

# Rule for compiling mutils.c into mutils.o
#mutils.o:
#	$(CC) $(CFLAGS) -c ../../master-utilities/mutils.h

# Rule for compiling utilities.c into utilities.o
utilities.o:
	$(CC) $(CFLAGS) -c ../utilities/utilities.c

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

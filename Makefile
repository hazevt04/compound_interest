# Good Makefile Example
TARGET = compound_interest
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

SRC_DIR = ./
INC_DIR = ./

.PHONY: default all clean

default: $(TARGET)
all: default

# Make a *.o file for every *.c file
OBJECTS = $(patsubst %.c, %.o, $(wildcard $(SRC_DIR)*.c))
HEADERS = $(wildcard $(INC_DIR)*.h)

# Target pattern to compile to the *.o files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

# The '-' in front of the rm
# is to continue processing if there is an error
# Covers the case where there are no *.o files
clean:
	-rm -f *.o
	-rm -f $(TARGET)




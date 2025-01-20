CC = g++
CFLAGS = -Wall -Wextra -std=c++17 -Iinclude
SRC = src/main.cc src/CompoundCalculator.cc src/InputHandler.cc
OBJ = $(SRC:.cc=.o)
TARGET = finance_calculator

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all run clean

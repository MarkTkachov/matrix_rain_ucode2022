BIN := matrix_rain


BIN_TARGET := MATRIX_RAIN

LINKER := -lncurses

.PHONY = all clean uninstall reinstall

CC = clang -std=c11  -Wall -Wextra -Werror -Wpedantic #compiler -std=c11

SOURCE := $(wildcard src/*.c)

HEAD := $(wildcard inc/*.h)

OBJECTS := $(notdir $(SOURCE:.c=.o))

all: $(BIN_TARGET) 

$(BIN_TARGET): $(SOURCE) $(HEAD)
	mkdir -p obj 
	$(CC) -c  $(SOURCE)  
	mv $(OBJECTS) ./obj
	$(CC) -o $(BIN) $(addprefix obj/, $(OBJECTS)) $(LINKER)


uninstall: clean
	rm -f $(BIN)

clean:
	rm -drf obj
	rm -f $(wildcard *.o)

reinstall: $(BIN_TARGET)

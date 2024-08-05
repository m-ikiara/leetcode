CC := gcc

BinDIR := ./bin
ObjDIR := ./obj
CFLAGS := -O3 -ggdb -Wall -Werror -Wextra -pedantic

SRC := $(wildcard ./src/*.c)
OBJ := $(addprefix $(ObjDIR)/, $(notdir $(SRC:.c=.o)))

.PHONY: all clean strip

$(ObjDIR)/%.o: ./src/%.c
	mkdir -p $(ObjDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BinDIR)/%.exe: ./obj/%.o
	mkdir -p $(BinDIR)
	$(CC) $(CFLAGS) -o $@ $<

all: $(addprefix $(BinDIR)/, $(notdir $(OBJ:.o=.exe)))

clean:
	rm -rf $(BinDIR)
	rm -rf $(ObjDIR)

strip:
	strip --strip-unneeded "$(BinDIR)/%" -o "$(BinDIR)/%"

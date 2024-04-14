CC := gcc
CFLAGS := -O3 -ggdb -Wall -Werror -Wextra -pedantic
BINARIES := ./bin
SRC := $(wildcard ./src/*.c)
TARGETS := atn

atn: ./src/add_two_numbers.c
	$(CC) $(CFLAGS) -o atn ./src/add_two_numbers.c

############################################################################
# TODO: finish up on this Makefile
############################################################################

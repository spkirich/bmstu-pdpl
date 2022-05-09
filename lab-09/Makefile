# Компилятор
CC := gcc

# Флаги компиляции
CFLAGS := -Wall -Wextra -Wpedantic -Iinc -g

# Фиктивные цели
.PHONY: all clean

all: out/prof out/prec

out/prof: src/prof.c inc/prof.h
	$(CC) $(CFLAGS) $< -o $@

out/prec: src/prec.c inc/prec.h
	$(CC) $(CFLAGS) $< -o $@

# Компилятор
CC := gcc

# Флаги компиляции
CFLAGS := -Wall -Wextra -Wpedantic -Iinc -g

# Фиктивные цели
.PHONY: clean

out/prec: src/prec.c inc/prec.h
	$(CC) $(CFLAGS) $< -o $@

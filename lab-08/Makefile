# Компилятор
CC := gcc

# Флаги компилятора
CFLAGS := -Wall -Wextra -Wpedantic -Iinc -g

# Ассемблер
SC := nasm

# Флаги ассемблера
SFLAGS := -felf64

# Фиктивные цели
.PHONY: clean

out/main: out/main.o out/slen.o out/scpy.o
	$(CC) $^ -o $@

out/main.o: src/main.c inc/slib.h
	$(CC) -c $(CFLAGS) $< -o $@

out/slen.o: src/slen.c inc/slib.h
	$(CC) -c $(CFLAGS) $< -o $@

out/scpy.o: src/scpy.s inc/slib.h
	$(SC)    $(SFLAGS) $< -o $@

clean:
	$(RM) out/*

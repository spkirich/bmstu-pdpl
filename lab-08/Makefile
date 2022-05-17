# Компилятор
CC := gcc

# Опции компилятора
CFLAGS := -Wall -Wextra -Wpedantic -Iinc -g

# Ассемблер
AS := nasm

# Опции ассемблера
ASFLAGS := -felf64

# Фиктивные цели
.PHONY: clean

out/runner: out/main.o out/slen.o out/scpy.o
	$(CC) $^ -o $@

out/main.o: src/main.c inc/slib.h | out
	$(CC) -c $(CFLAGS) $< -o $@

out/slen.o: src/slen.c inc/slib.h | out
	$(CC) -c $(CFLAGS) $< -o $@

out/scpy.o: src/scpy.s inc/slib.h | out
	$(AS)   $(ASFLAGS) $< -o $@

out:
	mkdir $@

clean:
	$(RM) -r out

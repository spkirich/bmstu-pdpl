# Компилятор
CC := gcc

# Опции компилятора
CFLAGS := -Wall -Wextra -Wpedantic -Iinc -g

# Фиктивные цели
.PHONY: clean

out/runner: out/main.o out/prod.o
	$(CC) $^ -o $@

out/main.o: src/main.c inc/prod.h | out
	$(CC) -c $(CFLAGS) $< -o $@

out/prod.o: src/prod.c inc/prod.h | out
	$(CC) -c $(CFLAGS) $< -o $@

out:
	mkdir $@

clean:
	$(RM) -r out

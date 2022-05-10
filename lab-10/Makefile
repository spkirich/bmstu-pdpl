# Компилятор
CC := gcc

# Флаги компиляции
CFLAGS := -Wall -Wextra -Wpedantic -Iinc -g

# Фиктивные цели
.PHONY: clean

out/main: out/main.o out/prod.o
	$(CC) $^ -o $@

out/main.o: src/main.c inc/prod.h
	$(CC) -c $(CFLAGS) $< -o $@

out/prod.o: src/prod.c inc/prod.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) out/*

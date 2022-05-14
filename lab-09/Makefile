# Компилятор
CC := gcc

# Флаги компиляции
CFLAGS := -Wall -Wextra -Wpedantic -Iinc -g

# Фиктивные цели
.PHONY: clean

out/runner: out/main.o out/prof.o out/prec.o
	$(CC) $^ -o $@

out/main.o: src/main.c inc/prof.h inc/prec.h
	$(CC) -c $(CFLAGS) $< -o $@

out/prof.o: CFLAGS += -mno-sse
out/prof.o: src/prof.c inc/prof.h
	$(CC) -c $(CFLAGS) $< -o $@

out/prec.o: src/prec.c inc/prec.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) out/*

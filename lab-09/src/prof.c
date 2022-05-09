#include <stdio.h>

// Профилирование
#include <time.h>

#include "prof.h"

#define LOOP 1e+8

// Не очень приятный макрос для профилирования разных функций
#define PROF(desc, func) do {                               \
    clock_t s = clock();                                    \
                                                            \
    for (int i = 0; i < LOOP; i++)                          \
        func(2.0, 2.0);                                     \
                                                            \
    clock_t t = clock();                                    \
                                                            \
    printf("%s: %e s\n",                                    \
        desc, (double) (t - s) / CLOCKS_PER_SEC / LOOP);    \
} while (0)

int main() {
    PROF("Soft 32 + 32", sadd32);
    PROF("Hard 32 + 32", hadd32);

    PROF("Soft 64 + 64", sadd64);
    PROF("Hard 64 + 64", hadd64);

    PROF("Soft 80 + 80", sadd80);
    PROF("Hard 80 + 80", hadd80);

    return 0;
}

float sadd32(float a, float b) {
    return a + b;
}

float hadd32(float a, float b) {
    float c;

    // Кладём на стек b и a, прибавляем b к a, забираем как c
    asm("fadd %%st(1), %%st(0)" : "=t" (c) : "0" (a), "u" (b));

    return c;
}

double sadd64(double a, double b) {
    return a + b;
}

double hadd64(double a, double b) {
    double c;

    // Кладём на стек b и a, прибавляем b к a, забираем как c
    asm("fadd %%st(1), %%st(0)" : "=t" (c) : "0" (a), "u" (b));

    return c;
}

long double sadd80(long double a, long double b) {
    return a + b;
}

long double hadd80(long double a, long double b) {
    long double c;

    // Кладём на стек b и a, прибавляем b к a, забираем как c
    asm("fadd %%st(1), %%st(0)" : "=t" (c) : "0" (a), "u" (b));

    return c;
}

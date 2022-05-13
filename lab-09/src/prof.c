#include <stdio.h>

// Профилирование
#include <time.h>

// Проверка условий
#include <assert.h>

#include "prof.h"

#define LOOP 1e+8

// Не очень приятный макрос для профилирования разных функций
#define PROF(func) do {                                     \
    clock_t s = clock();                                    \
                                                            \
    for (int i = 0; i < LOOP; i++)                          \
        assert(func(2.0, 2.0) == 4.0);                      \
                                                            \
    clock_t t = clock();                                    \
                                                            \
    printf("%s: %e s\n",                                    \
        #func, (double) (t - s) / CLOCKS_PER_SEC / LOOP);   \
} while (0)

int main() {
    PROF(sadd32);
    PROF(smul32);

    PROF(sadd64);
    PROF(smul64);

#ifdef X87

    PROF(sadd80);
    PROF(smul80);

    PROF(hadd32);
    PROF(hmul32);

    PROF(hadd64);
    PROF(hmul64);

    PROF(hadd80);
    PROF(hmul80);

#endif // X87

    return 0;
}

float sadd32(float a, float b) {
    return a + b;
}

float smul32(float a, float b) {
    return a * b;
}

double sadd64(double a, double b) {
    return a + b;
}

double smul64(double a, double b) {
    return a * b;
}

#ifdef X87

long double sadd80(long double a, long double b) {
    return a + b;
}

long double smul80(long double a, long double b) {
    return a * b;
}

float hadd32(float a, float b) {
    float c;

    // Кладём на стек b и a, прибавляем a к b
    asm("faddp" : "=t" (c) : "0" (a), "u" (b));

    return c;
}

float hmul32(float a, float b) {
    float c;

    // Кладём на стек b и a, домножаем b на a
    asm("fmulp" : "=t" (c) : "0" (a), "u" (b));

    return c;
}

double hadd64(double a, double b) {
    double c;

    // Кладём на стек b и a, прибавляем a к b
    asm("faddp" : "=t" (c) : "0" (a), "u" (b));

    return c;
}

double hmul64(double a, double b) {
    double c;

    // Кладём на стек b и a, домножаем b на a
    asm("fmulp" : "=t" (c) : "0" (a), "u" (b));

    return c;
}

long double hadd80(long double a, long double b) {
    long double c;

    // Кладём на стек b и a, прибавляем a к b
    asm("faddp" : "=t" (c) : "0" (a), "u" (b));

    return c;
}

long double hmul80(long double a, long double b) {
    long double c;

    // Кладём на стек b и a, домножаем b на a
    asm("fmulp" : "=t" (c) : "0" (a), "u" (b));

    return c;
}

#endif // X87

#include <stdio.h>

// Профилирование
#include <time.h>

// Проверка условий
#include <assert.h>

#include "prof.h"

#define LOOP 1e+8

// Не очень приятный макрос для профилирования разных функций
#define PROF(func, type) do {                               \
    type a = 2.0, b = 2.0, c;                               \
                                                            \
    clock_t s = clock();                                    \
                                                            \
    for (int i = 0; i < LOOP; i++) {                        \
        func(&a, &b, &c);                                   \
        assert(c == 4.0);                                   \
    }                                                       \
                                                            \
    clock_t t = clock();                                    \
                                                            \
    printf("%s: %e s\n",                                    \
        #func, (double) (t - s) / CLOCKS_PER_SEC / LOOP);   \
} while (0)

int main() {
    PROF(sadd32, float);
    PROF(smul32, float);

    PROF(sadd64, double);
    PROF(smul64, double);

    PROF(sadd80, long double);
    PROF(smul80, long double);

    PROF(hadd32, float);
    PROF(hmul32, float);

    PROF(hadd64, double);
    PROF(hmul64, double);

    PROF(hadd80, long double);
    PROF(hmul80, long double);

    return 0;
}

void sadd32(float *a, float *b, float *c) {
    *c = *a + *b;
}

void smul32(float *a, float *b, float *c) {
    *c = *a * *b;
}

void sadd64(double *a, double *b, double *c) {
    *c = *a + *b;
}

void smul64(double *a, double *b, double *c) {
    *c = *a * *b;
}

void sadd80(long double *a, long double *b, long double *c) {
    *c = *a + *b;
}

void smul80(long double *a, long double *b, long double *c) {
    *c = *a * *b;
}

void hadd32(float *a, float *b, float *c) {

    // Кладём на стек a и b, складываем
    asm("faddp" : "=t" (*c) : "u" (*a), "0" (*b));
}

void hmul32(float *a, float *b, float *c) {

    // Кладём на стек a и b, умножаем
    asm("fmulp" : "=t" (*c) : "u" (*a), "0" (*b));
}

void hadd64(double *a, double *b, double *c) {

    // Кладём на стек a и b, складываем
    asm("faddp" : "=t" (*c) : "u" (*a), "0" (*b));
}

void hmul64(double *a, double *b, double *c) {

    // Кладём на стек a и b, умножаем
    asm("fmulp" : "=t" (*c) : "u" (*a), "0" (*b));
}

void hadd80(long double *a, long double *b, long double *c) {

    // Кладём на стек a и b, складываем
    asm("faddp" : "=t" (*c) : "u" (*a), "0" (*b));
}

void hmul80(long double *a, long double *b, long double *c) {

    // Кладём на стек a и b, умножаем
    asm("fmulp" : "=t" (*c) : "u" (*a), "0" (*b));
}

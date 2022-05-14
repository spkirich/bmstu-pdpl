#include <stdio.h>

// Профилирование
#include <time.h>

// Проверка условий
#include <assert.h>

#include "prof.h"
#include "prec.h"

// Число повторов
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

void prec(long double p) {
    printf("π = %Le, sin(π / 1) = % Le, sin(π / 2) = % Le;\n",
        p, fsin(p / 1), fsin(p / 2));
}

int main() {
    puts("\nСкорость арифметических операций\n");

    PROF(sadd32, float);
    PROF(hadd32, float);

    PROF(sadd64, double);
    PROF(hadd64, double);

    PROF(sadd80, long double);
    PROF(hadd80, long double);

    PROF(smul32, float);
    PROF(hmul32, float);

    PROF(smul64, double);
    PROF(hmul64, double);

    PROF(smul80, long double);
    PROF(hmul80, long double);

    puts("\nТочность приближённых вычислений\n");

    prec(PREC2PI);
    prec(PREC6PI);
    prec(fldpi());

    return 0;
}

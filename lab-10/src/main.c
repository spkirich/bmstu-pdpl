#include <stdio.h>

// Профилирование
#include <time.h>

// Проверка условий
#include <assert.h>

#include "prod.h"

// Число повторов
#define LOOP 1e+8

void line(const char *f, clock_t s, clock_t t) {
    printf("%s: %e s\n", f,
        (double) (t - s) / CLOCKS_PER_SEC / LOOP);
}

int main() {
    float u[4] = { 1, 2, 3, 4 };
    float v[4] = { 1, 2, 4, 8 };

    clock_t s, t;

    /* Профилирование простой реализации */ {
        s = clock();

        for (int i = 0; i < LOOP; i++)
            assert(sdprod(u, v) == 49);

        t = clock();

        line("sdprod", s, t);
    }

    /* Профилирование быстрой реализации */ {
        s = clock();

        for (int i = 0; i < LOOP; i++)
            assert(fdprod(u, v) == 49);

        t = clock();

        line("fdprod", s, t);
    }

    return 0;
}

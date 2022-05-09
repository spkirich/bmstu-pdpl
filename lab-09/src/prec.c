#include "prec.h"

long double fsin(long double x) {
    long double y;

    // Кладём на вершину, берём синус
    asm("fsin" : "=t" (y) : "0" (x));

    return y;
}

long double fldpi() {
    long double p;

    // Кладём на вершину π
    asm("fldpi" : "=t" (p));

    return p;
}

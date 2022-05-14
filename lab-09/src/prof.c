#include "prof.h"

void sadd32(float *a, float *b, float *c) {
    *c = *a + *b;
}

void hadd32(float *a, float *b, float *c) {

    // Кладём на стек a и b, складываем
    asm("faddp" : "=t" (*c) : "u" (*a), "0" (*b) : "st(1)");
}

void smul32(float *a, float *b, float *c) {
    *c = *a * *b;
}

void hmul32(float *a, float *b, float *c) {

    // Кладём на стек a и b, умножаем
    asm("fmulp" : "=t" (*c) : "u" (*a), "0" (*b) : "st(1)");
}

void sadd64(double *a, double *b, double *c) {
    *c = *a + *b;
}

void hadd64(double *a, double *b, double *c) {

    // Кладём на стек a и b, складываем
    asm("faddp" : "=t" (*c) : "u" (*a), "0" (*b) : "st(1)");
}

void smul64(double *a, double *b, double *c) {
    *c = *a * *b;
}

void hmul64(double *a, double *b, double *c) {

    // Кладём на стек a и b, умножаем
    asm("fmulp" : "=t" (*c) : "u" (*a), "0" (*b) : "st(1)");
}

void sadd80(long double *a, long double *b, long double *c) {
    *c = *a + *b;
}

void hadd80(long double *a, long double *b, long double *c) {

    // Кладём на стек a и b, складываем
    asm("faddp" : "=t" (*c) : "u" (*a), "0" (*b) : "st(1)");
}

void smul80(long double *a, long double *b, long double *c) {
    *c = *a * *b;
}

void hmul80(long double *a, long double *b, long double *c) {

    // Кладём на стек a и b, умножаем
    asm("fmulp" : "=t" (*c) : "u" (*a), "0" (*b) : "st(1)");
}

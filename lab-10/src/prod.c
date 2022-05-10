#include "prod.h"

float sdprod(float *u, float *v) {

    // Очень дёшево и очень сердито, как по учебнику
    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2] + u[3] * v[3];
}

float fdprod(float *u, float *v) {
    float p;

    asm("movaps       (%1), %%xmm0\n\t" // Кладём u в xmm0
        "movaps       (%2), %%xmm1\n\t" // Кладём v в xmm1
        "mulps      %%xmm1, %%xmm0\n\t" // Домножаем u на v
        "movhlps    %%xmm0, %%xmm1\n\t" // Кладём старшую пару элементов
        "addps      %%xmm1, %%xmm0\n\t" // произведения в v и складываем
        "movaps     %%xmm0, %%xmm1\n\t" // Копируем частичную сумму в v
        "shufps $1, %%xmm0, %%xmm0\n\t" // Кладём второй элемент в первый
        "addps      %%xmm1, %%xmm0\n\t" // Складываем с исходным первым
    : "=Yz" (p) : "r" (u), "r" (v));

    return p;
}

#include "slib.h"

unsigned int slen(const char *str) {
    unsigned int len;

    asm("xor %%rax, %%rax\n\t" // Будем искать нулевой байт
        "xor %%rcx, %%rcx\n\t" // Устанавливаем счётчик
        "not %%rcx       \n\t" // на максимальное число
        "mov %%rcx, %%rbx\n\t" // Запоминаем его как длину
        "cld ;repne scasb\n\t" // Ищем нулевой байт
        "sub %%rcx, %%rbx\n\t" // Вычисляем его смещение
        "dec %%rbx       \n\t" // Учитываем нулевой байт
    : "=b" (len) : "D" (str) : "rax", "rcx");

    return len;
}

#include <stdio.h>

#include "slib.h"

int main() {
    char src[] = "Hello world!";
    char dst[] = "Hei maailma!";

    scpy(dst, src, 4);

    printf("Длина - %u: %s\n",
        slen(dst), dst);

    return 0;
}

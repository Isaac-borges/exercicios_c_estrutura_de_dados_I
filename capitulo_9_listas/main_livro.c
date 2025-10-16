#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    Lista L = no(1, no(2, no(2, no(2, no(5, NULL)))));
    printf("%d", ocorrencias(2, L));
    return 0;
}
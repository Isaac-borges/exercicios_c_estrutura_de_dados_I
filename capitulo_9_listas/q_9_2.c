#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    Lista L = no(1, no(2, no(1, no(4, no(1, NULL)))));
    exibe(L);
    printf("Qtd de ocorrencias do numero 1: %d vezes\n\n", ocorrencias(1, L));
    return 0;
}
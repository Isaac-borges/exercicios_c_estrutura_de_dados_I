#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    Lista L = no(1,no(2,no(6,no(7,NULL))));
    exibe(L);
    Lista L2 = no(1,no(3,no(6,no(7,NULL))));
    exibe(L2);
    if (igual(L, L2)) printf("Iguais");
    else printf("Diferentes");

    destroif(&L);
}

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    Lista L = no(1,no(2,no(6,no(7,NULL))));
    int pos_indicada = 5;
    ItemL pos = enesimo(pos_indicada, L);
    printf("O %d item eh %d", pos_indicada, pos);
    destroif(&L);
}
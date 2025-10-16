#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    Lista L = no(1,no(2,no(1,no(2,NULL))));
    exibe(L);
    L = substitui(2, 5, L);
    exibe(L);

    destroif(&L);
    return 0;
}
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    Lista L = no(7,no(9,no(2,NULL)));
    printf("Normal: ");
    exibe(L);
    L = inversa(L);
    printf("Inversa: ");
    exibe(L);
}
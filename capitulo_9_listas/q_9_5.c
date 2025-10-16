#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){ 
    Lista L = no(3,no(1,no(5,no(4,NULL))));
    ItemL soma_lista = soma(L, 0);
    printf("soma dos itens: %d", soma_lista);
}
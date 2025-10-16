#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    Lista L = no(3,no(1,no(5,NULL)));
    exibe_inv(L);
    return 0;
}
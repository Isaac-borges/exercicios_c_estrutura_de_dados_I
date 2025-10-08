#include <stdio.h>
#include <ctype.h>

#include "../capitulo_2_pilhas/char_static_stack.h"
#include "char_static_queue.h"

bool ehPalindroma(char frase[256]) {
    StaticQueue *Q = StaticQueue_create(256);
    StaticStack *S = StaticStack_create(256);
    bool palindroma_check;

    for (int i = 0; frase[i]; i++) {
        if (isalpha (frase[i])) {
            StaticQueue_enqueue(Q, toupper(frase[i]));
            StaticStack_push(S, toupper(frase[i]));
        } 
    }

    while (!StaticQueue_is_empty(Q) && StaticQueue_dequeue(Q)==StaticStack_pop(S));
    
    if (StaticQueue_is_empty(Q)) palindroma_check = true;
    else palindroma_check = false;

    StaticQueue_destroy(&Q);
    StaticStack_destroy(&S);

    return palindroma_check;
}

int main(void) {
    char frase[256];

    printf("\nFrase : ");
    gets(frase);

    if (ehPalindroma(frase)) puts("\nA frase eh palindroma.");
    else puts("\nA frase nao eh palíndroma.");

    return 0;
}


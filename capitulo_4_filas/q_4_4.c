#include <stdio.h>
#include "static_queue.h"

#define tempo 3

int main(void) {
    StaticQueue *Q = StaticQueue_create(5);
    StaticQueue_enqueue(Q, 17);
    StaticQueue_enqueue(Q, 25);
    StaticQueue_enqueue(Q, 39);
    StaticQueue_enqueue(Q, 46);

    while (!StaticQueue_is_empty(Q)) {
        int x = StaticQueue_dequeue(Q);
        int p = x / 10;
        int t = x % 10;
        if (t>3) StaticQueue_enqueue(Q, p*10+(t-tempo));
        else printf("Processo %d concluido\n", p);
    }
    StaticQueue_destroy(&Q);
    return 0;
}


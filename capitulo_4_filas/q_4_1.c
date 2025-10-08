#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

int main() {
    StaticQueue *F = StaticQueue_create(5);
    StaticQueue_enqueue(F, 1);
    StaticQueue_enqueue(F, 2);
    StaticQueue_enqueue(F, 3);
    StaticQueue_enqueue(F, StaticQueue_dequeue(F));
    StaticQueue_enqueue(F, StaticQueue_dequeue(F));
    printf("%d\n\n", StaticQueue_peek(F));
    StaticQueue_print(F);
    StaticQueue_destroy(&F);
    
    return 0;
}
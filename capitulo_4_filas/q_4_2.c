#include <stdio.h>
#include <stdlib.h>
#include "char_static_queue.h"

int main(void) {
    StaticQueue *F = StaticQueue_create(5);
    for(int i = 0; i <= 3; i++) StaticQueue_enqueue(F, 'A' + i);
    while (!StaticQueue_is_empty(F)) printf("%c\n", StaticQueue_dequeue(F));
    StaticQueue_destroy(&F);
    
    return 0;
}
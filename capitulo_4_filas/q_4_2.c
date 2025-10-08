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

// #include <stdio.h>
// #include <stdlib.h>
// #include "char_static_queue.h"

// int main() {
//     StaticQueue *F = StaticQueue_create(5);
//     StaticQueue_enqueue(F, 1);
//     StaticQueue_enqueue(F, 2);
//     StaticQueue_enqueue(F, 3);
//     StaticQueue_enqueue(F, StaticQueue_dequeue(F));
//     StaticQueue_enqueue(F, StaticQueue_dequeue(F));
//     printf("%d\n\n", StaticQueue_peek(F));
//     StaticQueue_print(F);
//     StaticQueue_destroy(&F);
    
//     return 0;
// }
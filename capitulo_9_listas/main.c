#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

int main() {
    LinkedList *L = LinkedList_create();

    LinkedList_add_last(L, 5);
    LinkedList_print(L);

    LinkedList_add_last(L, 4);
    LinkedList_print(L);

    LinkedList_add_last(L, 2);
    LinkedList_print(L);

    LinkedList_add_last(L, 10);
    LinkedList_print(L);

    LinkedList_print(L);

    return 0;
}
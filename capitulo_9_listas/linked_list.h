#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

typedef int ItemL;
typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

SNode *SNode_create(ItemL val);

LinkedList *LinkedList_create();
bool LinkedList_is_empty(const LinkedList *L);
void LinkedList_add_first(LinkedList *L, ItemL val);
void LinkedList_add_last_slow(LinkedList *L, ItemL val);
void LinkedList_add_last(LinkedList *L, ItemL val);
void LinkedList_print(const LinkedList *L);
void LinkedList_inverted_print(const LinkedList *L);
#endif
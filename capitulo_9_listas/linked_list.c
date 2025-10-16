#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

typedef int ItemL;

typedef struct _snode {
    ItemL val; 
    struct _snode *next;
} SNode;
 
typedef struct _linked_list {
    SNode *begin;
    SNode *end;
} LinkedList;



SNode *SNode_create(ItemL val) {
    SNode *snode = (SNode*) calloc(1, sizeof(SNode));
    snode->val = val;
    snode->next = NULL;

    return snode;
};



LinkedList *LinkedList_create() {
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));
    L->begin = NULL;
    L->end = NULL;

    return L;
};

bool LinkedList_is_empty(const LinkedList *L){
    return (L->end == NULL && L->begin == NULL);
};

// void LinkedList_add_first(LinkedList *L, ItemL val) {
//     SNode *p = SNode_create(val);
//     p->next = L->begin;
//     L->begin = p;
// };
 
void LinkedList_add_first(LinkedList *L, ItemL val) {
    SNode *p = SNode_create(val);
    p->next = L->begin;

    if (LinkedList_is_empty(L)) {
        L->end = p;
    }

    L->begin = p;
};
 

void LinkedList_add_last_slow(LinkedList *L, ItemL val) {
    SNode *q = SNode_create(val);

    // se a lista estiver vazia
    if (LinkedList_is_empty(L)) {
        L->begin = q;
    }
    else {    
        SNode *p = L->begin;

        //Enquanto o p não é o ultimo nó 
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = q;
    }
};

void LinkedList_add_last(LinkedList *L, ItemL val) {
    SNode *q = SNode_create(val);

    // se a lista estiver vazia
    if (LinkedList_is_empty(L)) {
        L->begin = q;
        L->end = q; 
    } 
    else {
        L->end->next = q;
        L->end = L->end->next;
    }
};



void LinkedList_print(const LinkedList *L){
    SNode *p = L->begin;

    printf("L -> ");
    while (p != NULL) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("NULL\n");
};

void LinkedList_inverted_print(const LinkedList *L) {

};

#ifndef CHAR_STATIC_STACK_H
#define CHAR_STATIC_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef char Itemp;

typedef struct _static_stack StaticStack;

StaticStack *StaticStack_create(long capacity);
void StaticStack_destroy(StaticStack **S_ref);

bool StaticStack_is_empty(const StaticStack *S);
bool StaticStack_is_full(const StaticStack *S);

void StaticStack_push(StaticStack *S, Itemp val);
Itemp StaticStack_peek(const StaticStack *S);
Itemp StaticStack_pop(StaticStack *S);

#endif
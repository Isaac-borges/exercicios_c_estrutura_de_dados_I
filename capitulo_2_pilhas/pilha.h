#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef char Itemp;

typedef struct pilha *Pilha;

Pilha pilha (int m);

int vaziap(Pilha P);

int cheiap (Pilha P);

void empilha (Itemp x, Pilha P);

Itemp desempilha (Pilha P);

Itemp topo(Pilha P);

void destroip(Pilha *Q);


#endif
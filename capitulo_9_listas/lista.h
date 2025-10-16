#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef int ItemL;
typedef struct no *Lista;

Lista no(ItemL x, Lista p);

void exibe(Lista L);
void exibe_inv(Lista L);
void anexa(Lista *A, Lista B);
void destroif (Lista *L);

int tam(Lista L);
bool pert(ItemL x, Lista L);

Lista clone(Lista L);

//Questão 9.2.
int ocorrencias(ItemL val, Lista L);

//Questão 9.3.
ItemL ultimo(Lista L);

//Questão 9.4.
Lista inversa(Lista L);

//Questão 9.5.
ItemL soma(Lista L, ItemL valor_acumulado);

//Questão 9.6.
Lista substitui(ItemL x, ItemL y, Lista L);

//Questão 9.7.
bool igual(const Lista A, const Lista B);

//Questão 9.8.
ItemL enesimo(int n, Lista L);

//Questão 9.9.


//Questão 9.10.


#endif 
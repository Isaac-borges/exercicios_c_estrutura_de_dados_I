#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef int ItemL;
typedef struct no {
    ItemL item;
    struct no *prox;
} *Lista;

Lista no(ItemL x, Lista p){
    Lista n = malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
};

void exibe(Lista L){
    printf("\nBEGIN -> ");
    while (L != NULL) {
        printf("%d -> ", L->item);
        L = L->prox;
    }
    printf("END\n");
};

void exibe_inv(const Lista L){
    if (L == NULL) return;
    exibe_inv(L->prox);
    printf("%d -> ", L->item);
};

void anexa(Lista *A, Lista B){
    if (B == NULL) return;
    while (*A != NULL) A = &(*A)->prox;
    *A = B;
};

void destroif (Lista *L){
    while (*L != NULL) {
        Lista n = *L;
        *L = n->prox;
        free(n);
    }
};

int tam(const Lista L){
    if (L == NULL) return 0;
    return 1 + tam(L->prox);
};

bool pert(ItemL x, const Lista L){
    if (L == NULL) return false;
    if (x == L->item) return true;
    return pert(x, L->prox);
};

Lista clone(Lista L) {
    if (L == NULL) return NULL;
    return no (L->item, clone(L->prox));
};

int ocorrencias(ItemL val, Lista L) {
    int ocorrencias = 0;
    while (L != NULL) {
        if (L->item == val) ocorrencias++;
        L = L->prox;
    }
    return ocorrencias;
};

ItemL ultimo(Lista L) {
    if (L != NULL) {
    
        while (L->prox != NULL) {
            L = L->prox;
        }
        return L->item;
    }
    else {
        fprintf(stderr, "ERROR in 'ultimo(Lista L)'\n");
        fprintf(stderr, "A lista esta vazia\n");
        exit(EXIT_FAILURE);
    }
}

Lista inversa(Lista L) {
    Lista anterior = NULL;
    Lista atual = L;
    Lista proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    L = anterior;

    return L;
};

ItemL soma(Lista L, ItemL valor_acumulado) {
    ItemL acumulado = valor_acumulado + L->item;
    if (L->prox != NULL) return soma(L->prox, acumulado);
    return acumulado;
} 

Lista substitui(ItemL x, ItemL y, Lista L) {
    if (L == NULL) return NULL;

    if (L->item == x) L->item = y;
    substitui(x, y, L->prox);
    return L;
}

bool igual(const Lista A, const Lista B){
    if (A == NULL && B == NULL) return true;
    else if ((A == NULL && B != NULL) || (A != NULL && B == NULL)) return false;

    if (A->item != B->item) return false;
    return igual(A->prox, B->prox);
};

//Questão 9.8.
ItemL enesimo(int n, Lista L){
    if (L == NULL) {
        fprintf(stderr, "ERROR in 'enesimo(int n,Lista L)'\n");
        fprintf(stderr, "A lista esta vazia\n");
        exit(EXIT_FAILURE);
    }
    else if (n == 1) return L->item;

    return enesimo(n-1, L->prox);
};
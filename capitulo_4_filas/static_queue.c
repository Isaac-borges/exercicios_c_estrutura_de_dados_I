#include "static_queue.h"

#include <stdio.h>
#include <stdlib.h>

//Pilha circular estática. 
typedef struct _static_queue {
    int *data;
    long capacity;
    long size;
    long begin;
    long end;
} StaticQueue; 

// Cria uma fila circular estática
StaticQueue *StaticQueue_create(long capacity){ 
    StaticQueue *Q = (StaticQueue*) calloc(1, sizeof(StaticQueue));
    Q->capacity = capacity;

    Q->data = (int*) calloc(capacity, sizeof(int));
    Q->capacity = capacity;
    Q->size = 0;
    Q->begin = 0;
    Q->end = 0;

    return Q;
};

void StaticQueue_destroy(StaticQueue **Q_ref) {
    StaticQueue *Q = *Q_ref;

    free(Q->data);
    free(Q);

    *Q_ref = NULL;
};

//Verifica se a Fila está vazia.
bool StaticQueue_is_empty(const StaticQueue *Q) {
    return Q->size == 0;
};

//Verifica se a fila está cheia.
bool StaticQueue_is_full(const StaticQueue *Q) {
    return Q->size == Q->capacity;
};

//Retorna a quantidade de dados na fila.
long StaticQueue_size(const StaticQueue *Q) {
    return Q->size;
};

// Enfileira um novo dado à fila
void StaticQueue_enqueue(StaticQueue *Q, int val) {
    if (StaticQueue_is_full(Q)) {
        fprintf(stderr, "ERROR in 'StaticQueue_enqueue'\n");
        fprintf(stderr, "A fila está cheia\n");
        exit(EXIT_FAILURE); 
    }
    
    Q->data[Q->end] = val;
    Q->end = (Q->end + 1) % Q->capacity;
    Q->size++;
};

int StaticQueue_peek(const StaticQueue *Q) {
    if (StaticQueue_is_empty(Q)) {
        fprintf(stderr, "ERROR in 'StaticQueue_peek'\n");
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE);   
    }

    return Q->data[Q->begin];
}; 

int StaticQueue_dequeue(StaticQueue *Q) {
    if (StaticQueue_is_empty(Q)) {
        fprintf(stderr, "ERROR in 'StaticQueue_dequeue'\n");
        fprintf(stderr, "A fila está vazia\n");
        exit(EXIT_FAILURE);  
    };
    
    int val = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;

    return val;
};

void StaticQueue_print(const StaticQueue *Q){ 
    printf("capacity: %ld\n", Q->capacity);
    printf("size: %ld\n", Q->size);
    printf("begin: %ld\n", Q->begin);
    printf("end: %ld\n\n", Q->end);

    long s; // Quantidade de elementos consultados.
    long i; // Indice de inicio

    for (s = 0, i = Q->begin; 
         s < Q ->size; 
         s++, i = (i+1) % Q->capacity) {
            printf("%d, ", Q->data[i]);
    }
    puts("");
};

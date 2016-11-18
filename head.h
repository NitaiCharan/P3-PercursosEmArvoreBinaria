#include <stdio.h>
#include <stdlib.h>

typedef struct dado{
    char nome[100];
}t_elemento;

typedef struct noA{
    struct noA * esq;
    t_elemento dado;
    struct noA * dir;
}t_arvore;

typedef struct noP{
    t_elemento dado;
    struct noP * prox;
}t_pilha;


typedef t_arvore * arvore;
typedef t_pilha * pilha;

void preordem_(arvore arv);
void inordem_(arvore arv);
void posordem_(arvore arv);
t_elemento pop(t_pilha ** pilha);
void push(t_pilha ** pilha,t_elemento dado);

pilha criaP();
t_arvore * criaA();

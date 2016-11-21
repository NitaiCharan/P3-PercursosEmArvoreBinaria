#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dado{
    char carac;
}t_elemento;

typedef struct noA{
    struct noA * esq;
    t_elemento dado;
    struct noA * dir;
}t_arvore;

typedef struct noP{
    t_arvore * noArv;
    struct noP * prox;
}t_pilha;


typedef t_arvore * arvore;
typedef t_pilha * pilha;

void preordem_(arvore );
void inordem_(arvore );
void posordem_(arvore );
t_arvore * pop(t_pilha ** pilha);
void push(t_pilha ** ,t_arvore * );
pilha criaP();
t_arvore * criaA();
void inserir(t_arvore ** tree, char carac);

#if defined(_WIN32) || defined(WIN32)
#define LIMPATELA system("cls")
#else
#define LIMPATELA system("clear")
#endif

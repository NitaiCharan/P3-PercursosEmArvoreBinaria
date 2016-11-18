#include "head.h"

void push(t_pilha ** pilha,int dado){
    t_pilha * aux = malloc (sizeof(t_pilha));
    aux->dado.n = dado;
    aux->prox = *pilha;
    * pilha = aux;
}
int pop(t_pilha ** pilha){
    int dado;
    t_pilha * aux = (*pilha)->prox;
    dado = (*pilha)->dado.n;
    free(*pilha);
    * pilha = aux;
    return dado;
}

pilha criaP(){
    pilha topo = (t_pilha *) malloc(sizeof(t_pilha));
    topo->prox = NULL;
    return topo;
}

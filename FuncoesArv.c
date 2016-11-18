#include"head.h"

void preordem_(arvore arv){
    pilha p = criaP();
    if(!arv)return;
    arvore aux = arv;
    do {
        while (aux) {
            push(&p,aux->dado);
            if(aux->esq){
                aux = aux ->esq;
                continue;
            }
            else if(aux->dir){
                aux = aux->dir;
                continue;
            }
        }
        if(p){
            aux->dado=pop(&p);
            printf("%s\n",aux->dado.nome);
        }
    } while(p);
}
void inordem_(arvore arv){
    pilha p = criaP();
    if(!arv)return;
    arvore aux = arv;
    do {
        int entrou =0;
        while (aux) {
            if(aux->esq){
                aux = aux ->esq;
                entrou = 1;
                continue;
            }
            push(&p,aux->dado);
            if(aux->dir && !entrou){
                aux = aux->dir;
                continue;
            }
        }
        if(p){
            aux->dado=pop(&p);
            printf("%s\n",aux->dado.nome);
        }
    } while(p);
}
void posordem_(arvore arv){
    pilha p = criaP();
    if(!arv)return;
    arvore aux = arv;
    do {
        while (aux->esq && aux->dir){
            if(aux->esq){
                aux = aux ->esq;
                continue;
            }
            else if(aux->dir){
                aux = aux->dir;
                continue;
            }
            push(&p,aux->dado);
        }
        if(p){
            aux->dado=pop(&p);
            printf("%s\n",aux->dado.nome);
        }
    } while(p);
}
t_arvore * criaA(){
  t_arvore * no = (t_arvore*)malloc(sizeof(t_arvore));
  if(no)no->esq=no->dir=NULL;
  return no;
}
void inserir(){

}

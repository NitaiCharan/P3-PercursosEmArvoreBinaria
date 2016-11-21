#include"head.h"

void preordem_(arvore arv){
}
void inordem_ (arvore arv) {
    pilha p=criaP();
    arvore aux;
    aux = arv;
    if (!arv) return;
    do {
        while (aux != NULL) {
            push(&p, aux);
            aux = (aux->esq);
        }
        if (p) {
            aux = pop(&p);
            printf("%c ", aux->dado.carac);
            aux = (aux->dir);
        }
    } while (p->prox);
    printf("\n");
}
void posordem_(arvore arv){
}
t_arvore * criaA(){
  t_arvore * no = (t_arvore*)malloc(sizeof(t_arvore));
  if(no)no->esq=no->dir=NULL;
  return no;
}
void inserir(t_arvore ** tree, char carac){
    if(!(*tree)){
        (*tree)=criaA();
        (*tree)->dado.carac=carac;
    }
    else if((*tree)->dado.carac > carac) inserir(&((*tree)->esq),carac);
    else inserir(&((*tree)->dir),carac);
}

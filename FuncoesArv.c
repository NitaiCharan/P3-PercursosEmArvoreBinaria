#include"head.h"

void preordem_(arvore arv){
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
    do {
        while (aux != NULL) {
            printf("%c ", aux->dado.carac);
            push(&p, aux);
            aux = (aux->esq);
        }
        if (p) {
            aux = pop(&p);
            aux = (aux->dir);
        }
    } while (p->prox || aux);
    printf("\n");

}
void inordem_ (arvore arv) {
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
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
    } while (p->prox || aux);
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

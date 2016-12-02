#include"head.h"

void preordem_(arvore arv){
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
    do {
        while (aux != NULL) {
            if(aux->dado.carac != -1)printf("%d ", aux->dado.carac);
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
            if(aux->dado.carac != -1)printf("%d ", aux->dado.carac);
            aux = (aux->dir);
        }
    } while (p->prox || aux);
    printf("\n");
}
void posordem_(arvore arv){
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
	int entrou=1;
    do {
        while (aux != NULL && entrou) {
            if(aux->esq){
            	push(&p, aux);
				aux = (aux->esq);
				entrou = 1;
				continue;
			}
            else if (aux->dir){
				push(&p, aux);
				aux = (aux->dir);
				entrou = 1;
				continue;
			}
			entrou = 0;
        }
        if (p) {
            if(aux->dado.carac != -1)printf("%d ", aux->dado.carac);
			if(p->noArv->esq == aux)p->noArv->esq=NULL;
			else if(p->noArv->dir == aux)p->noArv->dir=NULL;
            aux = pop(&p);
			entrou = 1;

        }
    } while (p && (p->prox || aux));
    printf("\n");
}


void delArv(t_arvore * arv){
    if (!arv) return;
    pilha p=criaP();
    arvore aux;
    aux = arv;
	int entrou=1;
    do {
        while (aux != NULL && entrou) {
            if(aux->esq){
            	push(&p, aux);
				aux = (aux->esq);
				entrou = 1;
				continue;
			}
            else if (aux->dir){
				push(&p, aux);
				aux = (aux->dir);
				entrou = 1;
				continue;
			}
			entrou = 0;
        }
        if (p) {
			if(p->noArv->esq == aux){
				free(p->noArv->esq);
				p->noArv->esq=NULL;
			}
	
			else if(p->noArv->dir == aux){
				free(p->noArv->dir);
				p->noArv->dir=NULL;	
			}
            aux = pop(&p);
			entrou = 1;
        }
    } while (p && (p->prox || aux));
    printf("\n");
}
t_arvore * criaA(){
  t_arvore * no = (t_arvore*)malloc(sizeof(t_arvore));
  if(no)no->esq=no->dir=NULL;
  return no;
}
void inserir(t_arvore ** tree, int carac){
    if(!(*tree)){
        (*tree)=criaA();
        (*tree)->dado.carac=carac;
    }
    else if((*tree)->dado.carac > carac) inserir(&((*tree)->esq),carac);
    else inserir(&((*tree)->dir),carac);
}
t_arvore * buscaArv(t_arvore ** tree, int carac){//Função volta 0 ou localização do pai ou avô.
	int entrou=0;
	t_arvore * conf=NULL;
	//Caso não encontre nó
	if(!(*tree))return 0;
	//Nó
    else if((*tree)->dado.carac ==  carac){
		conf=(*tree);
		entrou = 1;
	} 
	//Pai
	if(!entrou){
		if((*tree)->esq){
		
				if((*tree)->esq->dado.carac ==  carac){
						conf=(*tree);			
						entrou = 1;
				} 
				else if((*tree)->dir) if((*tree)->dir->dado.carac ==  carac){
						conf=(*tree);	
						entrou = 1;
				} 
		} 
	}
	//Avô
	else if(!entrou){
			if((*tree)->esq){
					if(((*tree)->esq->esq)&&!((*tree)->esq->dir)){
							if((*tree)->esq->esq->dado.carac ==  carac){
								conf=(*tree);		
								entrou = 1;
							} 
					}
					else if(((*tree)->esq->dir)&&!((*tree)->esq->esq)){
							if((*tree)->esq->esq->dado.carac ==  carac){
								conf=(*tree);		
								entrou = 1;
							} 
					}
			}
			else{
					if(((*tree)->dir->esq)&&!((*tree)->dir->dir)){
							if((*tree)->esq->esq->dado.carac ==  carac){
								conf=(*tree);		
								entrou = 1;
							} 
					}
					else if(((*tree)->dir->dir)&&!((*tree)->dir->esq)){
							if((*tree)->esq->esq->dado.carac ==  carac){
								conf=(*tree);		
								entrou = 1;
							} 
					}
			}
	}
	//Não localizou no filho ou neto. Deve continuar	
	if(!entrou){
			if((*tree)->dado.carac > carac)conf =  buscaArv(&((*tree)->esq),carac);
			else if((*tree)->dado.carac < carac)conf =  buscaArv(&((*tree)->dir),carac);
	}
	return conf;	
}
t_arvore * rmNoArv(t_arvore * tree,int dado){	
	t_arvore * ele;
	return ele;
}





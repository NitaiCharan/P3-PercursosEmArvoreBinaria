#include"head.h"
#ifdef WIN32
#include <windows.h>
void gotoxy(int coluna, int linha){
    COORD point;
    point.X = coluna;
    point.Y = linha;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
#else
void gotoxy(int x, int y){
    printf("\033[%d;%df", y, x);
    fflush(stdout);
}
#endif
void exibirGraficamente(t_arvore * tree, int col, int lin, int desloc){
    if (tree == NULL)return;
        gotoxy(col,lin);
        printf("%c",tree->dado.carac);
    if (tree->esq != NULL)exibirGraficamente(tree->esq,col-desloc,lin+2,desloc/2+1);
    if (tree->dir != NULL)exibirGraficamente(tree->dir,col+desloc,lin+2,desloc/2+1);
}

int main(int argc, char const *argv[]) {
    char op;
    LIMPATELA;

    char c='a';
    //int n =scanf("%d", &n);
    t_arvore * arv= NULL;
    FILE *open = fopen("nitai","r");
    do {
        if(!feof(open) && c !=';' && c!=',' && c!=-1){
            c=fgetc(open);
            if(c !=';' && c!=',' && c!=-1)inserir(&arv,c);
        }
        if(!feof(open))fgetc(open);
    } while(!feof(open));

    exibirGraficamente(arv,20,10,3);
    printf("\n\n");

    printf("Estudo de Árvores(somos nozes)-Estrutura de Dados 1\n");
    printf("1- Pré-ordem.\n");
    printf("2- Ordem Simétrica\n");
    printf("3- Pós-ordem\n");
    printf("0- Sair\n");
    printf("\n Digite uma opção: ");
    scanf("%c",&op);

    fclose(open);
    getchar();



    switch (op) {
        case '1':{
			preordem_(arv);
            break;
        }
        case '2':{
            inordem_(arv);
            break;
        }
        case '3':{
            posordem_(arv);
            break;
        }
        case '0':{
            break;
        }
        default:{

        }
    }
    exit(0);
}

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
        printf("%d",tree->dado.carac);
    if (tree->esq != NULL)exibirGraficamente(tree->esq,col-desloc,lin+2,desloc/2+1);
    if (tree->dir != NULL)exibirGraficamente(tree->dir,col+desloc,lin+2,desloc/2+1);
}

int main(int argc, char const *argv[]) {
	int n=0;
    FILE *open = fopen("nitai","r");
	char op;

	t_arvore * arv=NULL;
    LIMPATELA;
	while(fscanf(open,"%d",&n)==1){
        inserir(&arv,n);
		fgetc(open);
	}
    fclose(open);

    printf("\n\n");
	do{


			LIMPATELA;
			printf("ALUNO:\t\tNITAI CHARAN ALVARES PEREIRA\n");
			printf("DISCIPLINA:\tESTRUTURA DE DADOS I\n");
			printf("PROFESSOR:\tWALACE BONFIM\n\n");
			printf("1 – INSERIR\n");
			printf("2 – REMOVER APENAS UM NÓ\n");
			printf("3 – PESQUISAR\n");
			printf("4 – ESVAZIAR A ÁRVORE\n");
			printf("5 – EXIBIR A ÁRVORE\n");
			printf("0 – SAIR\n\n");



			printf("\t\tEDITOR DE ÁRVORE\n\n");
			printf("\n Digite uma opção: ");
            flush;
			scanf("%c",&op);
			flush;


			switch (op) {
				case '1':{
					LIMPATELA;
					int nu;
					printf("Digite um número: ");
					scanf("%d",&nu);	

        			inserir(&arv,nu);
					LIMPATELA;	
					exibirGraficamente(arv,20,0,3);
                   	flush;
					getchar();
                   	flush;
					break;
				}
				case '2':{
					break;
				}
				case '3':{
					t_arvore * nu;
					int ele;
					LIMPATELA;
					printf("Digite para busca: ");
					scanf("%d",&ele);
					nu=buscaArv(&arv,ele);
					if(nu) printf("O valor encontra-se na estrutura!!\n\nDigite algo para continuar: ");
					else printf("O valor não esta na estrutura!!!\n\nDigite algo para continuar: ");
					flush;
					getchar();
					
					break;
				}
				case '4':{
					delArv(arv);
					free(arv);
					arv=NULL;
					break;
				}
				case '5':{
					LIMPATELA;
					if(!arv){
						printf("Estrutura encontra-se vazia!!!Digite algo: ");	
						getchar();
						break;
					}
					exibirGraficamente(arv,20,0,3);
					
					printf("\n\nPre-Ordem: \n");
					preordem_(arv);
					printf("\n");
					printf("In-Ordem: \n");
					inordem_(arv);
					printf("\n");
					printf("Pos-Ordem: \n");
					posordem_(arv);
					printf("\n");
					printf("\n\nDigite algo: ");
                   	flush;
					getchar();
					break;
				}
				case '0':{
					exit(0);
					break;
				}
				default:{
					printf("\n\nOPÇÂO INCORRETA!!! TENTE NOVAMENTE: ");
					flush;
					getchar();
				}
			}

	}while(1);
}

#include"head.h"

int main(int argc, char const *argv[]) {
    char op;
    LIMPATELA;
    printf("Estudo de Árvores(somos nozes)-Estrutura de Dados 1\n");
    printf("1- Pré-ordem.\n");
    printf("2- Ordem Simétrica\n");
    printf("3- Pós-ordem\n");
    printf("0- Sair\n");
    printf("\n Digite uma opção: ");
    scanf("%c",&op);

    switch (op) {
        case '1':{
            char c='a';
            //int n =scanf("%d", &n);
            t_arvore * arv= NULL;
            FILE *open = fopen("nitai","r");
            do {
                if(!feof(open) && c !=';' && c!=','){
                    c=fgetc(open);
                    if(c !=';' && c!=',')inserir(&arv,c);
                }
                if(!feof(open))fgetc(open);
            } while(!feof(open));

			preordem_(arv);
            fclose(open);
            getchar();
            break;
        }
        case '2':{
            char c='a';
            //int n =scanf("%d", &n);
            t_arvore * arv= NULL;
            FILE *open = fopen("nitai","r");
            do {
                if(!feof(open) && c !=';' && c!=','){
                    c=fgetc(open);
                    if(c !=';' && c!=',')inserir(&arv,c);
                }
                if(!feof(open))fgetc(open);
            } while(!feof(open));

            inordem_(arv);
            fclose(open);
            getchar();
            break;
        }
        case '3':{

            char c='a';
            //int n =scanf("%d", &n);
            t_arvore * arv= NULL;
            FILE *open = fopen("nitai","r");
            do {
                if(!feof(open) && c !=';' && c!=','){
                    c=fgetc(open);
                    if(c !=';' && c!=',')inserir(&arv,c);
                }
                if(!feof(open))fgetc(open);
            } while(!feof(open));

            posordem_(arv);
            fclose(open);
            getchar();
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

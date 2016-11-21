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
            break;
        }
        case '2':{
            char c='a';
            //int n =scanf("%d", &n);
            t_arvore * arv= NULL;
            FILE *open = fopen("nitai","r");
            do {
                if(c!=-1 && c <='z' && c>='a'){
                    c=fgetc(open);
                    if(c <='z' && c>='a')inserir(&arv,c);
                }
                if(c!=-1)fgetc(open);
            } while(c!=-1);

            inordem_(arv);
            fclose(open);
            getchar();
            break;
        }
        case '3':{
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

#include"head.h"

int main(int argc, char const *argv[]) {
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

    exit(0);
}

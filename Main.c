#include"head.h"

int main(int argc, char const *argv[]) {
    int c=getc(stdin);
    FILE *open = fopen("nitai","r");
    do {
        do {
            printf("%c",c);
        } while(c != EOF && c!=',');
        printf(",");
        if(c!=EOF)fgetc(open);
    } while(c!=EOF);
    printf("\n");
    fclose(open);

    return 0;
}

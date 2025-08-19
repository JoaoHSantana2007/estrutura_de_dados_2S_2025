#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp; 
    fp = fopen("data\\tabuada_do_7_9.txt", "w");

    if(fp == NULL){ 
        printf("ERRO\nArquivo nao criado\n");
        exit(1);
    }

    for(int i = 0; i < 11; i++){
        fprintf(fp, "O resultado de 7 X %d = %d\n", i, i * 7);
    }
    
    fprintf(fp, "--------------------------\n");

    for(int i = 0; i < 11; i++){
        fprintf(fp, "O resultado de 9 X %d = %d\n", i, i * 9);
    }

    fclose(fp);

    return 0;
}

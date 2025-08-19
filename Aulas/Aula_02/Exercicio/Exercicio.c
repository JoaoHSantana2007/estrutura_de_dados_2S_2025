#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fp; 
    fp = fopen("Exercicio.txt", "r");

    if(fp == NULL){ 
        printf("ERRO\nArquivo nao criado\n");
        exit(1);
    }

    printf("Arquivo criado com sucesso\n");

    char Produto[10];
    int Quantidade;
    float Preco, PrecoTotalproduto, PrecoTotalCompra;
    
    while (fscanf(fp, "%[^ ] %d %f", Produto, &Quantidade, &Preco) != EOF) {
        PrecoTotalproduto = Quantidade * Preco;
        printf("Preco:%s\nuantidade:%d\nPreco:%2.f\n", Produto, Quantidade, Preco);
        printf("----------------------------------------------------------\n");
        PrecoTotalCompra += PrecoTotalproduto;
    }
    
    printf("Preco total da compra = %.2f", PrecoTotalCompra);

    fclose(fp);

    return 0;
}

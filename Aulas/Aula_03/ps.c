// Implementar oa algoritmo de PESQUISA SEQUENCIAL

#include <stdio.h>
#include <stdlib.h>

#define ERRO -1

int PesquisaSequencial(int *V, int N, int chave);

int main() {
    int Numeros[] = {
        14, 29, 37, 11, 43, 25, 19, 32, 16, 22,
        40, 13, 28, 35, 10, 45, 20, 38, 17, 24,
        30, 41, 15, 27, 33, 18, 26, 39, 12, 21
    };

    int Tamanho = sizeof(Numeros) / sizeof(int);
    int Elemento = 35;
    int Posicao = PesquisaSequencial(Numeros, Tamanho, Elemento);
    
    printf("%d\n", Posicao);

    return 0;
}

// Implementacao

int PesquisaSequencial(int *V, int N, int chave) {

    int i;
    for(i = 0; i < N; i++){
        if(V[i] == chave){
            return i;
        }
    }
    return ERRO;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos

void Insertiontort(int * V, int N);
void ExibirVetor(int * V, int N);

// Funcao Pirncipal

int main(){

    system("cls");

    int conjunto[] = {1, 9, 7, 8, 5, 2};
    int Tamanho = sizeof(conjunto) / sizeof(int);
    Insertiontort(conjunto, Tamanho);
    ExibirVetor(conjunto, Tamanho);
    
}

// Implimentacoes das funcoes

void Insertiontort(int * V, int N){

    int chave; // Elemento que sera insirido na parte ordenada
    int i; // Posicao (ou Cordenada) do elemento chave 
    int j; // Posicao de emento da "parte ordenada" que sera comparada com chave 

    for(i = 1; i < N; i++){
        chave = V[i];
        j = i - 1;
        
        while (j >= 0 && V[j] > chave){
            V[j + 1] = V[j];
            j--;
        }

        V[j + 1] = chave; // Copiando a chave do no ultimo lugar modificado      
    }

}

void ExibirVetor(int * V, int N){

    int i;
    for(i = 0; i < N; i++){
        printf("%d\t", V[i]);
    }
    printf("\n");

}
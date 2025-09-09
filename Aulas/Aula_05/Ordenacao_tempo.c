#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 500000

// Prototipos

void Insertiontort(int * V, int N);
void ExibirVetor(int * V, int N);

// Funcao Pirncipal

int main(){

    system("cls");

    int conjunto[TAMANHO];
    
    srand(time(NULL));
    for(int i = 0; i < TAMANHO; i++){
        conjunto[i] = rand() %100;
    }

    clock_t T0 = clock(); 
    Insertiontort(conjunto, TAMANHO);
    clock_t TF = clock();

    ExibirVetor(conjunto, TAMANHO);
    printf("\nTempo de CPU: %f\n", (double)(TF - T0) / CLOCKS_PER_SEC);

    
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
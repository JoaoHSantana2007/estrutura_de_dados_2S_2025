#include <stdio.h>
#include <stdlib.h>

void TrocarElemento(int * A, int * B);
int Particao(int * V, int Inf, int Sup);
void QuickSort(int * V, int Inf, int Sup);
void ExiberVetor(int * V, int N);

int main(){
    
   int Vetor[] = {3, 6, 4, 5, 1, 7, 2};
   int Tamanho = sizeof(Vetor) / sizeof(int);
   QuickSort(Vetor, 0, Tamanho - 1);
   ExiberVetor(Vetor, Tamanho);

   return 0;
}

void TrocarElemento(int * A, int * B) {
    
    // obs: A e B são ponteiros(guardam endereços de memória)
    
    int temp = *A;
    *A = *B;
    *B = temp;
}

int Particao(int * V, int Inf, int Sup){

    int Pivot = V[(Inf + Sup) / 2];
    
    int i = Inf;
    int j = Sup;

    while(i <= j) {
        while(V[i] < Pivot) {
            i++;
        }
        while(V[j] > Pivot) {
            j--;
        }
        if(i <= j) {
            TrocarElemento(&V[i], &V[j]);
            i++;
            j--;
        }
    }

    return i;
}

void QuickSort(int * V, int Inf, int Sup) {

    if(Inf < Sup) {
        int p = Particao(V, Inf, Sup);
        QuickSort(V, Inf, p -1);
        QuickSort(V, p, Sup);
    }
}

void ExiberVetor(int * V, int N) {
    for(int i = 0; i < N; i++) {
        printf("%d\t", V[i]);
    }
    printf("\n");
}
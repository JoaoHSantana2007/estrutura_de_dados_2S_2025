#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100000

int main() {

    int soma;

    srand(time(NULL));
    clock_t T0 = clock();
    
    for(int i = 0; i < TAMANHO; i++) {
        int temp = rand() %1000;
        printf("%d\n", temp);
        soma += temp;
    }
    
    clock_t TF = clock();

    double TempoCPU = (double)(TF - T0) /CLOCKS_PER_SEC;
    printf("Tempo de processamento = %.3f segundos\n", TempoCPU);
    printf("Soma = %d\n", soma);

    return 0;
}
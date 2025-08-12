#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float numerador;
    float denominador;
} Fracao;

Fracao CriarFracao(int N, int D){
    Fracao F;

    F.numerador = N;
    F.denominador = D;
    
    return F;
}

int main(){

    Fracao F1 = CriarFracao(7,2);

    printf("O valor de F1 eh %.2f",  F1.numerador / F1.denominador);

    return 0;
}
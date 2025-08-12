#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} Fracao;

int mdc(int a, int b) {
    while (b != 0) {
        int i = a % b;
        a = b;
        b = i;        
    }   

    return a;
}

int main() {
    Fracao f;

    printf("\n\tInforme o numerador da fracao: ");
    scanf("%d", &f.numerador);
    printf("\n\tInforme o denominador da fracao: ");
    scanf("%d", &f.denominador);

    if(f.numerador <= 0 && f.denominador <= 0){
        printf("\n\tERRO !\n\tDigite um valor inteiro, maior que zero para ambas as partes.\n");
        
        return 1;
    }

    int simplifica = mdc(f.numerador, f.denominador);

    f.numerador = f.numerador / simplifica;
    f.denominador = f.denominador / simplifica;

    printf("\n\tO resultado da fracao simplificada eh: %d / %d\n", f.numerador, f.denominador);

    return 0;
}

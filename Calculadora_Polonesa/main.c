#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expressao.h"

int main(){

    system("cls");

    char *tests[] = {
        "3 4 + 5 *",
        "7 2 * 4 +",
        "8 5 2 4 + * +",
        "6 2 / 3 + 4 *",
        "9 5 2 8 * 4 + * +",
        "2 3 + log 5 /",
        "10 log 3 ^ 2 +",
        "45 60 + 30 cos *",
        "0.5 45 sen 2 ^ +"
    };

    int n = sizeof(tests)/sizeof(tests[0]);

    for(int i=0;i<n;i++){
        float val = getValorPosFixa(tests[i]);
        char *inf = getFormaInFixa(tests[i]);
        printf("Teste %d\n  Posfixa: %s\n  Infixa: %s\n  Valor: %.6f\n\n", i+1, tests[i], inf?inf:"(erro)", val);
        if(inf) free(inf);
    }

    return 0;
}
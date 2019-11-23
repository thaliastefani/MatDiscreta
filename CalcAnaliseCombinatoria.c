#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    int iniciar = 1;
    int menu = 0;
    long int n = 0;
    long int k = 0;

    printf("Calculadora de An�lise Combinat�ria\n");

    while(iniciar == 1){
        printf("Escolha uma op��o para iniciar: [1-Permuta��o Simples, 2-Arranjo Simples, 3-Combina��o Simples, 4-Sair]\n");
        scanf("%d", &menu);

        switch(menu){
        case 1:
            printf("Permuta��o Simples\n");
            printf("Insira um valor para n[elementos]: \n");
            scanf("%d", &n);

            n = validaNumFat(n, 0);

            (n == 0) ? printf("Resultado: 1\n") : printf("Resultado: %d\n", fatorial(n));

            break;
        case 2:
            printf("Arranjo Simples\n");
            printf("Insira um valor para n[elementos]: \n");
            scanf("%d", &n);

            n = validaNumFat(n, 1);

            printf("Insira um valor para k[posi��es]: \n");
            scanf("%d", &k);

            while((k < 0) || (k > n)){
                printf("N�mero Inv�lido. O valor de k[posi��es] deve ser maior que 0 e menor que n[elementos]\n");
                printf("Insira um valor para k[posi��es]: \n");
                scanf("%d", &k);
            }

            (k == 0) ? printf("Resultado: 1\n") : printf("Resultado: %d\n", (fatorial(n) / fatorial(n-k)));

            break;
        case 3:
            printf("Combina��o Simples\n");
            printf("Insira um valor para n[elementos]: \n");
            scanf("%d", &n);

            n = validaNumFat(n, 1);

            printf("Insira um valor para k[posi��es]: \n");
            scanf("%d", &k);

            while(k < 0 || k > n){
                printf("N�mero Inv�lido. O valor de k[posi��es] deve ser maior ou igual a 0 e menor ou igual a n[elementos]\n");
                printf("Insira um valor para k[posi��es]: \n");
                scanf("%d", &k);
            }

            if(k == 0 || k == n){
                printf("Resultado: 1\n");
                break;
            }

            printf("Resultado: %d\n", (fatorial(n) / (fatorial (k) * fatorial(n-k))));
            break;
        case 4:
            iniciar = 0;
            printf("Sair\n");
            break;
        default:
            printf("Op��o Inv�lida.\n");
        }
    }

    return 0;
}

// Fun��o para calcular o fatorial
int fatorial(long int valor){
    long int fat = 0;

    for(fat = 1; valor > 1; valor--){
        fat = fat * valor;
    }

    return fat;
}

// Fun��o para validar "n"
int validaNumFat(long int valor, int condicao){
    while(valor < condicao){
        printf("N�mero Inv�lido. O  valor de n[elementos] deve ser maior ou igual a %d\n", condicao);
        printf("Insira um valor para n[elementos]: \n");
        scanf("%d", &valor);
    }

    return valor;
}

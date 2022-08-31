#include <stdio.h>
#include <stdlib.h>

int main()
{   int opcao;
    float valor;

     printf("------------------------------\n");
    printf("------------Bem-Vindo-----------\n");
     printf("------------------------------\n\n");

    printf("Codigo Produto Valor\n");
    printf("1-Pao de forma: 7,50\n");
    printf("2-Pao de Centeio: 8,69\n");
    printf("3-Broa de milho: 5,00\n");
    printf("4-Sonho: 4,50\n");
    printf("5-Tubaina 3,25\n\n");

    printf("Selecione um produto acima inserindo seu respectivo codigo: ");
    scanf("%d",&opcao);
    getchar();

    switch (opcao){
        case 1:
            valor = 7.50;
            break;
        case 2:
            valor = 8.69;
            break;
        case 3:
            valor = 5;
            break;
        case 4:
            valor = 4.50;
            break;
        case 5:
            valor = 3.25;
            break;
        default:
            printf("Opcao invalida, tente novamente");
    }
    return 0;
    }

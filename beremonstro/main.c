#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculos.h"
#include "source.h"

int main()
{
    int opc = 0;
    int tam = 0;
    item *base = (item *)malloc(sizeof(item));//vetor vet acumula os itens cadastrados
    if(base == NULL)
    {
        printf("Erro na alocação de memória");
        return(1);
    }


    do
    {
        sub_protudos();
        scanf("%d", &opc);
        getchar();
        limpar_tela();
        switch(opc)
        {
            case 0:
                break;
            case 1:
                if(tam == 0)
                {
                    printf("Não há nenhum produto cadastrado");
                }
                else
                {
                    visualizar_estoque(base, tam);
                }
                printf("\n");
                system("pause");
                break;
            case 2:
                /*aumenta a zona de memória do vetor vet*/
                base = (item *)realloc(base, (tam+1)*sizeof(item));
                if(base == NULL)
                {
                    printf("ERRO na realocação de memória");
                    exit(2);
                }
                tam = cadastrar_produto(base, tam);
                break;
            case 3:
                if(tam == 0)
                {
                    printf("Não há nenhum produto cadastrado");
                }
                else
                {
                    atualizar_produto(base, tam);
                }
                printf("\n");
                system("pause");
                break;
            case 4:
                if(tam == 0)
                {
                    printf("Não há nenhum produto cadastrado");
                }
                else
                {
                    tam = excluir_produto(base, tam);
                    base = (item *)realloc(base, (tam)*sizeof(item));
                }
                printf("\n");
                system("pause");
                break;
            default:
                continue;

        }


    }
    while(opc != 0);
    free(base);
    return 0;

}


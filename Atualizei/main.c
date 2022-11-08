#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "calculos.h"
#include "source.h"

//argc = Quantidade de respostas no prompt
//argv = Tem salvo as respostas utilizadas no prompt
int main(int argc, char *argv[])
{
    char arquivo[15];
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

            //Opção de Exibir os Produtos já Cadastrados
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

            //Cadastrar Produtos Novos.
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

            //Atualizar um produto ja cadastrado.
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

            //Excluir um item ja cadastrado.
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

            //Salvar os produtos Cadastrados
            case 5:
                fclose(arquivo);
                break;

            //Lê a lista de produtos no ultimo arquivo salvo.
            case 6:

                if((arquivo == fopen(argv[1], "r"))==NULL){
                    printf("Erro na abertura do Arquivo.");
                }else{
                    limpar_tela();
                    printf("Arquivo Aberto com sucesso.");
                }

            default:
                continue;

        }


    }
    while(opc != 0);
    free(base);
    return 0;

}


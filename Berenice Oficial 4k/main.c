#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //Usado para printar cupom
//#include <conio.h> //manipular caracteres na tela
#include "calculos.h" //Chamar header
#include "source.h" //Chamar header

int main(int argc, char *argv[])
{
    int opc = 0; //utilizado para selecionar opc do usuario
    int tam = 0; //Usado para dimensionar tamanho
    float total; //Total da compra

    item *base = (item *)malloc(sizeof(item));//Struct dimensionada dos itens
    relatorio *rel = (relatorio *)malloc(sizeof(relatorio));//Struct dimensionada dos itens (Usado para imprimir cupom)

    if(base == NULL)
    {
        printf("Erro na alocação de memória");
        return(1);
    }
    do // do menu principal
    {
        mn_inicial(); //chama funcao printf
        scanf("%d",&opc);
        if(opc == 1) //Produtos
        {
            do // do sub menu
            {
                limpar_tela();
                sub_protudos(); //funcao printf
                scanf("%d", &opc);
                getchar();
                limpar_tela();
                switch(opc) //switch para subprodutos
                {
                case 0:
                    break;

                //Opção de Exibir os Produtos já Cadastrados
                case 1:
                    if(tam == 0) //Caso nao tenha nenhum item
                    {
                        printf("...Vazio...");
                    }
                    else
                    {
                        visualizar_estoque(base, tam); //printf dos estoques disponiveis
                    }
                    printf("\n");
                    system("pause");
                    break;

                //Cadastrar Produtos Novos.
                case 2:
                    base = (item *)realloc(base, (tam+1)*sizeof(item)); //Aumenta o dimensionamento da memoria
                    if(base == NULL)
                    {
                        printf("ERRO na realocação de memória");
                        exit(2); //fechar caso de problemas na memoria
                    }
                    tam = cadastrar_produto(base, tam); //int main recebe de volta o valor do tamanho
                    break;

                case 3: //Atualizar um produto
                    if(tam == 0)
                    {
                        printf("...Vazio...");
                    }
                    else
                    {
                        atualizar_produto(base, tam);
                    }
                    printf("\n");
                    system("pause");
                    break;

                case 4: //Excluir um item
                    if(tam == 0)
                    {
                        printf("...Vazio...");
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
                    salvar(base,tam);
                    break;

                //Lê a lista de produtos no ultimo arquivo salvo.
                case 6:
                    ler(base,tam);
                default:
                    continue;// n pausar o programa

                }
            }
            while(opc != 0); //sai do loop

        }
        if(opc == 2) //Vendas
        {
            limpar_tela();
            if(tam<=0)
            {
                printf("...Vazio...");
                exit(1);
            }
            realizar_venda(base,rel,tam);
            printf("\n\t\tImprimindo Cupom Fiscal...\n");
            getchar(); //travar no imprimindo
            salvar_base(base,rel,tam);//CUPOM FISCAL

        }
    }
    while(opc !=3); //sai do loop
    free(base); //limpar memoria
    return 0;

}


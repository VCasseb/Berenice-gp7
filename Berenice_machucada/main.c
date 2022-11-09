#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //Usado para printar cupom
#include "source.h" //Chamar header

int main(int argc, char *argv[])
{
    int opc = 0; //utilizado para selecionar opc do usuario
    int tam = 0; //Usado para dimensionar tamanho
    int quantidade = 0; //Usado para adicionar uma quantidade pedida pelo cliente
    int qtd_vendas;
    float total; //Total da compra

    item *base = NULL;

    do // do menu principal
    {
        mn_inicial(); //chama funcao printf
        scanf("%d",&opc);
        switch(opc){ //Produtos
        case 1:
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
                    printf("Quantos produtos deseja cadastrar?\n");
                    do{
                    scanf("%i", &quantidade);
                    getchar();
                    if(quantidade<0){
                        printf("Valor invalido.\n");
                    }
                    }while(quantidade<=0);
                    base = (item *)realloc(base, (tam+quantidade)*sizeof(item)); //Aumenta o dimensionamento da memoria
                    if(base == NULL)
                    {
                        printf("ERRO na realocação de memória");
                        exit(2); //fechar caso de problemas na memoria
                    }
                    tam = cadastrar_produto(base, tam,quantidade); //int main recebe de volta o valor do tamanho
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
                break;
                default:
                    printf("\n\t\tOpcao Invalida! Clique Enter para continuar");
                getchar();

                }
            }
            while(opc != 0); //sai do loop
        break;
        case 2: //Vendas
            do{
            limpar_tela();
            sub_vendas();
            scanf("%d",&opc);
            if(opc == 1){
            limpar_tela();
            if(tam<=0)
            {
                printf("...Vazio...");
                exit(1);
            }
            realizar_venda(base,tam,qtd_vendas);
            qtd_vendas=0;
            qtd_vendas++;
            }
            if(opc == 2){
                relatorio(base,tam,qtd_vendas);
                printf("qtd_vendas %d",qtd_vendas);
                exit(1);
            }
            limpar_tela();
            }while(opc != 0);
        break;
        default:
            limpar_tela();
            printf("\t\t\tOpc Invalida!");
        }
    }
    while(opc !=3); //sai do loop
    free(base); //limpar memoria
    return 0;

}


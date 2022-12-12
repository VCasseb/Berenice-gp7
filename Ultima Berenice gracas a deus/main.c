#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    int opc,opc_2, qtd_usuario=0,k=0,j=0,c=0,d=0,y=1;
    int parcelas=0;
    float total = 0;
    int total_aux=0;
    int receber=0;
    long int valor; //codigo
    int quantidade;
    char nm[26] = "";
    float preco;
    int l=0;
    int soma_estoque;

    FILE *fp;

    long int fvalor;
    int fqtd, fqtd_venda;
    float fpreco;
    char fnome[26];

    Lista lista;

    No *removido;
    No *aux;
    criar_lista(&lista);

    do
    {
        printf("\n( 1 ) - Produtos\n( 2 ) - Vendas\n( 0 ) - Sair\n--->");
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            do
            {
                printf("\n1 - Exibir\n2 - Cadastrar\n3 - Atualizar\n4 - Excluir\n5 - Salvar\n6 - Ler\n0 - Voltar\n--->");

                scanf("%d",&opc_2);

                switch(opc_2)
                {

                case 1:
                    if(lista.tam <= 0)
                    {
                        printf("Vazio...\n");
                        break;
                    }
                    imprimir(lista);
                    break;

                case 2:
                    printf("Deseja cadastrar quantos produtos?\n---> ");
                    scanf("%d",&qtd_usuario);
                    for(int i=0; i<qtd_usuario; i++)
                    {
                        do{
                            printf("\n");
                            printf("[%d]Digite o codigo: ",y);
                            scanf("%ld",&valor);
                            receber = imprimir_existente(lista, valor);
                            if(receber > 0)
                            {
                                printf("\nCodigo Existente!\n");
                            }
                        }while(receber > 0);

                        do{
                            printf("[%d]Digite o nome: ",y);
                            setbuf(stdin,NULL);
                            gets(nm);

                            //validar se eh so espaco
                            for(c=0; c<26; c++)
                            {
                                if(nm[c] != NULL)
                                {
                                    k++;
                                }
                            }

                            for(d=0; d<k; d++)
                            {

                                if(nm[d] == ' ')
                                {
                                    j++;
                                }

                            }
                            if(j == k)
                            {
                                printf("\nNome invalido!\n");
                            }
                            else
                                break;
                        }while(j == k);

                        do{
                            printf("[%d]Digite o preco: ",y);
                            scanf("%f",&preco);
                            if(preco <=0)
                            {
                                printf("\nValor incorreto!\n");
                            }
                        }while(preco <= 0);

                        do{
                            printf("[%d]Digite a qtd: ",y);
                            scanf("%d",&quantidade);
                            if(quantidade <=0)
                            {
                                printf("\nValor incorreto!\n");
                            }
                        }while(quantidade<=0);
                        y++;
                        inserir_ini(&lista,valor,nm,preco,quantidade);
                    }
                    y=1;
                    break;

                case 3:
                    if(lista.tam<=0)
                    {
                        printf("Vazio...\n");
                        break;
                    }

                    do
                    {
                        receber = 0;
                        imprimir(lista);
                        printf("Digite o codigo do produto que deseja atualizar: ");
                        scanf("%d",&valor);
                        receber = imprimir_existente(lista, valor);

                        if(receber == 1)
                        {
                            do
                            {
                                printf("O que deseja atualizar?\n1 - Codigo\n2 - Nome\n3 - Preco\n4 - Quantidade\n---> ");
                                scanf("%d",&opc);

                                switch(opc)
                                {

                                case 1:
                                    editar_cod(&lista,valor);
                                    break;

                                case 2:
                                    editar_char(&lista,valor);
                                    break;

                                case 3:
                                    editar_preco(&lista,valor);
                                    break;

                                case 4:
                                    editar_qtd(&lista,valor);
                                    break;
                                }
                            }
                            while(opc == 'n');
                            break;

                        }
                        else
                        {
                            printf("Produto Nao encotrado\n");

                        }
                    }
                    while(valor == aux);

                    break;
                case 4:
                    if(lista.tam <= 0)
                    {
                        printf("Vazio...\n");
                        break;
                    }
                    imprimir(lista);
                    printf("Digite o Codigo desejado:\n---> ");
                    scanf("%d",&valor);
                    printf("\nElemento a ser removido: %d\nDeseja continuar?\n( 1 ) - Sim\n( 2 ) - Nao\n---> ",valor);
                    scanf("%d",&opc);
                    if(opc == 1)
                    {
                        removido = remover(&lista,valor);
                        if(removido)
                        {
                            printf("\nElemento Removido ( %ld )",removido->valor);
                            free(removido);
                        }
                        else
                            printf("\nCodigo Inexistente");
                    }
                    else
                    {
                        printf("Operacao Cancelada...");
                        break;
                    }
                    break;

                case 5:
                    salvar_txt(lista);
                    if(lista.tam <= 0)
                    {
                        printf("Vazio...\n");
                        break;
                    }
                    break;

                case 6:
                    fp = fopen("stock.txt","r");

                    if(fp == NULL)
                    {
                        printf("Erro na abertura do arquivo");
                        return 1;
                    }

                    No *no = lista.inicio;

                    printf("Vai ler quantos codigos?");
                    scanf("%d",&l);
                    for(int i=0;i<l;i++){ //DEIXAR DINAMICO
                        fscanf(fp,"%ld\n%s\n%f\n%d\n%d\n",&fvalor,&fnome,&fpreco,&fqtd,&fqtd_venda);
                        printf("cod %ld\n nome %s\npreco %f\n qtd %d\n",fvalor,fnome,fpreco,fqtd,fqtd_venda);
                        inserir_ini(&lista,fvalor,fnome,fpreco,fqtd);
                    }

                    fclose(fp);
                    if(lista.tam <= 0)
                    {
                        printf("Vazio...\n");
                        break;
                    }
                    break;

                case 0:
                    break;

                default:

                    printf("\nOpc invalida!\n");
                    break;
                }

            }
            while(opc_2 != 0);
            break;

        case 2:
            printf("\n1 - Vender\n2 - Relatorio de Vendas\n0 - Voltar");
            scanf("%d",&opc_2);

            if(opc_2 == 1)
            {
                do
                {
                    soma_estoque = imprimir_estoque(lista);
                    if(soma_estoque > 0)
                    {
                        printf("Digite o codigo do item desejado para a venda\n---> ");
                        scanf("%d",&valor);
                        total = vendas(&lista,valor,total);
                    }
                    else
                    {
                        printf("\nNao ha estoque suficiente para vender!");
                    }
                    printf("\nDeseja continuar vendendo?");
                    printf("\n( 1 ) - Sim\n( 0 ) - Nao\n---> ");
                    scanf("%d",&opc);
                }
                while(opc != 0);

                do
                {
                    printf("\nComo deseja pagar?\n( 1 ) - A vista\n( 2 ) - Parcelado\n---> ");
                    scanf("%d",&opc);

                    if(opc != 1 && opc !=2)
                        printf("\nDigite uma opc Valida!");

                }
                while(opc != 1 && opc != 2);

                switch(opc)
                {
                case 1:
                    if(total >0 && total <=50)
                    {
                        total_aux = total*0.05;
                        total = total - total_aux;
                        //CUPOM FISCAL
                        printf("\n-----Cupom Fiscal-----");
                        cupom(lista);
                        printf("----------\n");
                        printf("5%% Desconto\n");
                        printf("\nTotal ---> %.2f\n",total);
                    }
                    if(total >50 && total <=100)
                    {
                        total_aux = total*0.10;
                        total = total - total_aux;
                        //CUPOM FISCAL
                        printf("\n-----Cupom Fiscal-----\n");
                        cupom(lista);
                        printf("----------\n");
                        printf("10%% Desconto\n");
                        printf("\nTotal ---> %.2f\n",total);
                    }
                    if(total >=100)
                    {
                        total_aux = total*0.18;
                        total = total - total_aux;
                        //CUPOM FISCAL
                        printf("\n-----Cupom Fiscal-----");
                        cupom(lista);
                        printf("----------\n");
                        printf("18%% Desconto\n");
                        printf("\nTotal ---> %.2f\n",total);
                    }
                    total = 0,total_aux=0;
                    break;

                case 2:

                    printf("\nDigite o numero de parcelas\n---> ");
                    scanf("%d",&parcelas);

                    while(parcelas <=0)
                    {
                        if(parcelas<=0)
                        {
                            printf("\nValor invalido! \nDigite novamente\n---> ");
                            scanf("%d",&parcelas);
                        }
                    }
                    if(parcelas <=3)
                    {
                        total = total*1.05;
                        //CUPOM FISCAL
                        printf("\n-----Cupom Fiscal-----");
                        cupom(lista);
                        printf("----------\n");
                        printf("3%% juros\n");
                        printf("\nTotal ---> %.2f\n",total);
                    }
                    if(parcelas >3)
                    {
                        total = total*1.08;
                        //CUPOM FISCAL
                        printf("\n-----Cupom Fiscal-----");
                        cupom(lista);
                        printf("----------\n");
                        printf("8%% juros\n");
                        printf("\nTotal ---> %.2f\n",total);
                    }
                    total = 0,total_aux=0;

                    break;

                default:
                    printf("\nDigite um valor valido!\n");
                    break;
                }
                opc = 1;
            }

            if(opc_2 == 2)
            {
                relatorio(lista);
            }
            if(opc_2 == 0)
            {
                break;
            }
            break;


        default:
            if(opc != 0 )
            {
                printf("\nOpc invalida!\n");
            }
            break;
        }
    }
    while(opc != 0);

    return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "source.h"
#include <string.h>



//----------Functions for start menu



void mn_inicial() //cadeia de printf
{
    printf("\n\t\t\t------Bem Vindo------\n");
    printf("\n\t\t\t(1) - Produtos");
    printf("\n\t\t\t(2) - Vendas");
    printf("\n\t\t\t(3) - Sair");
    printf("\n\t\t\t----> ");
}

void sub_protudos() //cadeia de printf
{
    printf("\n\t\t\t------Produtos------\n");
    printf("\n\t\t\t(1) - Exibir");
    printf("\n\t\t\t(2) - Cadastrar");
    printf("\n\t\t\t(3) - Atualizar");
    printf("\n\t\t\t(4) - Excluir");
    printf("\n\t\t\t(5) - Salvar");
    printf("\n\t\t\t(6) - Ler");
    printf("\n\t\t\t(0) - Voltar");
    printf("\n\t\t\t----> ");
}

void sub_vendas() //cadeia de printf
{
    printf("\n\t\t\t------Sub Menu de Vendas------\n");
    printf("\n\t\t\t(1) - Realizar Venda");
    printf("\n\t\t\t(2) - Relatorio de Vendas");
    printf("\n\t\t\t(0) - Voltar");
    printf("\n\t\t\t----> ");
}

void limpar_tela() //system cls
{
    system("cls");
}

void visualizar_estoque (item *base, int tam)
{
    printf("|  \tCodigo\t  |  \tValor\t  |  \tEstoque\t  |  \tNome\t  |\n--------------------------------------------------------------------\n");
    for(int i=0; i<tam; i++) //for para printar todos os produtos disponiveis
    {
        printf("|  \t%d\t  |  \t%.2f\t  |  \t%d\t  |  \t%s\t\n", base[i].codigo, base[i].valor_unitario, base[i].estoque,base[i].nome);
    }
    printf("\nLinha: %d", tam); //printar quantos produtos tem
}

int cadastrar_produto(item *base, int tam, int quantidade)
{
    int nd=0,i=0,j=0;
    int aux_cod=0;

    for(j=0;j<quantidade;j++){
        if(tam==0)
        {
            base[tam].codigo = 1; //validar inicio
        }
        else
        {
            base[tam].codigo = base[tam-1].codigo + 1; //apos reordenar se ha um salto entre duas posicoes, se sim, insere uma posicao entre
            for(int i=0; i<tam; i++)
            {
                if(base[i+1].codigo==base[i].codigo+1)
                {
                    continue;
                }
                base[tam].codigo = i+2;
                break;
            }
        }

        printf("digite o cod do produto: \n");
        do
        {
            scanf("%d",&base[tam].codigo);
            aux_cod = base[tam].codigo;
            for(i=0;i<tam;i++){
                if(base[i].codigo==aux_cod){
                    printf("\nCodigo existente!\n");
                    base[tam].codigo=0;
                }
            }
            if(base[tam].codigo<=0)
            {
                printf("Digite novamente o Cod do Produto:\n");
            }
        }
        while(base[tam].codigo<=0);

        printf("\tInsira o nome do produto: \n");
        setbuf(stdin, NULL); //limpar buffer do teclado
        gets(base[tam].nome);

        printf("\tInsira o valor preco: \n");
        do
        {
            scanf("%f", &base[tam].valor_unitario);
            if(base[tam].valor_unitario<=0)
            {
                printf("Valor invalido!\n");
            }
        }
        while(base[tam].valor_unitario<=0);
        getchar();

        printf("\tInsira a quantidade para o estoque: \n");
        do
        {
            scanf("%d", &base[tam].estoque);
            getchar();
            if(base[tam].estoque<=0)
            {
                printf("Valor invalido!\n");
            }
        }
        while(base[tam].estoque<=0);
    tam++; //aumentar o tamanho
    }
    //tam=tam+quantidade;
    reordena_estoque(base, tam); //bubble sort
    return tam;
}

void atualizar_produto (item *base, int tam)
{
    int i, j,erro=0;
    int produto, opc,etq_antes;
    float pri_antes;
    char nm_antes[26];
    visualizar_estoque(base, tam);
    printf("\nDigite o Codigo desejado para Atualizar\n----> ");
    scanf("%d", &produto);
    getchar();
    system("cls");
    // do
    //{

    //limpar_tela();
    //printf("Codigo invalido! Tente novamente\n");
    visualizar_estoque(base,tam);
    //printf("----> ");
    //scanf("%d",&produto); DESEJA ALTERA ESSE PRODUTO?
    //getchar();

    //  }

    // while(produto >tam || produto <0); //fechar loop de atualizar prod


    for(i=0; i<tam; i++)
    {
        if(base[i].codigo==produto)//compara todas as posicoes com a do usuario
        {
            limpar_tela();
            printf("|  \tCodigo\t  |  \tValor\t  |  \tEstoque\t  |  \tNome\t  |\n--------------------------------------------------------------------\n");
            printf("|  \t%d\t  |  \t%.2f\t  |  \t%d\t  |  \t%s\t\n", base[i].codigo, base[i].valor_unitario, base[i].estoque,base[i].nome); //printf com o i do usuario
            printf("\n\nO que deseja alterar?\n----> "
                   "\n\t1 - Nome do Produto"
                   "\n\t2 - Preco"
                   "\n\t3 - Estoque"
                   "\n\t0 - Voltar"
                   "\n\t--->: ");
            scanf("%d", &opc);
            getchar();
            system("cls");
            strcpy(nm_antes,base[i].nome);
            pri_antes = base[i].valor_unitario;
            etq_antes = base[i].estoque;
            switch(opc)
            {
            case 1:
                printf("Insira o novo nome do produto: ");
                setbuf(stdin, NULL); //limpar buffer do teclado
                gets(base[i].nome);
                break;
            case 2:
                printf("Insira o novo preco do produto: ");
                scanf("%f", &base[i].valor_unitario);
                getchar();
                if(base[i].valor_unitario<=0)
                {
                    printf("'\nDigite um valor valido!");
                    base[i].valor_unitario=pri_antes;
                    erro++;
                }
                break;
            case 3:
                printf("Insira o novo estoque do produto: ");
                scanf("%d", &base[i].estoque);
                getchar();
                if(base[i].estoque<=0)
                {
                    printf("'\nDigite um valor valido!");
                    base[i].estoque=pri_antes;
                    erro++;
                }
                break;
            default:
                break;
            }
            if(erro<=0)
            {
                printf("\nAntes:\n");
                printf("|  \tCodigo\t  |  \tValor\t  |  \tEstoque\t  |  \tNome\t  |\n--------------------------------------------------------------------\n");
                printf("|  \t%d\t  |  \t%.2f\t  |  \t%d\t  |  \t%s\t\n", base[i].codigo, pri_antes, etq_antes,nm_antes); //printf com o i do usuario
                printf("\nDepois:\n");
                printf("|  \tCodigo\t  |  \tValor\t  |  \tEstoque\t  |  \tNome\t  |\n--------------------------------------------------------------------\n");
                printf("|  \t%d\t  |  \t%.2f\t  |  \t%d\t  |  \t%s\t\n", base[i].codigo, base[i].valor_unitario, base[i].estoque,base[i].nome); //printf com o i do usuario
                printf("\n\nDeseja alterar?\n( 0 ) - Nao\n( 1 ) - Sim\n--->");
                scanf("%d",&opc);
            }
            if(opc == 0)
            {
                strcpy(base[i].nome,nm_antes);
                base[i].valor_unitario=pri_antes;
                base[i].estoque = etq_antes;
                printf("\nAlteracoes desfeitas...");
            }


        }
        else
        {
            printf("Produto nao encontrado");
        }

    }
}

int excluir_produto(item *base, int tam)
{
    int i,aux_tam,opc=0;
    int produto;
    visualizar_estoque(base, tam);
    printf("\nDigite o código do item que deseja excluir: ");
    scanf("%d", &produto);
    getchar();
    limpar_tela();
    aux_tam = tam;

    printf("|  \tCodigo\t  |  \tValor\t  |  \tEstoque\t  |  \tNome\t  |\n--------------------------------------------------------------------\n");
    for(i=0; i<tam; i++)
    {
        if(base[i].codigo == produto)
        {
            printf("|  \t%d\t  |  \t%.2f\t  |  \t%d\t  |  \t%s\t\n", base[i].codigo, base[i].valor_unitario, base[i].estoque,base[i].nome); //printf com o i do usuario
            printf("\nDeseja excluir?\n( 0 ) - Nao\n( 1 ) - Sim");
            scanf("%d",&opc);
        }
    }

    if(opc == 1)
    {
        for(i=0; i<tam; i++)
        {


            if(base[i].codigo==produto)
            {
                for(; i<tam-1; i++)
                {
                    base[i] =base[i+1];
                }
                tam--;
            }
        }

    }


    if(aux_tam == tam && opc == 100)
    {
        printf("\n\t\tProduto nao encontrado");
    }

    return tam;
}

void reordena_estoque(item *base, int tam) //bubble sort
{
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(base[i].codigo>base[j].codigo)
            {
                item aux = base[i];
                base[i] = base[j];
                base[j] = aux;
            }
        }
    }
}

void realizar_venda(item *base, int tam)
{

    int produto, i,quantidade,opc,parcelas;
    float total,total_vet[tam],total_parc,rcbd,troco; //total_vet usado para somar todos as posicoes e ter valor final
    do
    {
        visualizar_estoque(base, tam);
        printf("\n\nLinhas: %d\n", tam);


        printf("\nDigite o Codigo desejado\n---->");
        scanf("%d", &produto);
        getchar();
        limpar_tela();
        printf("Qual a quantidade? ");
        scanf("%d",&quantidade);
        for(i=0; i<tam; i++)
        {
            if(base[i].codigo==produto)//buscar codigo desejado
            {
                do
                {
                    if(quantidade>base[i].estoque)//caso a quantidade exceda o estoque disp
                    {
                        printf("Quantidade invalida! Tente novamente: ");
                        scanf("%d",&quantidade);
                    }
                }
                while(quantidade>base[i].estoque);
                break;
            }
        }
        //transferir produtos vendidos para struct de cupom

        printf("Deseja continuar vendendo?\n");
        printf("( 0 ) - Nao\n( 1 ) - Sim");
        scanf("%d",&opc);
        base[i].estoque = base[i].estoque - quantidade; //subtrair estoque pela quantiddade desejada
        total_vet[i] = quantidade*base[i].valor_unitario; //multiplicar totais/qtd por posicoes

    }
    while(opc != 0); //fim loop


    for(i=0; i<tam; i++)
    {

        total += total_vet[i]; //somar totais
    }
    printf("\n\tO valor total foi de R$%.2f (Sem desconto) \n\n",total);

    printf("Forma de Pagamento\n");
    printf("( 1 ) - A vista\n( 2 ) - Parcelado");

    scanf("%d",&opc);//forma de pag
    switch(opc)
    {

    case 1:// a vista
        if(total<=50) //5% Desconto
        {
            total*=0.95;
        }
        else if(total>50 && total<100)  //10% Desconto
        {
            total*=0.90;
        }
        else if(total>=100)  //18% Desconto
        {
            total*=0.82;
        }
        do
        {
            printf("\t\tTotal com Desconto: %.2f\n\n",total);
            printf("\nDigite o dinheiro recebido:\n");
            scanf("%f", &rcbd);
            getchar();

            if(rcbd<total)
            {
                printf("Valor do troco Invalido,Falta R$ %.2f\n", -rcbd+total);
            }
        }
        while(rcbd<total);
        troco=-total+rcbd;
        printf("\t\tTotal com desconto: %.2f\n", total);
        printf("\t\tTroco comm desconto: %.2f\n\n", troco);
        break;

    case 2://parcelado
        do
        {
            printf("\tQual a quantidade de parcelas? ");
            scanf("%d",&parcelas);

            if(parcelas<1)
            {
                system("cls");
                printf("\n\tNúmero de parcelas inválido, digite um valor acima de 1.\n");
            }
        }
        while(parcelas <1);
        if(parcelas<=3)  //5% Juros
        {
            total*=1.05;
            total_parc = total/parcelas;
        }
        else if (parcelas>3) //8% Juros
        {
            total*=1.08;
            total_parc = total/parcelas;
        }
        printf("\n\t|------------------NOTA-------------------|\n\n");

        printf("\t|O valor a prazo (%d meses) ficou: R$%.2f\n",parcelas,total);
        printf("\t|O valor total das parcelas ficou: R$%.2f\n\n",total_parc);
        printf("\t|-----------------------------------------|\n\n\n");
        break;
    }
}

void salvar_base(item *base, int tam) //CUPOM FISCAL
{

    char filename[40];

    struct tm *timenow; //usado para pegar tempo atual

    time_t now = time(NULL);
    timenow = gmtime(&now);

    strftime(filename, sizeof(filename), "%Y-%m-%d_%H-%M-%S.txt", timenow); //adicionando nomenclatura e tamanho

    FILE *fp = fopen(filename, "w"); //abrindo arquito para escrita

    if(fp == NULL)
    {
        printf("Erro ao abrir o arquivo %s", filename);
        return 1;
    }

    fprintf(fp, "Quantidade de Vendas\n");
    fprintf(fp, "%d\n", tam);
    for(int i = 0; i < tam; i++) //usado para printar
    {
        fprintf(fp, "\nItem: %d", base[i]);
    }

    fclose(fp);
    printf("\t\tSalvamento com sucesso! Clique Enter para Continuar");
    getchar();
    limpar_tela();
    return filename;
}

void ler(item *base, int tam)
{

    char filename[40];
    char str[50];

    FILE *fp_bi;

    fp_bi = fopen("base.bin", "rb"); //ler arquivo

    if(fp_bi == NULL)
    {
        printf("Erro ao abrir o arquivo %s", filename);
        return;
    }
    fread(base,sizeof(base),tam,fp_bi);
    for(int i=0;i<tam;i++){
    printf("\n%i\t%s\n%.2f\n%i\n",base[i].codigo,base[i].nome,base[i].valor_unitario,base[i].estoque);
    }
    fclose(fp_bi);
    printf("\n\t\t\tLeitura da base com sucesso! \tClique Enter para continuar...");
    getchar();
}

void salvar(item *base, int tam) //BASE
{

    char filename[40];
    int qt_venda=0;

    FILE *fp = fopen("base.txt", "w");//String
    FILE *fp_bi = fopen("base.bin", "wb");//BINARIO

    if(fp == NULL || fp_bi == NULL)
    {
        printf("Erro ao abrir o arquivo %s", filename);
        exit(1);
    }

    fprintf(fp, "\n%d",tam);
    fprintf(fp_bi, "\n%d",tam);
    for(int i = 0; i < tam; i++)
    {
        //String
        fprintf(fp, "\n%d", base[i].codigo);
        fprintf(fp, "\n%s", base[i].nome);
        fprintf(fp, "\n%.2f", base[i].valor_unitario);
        fprintf(fp, "\n%d", base[i].estoque);
        //BINARIO
        fwrite(base,sizeof(base),tam,fp_bi);
    }

    fclose(fp);//fechar arq string
    fclose(fp_bi);//fechar aq binario
    printf("\t\tSalvamento com sucesso! Clique Enter para Continuar");
    getchar();
    limpar_tela();
}


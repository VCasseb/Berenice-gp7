#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED

//----------Functions for start menu

//Typedef ele redefine um tipo, ele da um apelido para o tipo de dados ja existente
typedef struct estrutura //struct principal
{
    int codigo;
    char nome[26];
    float valor_unitario;
    int estoque;
} item;

typedef struct estrutura_rel //stuct usada para copiar itens vendidos
{
    int codigo;
    char nome[26];
    float valor_unitario;
    int estoque;
} relatorio;

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
    printf("\n\Linha: %d", tam); //printar quantos produtos tem
}

int cadastrar_produto(item *base, int tam)
{
    if(tam==0)
    {
        base[tam].codigo = 1; //validar inicio
    }
    else
    {
        base[tam].codigo = base[tam-1].codigo + 1; //validar e criar codigos em ordem crescente
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
    printf("\tInsira o nome do produto: ");
    setbuf(stdin, NULL); //permite trocar entre o modo sem bufferização e o modo bufferização completa
    gets(base[tam].nome);
    printf("\tInsira o valor preco: ");
    scanf("%f", &base[tam].valor_unitario);
    getchar();
    printf("\tInsira a quantidade para o estoque: ");
    scanf("%d", &base[tam].estoque);
    getchar();

    tam++; //aumentar o tamanho
    reordena_estoque(base, tam); //bubble sort
    return tam;
}

void atualizar_produto (item *base, int tam)
{
    int i, j;
    int produto, opc;
    visualizar_estoque(base, tam);
    printf("\nDigite o Codigo desejado para Atualizar\n----> ");
    scanf("%d", &produto);
    getchar();
    system("cls");
    do
    {
        if(produto <0 || produto >tam) //validar se o produto existe
        {
            limpar_tela();
            printf("Codigo invalido! Tente novamente\n");
            printf("|  \tCodigo\t  |  \tValor\t  |  \tEstoque\t  |  \tNome\t  |\n--------------------------------------------------------------------\n");
            for(i=0; i<tam; i++)
            {
                printf("|  \t%d\t  |  \t%.2f\t  |  \t%d\t  |  \t%s\t\n", base[i].codigo, base[i].valor_unitario, base[i].estoque,base[i].nome);
            }
            printf("----> ");
            scanf("%d",&produto);
            getchar();

        }
    }
    while(produto >tam || produto <0); //fechar loop de atualizar prod
    for(i=0; i<tam; i++)
    {
        if(base[i].codigo==produto)
        {
            break;
        }
    }
    do
    {
        limpar_tela();
        printf("|  \tCodigo\t  |  \tValor\t  |  \tEstoque\t  |  \tNome\t  |\n--------------------------------------------------------------------\n");
        printf("|  \t%d\t  |  \t%.2f\t  |  \t%d\t  |  \t%s\t\n", base[i].codigo, base[i].valor_unitario, base[i].estoque,base[i].nome);
        printf("\n\nO que deseja alterar?\n----> "
               //"\n\t1 - Codigo"
               "\n\t1 - Nome do Produto"
               "\n\t2 - Preco"
               "\n\t3 - Estoque"
               "\n\t0 - Voltar"
               "\n\t--->: ");
        scanf("%d", &opc);
        getchar();
        system("cls");
        switch(opc)
        {
        case 0:
            break;
        /*case 1:
          do
          {
              printf("Insira o novo Codigo do produto: ");
              scanf("%d", &base[i].codigo);
              getchar();
              for(j=0; j<tam; j++)
              {
                  if(i == j)
                  {
                      continue;
                  }
                  else if(base[i].codigo == base[j].codigo)
                  {
                      printf("Este código já existe.\nEscolha uma novo\n\n");
                      system("pause");
                      break;
                  }
              }
          }
          while(base[j].codigo==base[i].codigo);
          break;*/
        case 1:
            printf("Insira o novo nome do produto: ");
            setbuf(stdin, NULL);
            gets(base[i].nome);
            break;
        case 2:
            printf("Insira o novo preco do produto: ");
            scanf("%f", &base[i].valor_unitario);
            getchar();
            break;
        case 3:
            printf("Insira o novo estoque do produto: ");
            scanf("%d", &base[i].estoque);
            getchar();
            break;
        default:
            break;
        }
    }
    while(opc > 3);
}

int excluir_produto(item *base, int tam)
{
    int i;
    int produto;
    visualizar_estoque(base, tam);
    printf("\nDigite o código do item que deseja excluir: ");
    scanf("%d", &produto);
    getchar();
    system("cls");
    for(i=0; i<tam; i++)
    {
        if(base[i].codigo==produto)
        {
            break;
        }
    }
    for(; i<tam-1; i++)
    {
        base[i] =base[i+1];
    }
    tam--; //reduzir tamanho pos exclusao
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

void realizar_venda(item *base,relatorio *rel, int tam)
{

    int produto, i,quantidade,opc,parcelas;
    float total,total_vet[tam],total_parc; //total_vet usado para somar todos as posicoes e ter valor final
    do
    {
        printf("|  \tCodigo\t  |  \tValor\t  |  \tEstoque\t  |  \tNome\t  |\n--------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            printf("|  \t%d\t  |  \t%.2f\t  |  \t%d\t  |  \t%s\t\n", base[i].codigo, base[i].valor_unitario, base[i].estoque,base[i].nome);
        }
        printf("\n\Linhas: %d\n", tam);


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
        rel[i].codigo = base[i].codigo;
        rel[i].nome[26] = base[i].nome[26];
        rel[i].valor_unitario = base[i].valor_unitario;
        rel[i].estoque = base[i].estoque;

        printf("Deseja continuar vendendo?\n");
        printf("( 0 ) - Nao\n( 1 ) - Sim");
        if(opc == 1)
        {

        }
        scanf("%d",&opc);
        base[i].estoque = base[i].estoque - quantidade; //subtrair estoque pela quantiddade desejada
        total_vet[i] = quantidade*base[i].valor_unitario; //multiplicar totais/qtd por posicoes
        //total_vet[i] += total;
    }
    while(opc != 10); //fim loop


    for(i=0; i<tam; i++)
    {

        total += total_vet[i]; //somar totais
    }
    //base[i].estoque = base[i].estoque - quantidade;
    //total = quantidade*base[i].valor_unitario;
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
        printf("\t\tTotal com Desconto: %.2f\n\n",total);
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

    /*
    printf("\n\t\t\t------RELATORIO------\n\n");
    for(i=0;i<tam;i++){

            printf("\t\tCodigo %d\n", rel[i].codigo);
            printf("\t\tNome %s\n", base[i].nome);
            printf("\t\tValor Total %.2f\n", rel[i].valor_unitario*rel[i].estoque);
            printf("\t\tQuantidade %d\n", rel[i].estoque);


    }*/
}

void salvar_base(item *base,relatorio *rel, int tam) //CUPOM FISCAL
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
        fprintf(fp, "\nItem: %d", rel[i].codigo);
        fprintf(fp, "\nProduto: %s", base[i].nome);
        fprintf(fp, "\nValor Total: %.2f", rel[i].valor_unitario*rel[i].estoque);
        fprintf(fp, "\nQtd: %d", rel[i].estoque);

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

    FILE *fp;

    fp = fopen("base.bin", "rb"); //ler arquivo

    if(fp == NULL)
    {
        printf("Erro ao abrir o arquivo %s", filename);
        return 1;
    }
    while (fgets(str, 50, fp) != NULL)
    {
        printf("\t\t%s", str);
    }
    fclose(fp );
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
        return 1;
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
        fprintf(fp_bi, "\n%d", base[i].codigo);
        fprintf(fp_bi, "\n%s", base[i].nome);
        fprintf(fp_bi, "\n%.2f", base[i].valor_unitario);
        fprintf(fp_bi, "\n%d", base[i].estoque);
    }

    fclose(fp);//fechar arq string
    fclose(fp_bi);//fechar aq binario
    printf("\t\tSalvamento com sucesso! Clique Enter para Continuar");
    getchar();
    limpar_tela();
    return filename;
}
#endif // CALCULOS_H_INCLUDED

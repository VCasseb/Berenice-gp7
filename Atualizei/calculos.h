#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED

//----------Functions for start menu

//Typedef ele redefine um tipo, ele da um apelido para o tipo de dados ja existente
typedef struct estrutura
{
    int codigo;
    char nome[26];
    float valor_unitario;
    int estoque;
} item;

void mn_inicial(){
        printf("\n\t\t\t(1) - Produtos");
        printf("\n\t\t\t(2) - Vendas");
        printf("\n\t\t\t(3) - Sair");
}

void sub_protudos(){
        printf("\n\t\t\t(1) - Exibir");
        printf("\n\t\t\t(2) - Cadastrar");
        printf("\n\t\t\t(3) - Atualizar");
        printf("\n\t\t\t(4) - Excluir");
        printf("\n\t\t\t(5) - Salvar");
        printf("\n\t\t\t(6) - Ler");
        printf("\n\t\t\t(7) - Voltar");
}

void printsf(){

        printf("\n\t\t\t(1) - Produtos");
        printf("\n\t\t\t(2) - Vendas");
        printf("\n\t\t\t(3) - Sair");

        printf("\n\t\t\t(1) - Realizar Venda");
        printf("\n\t\t\t(2) - Relatorio de Vendas");
        printf("\n\t\t\t(3) - Voltar");

        printf("\n\t\t\t(1) - Exibir");
        printf("\n\t\t\t(2) - Cadastrar");
        printf("\n\t\t\t(3) - Atualizar");
        printf("\n\t\t\t(4) - Excluir");
        printf("\n\t\t\t(5) - Salvar");
        printf("\n\t\t\t(6) - Ler");
        printf("\n\t\t\t(7) - Voltar");


}

void limpar_tela(){
    system("cls");
}



//funcoes saller          TIRA ISSO PELO AMOR DE DEUS QUANDO FOR MANDAR \*/\*/\/*

void visualizar_estoque (item *base, int tam)
{
    printf("Código\tNome\t\tValor\tEstoque\n");
    for(int i=0; i<tam; i++)
    {
        printf("%d\t%s\t\t%.2f\t%d\n", base[i].codigo, base[i].nome, base[i].valor_unitario, base[i].estoque);
    }
    printf("\n\nTamanho: %d", tam);
}

int cadastrar_produto(item *base, int tam)
{
    /*Se o cadatro é o primeiro, estabelece o código igual a 1
    Caso contrário, estabelece o código como um a mais que a posição anterior*/
    if(tam==0)
    {
        base[tam].codigo = 1;
    }
    else
    {
        base[tam].codigo = base[tam-1].codigo + 1;
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
    setbuf(stdin, NULL);
    gets(base[tam].nome);
    printf("\tInsira o valor preco: ");
    scanf("%f", &base[tam].valor_unitario);
    getchar();
    printf("\tInsira a quantidade para o estoque: ");
    scanf("%d", &base[tam].estoque);
    getchar();
    /*aumenta o valor de tamanho*/
    tam++;
    reordena_estoque(base, tam);
    return tam;
}

void atualizar_produto (item *base, int tam)
{
    int i, j;
    int produto, opc;
    visualizar_estoque(base, tam);
    printf("\nDigite o código do item que deseja atualizar: ");
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
    do
    {
        printf("%d\t%s\t\t%.2f\t%d", base[i].codigo, base[i].nome, base[i].valor_unitario, base[i].estoque);
        printf("\n\nQual elemento deseja editar?"
               "\n\t1 - Codigo"
               "\n\t2 - Nome do Produto"
               "\n\t3 - Preco"
               "\n\t4 - Estoque"
               "\n\t0 - Voltar"
               "\n\t--->: ");
        scanf("%d", &opc);
        getchar();
        system("cls");
        switch(opc)
        {
            case 0:
                break;
            case 1:
                do
                {
                    printf("Insira o novo código do produto: ");
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
                break;
            case 2:
                printf("Insira o novo nome do produto: ");
                setbuf(stdin, NULL);
                gets(base[i].nome);
                break;
            case 3:
                printf("Insira o novo preco do produto: ");
                scanf("%f", &base[i].valor_unitario);
                getchar();
                break;
            case 4:
                printf("Insira o novo estoque do produto: ");
                scanf("%d", &base[i].estoque);
                getchar();
                break;
            default:
                break;
        }
    }
    while(opc > 4);
}

int excluir_produto(item *base, int tam)
{
    int i;
    int produto;
    //item aux;
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
    for(; i<tam-1;i++)
    {
        base[i] =base[i+1];
    }
    tam--;
    return tam;
}

void reordena_estoque(item *base, int tam)
{
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1;j<tam; j++)
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


void arquivo_horario(){
    printf("Arquivo Criado em: %s Data: %s Horario : %s \n", __FILE__, __DATE__, __TIME__ );

    FILE     *fptr;
    char     *fmode, arquivo[15];
    struct   tm* tm;
    struct   timespec ts;
    time_t   agora;

    // Pega a data atual em segundos , utilizando o relogio do sistema
    agora = time(NULL);

    // Converte para estrutura tm, igual ao do relogio local.
    tm  = localtime(&agora);

    // Pega o horario atual pelo relogio do sistema.
    clock_gettime(CLOCK_REALTIME, &ts);

    // Gera o nome do para o arquivo, salvando na variavel, utilizando do sprintf
    sprintf(arquivo, "%04d-%02d-%02d_%02d-%02d-%02d.txt", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday, tm->tm_hour,tm->tm_min,tm->tm_sec);

    // Para adicionar no final do arquivo. Caso não exista, cria um arquivo.
    fmode = "a";

    // Abre o arquivo e escreve nele.
    fptr = fopen(arquivo, fmode);
    if (fptr == NULL) {
        printf("Nao foi possivel abrir o arquivo com esse nome. \n");
        exit(0);
    }
return arquivo;
}


#endif // CALCULOS_H_INCLUDED

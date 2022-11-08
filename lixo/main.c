#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct estrutura
{
    int codigo;
    char nome[26];
    float valor_unitario;
    int estoque;
} item;

void visualizar_estoque (item *vet, int tam);
int cadastrar_produto(item *vet, int tam);
void atualizar_produto (item *vet, int tam);
int excluir_produto(item *vet, int tam);
void reordena_estoque(item *vet, int tam);

int main()
{
    setlocale(LC_ALL, "portuguese");
    int escolha = 3;
    int tam = 0;
    item *vet = (item *)malloc(sizeof(item));//vetor vet acumula os itens cadastrados
    if(vet == NULL)
    {
        printf("ERRO na alocação de memória");
        exit(1);
    }
    do
    {
        system("cls");
        printf("O que deseja?"
               "\n\t1 - Vizualizar estoque"
               "\n\t2 - Inserir um item"
               "\n\t3 - Atualizar um item"
               "\n\t4 - Excluir um item"
               "\n\t0 - Sair"
               "\n\tEscolha: ");
        scanf("%d", &escolha);
        getchar();
        system("cls");
        switch(escolha)
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
                    visualizar_estoque(vet, tam);
                }
                printf("\n");
                system("pause");
                break;
            case 2:
                /*aumenta a zona de memória do vetor vet*/
                vet = (item *)realloc(vet, (tam+1)*sizeof(item));
                if(vet == NULL)
                {
                    printf("ERRO na realocação de memória");
                    exit(2);
                }
                tam = cadastrar_produto(vet, tam);
                break;
            case 3:
                if(tam == 0)
                {
                    printf("Não há nenhum produto cadastrado");
                }
                else
                {
                    atualizar_produto(vet, tam);
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
                    tam = excluir_produto(vet, tam);
                    vet = (item *)realloc(vet, (tam)*sizeof(item));
                    if(vet == NULL)
                    {
                        printf("ERRO na realocação de memória");
                        exit(3);
                    }
                }
                printf("\n");
                system("pause");
                break;
            default:
                continue;
        }
    }
    while(escolha != 0);
    free(vet);
    return 0;
}
void visualizar_estoque (item *vet, int tam)
{
    printf("Código\tNome\t\tValor\tEstoque\n");
    for(int i=0; i<tam; i++)
    {
        printf("%d\t%s\t\t%.2f\t%d\n", vet[i].codigo, vet[i].nome, vet[i].valor_unitario, vet[i].estoque);
    }
    printf("\n\nTamanho: %d", tam);
}
int cadastrar_produto(item *vet, int tam)
{
    /*Se o cadatro é o primeiro, estabelece o código igual a 1
    Caso contrário, estabelece o código como um a mais que a posição anterior*/
    if(tam==0)
    {
        vet[tam].codigo = 1;
    }
    else
    {
        vet[tam].codigo = vet[tam-1].codigo + 1;
        for(int i=0; i<tam; i++)
        {
            if(vet[i+1].codigo==vet[i].codigo+1)
            {
                continue;
            }
            vet[tam].codigo = i+2;
            break;
        }
    }
    printf("Insira o nome: ");
    setbuf(stdin, NULL);
    gets(vet[tam].nome);
    printf("Insira o valor unitário: ");
    scanf("%f", &vet[tam].valor_unitario);
    getchar();
    printf("Insira a quantidade em estoque: ");
    scanf("%d", &vet[tam].estoque);
    getchar();
    /*aumenta o valor de tamanho*/
    tam++;
    reordena_estoque(vet, tam);
    return tam;
}
void atualizar_produto (item *vet, int tam)
{
    int i, j;
    int produto, escolha;
    visualizar_estoque(vet, tam);
    printf("\nDigite o código do item que deseja atualizar: ");
    scanf("%d", &produto);
    getchar();
    system("cls");
    for(i=0; i<tam; i++)
    {
        if(vet[i].codigo==produto)
        {
            break;
        }
    }
    do
    {
        printf("%d\t%s\t\t%.2f\t%d", vet[i].codigo, vet[i].nome, vet[i].valor_unitario, vet[i].estoque);
        printf("\n\nQual elemento deseja editar?"
               "\n\t1 - Código"
               "\n\t2 - Nome"
               "\n\t3 - Valor unitário"
               "\n\t4 - Quantidade no estoque"
               "\n\t0 - Voltar"
               "\n\tEscolha: ");
        scanf("%d", &escolha);
        getchar();
        system("cls");
        switch(escolha)
        {
            case 0:
                break;
            case 1:
                do
                {
                    printf("Insira o novo código do produto: ");
                    scanf("%d", &vet[i].codigo);
                    getchar();
                    for(j=0; j<tam; j++)
                    {
                        if(i == j)
                        {
                            continue;
                        }
                        else if(vet[i].codigo == vet[j].codigo)
                        {
                            printf("Este código já existe.\nEscolha uma novo\n\n");
                            system("pause");
                            break;
                        }
                    }
                }
                while(vet[j].codigo==vet[i].codigo);
                break;
            case 2:
                printf("Insira o novo nome do produto: ");
                setbuf(stdin, NULL);
                gets(vet[i].nome);
                break;
            case 3:
                printf("Insira o novo valor unitário do produto: ");
                scanf("%f", &vet[i].valor_unitario);
                getchar();
                break;
            case 4:
                printf("Insira o novo estoque do produto: ");
                scanf("%d", &vet[i].estoque);
                getchar();
                break;
            default:
                break;
        }
    }
    while(escolha > 4);
}
int excluir_produto(item *vet, int tam)
{
    int i;
    int produto;
    //item aux;
    visualizar_estoque(vet, tam);
    printf("\nDigite o código do item que deseja excluir: ");
    scanf("%d", &produto);
    getchar();
    system("cls");
    for(i=0; i<tam; i++)
    {
        if(vet[i].codigo==produto)
        {
            break;
        }
    }
    for(; i<tam-1;i++)
    {
        vet[i] = vet[i+1];
    }
    tam--;
    return tam;
}
void reordena_estoque(item *vet, int tam)
{
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1;j<tam; j++)
        {
            if(vet[i].codigo>vet[j].codigo)
            {
                item aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

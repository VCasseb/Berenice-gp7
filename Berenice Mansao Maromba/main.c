#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    float preco;
    char nome[26];
    char *string;
    int quantidade;
    long int valor; //codigo

    float preco_cp;
    char nome_cp[26];
    int qtd_cp;
    long int valor_cp;
    float venda;
    float subtt;
    float tt;
    struct no *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

int imprimir_existente(Lista lista, int num);
void cupom(Lista lista);
void criar_lista(Lista *lista);
void inserir_ini(Lista *lista,int num, char nomes[30], float pc, int qtds);
int imprimir_estoque(Lista lista);
No* venda(Lista *lista, int num);
No *editar_char(Lista *lista, int num);
No *editar_preco(Lista *lista, int num);
No *editar_qtd(Lista *lista, int num);
No *editar_cod(Lista *lista, int num);
No *remover(Lista *lista, int num);
No* buscar(Lista *lista, int num);
void imprimir(Lista lista);

int main()
{

    int opc,opc_2,ant, qtd_usuario=0,k=0,j=0,c=0,d=0,y=1;
    int receber=0;
    int valor; //codigo
    int quantidade;
    char nm[26] = "";
    float preco;
    int soma_estoque;

    //No *lista = NULL;
    Lista lista;

    No *removido;
    No *aux;

    criar_lista(&lista);

    do
    {
        printf("\n( 1 ) - Produtos\n( 2 ) - Vendas\n( 3 ) - Sair");
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            do
            {
                printf("\n1 - Exibir\n2 - Cadastrar\n3 - Atualizar\n4 - Excluir\n5 - Salvar\n6 - Ler\n0 - Voltar");

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
                        printf("\n");
                        printf("[%d]Digite o codigo: ",y);
                        scanf("%d",&valor);
                        receber = imprimir_existente(lista, valor);
                        if(receber > 0)
                        {
                            printf("Codigo Existente!");
                            system("pause");
                            break;
                        }

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

                        if(j == c)
                        {
                            printf("\nNome invalido!\n");
                            break;
                        }

                        printf("[%d]Digite o preco: ",y);
                        scanf("%f",&preco);
                        if(preco <=0)
                        {
                            printf("Valor incorreto!");
                            break;
                        }

                        printf("[%d]Digite a qtd: ",y);
                        scanf("%d",&quantidade);
                        if(quantidade <=0)
                        {
                            printf("Valor incorreto!");
                            break;
                        }
                        y++;
                        inserir_ini(&lista,valor,nm,preco,quantidade);
                    }
                    break;

                case 3:
                    //finalizar atualizar
                    if(lista.tam<=0)
                    {
                        printf("Vazio...\n");
                        break;
                    }

                    do
                    {
                        imprimir(lista);
                        printf("Digite o codigo do produto que deseja atualizar: ");
                        scanf("%d",&valor);
                        int aux = buscar(&lista, valor);
                        if(valor == aux)
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
                    while(valor ==aux);
                    //}else{
                    //    printf("Nao ha produtos cadastrados");
                    //}


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
                    if(opc == 1){
                    removido = remover(&lista,valor);
                    if(removido)
                    {
                        printf("\nElemento Removido ( %d )",removido->valor);
                        free(removido);
                    }
                    else
                        printf("\nCodigo Inexistente");
                    }else
                    {
                        printf("Operacao Cancelada...");
                        break;
                    }
                    break;

                case 5:
                    if(lista.tam <= 0)
                    {
                        printf("Vazio...\n");
                        break;
                    }
                    break;

                case 6:
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
            do
            {
                soma_estoque = imprimir_estoque(lista);
                if(soma_estoque > 0)
                {
                    printf("Digite o codigo do item desejado para a venda\n---> ");
                    scanf("%d",&valor);
                    venda(&lista,valor);
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

            //CUPOM FISCAL
            cupom(lista);
            system("pause");
            opc = 1;
            break;

        default:
            if(opc != 0 ){
            printf("\nOpc invalida!\n");
            }
            break;
        }
    }
    while(opc != 0);

    return 0;
}

No* venda(Lista *lista, int num)
{
    No *aux, *no = NULL;

    float preco,total=0,subtotal=0,quant;
    char nomes[30];
    int quantidade,opc;
    long int valor; //codigo

    float preco_cu;

    aux = lista->inicio;
    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux->valor == num)
    {
        preco = aux->preco;
        strcpy(nomes,aux->nome);
        quantidade = aux->quantidade;
        valor = aux->valor;
    }
    printf("\n-----------");
    printf("\n\nCodigo: %d",valor);
    printf("\nNome: %s",nomes);
    printf("\nPreco: %.2f",preco);
    printf("\nQuantidade: %d\n",quantidade);
    printf("-----------\n");


    printf("\nDigite a quantidade\n---> ");
    scanf("%f",&quant);

    if(quant <=0  || quant > aux->quantidade)
    {
        printf("Quantidade invalida ou insuficiente!");
    }

    if(quant >0  && quant <= aux->quantidade)
    {
        //passar valores para struct CUPOM
        aux->quantidade = aux->quantidade - quant; //Subtrair do estoque real

        aux->preco_cp = preco;
        strcpy(aux->nome_cp, nomes);
        aux->qtd_cp = aux->quantidade;
        aux->valor_cp = valor;

        subtotal = quant*preco;
        aux->venda = total+subtotal;

        printf("\nTotal: %.2f",aux->venda);

        system("pause");

        if(aux)
            no = aux;
    }

    return no;
}

void cupom(Lista lista)
{
    No *no = lista.inicio;
    printf("\nLista Tam %d\n",lista.tam);
    while(no)
    {
        printf("%d ", no->valor_cp);
        printf("%s ", no->nome_cp);
        printf("%f ", no->preco_cp);
        printf("%d ", no->qtd_cp);
        printf("%f ", no->venda);
        printf("\n");
        no = no->proximo;
    }
    printf("\n\n");

}

void imprimir(Lista lista)
{
    printf("\n");
    printf("-------------");
    printf("\n");

    No *no = lista.inicio;
    printf("Itens %d\n",lista.tam);
    printf("-------------\n\n");
    while(no)
    {
        printf("Codigo do Produto: %d\n", no->valor);
        printf("Nome: %s\n", no->nome);
        printf("Preco: %.2f\n", no->preco);
        printf("Quantidade: %d\n", no->quantidade);
        printf("\n");
        printf("-------------\n");
        printf("\n");
        no = no->proximo;
    }
    printf("\n\n");

}

int imprimir_existente(Lista lista, int num)
{
    No *no = lista.inicio;

    while(no)
    {
        //printf("%d ", no->valor);
        if(no->valor == num)
        {
            return 1;
        }
        no = no->proximo;
    }
}

int imprimir_estoque(Lista lista)
{
    int soma;

    No *no = lista.inicio;
    printf("\nLista Tam %d\n",lista.tam);
    while(no)
    {
        if(no->quantidade > 0)
        {
            printf("%d ", no->valor);
            printf("%s ", no->nome);
            printf("%f ", no->preco);
            printf("%d ", no->quantidade);
            printf("\n");
            soma += no->quantidade;
        }
        no = no->proximo;
    }
    printf("\n\n");

    return soma;
}

No* buscar(Lista *lista, int num)
{
    No *aux, *no = NULL;

    aux = lista->inicio;
    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        no = aux;

    return no;
}

No *remover(Lista *lista, int num)
{
    No *aux,*remover = NULL;

    if(lista->inicio)
    {
        if(lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        }
        else
        {
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
            }
        }
    }


    return remover;
}

void criar_lista(Lista *lista)
{

    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_ini(Lista *lista,int num, char nomes[26], float pc, int qtds)
{
    int receber;
    No *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
        strcpy(novo->nome, nomes);
        novo->preco = pc;
        novo->quantidade = qtds;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria");
}

No *editar_cod(Lista *lista, int num)
{
    int alterar;

    No *aux,*remover = NULL;

    if(lista->inicio)
    {
        //Achar primeiro da lista OK
        if(lista->inicio->valor == num)
        {
            printf("Digite o valor desejado: ");
            scanf("%d",&alterar);
            lista->inicio->valor =  alterar;
        }
        else
        {
            //Achar proximo da Lista OK
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo)
            {
                printf("Digite o valor desejado: ");
                scanf("%d",&alterar);
                aux->proximo->valor = alterar;
            }
            else
            {
                printf("Item nao Existe!");
            }
        }
    }
}

No *editar_qtd(Lista *lista, int num)
{
    int alterar;

    No *aux,*remover = NULL;

    if(lista->inicio)
    {
        //Achar primeiro da lista OK
        if(lista->inicio->valor == num)
        {
            printf("Digite o valor desejado: ");
            scanf("%d",&alterar);
            lista->inicio->quantidade =  alterar;
        }
        else
        {
            //Achar proximo da Lista OK
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo)
            {
                printf("Digite o valor desejado: ");
                scanf("%d",&alterar);
                aux->proximo->quantidade = alterar;
            }
            else
            {
                printf("Item nao Existe!");
            }
        }
    }
}

No *editar_preco(Lista *lista, int num)
{
    float alterar;

    No *aux,*remover = NULL;

    if(lista->inicio)
    {
        //Achar primeiro da lista OK
        if(lista->inicio->valor == num)
        {
            printf("Digite o valor desejado: ");
            scanf("%f",&alterar);
            lista->inicio->preco =  alterar;
        }
        else
        {
            //Achar proximo da Lista OK
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo)
            {
                printf("Digite o valor desejado: ");
                scanf("%f",&alterar);
                aux->proximo->preco = alterar;
            }
            else
            {
                printf("Item nao Existe!");
            }
        }
    }
}

No *editar_char(Lista *lista, int num)
{
    char alterar[30];

    No *aux,*remover = NULL;

    if(lista->inicio)
    {
        //Achar primeiro da lista OK
        if(lista->inicio->valor == num)
        {
            printf("Digite o valor desejado: ");
            setbuf(stdin,NULL);
            gets(alterar);
            strcpy(lista->inicio->nome, alterar);
        }
        else
        {
            //Achar proximo da Lista OK
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo)
            {
                printf("Digite o valor desejado: ");
                setbuf(stdin,NULL);
                gets(alterar);
                strcpy(aux->proximo->nome, alterar);
            }
            else
            {
                printf("Item nao Existe!");
            }
        }
    }
}






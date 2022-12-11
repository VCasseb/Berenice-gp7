#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

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
    int qtd_venda;

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
No* venda(Lista *lista, int num, int total_tt);
No *editar_char(Lista *lista, int num);
No *editar_preco(Lista *lista, int num);
No *editar_qtd(Lista *lista, int num);
No *editar_cod(Lista *lista, int num);
No *remover(Lista *lista, int num);
No* buscar(Lista *lista, int num);
void imprimir(Lista lista);

#endif // HEADER_H_INCLUDED

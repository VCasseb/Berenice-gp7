#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

//Typedef ele redefine um tipo, ele da um apelido para o tipo de dados ja existente
typedef struct estrutura //struct principal
{
    int codigo;
    char nome[26];
    float valor_unitario;
    int estoque;
} item;

void mn_inicial(); // Printf do menu linha 23
void sub_protudos(); //Printf do submenu linha 32
void limpar_tela(); //SystemCLS linha 45
void visualizar_estoque (item *base, int tam); //linha 50
int cadastrar_produto(item *base, int tam, int quantidade);
void atualizar_produto (item *base, int tam);
int excluir_produto(item *base, int tam);
void reordena_estoque(item *base, int tam); //buble sort
void salvar(item *base, int tam); //Salver cupom fiscal
void ler();
void sub_vendas();
void relatorio(item *base, int tam,int qtd_vendas);
void realizar_venda(item *base, int tam,int qtd_vendas);

#endif // SOURCE_H_INCLUDED

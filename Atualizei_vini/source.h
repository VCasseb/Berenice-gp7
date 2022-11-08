#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

void mn_inicial();
void sub_protudos();
void limpar_tela();
void visualizar_estoque (item *base, int tam);
int cadastrar_produto(item *base, int tam);
void atualizar_produto (item *base, int tam);
int excluir_produto(item *base, int tam);
void reordena_estoque(item *base, int tam);
void arquivo_horario();
void realizar_venda(item *base,relatorio *rel, int tam);


#endif // SOURCE_H_INCLUDED

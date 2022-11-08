#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

void mn_inicial(); // Printf do menu
void sub_protudos(); //Printf do submenu
void limpar_tela(); //SystemCLS
void visualizar_estoque (item *base, int tam);
int cadastrar_produto(item *base, int tam);
void atualizar_produto (item *base, int tam);
int excluir_produto(item *base, int tam);
void reordena_estoque(item *base, int tam); //buble sort
void realizar_venda(item *base,relatorio *rel, int tam);
void salvar_base(item *base,relatorio *rel, int tam); //Salvar itens
void salvar(item *base, int tam); //Salver cupom fiscal


#endif // SOURCE_H_INCLUDED

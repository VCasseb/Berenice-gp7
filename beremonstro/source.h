#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

void visualizar_estoque (item *vet, int tam);
int cadastrar_produto(item *vet, int tam);
void atualizar_produto (item *vet, int tam);
int excluir_produto(item *vet, int tam);
void reordena_estoque(item *vet, int tam);
void limpar_tela();
void mn_inicial();
void sub_protudos();

#endif // SOURCE_H_INCLUDED

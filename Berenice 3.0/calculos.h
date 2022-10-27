#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED

extern int opc,sub_opc;

//----------Funcoes para o menu iniciar
void mn_inicial(){
    system("cls");
    printf("\n\t\t\t(1) - Produtos");
    printf("\n\t\t\t(2) - Vendas");
    printf("\n\t\t\t(3) - Sair");
    printf("\n\t\t\t---> ");
    scanf("%d",&opc);
    system("cls");
    return;
}

void switch_menu(){ //Swithc para o menu iniciar

    switch(opc){

        case 1:
            sub_produtos();
        break;

        case 2:
            sub_vendas();
        break;
        }

    return;
}

void sub_produtos(){

    printf("\n\t\t\tVoce selecionou Produtos\n");
    do{

        printf("\n\t\t\t(1) - Exibir");
        printf("\n\t\t\t(2) - Cadastrar");
        printf("\n\t\t\t(3) - Atualizar");
        printf("\n\t\t\t(4) - Excluir");
        printf("\n\t\t\t(5) - Salvar");
        printf("\n\t\t\t(6) - Ler");
        printf("\n\t\t\t(7) - Voltar");
        printf("\n\t\t\t---> ");\
        scanf("%d",&sub_opc);
        system("cls");
        if(sub_opc <1 || sub_opc >7){
            printf("\n\t\t\tOpcao Invalida!");
        }
    }while(sub_opc!=7);

    return;
}

void sub_vendas(){

    printf("\n\t\t\tVoce selecionou Vendas\n");

    do{
        printf("\n\t\t\t(1) - Realizar Venda");
        printf("\n\t\t\t(2) - Relatorio de Vendas");
        printf("\n\t\t\t(3) - Voltar");
        printf("\n\t\t\t---> ");\
        scanf("%d",&sub_opc);
        system("cls");
        if(sub_opc <1 || sub_opc >3){
            printf("\n\t\t\tOpcao Invalida!");
        }
    }while(sub_opc!=3);
    return;
}
//----------Funcoes para o menu iniciar





#endif // CALCULOS_H_INCLUDED

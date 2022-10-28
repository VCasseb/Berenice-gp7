#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED

//----------Functions for start menu
void mn_inicial(){

    system("cls");
    printf("\n\t\t\t(1) - Produtos");
    printf("\n\t\t\t(2) - Vendas");
    printf("\n\t\t\t(3) - Sair");
    printf("\n\t\t\t---> ");
    return;
}

int switch_menu(int fopc){ //Switch for start menu

    switch(fopc){

        case 1:
            sub_produtos();
        break;

        case 2:
            sub_vendas();
        break;
        }

    return fopc;
}

void sub_produtos(){

    int sub_opc=0;

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

    int sub_opc=0;

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
//----------Functions start menu


//----------Functions to change the base
void ler_base_txt(){ //To read the base
    FILE *base;

    base = fopen("base.txt","r");

    if(base == NULL){
        printf("Problemas com a base");
        exit(0);
    }

    char txt[1000];

    while(fgets(txt,1000,base)!=NULL){
        printf("%s",txt);
    }
    fclose(base);

    return;
}

void cadastrar_base_txt(){ //To change the base

    FILE *base;

    int x,sair;
    float y;
    char palavra[25];

    base = fopen("base.txt","a");

    if(base == NULL){
        printf("Problemas com a base");
        exit(0);
    }

    printf("digite a qtd item ");
    scanf("%d",&x);
    fprintf(base,"%d\n",x);
    getchar();

    do{
    printf("digite o codigo ");
    scanf("%d",&x);
    fprintf(base,"%d\n",x);
    getchar();

    printf("digite o nome ");
    gets(palavra);
    fprintf(base,"%s\n",palavra);

    printf("digite o valor unitario ");
    scanf("%f",&y);
    fprintf(base,"%f\n",y);

    printf("digite a qtd estoque ");
    scanf("%d",&x);
    fprintf(base,"%d\n",x);

    printf("digite a qtd vendida ");
    scanf("%d",&x);
    fprintf(base,"%d\n\n",x);

    printf("Digite 0 para sair");
    scanf("%d",&sair);
    }while(sair !=0);
    fclose(base);
}
//----------Functions to change the base



#endif // CALCULOS_H_INCLUDED

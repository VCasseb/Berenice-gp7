#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Funcoes
void itens();
float menu(float fsubtt_stock[5]);
int catalogo_inic();
void catalogo(void);
float parcelamento(float total);
float avista(float total);
float itemselec(float fsubtt_qty[5]);
float menu_stock(float fsubtt_stock[5]);
void zerar(); //Inicializar vetores em 0

int opcase,opc;
float subtt[5],subtt_qty[5],estoque[5],subtt_stock[5],subtt_stockva[5];
int nome[5]= {1,2,3,4,5};
float total, quantidade[5],price[] = {7.50,8.69,5.00,4.50,3.25};//subtt[5],subtt_qty[5],estoque[5],subtt_stock[5],subtt_stockva[5];

int main()
{
    setlocale(LC_ALL, "Portuguese");

    zerar();//Inicializar vetores em 0

    do{

    opc = catalogo_inic(); //funcao para switch case
    system("cls");

    switch(opc){
    case 1:
        system("cls");
        printf("\n\t\t\t        -----------Cadastrar estoque----------\n\n");
        itens();
        caso1();
        break;

    case 2:
        printf("\t\t----------Você selecionou Visualizar estoque----------\n\n");
        menu_stock(subtt_stock);
        break;

    case 3:
        printf("\t\t----------Você selecionou Realizar Venda----------\n\n");
        do{ //Loop para selecionar outro produto

        do{
        caso3();
        }while(opc<1 || opc>5);

        itemselec(subtt_qty);

        printf("\n\n\t\tO valor total foi de R$%.2f\n\n",total);
        printf("\t\t--------------------------\n");
        printf("\t\tDeseja selecionar outro produto?\n\t\t(1) - Sim\n\t\t\(2) - Não\n\t\t");
        scanf("%d", &opc);
        getchar();
        system("cls");

    }while(opc  ==1);//Loop para selecionar outro produto

    buble_sort();

    printf("\n\n\t\t-------------------------\n");
    printf("\t\tTotal da compra: R$%.2f",total);
    printf("\n\t\t-------------------------\n\n");
    printf("\n\t\tInsira a Forma de Pagamento\n");;
    printf("\n\t\t(1) Parcelar \n\t\t(2) A vista\n\t\t--->");
    //printf("\n\t\tQual seria a Forma de Pagamento? ");
    scanf("%d",&opc); //Forma de pagamento
    getchar();
    system("cls");

    if (opc == 1){ //Parcelado
        parcelamento(total);
    }//Fim if Parcelado

    if(opc == 2){//A vista
        avista(total);
    }// Fim if A VISTA
    if(opc != 1 && opc !=2){
        printf("\t\tSeleção de pagamento invalido. Selecione opções de 1 a 2\n");
    }//Fim do if da opc invalida de pagamento.
        }

    }while(opc!=4);

    return 0;
}//FIM INT MAIN

void buble_sort()
{

        for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(subtt[i]>subtt[j])//Maior pro menor
            {
                int tempor1 = nome[i];
                int tempor2 = subtt[i];

                subtt[i] = subtt[j];
                nome[i] = nome[j];

                subtt[j] = tempor2;
                nome[j] = tempor1;
            }

        }
    }
    printf("\n\t\t---Itens Selecionados---\n");
    for (int i=0; i<5; i++)
    {
        if(subtt[i]>0)
        {
            //printf("\n\t\t---Itens Selecionados---");
            if(nome[i]==1)
            {
                printf("\n\t\tPao de centeio --- R$%.2f",subtt[i]);
            }
            if(nome[i]==2)
            {
                printf("\n\t\tPao de forma ----- R$%.2f",subtt[i]);
            }
            if(nome[i]==3)
            {
                printf("\n\t\tBroa de Milho ---- R$%.2f",subtt[i]);
            }
            if(nome[i]==4)
            {
                printf("\n\t\tSonho ------------ R$%.2f",subtt[i]);
            }
            if(nome[i]==5)
            {
                printf("\n\t\tTubaina ---------- R$%.2f",subtt[i]);
            }
            //printf("\n\t\t-------------------------");
        }//Fim Cadeia IF
    }//Fim For

}

void zerar()
{


    for(int i=0; i<=5; i++) //Inicializar os valores de subtt_qty como 0 pois o programa estava retornando lixo para as variaveis.
    {
        subtt_qty[i] = 0;
        subtt[i] = 0;
        estoque[i] = 0;
        subtt_stock[i] = 0;
    }

}

void caso1()
{
    printf("\n\t\t\tDigite um item\n\t\t\t--->");
        scanf("%d",&opcase);
        if(opcase == 1)
        {
            printf("\n\t\tDigite a quantidade para Estoque: ");
            scanf("%f",&estoque[0]);
            subtt_stock[0] += estoque[0]; //Somar estoque antigo + atual;
                    if(subtt_stock[0]<=0)
        {
            printf("\n\t\t\tQuantidade inválida");
        }

        }
        else if(opcase == 2)
        {
            printf("\n\t\tDigite a quantidade para Estoque: ");
            scanf("%f",&estoque[1]);
            subtt_stock[1] += estoque[1];
                    if(subtt_stock[1]<=0)
        {
            printf("\n\t\t\tQuantidade inválida");
        }

        }
        else if(opcase == 3)
        {
            printf("\n\t\tDigite a quantidade para Estoque: ");
            scanf("%f",&estoque[2]);
            subtt_stock[2] += estoque[2];
                    if(subtt_stock[2]<=0)
        {
            printf("\n\t\t\tQuantidade inválida");
        }
        }
        else if(opcase == 4)
        {
            printf("\n\t\tDigite a quantidade para Estoque: ");
            scanf("%f",&estoque[3]);
            subtt_stock[3] += estoque[3];
                    if(subtt_stock[3]<=0)
        {
            printf("\n\t\t\tQuantidade inválida");
        }
        }
        else if(opcase == 5)
        {
            printf("\n\t\tDigite a quantidade para Estoque: ");
            scanf("%f",&estoque[4]);
            subtt_stock[4] += estoque[4];
                    if(subtt_stock[4]<=0)
        {
            printf("\n\t\t\tQuantidade inválida");
        }
        }
        else if(opcase <=0 || opcase >=5)
        {
            system("cls");
            printf("\n\t\t\t---Codigo invalido!---\n");
        }
}

void caso3()
{

    opc= menu(subtt_stock); //Chama a funcao do menu de itens disponiveis
        system("cls"); //limpar a tela

        switch(opc)
        {
        case 1:

            printf("\t\t----------Você selecionou Pão de forma----------\n\n");
            printf("\t\tQual seria a quantidade desejada? ");
            scanf("%f",&quantidade[0]); //Quantidade usuario
            getchar();
            subtt[0] = price[0] * quantidade[0];
            subtt_qty[0] += quantidade[0];
            total+=subtt[0];
            subtt_stock[0]-= quantidade[0]; //subtrair estoque a quantidade
                if(subtt_stock[0]<0){
                    printf("\n\t\t\tQuantidade inválida ou insuficiente. Voltando ao menu iniciar...\n");
                    return main();
                    }
            break;

        case 2:
            printf("\t\t----------Você selecionou Pão de centeio----------\n\n");
            printf("\t\tQual seria a quantidade desejada? ");
            scanf("%f",&quantidade[1]); //Quantidade usuario
            getchar();
            subtt[1] = price[1] * quantidade[1];
            subtt_qty[1] += quantidade[1];
            total+=subtt[1];
                    subtt_stock[1]-= quantidade[1]; //subtrair quantidade com o estoque

                if(subtt_stock[1]<0){
                    printf("\n\t\t\tQuantidade inválida ou insuficiente. Voltando ao menu iniciar...\n");
                    return main();}
            break;

        case 3:
            printf("\t\t----------Você selecionou Broa de Milho----------\n\n");
            printf("\t\tQual seria a quantidade desejada? ");
            scanf("%f",&quantidade[2]); //Quantidade usuario
            getchar();
            subtt[2] = price[2] * quantidade[2];
            subtt_qty[2] += quantidade[2];
            total+=subtt[2];
                subtt_stock[2]-= quantidade[2]; //subtrair quantidade com o estoque

                if(subtt_stock[2]<0){
                    printf("\n\t\t\tQuantidade inválida ou insuficiente. Voltando ao menu iniciar...\n");
                    return main();}
            break;

        case 4:
            printf("\t\t----------Você selecionou Sonho----------\n\n");
            printf("\t\tQual seria a quantidade desejada? ");
            scanf("%f",&quantidade[3]); //Quantidade usuario
            getchar();
            subtt[3] = price[3] * quantidade[3];
            subtt_qty[3] += quantidade[3];
            total+=subtt[3];
                subtt_stock[3]-= quantidade[3]; //subtrair quantidade com o estoque

                if(subtt_stock[3]<0){
                    printf("\n\t\t\tQuantidade inválida ou insuficiente. Voltando ao menu iniciar...\n");
                    return main();}
            break;

        case 5:
            printf("\t\t----------Você selecionou Tubaina----------\n\n");
            printf("\t\tQual seria a quantidade desejada? ");
            scanf("%f",&quantidade[4]); //Quantidade usuario
            getchar();
            subtt[4] = price[4] * quantidade[4];
            subtt_qty[4] += quantidade[4];
            total+=subtt[4];
                subtt_stock[4]-= quantidade[4]; //subtrair quantidade com o estoque

                if(subtt_stock[0]<0){
                    printf("\n\t\t\tQuantidade inválida ou insuficiente. Voltando ao menu iniciar...\n");
                    return main();}
            break;
        default:
            printf("\n\t\t\t\tCodigo inválido!\n\n");
        }



}

int catalogo_inic()
{
    int opc;
    printf("\n\t\t\t1. Cadastrar estoque");
    printf("\n\t\t\t2. Visualizar estoque");
    printf("\n\t\t\t3. Realizar Venda");
    printf("\n\t\t\t4. Sair");
    printf("\n\t\t\t--->");
    scanf("%d",&opc);
    getchar();

    return opc;
}

void itens()
{

    printf("\t\t\t\t---------- Catalogo Estoque ----------\n\n");
    printf("\t\t\t\t1 - Pão de forma\n");
    printf("\t\t\t\t2 - Pão de centeio\n");
    printf("\t\t\t\t3 - Broa de milho\n");
    printf("\t\t\t\t4 - Sonho\n");
    printf("\t\t\t\t5 - Tubaína\n\n");


}

float itemselec(float fsubtt_qty[5])
{
    system("cls");
    printf("\n\t\t-----Qtd Selecionada----");
    printf("\n\t\t Pao de Forma   --- %.0fx",fsubtt_qty[0]);
    printf("\n\t\t Pao de Centeio --- %.0fx",fsubtt_qty[1]);
    printf("\n\t\t Broa de Milho  --- %.0fx",fsubtt_qty[2]);
    printf("\n\t\t Sonho          --- %.0fx",fsubtt_qty[3]);
    printf("\n\t\t Tubaina        --- %.0fx",fsubtt_qty[4]);


    printf("\n\t\t-------------------------");
    return 0;
}
float menu_stock(float fsubtt_stock[5])
{

    printf("\t\t\t\t---------- Catalogo Padaria ----------\n\n");
    printf("\t\t\t\t1 - Pão de forma ------ R$7,50 --- %.0fx\n",fsubtt_stock[0]);
    printf("\t\t\t\t2 - Pão de centeio ---- R$8,69 --- %.0fx\n",fsubtt_stock[1]);
    printf("\t\t\t\t3 - Broa de milho ----- R$5,00 --- %.0fx\n",fsubtt_stock[2]);
    printf("\t\t\t\t4 - Sonho ------------- R$4,50 --- %.0fx\n",fsubtt_stock[3]);
    printf("\t\t\t\t5 - Tubaína ----------- R$3,25 --- %.0fx\n\n",fsubtt_stock[4]);



}

float menu(float fsubtt_stock[5])
{
    int opc;
    printf("\t\t\t\t---------- Catalogo Padaria ----------\n\n");
    if(fsubtt_stock[0]>0){
    printf("\t\t\t\t1 - Pão de forma ------ R$7,50 --- %.0fx\n",fsubtt_stock[0]);
    }if(fsubtt_stock[1]>0){
    printf("\t\t\t\t2 - Pão de centeio ---- R$8,69 --- %.0fx\n",fsubtt_stock[1]);
    }if(fsubtt_stock[2]>0){
    printf("\t\t\t\t3 - Broa de milho ----- R$5,00 --- %.0fx\n",fsubtt_stock[2]);
    }if(fsubtt_stock[3]>0){
    printf("\t\t\t\t4 - Sonho ------------- R$4,50 --- %.0fx\n",fsubtt_stock[3]);
    }if(fsubtt_stock[4]>0){
    printf("\t\t\t\t5 - Tubaína ----------- R$3,25 --- %.0fx\n\n",fsubtt_stock[4]);
    }

    printf("\t\t\t\t------Selecione a opção desejada: ");
    scanf("%d",&opc); //Switch e condição do loop
    getchar(); //pra garantir que vai pegar o enter

    return opc;
}

float parcelamento(float total)
{
    float totalfinal,total_parcelas;
    int parcelas;
    do{
    printf("\tQual a quantidade de parcelas? ");
    scanf("%d",&parcelas);
    if(parcelas<1){
        system("cls");
        printf("\n\tNúmero de parcelas inválido, digite um valor acima de 1.\n");
    }
    getchar();
    }while(parcelas <1);
    if(parcelas<=3)  //5% Juros
    {
        totalfinal=total*1.05;
        total_parcelas=totalfinal/parcelas;
    }
    else if (parcelas>3)  //8% Juros
    {
        totalfinal=total*1.08;
        total_parcelas=totalfinal/parcelas;
    }

    system("cls");
    printf("\n\t|------------------NOTA-------------------|\n\n");
    \
    printf("\t|O valor a prazo (%d meses) ficou: R$%.2f\n",parcelas,total_parcelas);
    printf("\t|O valor total das parcelas ficou: R$%.2f\n\n",totalfinal);
    printf("\t|-----------------------------------------|\n");
    return totalfinal;
}

float avista(float total)
{
    float valor_recebido,desconto,troco;
    printf("\n\tO valor total foi de R$%.2f (Sem desconto) \n\n",total);

   // do{
    printf("\n\tPrecisa de troco?\n\n");
    printf("\tInsira seu dinheiro: ");
    scanf("%f",&valor_recebido);

   // if(valor_recebido<total){
   //     printf("\n\tDinheiro Invalido ou insuficiente");
   // }
    //getchar();
    //}while(valor_recebido<total);

    if(total<=50)  //5% Desconto
    {
        desconto=total*0.95;
        troco=valor_recebido-desconto;
    }
    else if(total>50 && total<100)  //10% Desconto
    {
        desconto=total*0.90;
        troco=valor_recebido-desconto;
    }
    else if(total>=100)  //18% Desconto
    {
        desconto=total*0.82;
        troco=valor_recebido-desconto;
    }

    //system("cls");
    printf("\n\t|------------------NOTA-------------------|\n\n");

    printf("\t|Total com desconto: R$%.2f\n",desconto);
    printf("\t|Valor entregue: R$%.2f\n",valor_recebido);
    printf("\t|Troco: R$%.2f\n\n",troco);
    printf("\t|-----------------------------------------|\n");

    if(troco<0)
    {
        printf("\n\t--__-- Ficou faltando R$%.2f --__--\n",troco);
    }

    return 0;
}


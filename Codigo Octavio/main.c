#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Funcoes
void itens();//Catalogo Estoque
void catalogo(void); // funcao n estamos usando
int catalogo_inic(); // menu opcoes 1 a 4
float menu(float fsubtt_stock[5]); //Catalogo Padaria, mostra a quantidade de estoque de cada item
float parcelamento(float total); // funcao do pagamento parcelado
float avista(float total);// funcao pagamento a vista
float itemselec(float fsubtt_qty[5]); //mostra os produtos e quantidades selecionadas no final
float menu_stock(float fsubtt_stock[5]);//mostra os produtos e sua quantidade em estoque

int opcase,opc;
int nome[5]= {1,2,3,4,5};
float subtt[5]={0,0,0,0,0},subtt_qty[5]={0,0,0,0,0},estoque[5]={0,0,0,0,0},subtt_stock[5]={0,0,0,0,0},subtt_stockva[5]={0,0,0,0,0};
float total, quantidade[5],price[] = {7.50,8.69,5.00,4.50,3.25};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    do
    {

        opc = catalogo_inic(); //funcao para switch case
        system("cls");

        switch(opc)
        {
        case 1://Cadastrar stock
            system("cls");
            itens();//Printa as opcoes LINHA 358
            caso1();//Cadastrar estoque LINHA 182
            break;

        case 2://Visualizar Stock
            menu_stock(subtt_stock);//Printa as opcoes e suas quantidades de estoque LINHA 385
            break;

        case 3://Realizar Venda
            do  //Loop para selecionar outro produto
            {

                do //Loop para caso digite uma opcao invalida, seguir o cod ate digitar uma opc correta.
                {
                    caso3();// item/produto selecionado em cada switch case LINHA 245
                }
                while(opc<1 || opc>5);

                itemselec(subtt_qty); //mostra os produtos e quantidades selecionadas no final LINHA 371

                printf("\n\n\t\tO valor total foi de R$%.2f\n\n",total);
                printf("\t\t--------------------------\n");
                printf("\t\tDeseja selecionar outro produto?\n\t\t(1) - Sim\n\t\t\(2) - Nao\n\t\t");
                scanf("%d", &opc);
                getchar();
                system("cls");

            }
            while(opc  ==1); //Loop para selecionar outro produto

            buble_sort(); //ordenar de forma crescente LINHA 115

            printf("\n\n\t\t-------------------------\n");
            printf("\t\tTotal da compra: R$%.2f",total);
            printf("\n\t\t-------------------------\n\n");
            printf("\n\t\tInsira a Forma de Pagamento\n");;
            printf("\n\t\t(1) Parcelar \n\t\t(2) A vista\n\t\t--->");
            scanf("%d",&opc); //Forma de pagamento
            getchar();
            system("cls");

            if (opc == 1)  //Parcelado
            {
                parcelamento(total);//Opc Parcelamento LINHA 431
            }else
                 if(opc == 2) //A vista
                    {
                        avista(total);//Opc A Vista LINHA 468
                    }// Fim if A VISTA

            if(opc != 1 && opc !=2)//Caso a opc n seja 1 ou 2, printar erro
            {
                printf("\t\tSelecao de pagamento invalido. Selecione opcoes de 1 a 2\n");
            }//Fim do if da opc invalida de pagamento.
            for(int i=0;i<5;i++){//foi feito devido a funçao relatorio
                subtt_stockva[i]=subtt_qty[i]; // atribuir qty em stockva
                subtt_qty[i]=0; //zerar variavel quantidade
            }
            total=0;
        }
    }
    while(opc!=4); // caso seja selecionado a opc 4, o programa encerra
    relatorio(); //Printar nota final LINHA 100
    return 0;
}//FIM INT MAIN

void relatorio(){

    system("cls");
    printf("\n\t\t---Itens Selecionados---\n");
    for (int i=0; i<5; i++)
    {
        if(subtt[i]>0) // printar somente itens selecionados
        {
            //printf("\n\t\t---Itens Selecionados---");
            if(nome[i]==1) // se nome for 1, printf pao de centeio
            {
                            printf("\n\t\tPao de centeio --- %.0fx --- R$%.2f",subtt_stockva[i],subtt[i]);
            }else
                if(nome[i]==2)
                {
                            printf("\n\t\tPao de forma --- %.0fx --- R$%.2f",subtt_stockva[i],subtt[i]);
                }else
                    if(nome[i]==3)
                    {
                            printf("\n\t\tBroa de Milho -- %.0fx -- R$%.2f",subtt_stockva[i],subtt[i]);
                    }else
                        if(nome[i]==4)
                        {
                            printf("\n\t\tSonho ---------- %0.fx -- R$%.2f",subtt_stockva[i],subtt[i]);
                        }else
                            if(nome[i]==5)
                            {
                            printf("\n\t\tTubaina -----%0.fx----- R$%.2f",subtt_stockva[i],subtt[i]);
                            }
            //printf("\n\t\t-------------------------");
        }//Fim Cadeia IF
    }
    printf("\n\t\t-------------------------");

}

void buble_sort()
{

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(subtt[i]>subtt[j])//Maior pro menor
            {
                int tempor1 = nome[i]; //variaveis locais, existentes somente nesse if
                int tempor2 = subtt[i];
                int tempor3 = subtt_stockva[i];

                subtt[i] = subtt[j]; //i recebe j, ou seja, posicao seguinte inverte
                nome[i] = nome[j];
                subtt_stockva[i] = subtt_stockva[j];

                subtt[j] = tempor2; // j recebe o q esta na variavel aux, nesse caso tempor2, q vale subtt[i]
                nome[j] = tempor1;
                subtt_stockva[j] = tempor3;
            }

        }
    }
    printf("\n\t\t---Itens Selecionados---\n");
    for (int i=0; i<5; i++)
    {
        if(subtt[i]>0) // printar somente itens selecionados
        {
            //printf("\n\t\t---Itens Selecionados---");
            if(nome[i]==1) // se nome for 1, printf pao de centeio
            {
                printf("\n\t\tPao de centeio --- R$%.2f",subtt[i]);
            }else
                if(nome[i]==2)
                {
                    printf("\n\t\tPao de forma ----- R$%.2f",subtt[i]);
                }else
                    if(nome[i]==3)
                    {
                        printf("\n\t\tBroa de Milho ---- R$%.2f",subtt[i]);
                    }else
                        if(nome[i]==4)
                        {
                            printf("\n\t\tSonho ------------ R$%.2f",subtt[i]);
                        }else
                            if(nome[i]==5)
                            {
                                printf("\n\t\tTubaina ---------- R$%.2f",subtt[i]);
                            }
            //printf("\n\t\t-------------------------");
        }//Fim Cadeia IF
    }//Fim For

}

void caso1()
{
    printf("\n\t\t\t\t----------> Digite um item <----------\n\t\t\t\t--->");
    scanf("%d",&opcase);
    if(opcase == 1)
    {
        printf("\n\t\t\t\tDigite a quantidade para Estoque: ");
        scanf("%f",&estoque[0]);
        subtt_stock[0] += estoque[0];//Somar estoque antigo + atual;
        system("cls");
        if(subtt_stock[0]<=0)
        {
            printf("\n\t\t\tQuantidade inválida");
        }

    }else
        if(opcase == 2)
        {
            printf("\n\t\t\t\tDigite a quantidade para Estoque: ");
            scanf("%f",&estoque[1]);
            subtt_stock[1] += estoque[1];
                if(subtt_stock[1]<=0)
                {
                    printf("\n\t\t\tQuantidade inválida");
                }

        }else
            if(opcase == 3)
            {
                printf("\n\t\t\t\tDigite a quantidade para Estoque: ");
                scanf("%f",&estoque[2]);
                subtt_stock[2] += estoque[2];
                    if(subtt_stock[2]<=0)
                    {
                        printf("\n\t\t\tQuantidade inválida");
                    }
            }else
                if(opcase == 4)
                {
                    printf("\n\t\t\t\tDigite a quantidade para Estoque: ");
                    scanf("%f",&estoque[3]);
                    subtt_stock[3] += estoque[3];
                        if(subtt_stock[3]<=0)
                        {
                        printf("\n\t\t\tQuantidade inválida");
                        }
                }else
                    if(opcase == 5)
                    {
                        printf("\n\t\t\t\tDigite a quantidade para Estoque: ");
                        scanf("%f",&estoque[4]);
                        subtt_stock[4] += estoque[4];
                            if(subtt_stock[4]<=0)
                            {
                                printf("\n\t\t\tQuantidade inválida");
                            }
                    }else
                        if(opcase <=0 || opcase >=5)
                        {
                            system("cls");
                            printf("\n\t\t\t---Codigo inválido!---\n");
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
        if(subtt_stock[0]<0)
        {
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

        if(subtt_stock[1]<0)
        {
            printf("\n\t\t\tQuantidade inválida ou insuficiente. Voltando ao menu iniciar...\n");
            return main();
        }
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

        if(subtt_stock[2]<0)
        {
            printf("\n\t\t\tQuantidade inválida ou insuficiente. Voltando ao menu iniciar...\n");
            return main();
        }
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

        if(subtt_stock[3]<0)
        {
            printf("\n\t\t\tQuantidade inválida ou insuficiente. Voltando ao menu iniciar...\n");
            return main();
        }
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

        if(subtt_stock[4]<0)
        {
            printf("\n\t\t\tQuantidade inválida ou insuficiente. Voltando ao menu iniciar...\n");
            return main();
        }
        break;
    default:
        printf("\n\t\t\t\tCodigo inválido!\n\n");
    }


}

int catalogo_inic()
{
    int opc;
    printf("\t\t\t\t=====================================\n");
    printf("\n\t\t\t\t1. Cadastrar estoque");
    printf("\n\t\t\t\t2. Visualizar estoque");
    printf("\n\t\t\t\t3. Realizar Venda");
    printf("\n\t\t\t\t4. Sair\n\n");
    printf("\t\t\t\t=====================================\n");
    printf("\n\t\t\t\t--->");
    scanf("%d",&opc);
    getchar();

    return opc;
}

void itens()
{

    printf("\t\t\t\t---------- Catalogo Estoque ----------\n\n");
    printf("\t\t\t\t\t1 -> Pao de forma\n");
    printf("\t\t\t\t\t2 -> Pao de centeio\n");
    printf("\t\t\t\t\t3 -> Broa de milho\n");
    printf("\t\t\t\t\t4 -> Sonho\n");
    printf("\t\t\t\t\t5 -> Tubaina\n\n");


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
    printf("\t\t\t\t1 - Pao de forma ------ R$7,50 --- %.0fx\n",fsubtt_stock[0]);
    printf("\t\t\t\t2 - Pao de centeio ---- R$8,69 --- %.0fx\n",fsubtt_stock[1]);
    printf("\t\t\t\t3 - Broa de milho ----- R$5,00 --- %.0fx\n",fsubtt_stock[2]);
    printf("\t\t\t\t4 - Sonho ------------- R$4,50 --- %.0fx\n",fsubtt_stock[3]);
    printf("\t\t\t\t5 - Tubaina ----------- R$3,25 --- %.0fx\n\n",fsubtt_stock[4]);



}

float menu(float fsubtt_stock[5])
{
    int opc;
    printf("\t\t\t\t---------- Catalogo Padaria ----------\n\n");
    if(fsubtt_stock[0]>0)
    {
        printf("\t\t\t\t1 - Pao de forma ------ R$7,50 --- %.0fx\n",fsubtt_stock[0]);
    }
        if(fsubtt_stock[1]>0)
        {
            printf("\t\t\t\t2 - Pao de centeio ---- R$8,69 --- %.0fx\n",fsubtt_stock[1]);
        }
            if(fsubtt_stock[2]>0)
            {
                printf("\t\t\t\t3 - Broa de milho ----- R$5,00 --- %.0fx\n",fsubtt_stock[2]);
            }
                if(fsubtt_stock[3]>0)
                {
                    printf("\t\t\t\t4 - Sonho ------------- R$4,50 --- %.0fx\n",fsubtt_stock[3]);
                }
                    if(fsubtt_stock[4]>0)
                    {
                        printf("\t\t\t\t5 - Tubaina ----------- R$3,25 --- %.0fx\n\n",fsubtt_stock[4]);
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
    do
    {
        printf("\tQual a quantidade de parcelas? ");
        scanf("%d",&parcelas);
        if(parcelas<1)
        {
            system("cls");
            printf("\n\tNúmero de parcelas inválido, digite um valor acima de 1.\n");
        }
        getchar();
    }
    while(parcelas <1);
    if(parcelas<=3)  //5% Juros
    {
        totalfinal=total*1.05;
        total_parcelas=totalfinal/parcelas;
    }
    else
        if (parcelas>3)  //8% Juros
        {
            totalfinal=total*1.08;
            total_parcelas=totalfinal/parcelas;
        }

    system("cls");
    printf("\n\t|------------------NOTA-------------------|\n\n");

    printf("\t|O valor a prazo (%d meses) ficou: R$%.2f\n",parcelas,total_parcelas);
    printf("\t|O valor total das parcelas ficou: R$%.2f\n\n",totalfinal);
    printf("\t|-----------------------------------------|\n");

    return totalfinal;
}

float avista(float total)
{
    float valor_recebido,desconto,troco;
    printf("\n\tO valor total foi de R$%.2f (Sem desconto) \n\n",total);

    printf("\n\t\tPrecisa de troco?\n\t\t( 1 ) - Sim\n\t\t( 2 ) - Nao\n\n\t\t--->");
    scanf("%d",&opc);
    if(total<=50) //5% Desconto
    {
        desconto=total*0.95;
    }
    else if(total>50 && total<100)  //10% Desconto
        {
            desconto=total*0.90;
        }
    else if(total>=100)  //18% Desconto
        {
        desconto=total*0.82;
        }
    switch(opc){
    case 1:
        do{
            printf("\n\t\tDigite o valor recebido: ");
            scanf("%f",&valor_recebido);
            getchar();
            if(valor_recebido<total){
                 printf("\n\tDinheiro Invalido ou insuficiente");
            }
        }while(valor_recebido<total);
    troco=valor_recebido-desconto;
    printf("\n\t|------------------NOTA-------------------|\n\n");

    printf("\t|Total com desconto: R$%.2f\n",desconto);
    printf("\t|Valor entregue: R$%.2f\n",valor_recebido);
    printf("\t|Troco: R$%.2f\n\n",troco);
    printf("\t|-----------------------------------------|\n");
    if(troco<0)
    {
        printf("\n\t--__-- Ficou faltando R$%.2f --__--\n",troco);
    }
    break;

    case 2:

    printf("\n\t|------------------NOTA-------------------|\n\n");
    printf("\t|Total sem desconto: R$%.2f\n",total);
    printf("\t|Total com desconto: R$%.2f\n",desconto);
    printf("\t|-----------------------------------------|\n");
    break;

}
    total=0;

    return 0;
}

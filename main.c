#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Utilizar funcao para mostrar a nota e para o metodo de pagamento
float parcelamento(float total)
{
    float totalfinal,total_parcelas;
    int parcelas;

        printf("\tQual a quantidade de parcelas? ");
        scanf("%d",&parcelas);
        getchar();

        if(parcelas<=3){ //5% Juros
            totalfinal=total*1.05;
            total_parcelas=totalfinal/parcelas;
        }
        else if (parcelas>3){ //8% Juros
                totalfinal=total*1.08;
                total_parcelas=totalfinal/parcelas;
             }

        system("cls");
        printf("\n\t|------------------NOTA-------------------|\n\n");\
        printf("\t|O valor a prazo (%d meses) ficou: R$%.2f\n",parcelas,total_parcelas);
        printf("\t|O valor total das parcelas ficou: R$%.2f\n\n",totalfinal);
        printf("\t|-----------------------------------------|\n");
        return totalfinal;
}

float avista(float total)
{
    float valor_recebido,desconto,troco;
        printf("\n\tO valor total foi de R$%.2f (Sem desconto) \n\n",total);
        printf("\tInsira seu dinheiro: ");
        scanf("%f",&valor_recebido);
        getchar();

        if(total<=50){ //5% Desconto
            desconto=total*0.95;
            troco=valor_recebido-desconto;
        }
            else if(total>50 && total<100){ //10% Desconto
                    desconto=total*0.90;
                    troco=valor_recebido-desconto;
                 }
                    else if(total>=100){ //18% Desconto
                        desconto=total*0.82;
                        troco=valor_recebido-desconto;
                        }

        system("cls");
        printf("\n\t|------------------NOTA-------------------|\n\n");\
        printf("\t|Total com desconto: R$%.2f\n",desconto);
        printf("\t|Valor entregue: R$%.2f\n",valor_recebido);
        printf("\t|Troco: R$%.2f\n\n",troco);
        printf("\t|-----------------------------------------|\n");

        if(troco<0){
            printf("\n\t--__-- Ficou faltando R$%.2f --__--\n",troco);
        }
        return troco;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float total, quantidade,price;
    int opc;
    do{
        printf("\t\t\t\t---------- Catalogo Padaria ----------\n\n");
        printf("\t\t\t\t1 - Pão de forma ------ R$7,50\n");
        printf("\t\t\t\t2 - Pão de centeio ---- R$8,69\n");
        printf("\t\t\t\t3 - Broa de milho ----- R$5,00\n");
        printf("\t\t\t\t4 - Sonho ------------- R$4,50\n");
        printf("\t\t\t\t5 - Tubaína ----------- R$3,25\n\n");

        printf("\t\t\t\t------Selecione a opção desejada: ");
        scanf("%d",&opc); //Switch e condição do loop
        getchar(); //pra garantir que vai pegar o enter
        system("cls"); //limpar a tela

    switch(opc){
        case 1:
            printf("\t\t----------Você selecionou Pão de forma----------\n\n");
            price=7.50;
        break;

        case 2:
            printf("\t\t----------Você selecionou Pão de centeio----------\n\n");
            price=8.69;
        break;

        case 3:
            printf("\t\t----------Você selecionou Broa de Milho----------\n\n");
            price=5.00;
        break;

        case 4:
            printf("\t\t----------Você selecionou Sonho----------\n\n");
            price=4.50;
        break;

        case 5:
            printf("\t\t----------Você selecionou Tubaina----------\n\n");
            price=3.25;
        break;

        default:
            printf("\n\t\tOpção inválida!!! Digite de 1 a 5\n");
            system("cls");
            return 0; //fechar codigo caso opc errada

    }//Fim do switch case

    printf("\t\tQual seria a quantidade desejada? ");
    scanf("%f",&quantidade); //Quantidade usuario
    getchar();
    system("cls");

    total=total+(quantidade*price); //Quantidade * valor do item
    printf("\n\t\tO valor total foi de R$%.2f\n\n",total);
    printf("\t\t--------------------------\n");
    printf("\t\tDeseja selecionar outro produto?\n\t\t(1) - Sim\n\t\t\(2) - Não\n\t\t");
    scanf("%d", &opc);
    getchar();
    }while(opc==1);

    printf("\t\t(1) Parcelar \n\t\t(2) A vista\n");
    printf("\n\t\tQual seria a Forma de Pagamento? ");
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
    return 0;
}

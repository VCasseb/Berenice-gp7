#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float totalfinal,total, quantidade, parcelas, total_parcelas, valor_recebido, troco,desconto, valor_sem_desconto; //VARIAVEIS DO TIPO FLOAT
    int opc,opcao; //VARIAVEIS DO TIPO INTEIRO


    printf("\t\t\t\t---------- Catalogo Padaria ----------\n\n");
    printf("\t\t\t\t1 - Pao de forma ------ R$7,50\n");
    printf("\t\t\t\t2 - Pao de centeio ---- R$8,69\n");
    printf("\t\t\t\t3 - Broa de milho ----- R$5,00\n");
    printf("\t\t\t\t4 - Sonho ------------- R$4,50\n");
    printf("\t\t\t\t5 - Tubaina ----------- R$3,25\n\n");
    printf("\t\t\t\t------Selecione a op��o desejada: ");

    scanf("%d",&opc); //Switch
    getchar();
    system("cls"); //limpar a tela

    switch(opc)
    {
    case 1:
        printf("\t\t----------Voc� selecionou P�o de forma----------\n\n");
        printf("\t\tQual seria a quantidade desejada? ");
        scanf("%f",&quantidade);
        getchar();

                total=quantidade*7.50; //Quantidade * item
                system("cls");

        printf("\t\tO valor total foi de R$%.2f\n\n",total);
        printf("\t\t--------------------------\n",opcao);
        printf("\t\t(1) Parcelar \n\t\t(2) A vista\n",opcao);
        printf("\n\t\tQual seria a Forma de Pagamento? ",opcao);

        scanf("%d",&opcao); //Selecionar forma de Pagamento
        getchar();
        system("cls");
    break;

    case 2:
        printf("\t\t----------Voc� selecionou P�o de centeio----------\n\n");
        printf("\t\tQual seria a quantidade desejada? ");
        scanf("%f",&quantidade);
        getchar();

                total=quantidade*8.69;
                system("cls");

        printf("\n\t\tO valor total foi de R$%.2f\n\n",total);
        printf("\t\t--------------------------\n",opcao);
        printf("\t\t(1) Parcelar \n\t\t(2) A vista\n",opcao);
        printf("\n\t\tQual seria a Forma de Pagamento? ",opcao);

        scanf("%d",&opcao);
        getchar();
        system("cls");
    break;

    case 3:
        printf("\t\t----------Voc� selecionou Broa de Milho----------\n\n");
        printf("\t\tQual seria a quantidade desejada? ");
        scanf("%f",&quantidade);
        getchar();

                total=quantidade*5;
                system("cls");

        printf("\n\t\tO valor total foi de R$%.2f\n\n",total);
        printf("\t\t(1) Parcelar \n\t\t(2) A vista\n",opcao);
        printf("\n\t\tQual seria a Forma de Pagamento? ",opcao);

        scanf("%d",&opcao);
        getchar();
        system("cls");
    break;

    case 4:
        printf("\t\t----------Voc� selecionou Sonho----------\n\n");
        printf("\t\tQual seria a quantidade desejada? ");
        scanf("%f",&quantidade);
        getchar();

                total=quantidade*4.50;
                system("cls");

        printf("\n\t\tO valor total foi de R$%.2f\n\n",total);
        printf("\t\t(1) Parcelar \n\t\t(2) A vista\n",opcao);
        printf("\n\t\tQual seria a Forma de Pagamento? ",opcao);

        scanf("%d",&opcao);
        getchar();
        system("cls");
    break;

    case 5:
        printf("\t\t----------Voc� selecionou Tubaina----------\n\n");
        printf("\t\tQual seria a quantidade desejada? ");
        scanf("%f",&quantidade);
        getchar();

                total=quantidade*3.25;
                system("cls");

        printf("\n\t\tO valor total foi de R$%.2f\n\n",total);
        printf("\t\t(1) Parcelar \n\t\t(2) A vista\n",opcao);
        printf("\n\t\tQual seria a Forma de Pagamento? ",opcao);

        scanf("%d",&opcao);
        getchar();
        system("cls");
    break;
    default:
        printf("\n\t\tOp��o inv�lida!!! Digite de 1 a 5\n");

    }//Fim do switch case

    if (opcao == 1){ //Parcelado
        printf("\tQual a quantidade de parcelas? ");
        scanf("%f",&parcelas);
        getchar();

            if(parcelas<=3){ //5% Juros
                totalfinal=total*1.05;
                total_parcelas=totalfinal/parcelas;
                }
            else
                if (parcelas>3){ //8% Juros
                totalfinal=total*1.08;
                total_parcelas=totalfinal/parcelas;
                }

        system("cls");
        printf("\n\t|------------------NOTA-------------------|\n\n");\
        printf("\t|O valor a prazo (%.0f meses) ficou: R$%.2f\n",parcelas,total_parcelas);
        printf("\t|O valor total das parcelas ficou: R$%.2f\n\n",totalfinal);
        printf("\t|-----------------------------------------|\n");
    }//Fim if Parcelado

    if(opcao == 2) {//A vista

        printf("\n\tO valor total foi de R$%.2f (Sem desconto) \n\n",total);
        printf("\tInsira seu dinheiro: ");
        scanf("%f",&valor_recebido);
        getchar();

                    if(total<=50){ //5% Desconto
                valor_sem_desconto=total*0.05;
                desconto=total-valor_sem_desconto;
                troco=valor_recebido-desconto;
                }
                else
                    if(total>50 && total<100){ //10% Desconto
                        valor_sem_desconto=total*0.10;
                        desconto=total-valor_sem_desconto;
                        troco=valor_recebido-desconto;
                }
                else
                    if(total>=100){ //18% Desconto
                        valor_sem_desconto=total*0.18;
                        desconto=total-valor_sem_desconto;
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
    }//Fim if A VISTA
    return 0;
    }





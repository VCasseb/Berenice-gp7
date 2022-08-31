#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float totalfinal,total, quantidade, total_parcelas, valor_recebido, troco,desconto, valor_sem_desconto,price;
    int opc,parcelas;

    printf("\t\t\t\t---------- Catalogo Padaria ----------\n\n");
    printf("\t\t\t\t1 - Pão de forma ------ R$7,50\n");
    printf("\t\t\t\t2 - Pão de centeio ---- R$8,69\n");
    printf("\t\t\t\t3 - Broa de milho ----- R$5,00\n");
    printf("\t\t\t\t4 - Sonho ------------- R$4,50\n");
    printf("\t\t\t\t5 - Tubaína ----------- R$3,25\n\n");

    printf("\t\t\t\t------Selecione a opção desejada: ");
    scanf("%d",&opc); //Switch
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
        return 0; //fechar codigo caso opc errada
    }//Fim do switch case

    printf("\t\tQual seria a quantidade desejada? ");
    scanf("%f",&quantidade); //Quantidade usuario
    getchar();
    system("cls");

    total=quantidade*price; //Quantidade * valor do item

    printf("\n\t\tO valor total foi de R$%.2f\n\n",total);
    printf("\t\t--------------------------\n");

    printf("\t\t(1) Parcelar \n\t\t(2) A vista\n");
    printf("\n\t\tQual seria a Forma de Pagamento? ");
    scanf("%d",&opc); //Forma de pagamento
    getchar();
    system("cls");

    if (opc == 1){ //Parcelado
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
        }//Fim if Parcelado

    if(opc == 2){//A vista

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
    }//Fim if A VISTA
    return 0;
    }

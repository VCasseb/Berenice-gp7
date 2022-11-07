#include <stdio.h>
#include <stdlib.h>
#include "source.h"
#include "calculos.h"

int main()
{
    int opc;

    do{

    mn_inicial(); //Call start menu
    scanf("%d",&opc); // Option for menu

    opc = switch_menu(opc); //Call Switch Case

    }while(opc != 3);

    return 0;
}

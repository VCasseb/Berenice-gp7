#include <stdio.h>
#include <stdlib.h>
#include "source.h"
#include "calculos.h"

int opc=0,sub_opc=0;

int main()
{

    do{

    mn_inicial(); //Chama o primeiro menu
    switch_menu(); //Chama o Switch Case

    }while(opc != 3);

    return 0;
}

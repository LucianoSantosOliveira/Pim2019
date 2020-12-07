#include "stdlib.h"
#include "stdio.h"
#include "string.h"
///
#include "bd.c"


void main()
{
    inicialogin();

    char Logintemp[4];
    char Senhatemp[4];
    int retorno=1;
    while(retorno==1)
    {
        system("cls");
    printf("Digite o Login:\n");
    fgets(Logintemp,4,stdin);
    fflush(stdin);
    printf("Senha");
    fgets(Senhatemp,4,stdin);
    fflush(stdin);
    if(strcmp(Logintemp,Log[0].Login) == 0)
    {
        system("cls");
        printf("Login efetuado com sucesso");
        retorno = 0;
    }
    else
    {
        system("cls");
        printf("Tente novamente");
        retorno = 1;
    }
  }
}

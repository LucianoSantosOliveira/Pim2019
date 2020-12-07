#include "stdlib.h"
#include "stdio.h"
#include "string.h"
///
#include "bd.c"


void login()
{
    inicialogin();

    char Logintemp[10];
    char Senhatemp[10];
    int retorno = 0;

    printf("Digite o login: ");
    fgets(Logintemp,4,stdin);
    fflush(stdin);
    printf("Digite a senha: ");
    fgets(Senhatemp,4,stdin);
    fflush(stdin);
    if(strcmp(Logintemp,Log[0].Login) == 0)
    {
        main();
    }
    else
    {
        printf("Tente novamente");
    }




}

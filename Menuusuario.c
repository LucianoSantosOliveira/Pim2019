#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "locale.h"
#include "incusuario.c"

void menusuario()
{
    setlocale(LC_ALL, "portuguese");
    system("cls");
    Cabecalho();
    int op;
    SetColor(6);
    printf("USU�RIOS\n");
    SetColor(15);
    printf("____________________________\n");
    printf("[1]...Cadastrar novo usu�rio\n");
    printf("[2]...Consultar lista de usu�rios\n");
    printf("[3]...Excluir usu�rio existente\n");
    printf("[4]...Retornar ao menu principal\n\n");
    printf("Escolha uma op��o: ");
    scanf("%d",&op);
    fflush(stdin);

    switch (op)
    {
    case 1:
        incusuario();
        break;
    case 2:
        listarusuario();
        break;
    case 3:
        deletausuario();
       break;
    }
}

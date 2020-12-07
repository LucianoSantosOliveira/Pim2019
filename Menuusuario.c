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
    printf("USUÁRIOS\n");
    SetColor(15);
    printf("____________________________\n");
    printf("[1]...Cadastrar novo usuário\n");
    printf("[2]...Consultar lista de usuários\n");
    printf("[3]...Excluir usuário existente\n");
    printf("[4]...Retornar ao menu principal\n\n");
    printf("Escolha uma opção: ");
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

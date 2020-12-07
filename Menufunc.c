#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "incfunc.c"
void menufunc()
{
    setlocale(LC_ALL, "portuguese");

    int op;
    system("cls");
    Cabecalho();
    SetColor(6);
    printf("FUNCION�RIOS\n");
    SetColor(15);
    printf("____________________\n");
    printf("[1]...Cadastrar novo funcion�rio\n");
    printf("[2]...Consultar lista de funcion�rios\n");
    printf("[3]...Excluir cadastro existente\n");
    printf("[4]...Retornar ao menu principal");
    scanf("%d",&op);
    fflush(stdin);

    switch(op)
    {
    case 1:
        inclifunc();
        break;
    case 2:
        system("cls");
        SetColor(6);
        printf("LISTA DE FUNCION�RIOS \n");
        SetColor(15);
        printf("________________________\n");
        for (int i=0; i<16; i++)
        {
            if (fun[i].CodFunc==0)
            {
                //printf(" ");
            }
            else if(fun[i].CodFunc>0)
            {
                printf("C�d: %d  Nome:%s \n",fun[i].CodFunc, fun[i].nome);
                printf("Registro:%d\n",fun[i].registro);
                printf("Sal�rio:%f\n\n",fun[i].salario);
            }
        }
        getch();
        break;

    case 3:
        op = 0;
        system("cls");
        printf("Digite o c�digo do funcion�rio que deseja excluir:\n");
        scanf("%d",&op);
        fflush(stdin);

        for(int i=0; i<16; i++)
        {
            if(fun[i].CodFunc == op)
            {
                strcpy(fun[i].nome,"");
                fun[i].CodFunc = 0;
                fun[i].salario = 0;
                fun[i].registro =0;
            }

        }
        printf("Funcion�rio de c�digo:%d deletado",op);
        getch();
        break;

    case 4:
        break;

    default:
        printf("Op��o inv�lida!");
        break;
    }
}

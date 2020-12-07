#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "locale.h"

void inclifunc()
{
    setlocale(LC_ALL, "portuguese");

    int encontrou = 0,pos,fim;
    while(fim!=2)
    {
        for (int i = 0; i<16; i++)
        {
            if (encontrou == 0)
            {
                if (fun[i].CodFunc==0)
                {
                    encontrou = 1;
                    pos = i;
                    fun[i].CodFunc = i+1;
                }
                else
                {
                    pos = -1;
                }
            }
        }
        system("cls");
        Cabecalho();
        printf("Novo cadastro ->\n\n");
		printf("Digite o nome do funcionário: ");
        fgets(fun[pos].nome,31,stdin);
        fflush(stdin);

		printf("Digite o registro do funcionário: ");
		scanf("%d",&fun[pos].registro);
		fflush(stdin);

        printf("Digite o salário: ");
        scanf("%f",&fun[pos].salario);
        fflush(stdin);

        printf("Dados salvos..\n");
        getch();
        printf("Deseja continuar? 1-S 2-N \n");
        scanf("%d",&fim);
    }

}

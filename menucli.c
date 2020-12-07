#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "locale.h"
#include "inccli.c"

void menucli()
{
  setlocale(LC_ALL, "portuguese");
  int codcli,conf;
  int i,op,opc;
  op = 1;
  while(op!=4)
  {
    system("cls");
    Cabecalho();
    SetColor(6);
    printf("CLIENTES\n");
    SetColor(15);
    printf("_______________\n\n");
    printf("[1]...Cadastrar novo cliente\n");
    printf("[2]...Consultar lista de clientes\n");
    printf("[3]...Excluir cadastro existente\n");
    printf("[4]...Retornar ao menu principal\n\n");
    printf("Escolha sua opção: ");
    scanf("%d", &op);

    switch(op)
    {
      case 1:
        inccli();
        break;
      case 2:
        printf("\n");
        for(i=0;i<10;i++)
        {
        	if (cli[i].codcli !=0)
        	{
              printf("Código..: %d\n",cli[i].codcli);
              printf("Nome....: %s\n",cli[i].nomecli);
              printf("Telefone: %s\n\n",cli[i].telcli);
			}
			else if (cli[i].codcli == 0)
			{
				printf(" ");
			}

        }
        getch();
        break;
      case 3:
        delcli();
        getch();
        break;
      case 4:
	    getch();
        break;
      default:
        printf("Opção invalida!");
        getch();
        break;
    }
  }
}

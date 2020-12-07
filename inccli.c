#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "locale.h"

void inccli()
{
  int fim = 0;
  int i,encontrou = 0,pos;
  while(fim!=2)
  {
    //Procura a próxima posição livre no vetor (código = 0)
    for(i=0;i<10;i++)
    {
      if(encontrou == 0)
      {
        if(cli[i].codcli == 0)
        {
          pos = i;
          encontrou = 1;
          cli[i].codcli = i+1;
        }
        else
        {
          pos = -1;
        }
      }
    }
    //analisa se ha posicao livre ou nao
    if(pos<0)
    {
      printf("Não há memória disponível para novo cadastro\n");
      getch();
    }
    else
    {fflush(stdin);
      system("cls");
      printf("Informe os dados do cliente ->\n\n");
      //printf("Codigo..: ");
      //scanf("%d", &cli[pos].codcli);
      fflush(stdin);
      printf("Nome....: ");
      fgets(cli[pos].nomecli,30,stdin);
      printf("Telefone: ");
      fgets(cli[pos].telcli,20,stdin);
    }
    fflush(stdin);
    encontrou = 0;
    printf("Deseja continuar?(1-S/2-N): ");
    scanf("%d", &fim);
  }
}


void delcli()
{
    setlocale(LC_ALL, "portuguese");
	int opc;
	printf("Digite o código do cliente que deseja excluir: ");
	scanf("%d",&opc);

	for (int i=0; i<11; i++)
	{
		if (cli[i].codcli == opc)
		{
			cli[i].codcli = 0;
			strcpy(cli[i].nomecli,"");
			strcpy(cli[i].telcli,"");
		}
	}

}

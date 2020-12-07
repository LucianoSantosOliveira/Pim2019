#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"

void IncliMerc()
{
  int fim = 0;
  int i,encontrou = 0,pos;
  while(fim!=2)
  {fflush(stdin);

    //Procura a próxima posição livre no vetor (código = 0)
    for(i=0;i<10;i++)
    {
      if(encontrou == 0)
      {
        if(Merc[i].CodMerc == 0)
        {
          pos = i;
          encontrou = 1;
          Merc[i].CodMerc = i+1;
        }
        else
        {
          pos = -1;
        }
      }
    }
    //analisa se há posição livre ou não
    if(pos<0)
    {
      printf("Não há memória disponível para novo cadastro\n");
      getch();
    }
    else
    {
      system("cls");
      printf("Informe os dados da mercadoria ->\n\n");
      printf("Inserir nome:\n");
      fgets(Merc[pos].NomMerc,30,stdin);
      fflush(stdin);
      printf("Inserir valor:\n");
      scanf("%f",&Merc[pos].ValorMerc);
      fflush(stdin);

    }
    fflush(stdin);
    encontrou = 0;
    printf("Deseja continuar?(1-S/2-N): ");
    scanf("%d", &fim);
  }
}

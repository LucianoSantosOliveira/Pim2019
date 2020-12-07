#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "locale.h"

void MenuSugestoes()
{
    setlocale(LC_ALL, "portuguese");
    int op;
    printf("[1]...Cadastrar nova sugestão\n");
    printf("[2]...Consultar lista de sugestões\n");
    printf("[3]...Excluir sugestão existente\n\n");
    printf("Escolha uma opção: ");
    scanf("%d",&op);

    switch (op)
    {
        case 1:
            incSugestao();
            break;
        case 2:
            listsug();
            break;
        case 3:
            Delsug();
    }
}


void incSugestao()
{
  setlocale(LC_ALL, "portuguese");
  int encontrou=0,op,fim,pos,GeraCod;
  for(int i=0;i<10;i++)
    {
      if(encontrou == 0)
      {
        if(Sug[i].codSug == 0)
        {
          pos = i;
          encontrou = 1;
          Sug[i].codSug = i+1;
          GeraCod++;
        }
        else
        {
          pos = -1;
        }
      }
    }
    if  (pos<0)
    {
        system("cls");
        Cabecalho();
        printf("Não há memória disponível para novo cadastro!\nPressione uma tecla para continuar...\n");
        getch();
    }else
    {fflush(stdin);

        system("cls");
        Cabecalho();
        printf("Código da sugestão: ");
        scanf("%d",&Sug[pos].codSug);
        fflush(stdin);
        printf("Nome do cliente: ");
        fgets(Sug[pos].NomCli,30,stdin);
        fflush(stdin);
        printf("Insira a crítica ou sugestão->\n");
        fgets(Sug[pos].SugeCri,200,stdin);
        fflush(stdin);
    }
}


void listsug()
{
    system("cls");
    Cabecalho();
    SetColor(6);
    printf("LISTA DE SUGESTÕES\n");
    SetColor(15);
    printf("_______________________\n");
    setlocale(LC_ALL, "portuguese");
    for (int i=0; i<10; i++)
    {
        if (Sug[i].codSug>0)
        {
            printf("Código: %d\n",Sug[i].codSug);
            printf("Nome do cliente: %s\n",Sug[i].NomCli);
            printf("Sugestão: %s\n\n\n",Sug[i].SugeCri);
        }

    }
    printf("Pressione uma tecla para continuar...\n");
    getch();

}



void Delsug()
{
    system("cls");
    Cabecalho();
    setlocale(LC_ALL, "portuguese");
    int opc;
    printf("Digite o código da sugestão que deseja excluir: ");
    scanf("%d",&opc);
    for (int i=0; i<10; i++)
    {
        if (Sug[i].codSug == opc)
        {
            Sug[i].codSug = 0;
            strcpy(Sug[i].NomCli,"");
            strcpy(Sug[i].NomCli,"");
        }
    }
}

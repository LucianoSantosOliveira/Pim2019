#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "locale.h"

void menuMaterias()
{
    setlocale(LC_ALL, "portuguese");
    Cabecalho();
    int op,encontrou=0,pos,fim=0,Metrica,i,hold;
    float Qtd;
    printf("[1]...Cadastrar nova matéria prima\n");
    printf("[2]...Consultar lista de matérias primas\n");
    printf("[3]...Excluir materia prima existente\n");
    printf("[4]...Adicionar estoque\n");
    printf("[5]...Retornar ao menu principal\n\n");
    printf("Escolha uma opção: ");
    scanf("%d",&op);

    switch (op)
    {
    case 1:
        while (fim!=2)
        {
            for (int i=0; i<10; i++)
            {
        if(encontrou == 0)
      {
        if(Estoq[i].codigoEstoq == 0)
        {
          pos = i;
          encontrou = 1;
          Estoq[i].codigoEstoq = i+1;
        }
        else
        {
          pos = -1;
        }
      }
    }
    if (pos<0)
    {
        system("cls");
        Cabecalho();
        printf("Não há memória disponível para novo cadastro\n");
    }else
    {
        system("cls");
        Cabecalho();
        printf("Tipo de contagem (1-Unidade 2-Quilo): ");
        scanf("%d",&Metrica);
        fflush(stdin);
        printf("Digite o nome da matéria prima: ");
        fgets(Estoq[pos].NomeMateria,20,stdin);
        fflush(stdin);
        printf("Digite a quantidade: ");
        if (Metrica==1)
        {
            scanf("%f",&Estoq[pos].Kilo);
            //Estoq[pos].Kilo = 0;

        }else if (Metrica >1)
        {
            scanf("%f",&Estoq[pos].Kilo);
            //Estoq[pos].Unidade = 0;
        }
        printf("\nNovo cadastro S-1 2-N: ");
        encontrou = 0;
        scanf("%d",&fim);
    }
   }
   break;

    case 2:
        system("cls");
        Cabecalho();
        SetColor(6);
        printf("ESTOQUE DE MATÉRIAS PRIMAS\n");
        SetColor(15);
        printf("______________________________\n");
        for (int i=0; i<10; i++)
        {
            if (Estoq[i].codigoEstoq>0)
            {
              printf("Código:%d\n",Estoq[i].codigoEstoq);
              printf("Nome: %s\n",Estoq[i].NomeMateria);
              printf("Quantidade: %f\n\n",Estoq[i].Kilo);
           }
        }
        getch();
        break;

    case 4:
        system("cls");
        Cabecalho();

        SetColor(6);
        printf("ESTOQUE DE MATÉRIAS PRIMAS\n");
        SetColor(15);
        printf("______________________________\n");
        for (int i=0; i<10; i++)
        {
            if (Estoq[i].codigoEstoq>0)
            {
              printf("Código:%d\n",Estoq[i].codigoEstoq);
              printf("Nome: %s\n",Estoq[i].NomeMateria);
              printf("Quantidade: %f\n\n",Estoq[i].Kilo);
           }
        }
        printf("Digite o codigo da materia prima para adicionar ao estoque\n");
        scanf("%d",&op);
        system("cls");
        for (int i=0; i<10; i++)
        {
            if(Estoq[i].codigoEstoq==op)
            {
                hold = i;
            }
        }
        printf("Digite a Quantidade que deseja adicionar:\n");
        scanf("%f",&Qtd);
        Estoq[hold].Kilo = Estoq[hold].Kilo + Qtd;
        break;



  }
}

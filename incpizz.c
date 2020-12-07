#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "locale.h"


void incpizz()
{

    setlocale(LC_ALL, "portuguese");
    int i,encontrou=0,pos,fim=0,op;
    fflush(stdin);

     while(fim !=2 )
    {
        for (i=0; i<11; i++)
        {
            if (encontrou==0)
        {
            if (pizza[i].cod_pizza == 0)
            {
                pos = i;
                encontrou = 1;
                pizza[i].cod_pizza = i+1;
            }
            else
        {
            pos = -1;
        }
        }


        }
        if (pos<0)
        {
            printf("Não há memória disponível para novo cadastro\n");
            getch();
        }
        else
        {
            printf("Novo cadastro ->\n\n");
            printf("Insira o nome da pizza: ");
            fgets(pizza[pos].nome_pizza,30,stdin);
            fflush(stdin);
            printf("Insira o valor da pizza: ");
            scanf("%f",&pizza[pos].ValorPizza);
            SetColor(2);
            printf("Digite qual materia prima é utilizada na pizza pelo codigo\n");
            SetColor(7);
            //lista as materias primas;

             for (int i=0; i<10; i++)
             {
                 if (Estoq[i].codigoEstoq>0)
                 {
                     printf("Codigo:%d\n",Estoq[i].codigoEstoq);
                     printf("Nome:%s\n",Estoq[i].NomeMateria);
                     printf("---------------------------------\n");

                 }

             }
            scanf("%d",&pizza[pos].OpcMat);
            printf("Digite a quantidade que sera utilizada em cada pizza\n");
            scanf("%f",&pizza[pos].MatPrima);
            fflush(stdin);
        }
        fflush(stdin);
        encontrou = 0;
        printf("Novo cadastro ?(s=1/n=2)\n");
        scanf("%d",&fim);
        fflush(stdin);

    }

}

void delpizz()
{
    setlocale(LC_ALL, "portuguese");
	int opc;
    	printf("Digite o código da pizza que deseja excluir: ");
    	scanf("%d",&opc);
    	for (int i=0; i<11; i++)
    	{
    		if(pizza[i].cod_pizza==opc)
    		{
    			pizza[i].cod_pizza = 0;
    			strcpy(pizza[i].nome_pizza,"");

			}
		}
}

void iniciapizza()
{

}

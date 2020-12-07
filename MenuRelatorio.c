#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "locale.h"

void menuRelatorio()
{
    setlocale(LC_ALL, "portuguese");
    Cabecalho();
    int op,pos=0,Codpizz;
    float Hold;
    printf("RELATÓRIOS\n");
    SetColor(15);
    printf("____________________________\n");
    printf("[1]...Relatório diário\n");
    printf("[2]...Relatório mensal\n");
    printf("[3]...Pizza mais vendida\n");
    printf("[4]...Unidade de maior lucro\n\n");
    printf("Escolha uma opção: ");
    scanf("%d",&op);

    switch (op)
    {
    case 1:
        system("cls");
        Cabecalho();
        printf("Valor do faturamento diário: %f\n\n",Rela[Estab].ValDia);
        Rela[Estab].ValDia = 0;
        printf("Pressione uma tecla para retornar ao menu principal\n");
        getch();
        break;

    case 2:
        system("cls");
        Cabecalho();
        printf("Valor do faturamento mensal: %f\n\n",Rela[Estab].ValMens);
        Hold = Rela[Estab].ValMens;
        Rela[Estab].ValMens = 0;
        printf("Pressione uma tecla para retornar ao menu principal\n");
        getch();
        break;

    case 3:
        for(int i=0; i<10; i++)
        {
            if (i==0)
            {
                pos=0;

            }else if(i>0)
            {
                pos++;
            }

        for (int i=0; i<10; i++)
        {
            if(pizza[pos].ContPizza>pizza[i].ContPizza)
            {
                Codpizz = pos;
            }
        }
        }
        system("cls");
        Cabecalho();
        printf("Pizza mais vendida: %s\n\n",pizza[Codpizz].nome_pizza);
        printf("Pressione uma tecla para retornar ao menu principal\n");
        getch();
        break;

    case 4:
        system("cls");
        Cabecalho();
        if (Rela[0].ValMens>Rela[1].ValMens && Rela[0].ValMens>Rela[2].ValMens)
        {
            printf("Unidade que mais faturou: 1");

        }else if (Rela[1].ValMens>Rela[0].ValMens && Rela[1].ValMens>Rela[2].ValMens)
        {
            printf("Unidade que mais faturou: 2");
        }else if(Rela[2].ValMens>Rela[0].ValMens && Rela[2].ValMens>Rela[1].ValMens)
        {
            printf("Unidade que mais faturou: 3");
        }
        getch();
        break;

    }//switch
}

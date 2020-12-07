#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "locale.h"
#include "incvenda.c"


void MenuVendas()
{
    int op,verifica=0;
    printf("[1]...Nova venda\n");
    printf("[2]...Consultar vendas\n");
    printf("[3]...Finalizar venda\n");
	printf("[4]...Retornar ao menu principal\n\n");
	printf("Escolha uma opção: ");
    scanf("%d",&op);

    switch (op)
    {
    case 1:
        system("cls");
        incvend();
        break;
    case 2:
        system("cls");
        Cabecalho();
        for (int i=0; i<10; i++)
        {
            if(venda[i].SenhaVend == 0)
            {
                verifica = 1;
            }
            else if(venda[i].SenhaVend!=0)
            {
                printf("Senha do pedido: %d\n",venda[i].SenhaVend);
                printf("Nome do cliente: %s\n",venda[i].nomeCliVen);
                printf("Telefone do cliente: %s\n",venda[i].TelCliVend);
                printf("Valor da pizza: %f | Pizza comprada: %s\n",venda[i].ValorPizzaVen,venda[i].nomePizzaVen);
                printf("Valor da mercadoria comprada: %f\n",venda[i].ValorMercVend);
                printf("Valor TOTAL DA COMPRA: %f\n\n",venda[i].ValorTotalVend);
                printf("-------------------------------------------------------\n");
            }
        }
        if (verifica==1)
        {
            //printf("Não há vendas\n");
        }
        getch();
            break;
    case 3:
        delvend();
        break;
    case 4:
		break;
    default:
        printf("Opção inválida");
        break;

    }
}

#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "locale.h"



void incvend()
{
  setlocale(LC_ALL, "portuguese");
  int fim = 0;
  int i,encontrou = 0,pos,opc;
  int senha = 0;
  while(fim!=2)
  {
    //Procura a próxima posição livre no vetor (código = 0)
    for(i=0;i<10;i++)
    {
      if(encontrou == 0)
      {
        if(venda[i].venda_cod == 0)
        {
          pos = i;
          encontrou = 1;
          venda[pos].SenhaVend  = i+1;
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
    {
      //coloca senha no pedido
      system("cls");
      Cabecalho();
      printf("Informe os Dados da venda\n");
      printf("__________________________\n\n");

      //Lista os clientes cadastrados;
      system("cls");
      Cabecalho();
      SetColor(6);
      printf("CLIENTES CADASTRADOS\n");
      SetColor(15);
      printf("____________________________\n");
      for(i=0;i<10;i++)
        {
        	if (cli[i].codcli !=0)
        	{
              printf("Código..: %d\n",cli[i].codcli);
              printf("Nome....: %s\n",cli[i].nomecli);
              printf("Telefone: %s\n\n",cli[i].telcli);
			}
        }

      ///Pergunta qual cliente deseja incluir;
      SetColor(15);
      printf("Código do cliente: \n");
      scanf("%d",&opc);
      int guadaPos;

      ///Incluir o cliente no pedido;
      for (i=0; i<10; i++)
      {fflush(stdin);
          if(cli[i].codcli == opc)
          {
              guadaPos = i;
          }
      }opc=0;
      venda[pos].venda_cod = cli[guadaPos].codcli;
      strcpy(venda[pos].nomeCliVen,cli[guadaPos].nomecli);
      strcpy(venda[pos].TelCliVend,cli[guadaPos].telcli);






      ///lista as pizzas
      system("cls");
      Cabecalho();
      SetColor(6);
      printf("Pizzas Cadastradas\n");
      SetColor(15);
      printf("_________________________________\n");
      for (int i=0; i<10; i++)

        {
        	if (pizza[i].cod_pizza==0)
        	{
        		//printf("Nao há cadastros...\n");
			}
			else if (pizza[i].cod_pizza != 0 )
			{
        		printf("Nome:%s \n", pizza[i].nome_pizza);
                printf("Código:%d \n",pizza[i].cod_pizza);
                printf("Valor da pizza:%f \n\n",pizza[i].ValorPizza);
			}
        }
        ///Pergunta qual pizza foi comprada
      printf("Código da pizza comprada: ");
      scanf("%d",&opc);
      ///Coloca os dados da pizza no pedido;
      for (i=0; i<10; i++)
      {fflush(stdin);
          if(pizza[i].cod_pizza == opc)
          {
              venda[pos].ValorPizzaVen = pizza[i].ValorPizza;
              strcpy(venda[pos].nomePizzaVen, pizza[i].nome_pizza);
              pizza[i].ContPizza = pizza[i].ContPizza + 1;
              Estoq[i].Kilo =  Estoq[i].Kilo - pizza[i].MatPrima ;
          }

      }opc=0;



      ///lista as mercadorias;
      system("cls");
      Cabecalho();
      printf("LISTA DE MERCADORIAS\n");
      printf("__________________________\n");
      for (i=0; i<10; i++)
        {
            if (Merc[i].CodMerc !=0)
            {
                printf("Nome:%s\n",Merc[i].NomMerc);
                printf("Código:%d\n",Merc[i].CodMerc);
                printf("Valor:%f\n\n",Merc[i].ValorMerc);
            }
        }

      printf("Insira o código da mercadoria:");
      scanf("%d",&opc);

      for(i=0; i<10; i++)
      {
          if(Merc[i].CodMerc == opc)
          {
              strcpy(Merc[i].NomMerc,venda[pos].NomMercVend);
               venda[pos].ValorMercVend = Merc[i].ValorMerc;
          }

      }

    }
    venda[pos].ValorTotalVend = (venda[pos].ValorPizzaVen + venda[pos].ValorMercVend);

    fflush(stdin);
    encontrou = 0;
    printf("Deseja efetuar mais um pedido?(1-S/2-N): ");
    scanf("%d", &fim);

  }
}







void delvend()
{
	int opc;
	float Money,Troco;
	printf("Digite a senha do pedido que deseja finalizar: ");
	scanf("%d",&opc);

	for (int i=0; i<11; i++)
	{
		if (venda[i].SenhaVend == opc)
		{
		    venda[i].ValorTotalRela = venda[i].ValorTotalVend + venda[i].ValorTotalRela;
            printf("\nSenha do pedido: %d\n",venda[i].SenhaVend);
            printf("Nome do cliente: %s\n",venda[i].nomeCliVen);
            printf("Telefone do cliente: %s\n",venda[i].TelCliVend);
            printf("Valor da pizza: %f |Pizza comprada: %s\n",venda[i].ValorPizzaVen,venda[i].nomePizzaVen);
            printf("Valor da mercadoria comprada: %f\n\n",venda[i].ValorMercVend);
            printf("-------------------------------------------------------------\n");
            printf("Valor total da compra: %f\n",venda[i].ValorTotalVend);
            printf("Digite o valor dado pelo cliente: ");
		    scanf("%f",&Money);
		    ///soma o valor da venda no relatorio diario
		    Rela[Estab].ValDia = venda[i].ValorTotalVend + Rela[Estab].ValDia;
		    Rela[Estab].ValMens = Rela[Estab].ValDia + Rela[Estab].ValMens;
		    Troco = Money-venda[i].ValorTotalVend;
		}
	}

	SetColor(2);
	printf("\nTroco:%f\n",Troco);
   for (int i=0; i<11; i++)
   {
     if (venda[i].SenhaVend == opc)
     {
      venda[i].SenhaVend = 0;
      strcpy(venda[i].nomeCliVen,"");
      strcpy(venda[i].TelCliVend,"");
      venda[i].venda_cod = 0;
      venda[i].ValorPizzaVen = 0;
      strcpy(venda[i].nomePizzaVen ,"");
      strcpy(venda[i].NomMercVend ,"");
      venda[i].ValorMercVend = 0;
      venda[i].ValorTotalVend = 0;
      getch();
    }
  }
}

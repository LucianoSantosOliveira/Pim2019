#include "stdlib.h"
#include "stdio.h"

///
#include "incpizz.c"
void menupizza()
{
    int VerificaCadastro=0;
    system("cls");
    Cabecalho();
    SetColor(6);
    printf("PIZZAS");
    SetColor(15);
    printf("_________________\n");
    int op;
    printf("[1]...Cadastrar nova pizza\n");
    printf("[2]...Consultar lista de sabores\n");
    printf("[3]...Excluir sabor existente\n");
    printf("[4]...Retornar ao menu principal\n");
    scanf("%d",&op);

    switch (op)
    {
    case 1:
    incpizz();
    break;
    case 2:
        system("cls");
        Cabecalho();
        SetColor(6);
        printf("LISTA DE SABORES\n");
        SetColor(15);
        printf("____________________\n");
        for (int i=0; i<10; i++)
        {
              if (pizza[i].cod_pizza != 0 )
			{
        		printf("Nome:%s \n", pizza[i].nome_pizza);
                printf("Código:%d \n",pizza[i].cod_pizza);
                printf("Valor da pizza:%f \n",pizza[i].ValorPizza);
                printf("-------------------------------------------\n");
			}else if(pizza[i].cod_pizza==0)
			{
			    VerificaCadastro++;
			}
        }
        if (VerificaCadastro == 9)
        {
            printf("Nao tem cadastro\n");
        }
        getch();

        break;

    case 3:
    	delpizz();
    	break;
    case 4:
        break;
    default:
        printf("Opção Inválida!\n");
        break;

    }
}

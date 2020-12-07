#include "stdlib.h"
#include "conio.h"
#include "stdio.h"
#include "string.h"
#include "locale.h"
#include "IncMercadoria.c"

void menuMercadoria()
{system("cls");

    setlocale(LC_ALL, "portuguese");
    int op;
    Cabecalho();
    SetColor(6);
    printf("MERCADORIAS\n");
    SetColor(15);
    printf("__________________________\n");
    printf("[1]...Cadastrar nova mercadoria\n");
    printf("[2]...Consultar lista de mercadorias\n");
    printf("[3]...Excluir mercadoria existente\n");
    printf("[4]...Retornar ao menu principal");
    scanf("%d",&op);
    fflush(stdin);



    switch (op)
    {
    case 1:
        IncliMerc();
        getch();
        break;
    case 2:
        system("cls");
        SetColor(6);
        printf("LISTA DE MERCADORIAS");
        SetColor(15);
        printf("______________________\n\n");
        for (int i=0; i<10; i++)
        {
            if (Merc[i].CodMerc == 0)
            {
                printf(" ");
            }else
            {
                printf("Nome:%s\n",Merc[i].NomMerc);
                printf("Código:%d\n",Merc[i].CodMerc);
                printf("Valor:%f\n\n",Merc[i].ValorMerc);
            }

        }
        printf("Pressione uma tecla para continuar...\n");
        getch();
        break;
    case 3:
        op=0;
        printf("Insira o código da mercadoria que deseja deletar: ");
        scanf("%d",&op);
        for (int i=0; i<10; i++)
        {
            if (Merc[i].CodMerc == op)
            {
                strcpy(Merc[i].NomMerc,"");
                Merc[i].ValorMerc = 0;
                Merc[i].CodMerc = 0;
            }
        }
        break;

    case 4:
        break;
    default:
        printf("Opção inválida!");
        break;

     }
}

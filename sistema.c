//////Bibliotecas padrões
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "locale.h"

///// Programa que contem os dados
#include "bd.c"

///cabeçalho
#include "cabecalho.c"

///// Demais módulos do Sistema
#include "menucli.c"
#include "Menupizza.c"
#include "Menufunc.c"
#include "MenuMercadoria.c"
#include "MenuRelatorio.c"
#include "MenuVendas.c"
#include "Menuusuario.c"
#include "MenuSugestoes.c"
#include "MenuMaterias.c"

int VerificaLogin,CommonUser,FirstLog;
void main()
{
   setlocale(LC_ALL, "portuguese");
   if(VerificaLogin==0)
   {
       login();
   }

   if (CommonUser==1)
    {
        MenuRestrito();
    }
   ///Pergunta qual é o estabelecimento
  int op;
  system("cls");
  Cabecalho();
  printf("[1]...Estabelecimento 1\n");
  printf("[2]...Estabelecimento 2\n");
  printf("[3]...Estabelecimento 3\n\n");
  printf("Digite o código do estabelecimento: ");
  scanf("%d",&Estab);
  fflush(stdin);

  iniciabdcli();
  inserirdados();

  while(op!=11)
  {
    system("cls");
    Cabecalho();
    SetColor(2);
    printf("[ Estabelecimento: %d ]   [ Modo: Admistrativo ]",Estab);
    printf("  [TOTALIZADOR DIÁRIO R$:%.2f]\n\n",Rela[Estab].ValDia);
    SetColor(7);
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("[1]...Clientes\n");
    printf("[2]...Pizzas\n");
    printf("[3]...Funcionários\n");
    printf("[4]...Mercadorias\n");
    printf("[5]...Relatórios\n");
    printf("[6]...Vendas\n");
    printf("[7]...Usuários\n");
    printf("[8]...Sugestões\n");
    printf("[9]...Matérias primas\n");
    printf("[10]..Entrar com outro usuário\n");
    printf("[11]..Sair\n\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    switch(op)
    {
      case 1:
          printf("\nIniciando o menu de clientes...");
          Sleep(500);
          system("cls");
          menucli();
          break;
      case 2:
          printf("\nIniciando o menu de pizzas...");
          Sleep(500);
          system("cls");
          menupizza();
          break;
      case 3:
          printf("\nIniciando o menu de funcionários...");
          Sleep(500);
          system("cls");
          menufunc();
          break;
      case 4:
          printf("\nIniciando o menu de mercadorias...");
          Sleep(500);
          system("cls");
          menuMercadoria();
          break;
      case 5:
          printf("\nIniciando o menu de relatórios..");
          Sleep(500);
          system("cls");
          menuRelatorio();
          break;
      case 6:
          printf("\nIniciando o menu de vendas...");
          Sleep(500);
          system("cls");
          MenuVendas();
          break;
      case 7:
          printf("\nIniciando o menu de usuários...");
          Sleep(500);
          system("cls");
          menusuario();
          break;
      case 8:
          printf("\nIniciando o menu de sugestões...");
          Sleep(500);
          system("cls");
          MenuSugestoes();
          break;
      case 9:
          printf("\nIniciando o menu de matérias primas...");
          Sleep(500);
          system("cls");
          menuMaterias();
          break;
      case 10:
          system("cls");
          login();
          break;
      case 11:
          printf("\nSaindo do programa...");
          Sleep(500);
         break;
      default:
          printf("Opção inválida!");
          break;
    }//switch
  }//while
}//void


void MenuRestrito()
{
    CommonUser = 1;
    int op;
    system("cls");
    Cabecalho();
    SetColor(2);
    printf("[ Estabelecimento: %d ]   [ Modo: Usuario comum ]\n\n",Estab);
    SetColor(7);
    printf("-------------------------------------------------------------\n");
    printf("[1]...Clientes\n");
    printf("[2]...Pizzas\n");
    //printf("[3]...Funcionários\n");
    printf("[4]...Mercadorias\n");
    //printf("[5]...Relatórios\n");
    printf("[6]...Vendas\n");
    //printf("[7]...Usuários\n");
    printf("[8]...Sugestões\n");
    printf("[9]...Matérias primas\n");
    printf("[10]..Entrar com outro usuário\n\n");
    printf("Escolha uma opção: ");
    scanf("%d",&op);
    switch(op)
    {
      case 1:
          printf("\nIniciando o menu de clientes...");
          Sleep(500);
          system("cls");
          menucli();
          break;
      case 2:
          printf("\nIniciando o menu de pizzas...");
          Sleep(500);
          system("cls");
          menupizza();
          break;
      //case 3:
          //printf("\nIniciando o menu de funcionários...");
          //Sleep(500);
          //system("cls");
          //menufunc();
          //break;
      case 4:
          printf("\nIniciando o menu de mercadorias...");
          Sleep(500);
          system("cls");
          menuMercadoria();
          break;
      //case 5:
        // printf("\nIniciando o menu de relatórios..");
          //Sleep(500);
          //system("cls");
          //menuRelatorio();
          //break;
      case 6:
          printf("\nIniciando o menu de vendas...");
          Sleep(500);
          system("cls");
          MenuVendas();
          break;
      //case 7:
        //printf("\nIniciando o menu de usuários...");
          //Sleep(500);
          //system("cls");
          //menusuario();
          //break;
      case 8:
          printf("\nIniciando o menu de sugestões...");
          Sleep(500);
          system("cls");
          MenuSugestoes();
          break;
      case 9:
          printf("\nIniciando o menu de matérias primas...");
          Sleep(500);
          system("cls");
          menuMaterias();
          break;
      case 10:
          system("cls");
          login();
          break;
      case 11:
          printf("\nSaindo do programa...");
          Sleep(500);

         system("exit");
         break;
      default:
          printf("Opção inválida!");
          break;
    }//switch

}



void login()
{
    ///login

    int verificalogin=1;


    while(verificalogin == 1)
    {
        inicialogin();
        //printf("______________________________\n");
        system("cls");

    char Logintemp[4];
    char Senhatemp[4];
    Cabecalho();
    printf("LOGIN E SENHA PADRAO: adm e adm\n");
    printf("________________________________\n");

    printf("Digite o Login: ");
    fgets(Logintemp,4,stdin);
    fflush(stdin);

    printf("Digite a Senha: ");
    fgets(Senhatemp,4,stdin);
    fflush(stdin);

    for(int i=0; i<11; i++)
    {
        if (strcmp(Logintemp,Log[i].Login)==0 && strcmp(Log[i].Senha,Senhatemp)==0)
        {fflush(stdin);
            system("cls");
            Cabecalho();
            SetColor(15);
            printf("Pressione uma tecla para continuar...");
            //verificalogin = 0;
            VerificaLogin = 1;
            getch();
            if (Log[i].Restrict == 0)
            {
                main();
                CommonUser = 0;

            }else if(Log[i].Restrict == 1)
            {
                MenuRestrito();
                CommonUser = 1;
            }
        }
    }
    if (verificalogin==1)
    {
        system("cls");
        Cabecalho();
        SetColor(4);
        printf("LOGIN INCORRETO\n");
        SetColor(15);
        printf("Pressione uma tecla para tentar novamente...");
        getch();
    }
   }//while
}

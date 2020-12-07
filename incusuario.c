#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "locale.h"


void incusuario()
{
  int fim = 0;
  int i,encontrou = 0,pos;
  while(fim!=2)
  {
    //Procura a próxima posição livre no vetor (código = 0)
    for(i=0;i<10;i++)
    {
      if(encontrou == 0)
      {
        if(cli[i].codcli == 0)
        {
          pos = i;
          encontrou = 1;
          Log[i].CodUsu = i+1;
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
        printf("Novo cadastro ->\n");
        printf("___________________________\n\n");
        printf("Digite um login para o novo usuário com até 4 caracteres: \n");
        fgets(Log[pos].Login,4,stdin);
        fflush(stdin);
        printf("Digite uma senha de até 4 caracteres: \n");
        fgets(Log[pos].Senha,4,stdin);
        fflush(stdin);
        getch();
    }
    system("cls");
    printf("deseja continuar? 1-S 2-N\n");
    scanf("%d",&fim);
  }
}

void deletausuario()
{
    setlocale(LC_ALL, "portuguese");
    int op;
    char LoginTemp[4];
    printf("\n\nDigite o login do usuário que deseja excluir: ");
    fgets(LoginTemp,4,stdin);
    for (int i=0; i<10; i++)
    {
        if(strcmp(LoginTemp,Log[i].Login)==0)
        {
            strcpy(Log[i].Login,"");
            strcpy(Log[i].Senha,"");
        }
    }
    printf("Deletado com sucesso\n");
    getch();

}


void listarusuario()
{
    setlocale(LC_ALL, "portuguese");
    system("cls");
    Cabecalho();
    SetColor(6);
    printf("LISTA DE USUÁRIOS:\n");
    SetColor(15);
    printf("_____________________\n\n");
    for (int i=0; i<10; i++)
    {
        if(Log[i].CodUsu>0)
        {
        printf("Login:%s\n",Log[i].Login);
        printf("Senha:%s\n\n",Log[i].Senha);
        }
    }
    getch();
}

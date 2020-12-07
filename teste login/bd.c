#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

/*Arquivo de Banco de Dados em C
  Contem  estruturas e vetores dos modelos de dados
  que serão usados no sistema de pizzaria.
  Aqui, serao criadas todas as estruturas, variáveis
  globais e vetores utilizados no sistema.
  Este arquivo deverá ser importado nos demais módulos
  sistêmicos onde os dados serão tratados.
*/

typedef struct
{
	char Login[4];
	char Senha[4];
}logar;

typedef struct{
  int  codcli;
  char nomecli[31],telcli[21];
}Cliente;

typedef struct{
  char nome_pizza[30];
  int  cod_pizza;
  float ValorPizza;
}Pizza;

typedef struct{
  int venda_cod;
  int venda_codcli;
  int venda_codpizza;
}Venda;

typedef struct
{
  char nome[31];
  int registro;
  float salario;
}Tfunc;

logar Log[10];
Tfunc fun[10];
Cliente cli[10];
Pizza pizza[10];
Venda venda[10];

void inicialogin()
{
	strcpy(Log[0].Login,"adm");
	strcpy(Log[0].Senha,"adm");
}

void iniciabdcli()
{
  int i;
  for(i=0;i<10;i++)
  {
    if(i<5)
    {
      cli[i].codcli = i+1;
    }
    else
    {
      cli[i].codcli = 0;
    }

  }
  strcpy(cli[0].nomecli,"Rogerio Silva");
  strcpy(cli[1].nomecli,"Aline Santos");
  strcpy(cli[2].nomecli,"Marcelo Souza");
  strcpy(cli[3].nomecli,"Daniela Silva");
  strcpy(cli[4].nomecli,"Carlos de Almeida");

  strcpy(cli[0].telcli,"(11)96458-4524");
  strcpy(cli[1].telcli,"(11)95478-1452");
  strcpy(cli[2].telcli,"(11)97563-5786");
  strcpy(cli[3].telcli,"(11)96555-1002");
  strcpy(cli[4].telcli,"(11)97542-2244");

}






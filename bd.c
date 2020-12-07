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


int Estab;

typedef struct
{
float ValDia;
float ValMens;
float TopUn;
}Relatorio;

typedef struct
{
    int codigoEstoq;
    char NomeMateria[20];
	float Kilo;
	int Unidade;
}Estoque;

typedef struct
{
    int codSug;
	char NomCli[30];
	char SugeCri[200];
}Sugestoes;

typedef struct
{
	int CodUsu;
	char Login[4];
	char Senha[4];
	int Restrict;
}logar;

typedef struct{
  int  codcli;
  char nomecli[31],telcli[21],Endereco[30];
}Cliente;

typedef struct{
  char nome_pizza[30];
  int  cod_pizza;
  float ValorPizza;
  int OpcMat;
  int ContPizza;
  float MatPrima;
}Pizza;

typedef struct{
  int venda_cod;//codigo do cliente;
  int venda_codcli;
  char nomeCliVen[31];//nome do cliente;
  char nomePizzaVen[30];//nome da pizza no pedido;
  char TelCliVend[21];//telefone do cliente;
  float ValorPizzaVen;//valor da pizza no pedido;
  char NomMercVend[30];//nome da mercadoria no pedido;
  float ValorMercVend;//Valor da mercadoria no pedido;
  char EnderecoVend;
  int SenhaVend;//senha do pedido;
  int venda_codpizza;//
  float ValorTotalVend;//Valor total do pedido;

  float ValorTotalRela;
  float Grana;
}Venda;

typedef struct
{
  int CodFunc;
  char nome[31];
  int registro;
  float salario;
}Tfunc;

typedef struct
{
	int CodMerc;
	char NomMerc[30];
	float ValorMerc;
}Mercadoria;

Relatorio Rela[2];
Estoque Estoq[10];
Mercadoria Merc[10];
Sugestoes Sug[10];
logar Log[10];
Tfunc fun[15];
Cliente cli[10];
Pizza pizza[10];
Venda venda[10];

void inicialogin()
{
    Log[0].CodUsu = 1;
    Log[1].CodUsu = 2;
    Log[0].Restrict = 0;
    Log[1].Restrict = 1;
	strcpy(Log[0].Login,"adm");
	strcpy(Log[0].Senha,"adm");
	strcpy(Log[1].Login,"luc");
	strcpy(Log[1].Senha,"123");
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

void inserirdados()
{
    int i;
  for(i=0;i<10;i++)
  {
    if(i<2)
    {
      pizza[i].cod_pizza = i+1;
      fun[i].CodFunc = i+1;
      Sug[i].codSug =i+1;
      Estoq[i].codigoEstoq = i+1;
      Merc[i].CodMerc = i+1;
    }
    else
    {
     pizza[i].cod_pizza = 0;
    }
    //pizza;
    strcpy(pizza[0].nome_pizza,"Calabresa");
    pizza[0].ValorPizza = 35;
    pizza[0].MatPrima = 1;
    pizza[0].OpcMat = 1;
    strcpy(pizza[1].nome_pizza,"Mussarela");
    pizza[1].ValorPizza = 30;
    pizza[1].MatPrima = 2;
    pizza[1].OpcMat = 2;
    //funcionarios;
    strcpy(fun[0].nome,"Zeca pagodinho");
    fun[0].salario = 1500.00;
    fun[0].registro = 1234;
    strcpy(fun[1].nome,"Bozonaro");
    fun[1].salario = 1500.00;
    fun[1].registro = 1234;
    //sugestoes;
    strcpy(Sug[0].NomCli,"Bill gates");
    strcpy(Sug[0].SugeCri,"Bom,Bonito e Barato");
    strcpy(Sug[1].NomCli,"Steve balmer");
    strcpy(Sug[1].SugeCri,"Devia ser gratis");
    //Materiaprima
    strcpy(Estoq[0].NomeMateria,"calabresa");
    strcpy(Estoq[1].NomeMateria,"Mussarela");
    //Mercadoria
    strcpy(Merc[0].NomMerc,"Guarana");
    Merc[0].ValorMerc = 5.00;
    Merc[1].ValorMerc = 3.80;
    strcpy(Merc[1].NomMerc,"Coca cola 350ml");
}
}

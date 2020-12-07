#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>

//a imprimir o cabeçalho padrao do sistema...
void Cabecalho()
{
  setlocale(LC_ALL, "portuguese");
  SetColor(6);
  printf("  ___  _                     _        ___                            _    _                                         ");
  printf("     |   \\|_| ___  ___  __ _ _ _|_| __ _ |   \\ _   _   ___  _ __   __ _ | \\  / | __ _  ____  ____   __ _\n");
  printf(" |  _/ _ |_ / |_ / / _` | '_|_ / _` || ´ /| | | | / _ \\| '_ \\ / _` ||  \\/  |/ _` ||  __||  __| / _` |\n");
  printf(" | |  | | /(_  /(_| (_| | | | | (_| || ´ \\| \\_/ || (_) | | | | (_| || |\\/| | (_| | \\__ \\ \\__ \\| (_| |\n");
  printf(" |_|  |_|/___|/___|\\__,_|_| |_|\\__,_||___/ \\___/  \\___/|_| |_|\\__,_||_|  |_|\\__,_||____/|____/ \\__,_|\n\n");
  SetColor(7);
  printf("                                            Software para controle de pizzaria - PIM 2º Semestre 2019\n");
  printf("                                               Turma DS2Q40  -  Coordenador: Rogério Barbosa da Silva\n");
  printf("_____________________________________________________________________________________________________\n\n");
}

//Função usada para possibilitar alteração de cores dos caracteres
void SetColor(int ForgC)
{
  WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  //Aqui é usado csbi para a palavra wAttributes
  if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
  {
    //Mascara tudo menos o atributo do background, e adiciona a cor do primeiro plano
    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
  }
  fflush(stdin);
  return;
}

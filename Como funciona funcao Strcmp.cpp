#include <stdio.h>
#include <string.h>//necess�rio para strcmp
#include <conio.h>
int main (void)
{
  char str1[] = "abc";
  char str2[] = "abc";
  int retorno;
 
  retorno = strcmp(str1, str2);
  printf("retorno = %d\n", retorno);
  //mostra o retorno da fun��o strcmp
 
  getch();
  return 0;
}

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int contaChar(char[],char);
main(){
   
       char texto[100],c;
       printf ("\n Informe uma string: ");
       gets (texto);
       printf ("\nInforme o caractere a ser contado: \n");
       scanf("%c",&c);
       printf("o caractere %c aparece %d vezes no texto\n",c,contaChar(texto,c));   
       system("pause");
}
int contaChar(char s[], char ch) {
    int i,cont=0;
    for (i=0;i<strlen(s);i++)
        if (s[i]==ch) cont=cont+1;
    return cont;        
}


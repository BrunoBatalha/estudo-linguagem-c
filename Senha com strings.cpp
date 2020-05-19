//Verificador de senhas
#include <stdio.h>
#include <string.h>

int main(){
 char senha1[21],senha2[21],deposito[26];
 
 printf("Senha1: ");
 fgets(senha1,sizeof(senha1),stdin);

	
 printf("Senha2: ");
 fgets(senha2,sizeof(senha2),stdin);

 
 if(strcmp(senha1,senha2)==0){
 	puts("\n\nSenhas conferem\n");
 }	else
 	puts("\n\nSenhas erradas\n");
return 0;
}


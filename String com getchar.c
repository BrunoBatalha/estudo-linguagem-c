#include <stdio.h>
int main(){
	
	char nome[100];
	char palavra;
	int i=0;
	
	do{
		palavra = getchar();
		nome[i] = palavra;
		++i;
	}while (palavra != '\n');
	
	nome[i-1]='\0';
	
	printf("%s\n",nome);
	
	getch();
	return 0;
}

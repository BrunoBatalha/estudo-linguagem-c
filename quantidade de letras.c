#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	system("color c");
	int caractere(char[], char);
	void linha(void);
	char frase[100], letra;
	
	linha();
	printf("Digite alguma frase: ");
	gets(frase);
	printf("Diga o caractere que deseja contar: ");
	scanf("%c",&letra);
	linha();
	
	printf("O caractere >%c< aparece %i vezes na frase: ",letra, caractere(frase, letra));
	puts(frase);

	linha();
	return 0;
}

void linha(void){
	int i;
	for(i=0;i<=20;i++)
		printf("*");
	printf("\n");
}

int caractere(char s[],char carac){
	int cont;
	int i;
	for(i=0;i<=strlen(s);i++)
		if(s[i]==carac)
			cont++;
return cont;		
}

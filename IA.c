#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
main (){
	char a;
	int idade;
	char nome[5];
	
	setlocale(LC_ALL,"portuguese");
	
	printf("Oi...");
	scanf("%c", &a);
	fflush(stdin);
	system("cls");
	
	printf("tudo bem?...");
	scanf("%c", &a);
	fflush(stdin);
	system("cls");
	
	printf("Que bom...Qual sua idade?...");
	scanf("%d",&idade);
	system("cls");
	
	if(idade <= 15){
		fflush(stdin);
		printf("Muito novo...\n");
		printf("Por que está aqui?\n");
		scanf("%c",&a);
		fflush(stdin);
		printf("Legal...Fera!\n\n");
	}else {
		printf("Hmmmmmmmmmmmmm, interessante...\n");
		printf("Por que está aqui?\n");
		scanf("%c",&a);
		fflush(stdin);
		printf("Legal...Fera!\n\n");
	}	
	
	printf("Qual seu nome? TODO PF!!");	
	gets(nome);
	system("cls");
	
	printf("Seu nome é ");
	puts(nome);
	printf("?? que estranho...Meu primo tmb tem esse nome\n");
	printf("Mas tudo bem ");
	puts(nome);
	printf("vamos continuar...\n\n");
	
	
	system("pause");
}

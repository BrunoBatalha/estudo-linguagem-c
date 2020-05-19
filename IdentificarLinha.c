/*9.Faça um programa que leia 10 nomes incluindo o 
seu. Ao final, imprima em qual posição do vetor está 
armazenado o seu nome.*/
#include<stdio.h>
#include<string.h>
int main(){
	char matriz[10][100],nome;
	int i,j=0;
	char meuNome[6]="bruno";
	
	for(i=0;i<10;i++){
		j=0;
		printf("Nome: ");
		nome = getchar();
		do{
			matriz[i][j] = nome;
			j++;
			fflush(stdin);
		}while(nome == '\n');
		
		matriz[i][j-1] = '\0';
	}j=0;
	for(i=0;i<10;++i){
		for(j=0;j<100;++j){
			if(matriz[i][j]==meuNome[j] || meuNome[j] == '\0'
										&& matriz[i][j]=='\0'){
										 	printf("Seu nome(%s) esta na linha %i\n",meuNome,i);
										 }
		}
	}
	
	getch();
	return 0;
}


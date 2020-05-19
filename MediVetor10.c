#include<stdio.h>

int main(){
//declaracao de variaveis
	float nota1[10];
	float nota2[10];
	float media[10];
	int i, AcimaDaMedia=0,NaPrimeira=0,NaSegunda=0,Nenhuma=0;
	float soma;
	void linha(void);
	void lin(void);

//inicio
	for(i=0;i<10;i++){
		linha();
		printf("Aluno %i nota 1: ",i+1);
		scanf("%f",&nota1[i]);
		printf("Aluno %i nota 2: ",i+1);
		scanf("%f",&nota2[i]);
		
		soma = nota1[i] + nota2[i];
		media[i]=soma/2;
	}printf("\n");
	for(i=0;i<10;i++){
		printf("Media do aluno %i : %.1f\n", i+1, media[i]);
	}printf("\n");
	
	for(i=0;i<10;i++){
		if(nota1[i]>=6.0 && nota2[i]>=6.0)
			AcimaDaMedia++;
		else if(nota1[i]>=6.0)
			NaPrimeira++;
			else if(nota2[i]>=6.0)
				NaSegunda++;
				 else
				 	Nenhuma++;
	}printf("\n");
	
	printf("--Quantidade de alunos que tiraram nota \nigual ou acima de 6.0 nas duas provas: %i\n",AcimaDaMedia);
	lin();
	printf("--Quantidade de alunos que tiraram nota \nigual ou acima de 6.0 somente na primeira prova: %i\n",NaPrimeira);
	lin();
	printf("--Quantidade de alunos que tiraram nota \nigual ou acima de 6.0 somente na segunda prova: %i\n",NaSegunda);
	lin();
	printf("--Quantidade de alunos que tiraram nota inferior\na 6.0 nas duas provas: %i\n",Nenhuma);
	lin();
	getch();
	return 0;
}
//minha funcao
void linha(void){
	int i;
	for(i=1;i<=20;i++)
		printf("º");
	printf("\n");
}

void lin(void){
	int i;
	for(i=1;i<=20;i++)
		printf("-");
	printf("\n");
}

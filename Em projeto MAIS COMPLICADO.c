#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAMANHO 10

struct Dados_Pessoais{
	char nome[45];
	int idade;
};

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	struct Dados_Pessoais dados[TAMANHO];
	int aqui[TAMANHO],i=0,opcao1,opcao2;
	FILE *Leia;
	FILE *Modificar;
	
	Leia = fopen("Perfis.txt","r");
	Modificar = fopen("Perfis.txt","a");
	
	for(i = 0 ; i < TAMANHO ; i++)aqui[i]=0;
	
	
	do{
		printf("----------\n");																										 
		printf("1 - Novo perfil\n2 - Carregar\n3 - Sair\nDigite sua opcao: ");    
		scanf("%i",&opcao1);
		
		switch(opcao1){
			case 1:{
				system("cls");
				printf("---Preencha tudo---\n");
				for(i=0;i<TAMANHO;i++){
					if(aqui[i]==0){
						 fflush(stdin);
						printf("Nome: ");
						 fprintf(Modificar,gets(dados[i].nome));
					
						printf("Idade: ");
						 scanf("%i",&dados[i].idade);
						 fprintf(Modificar,"%i",dados[i].idade);
						aqui[i]=1;
						getch();
						
						system("cls");
						printf("\n---Perfil criado com sucesso---\a\a");	
						getch();
						break;
					}
				}
		break;}
			case 2:{
				system("cls");
				if(aqui[0]==0){
					printf("Nada encontrado!\n");
					getch(); 
					break;
				}
					 printf("---Escolha o perfil---\n*%8s %d*\n\n","Máximo de perfis",TAMANHO);
				
				for(i=0;i<TAMANHO;i++){
					if(aqui[i]==1)
						printf("%d - %s\n",i+1,dados[i].nome);
				}printf("\n\n0 - Voltar.\n");
				
				printf("\nDigite sua opcao: ");
				scanf("%i",&opcao2);
				
				if(opcao2==-1)break;
				
				system("cls");
				for(i = 0 ; i < TAMANHO ; i++ ){
					if(i+1 == opcao2){
							printf("-------------\n");
							printf("Nome: %s\n",dados[i].nome);
							printf("Idade: %i\n",dados[i].idade);
							getch();
							break;
					}	
	 			}break;
			}
			
		}
	system("cls");
	}while(opcao1!=3);
return 0;
}

//De: bruno batalha

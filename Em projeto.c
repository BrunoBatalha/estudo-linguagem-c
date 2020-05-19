#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAMANHO 5

struct Dados_Pessoais{
	char nome[45];
	int idade;
};

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	struct Dados_Pessoais dados[TAMANHO];
	int aqui[TAMANHO],i=0,opcao1,opcao2;
	
	for(i = 0 ; i < TAMANHO ; i++)aqui[i]=0;
	
	do{
		printf("----------\n");																										 
		printf("1 - Novo perfil\n2 - Carregar\n3 - Excluir\n4 - Sair\nDigite sua opcao: ");    
		scanf("%i",&opcao1);
		
		switch(opcao1){
			case 1:{
				system("cls");
				printf("---Preencha tudo---\n");
				for(i=0;i<TAMANHO;i++){
					if(aqui[i]==0){
						 fflush(stdin);
						printf("Nome: ");
						 gets(dados[i].nome);
					 	 fflush(stdin);
						printf("Idade: ");
						 scanf("%i",&dados[i].idade);
						aqui[i]=1;
						getch();
						
						system("cls");
						printf("\n---Perfil criado com sucesso---\a\a");	
						getch();
						break;
					}
				}break;
			}
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
			case 3:{
				system("cls");
				char exluir[45];
				printf("Nome do perfil que deseja excluir: ");
				fgets(exluir,45,stdin);
				int j=0;
				while(aqui[i] != 0){
				 	j = aqui[i];
					i++;				 
				 } 
				while(exluir != dados[j].nome)
				break;
			}
		}
	system("cls");
	}while(opcao1!=4);
return 0;
}

//De: bruno batalha

/*Peça ao usuário para digitar seus dados pessoais 
(Nome, Endereço, Data de Nascimento, Cidade, CEP, email), 
verifique se as informações de Data de Nascimento, CEP e 
email fazem sentido, e mostre ao usuário as informações, 
se estão todas corretas, ou mostre que alguma informação estava errada.*/
#include <stdio.h>
#include <ctype.h>
#define VETOR 100
struct Dados{
	char nome[VETOR];
	char endereco[VETOR];
	char data_nascimento[15];
	char cidade[VETOR];
	char email[VETOR];
	int CEP;
}Pessoais;
void conferir_nome(char[],int);

int main(){
	printf("%cNome: ",219); fgets(Pessoais.nome,VETOR,stdin);
	conferir_nome(Pessoais.nome,VETOR);
	
	printf("%cData de Nascimento: ",219); fgets(Pessoais.data_nascimento,VETOR,stdin);
	printf("%cCidade: ",219); fgets(Pessoais.cidade,VETOR,stdin);
	printf("%cEndereco: ",219); fgets(Pessoais.endereco,VETOR,stdin);
	printf("%cCEP: ",219); 	scanf("%i",&Pessoais.CEP);
	printf("%cEmail: ",219); fgets(Pessoais.email,VETOR,stdin);
	
	
	
return 0;
}

void conferir_nome(char nome[],int tamanho){
	int i;
	
	for(i = 0 ; i < tamanho ; i++){
		if(tolower(nome[i]) >= 97 && tolower(nome[i]) <= 119 || nome[i] == ' ' || nome[i] == '\n' ){
			printf("%c\n",tolower(nome[i]));
			continue;
		}else{
			printf("** %c\n",tolower(nome[i]));
			break;
		}
	}
	if(i != tamanho - 1) printf("ERRO NO NOME");
	
}


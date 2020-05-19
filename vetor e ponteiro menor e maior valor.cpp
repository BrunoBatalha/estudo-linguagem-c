/*Escreva uma função mm que receba um vetor inteiro v[0..n-1] e os endereços de duas variáveis 
inteiras, digamos min e max, e deposite nessas variáveis ovalor de um elemento mínimo e o valor 
de um elemento máximo do vetor.Escreva também uma função main que use a função mm.*/
#include <stdio.h>
	void max_min(int [], int , int* , int*);
int main(){
	int x = 5;
	int v[x],min ,max;

	
	int i ;
	for( i = 0 ; i < x ; i++){
		scanf("%d",&v[i]);
	}
	
	max_min(v,x,&max,&min);
	
return 0;
}
void max_min(int vetor[],int tamanho_vetor, int* maximo , int* minimo){
	int i;

	for( i = 0 ; i < tamanho_vetor ; i++){
		
		if(i == 0){
			maximo = &vetor[i];  
			minimo = &vetor[i];
		}
		
		if(vetor[i] > *maximo)  maximo = &vetor[i];
		else if(vetor[i] < *minimo) minimo = &vetor[i];
	}
	
	printf("max: %d\n",*maximo);
	printf("min: %d",*minimo);
}

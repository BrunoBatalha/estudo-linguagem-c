//7.	Criar um programa que leia dados para um vetor de 100 elementos inteiros. 
//Imprimir o maior e o menor elemento, o percentual de números pares 
//e a média dos elementos digitados


#include <stdio.h>
#include <iostream>

using namespace std;

const int MAX    = 10;



int main() {
  	int  vetor[MAX];		
	
	int indice=0;
	int valormaximo=0;
	int valorminimo=0;
	int media_valores=0;
	
	float percentual_pares=0;
	
	
	//preencher vetor
	while(indice<MAX){
		cout <<"Informe valor para posicao{"<<indice<<"}:";		
		cin>>vetor[indice];
		getchar();
		indice++;
	}
	
	//avalia os valores
	printf("------------------------------------------\n");
	valormaximo = vetor[0];
	valorminimo = vetor[0];
	for(int i=0; i<MAX; i++){				
		if(vetor[i] > valormaximo){			
			valormaximo = vetor[i] ;	
		}		
		if(vetor[i]< valorminimo){			
			valorminimo= vetor[i] ;	
		}		
		if(vetor[i]%2==0 ){						
			percentual_pares++;
		}
		media_valores +=vetor[i];
	}
	
	
	
	//imprimindo resultado
	printf("------------------------------------------\n");
	printf("Maximo: %i; Minimo: %i; Percentual Pares:%.2f%; Media:%d\n",valormaximo,valorminimo,((percentual_pares/MAX)*100),(media_valores/MAX));	
	
}	
	

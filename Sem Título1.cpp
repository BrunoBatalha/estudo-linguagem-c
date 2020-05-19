#include <stdio.h>

int main(){
	double Notas[100];
    int result;
    int i;
    FILE* arq;
    for(int i=0;i<100;Notas[i]=i,i++){}

    // Cria um arquivo binário para gravação
    arq = fopen("ArquivoB.txt","w");
    // Grava 30 números do vetor a partir da posição 50
    result = fwrite (&Notas[0], sizeof(double), 30, arq);

    printf("Nro de elementos gravados: %d", result);
    fclose(arq);

	//Lê
	double Vet[100];
	arq = fopen("ArquivoB.txt","r");
	result = fread (&Vet[0], sizeof(double), 100, arq);
  	printf("\nNro de elementos lidos: %d\n", result);
  	for(i=0; i<result; i++)printf("%2.f ", Vet[i]);
    fclose(arq);
    
/*
    arq = fopen("ArquivoB.txt","ab");


    arq = fopen("ArquivoB.txt","rb");char nome1[10];
     fread(nome1,sizeof(nome1),10,arq);
    printf("%s",nome1);

*/
	return 0;
}

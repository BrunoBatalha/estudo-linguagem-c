#include<stdio.h>
#include<stdlib.h>
int main(){
	int PC[6];
	int CN[6];
	int i, j;
	system("color 70");
	i = 1;
	printf("Entre com as matriculas dos alunos(5) de Programacao de Computadores (finalizar: 9999):\n");
	printf("PC[%d] = ",i);
	scanf("%d",&PC[i]);
	
	while(PC[i] != 9999){
		i++;
		printf("PC[%d] = ",i);
		scanf("%d",&PC[i]);
	}
	
	i=1;
	printf("Entre com as matriculas dos alunos(5) de Calculo Numerico (finalizar: 9999):\n");
	printf("CN[%d] = ",i);
	scanf("%d",&CN[i]);
	
	while(CN[i] != 9999){
		i++;
		printf("CN[%d] = ", i);
		scanf("%d",&CN[i]);
	}
	
	i=1;
	while(CN[i] != 9999){
		j = 1;
		while((CN[j] != 9999) && (PC[i] != CN[j]))
			j++;
		if((PC[i] != 9999) && (PC[i] == CN[j])){
			printf("Numeros de matricula = %d\n",PC[i]);
		}else
			printf("Nao ha alunos matriculados em ambas as disciplinas");
		i++;
	}	
	
	return 0;
}

#include<stdio.h>

int main(){

	int op = menu();

	printf("Vc escolheu a Opcao %i.\n",op);
	
	return 0;
}	

int menu(){
	int i;
	do{
		printf("(1) Opcao 1\n");
		printf("(2) Opcao 2\n");
		printf("(3) Opcao 3\n");
		scanf("%i",&i);
	}while((i<1)||(i>3));
	
	return i;
}

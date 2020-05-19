#include <stdio.h>


int main(){

	int cuboDeReferencia(int) ;

	int numero = 5;

	printf("O valor original do numero eh: %d",numero);
	numero=cuboDeReferencia(numero);
	printf("\nO novo valor do numero eh: %d",numero);

    getch();
	return 0;
}

int cuboDeReferencia(int n){
	return n*n*n;
}

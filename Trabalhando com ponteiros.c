#include <stdio.h>

	void cuboDeReferencia(int *nPtr) ;

int main(){

	
	int numero = 5;
	
	printf("O valor original do numero eh: %d",numero);
	cuboDeReferencia(&numero);
	printf("\nO novo valor do numero eh: %d",numero);
	

	return 0;
}

void cuboDeReferencia(int *nPtr){
	*nPtr = *nPtr * *nPtr * *nPtr;
}

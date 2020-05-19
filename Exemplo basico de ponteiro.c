#include <stdio.h>												// " * " = ASTERISTICO;

int main(){
 	int x;
	int *ptr;
  
	x = 5;
  
	ptr = &x;														// O PONTEIRO "ptr" recebeu o endereço da variavel 'x'| OBS.: NAO PRA RECEBER O ENDERECO NAO COLOQUE " * " NO PONTEIRO;
  	printf("O valor da variavel X e: %d\n", *ptr);  	//COLOCANDO " * " NA HORA DE EXIBIR EU MOSTRO O VALOR DA VARIAVEL QUE ELE APONTA, NO CASO O 'x';
  	*ptr = 10;                          					//COLOCANDO " * " EH POSSIVEL ALTERAR O VALOR DA VARIAVEL NO QUAL O PONTEIRO "ptr" APONTA, NO CASO O 'x';
  	printf("Agora, X vale: %d\n", *ptr);
return 0;
}


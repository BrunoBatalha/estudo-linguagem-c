/* Um palíndromo é uma string que é lida da mesma maneira 
da esquerda para a direita e da direita para a esquerda. 
Alguns exemplos de palíndromo são radar e a bola da loba 
(se os espaços forem ignorados) Escreva uma função recursiva 
que retorna 1 se a string armazenada no array for um palíndromo 
e 0, caso contrário. O método deve ignorar espaços e pontuação 
na string. 40*/
#include <stdio.h>

void reverso(char *sPtr);
int main(){
	
	char sentenca[80];
	
	printf("Digite uma linha de texto: \n");
	fgets(sentenca,80,stdin);
	
	printf("\nA linha impressa na ordem inversa:\n");
	reverso(sentenca);
	
return 0;
}
void reverso( char *sPtr){
	if (sPtr[0] == '\0'){
		return; 
	}else{
		reverso(&sPtr[1]);
		putchar(sPtr[0]);
	}
}

/* Um pal�ndromo � uma string que � lida da mesma maneira 
da esquerda para a direita e da direita para a esquerda. 
Alguns exemplos de pal�ndromo s�o radar e a bola da loba 
(se os espa�os forem ignorados) Escreva uma fun��o recursiva 
que retorna 1 se a string armazenada no array for um pal�ndromo 
e 0, caso contr�rio. O m�todo deve ignorar espa�os e pontua��o 
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

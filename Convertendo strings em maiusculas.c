#include <stdio.h>


void ParaMaiuscula(char *sPtr);
int main(){
	char string[]="caractere e R$ 32,98";

	printf("A string antes: %s\n",string);
	ParaMaiuscula(string);
	printf("String depois: %s",string);	
	return 0;
}
void ParaMaiuscula(char *sPtr){
	while (*sPtr!='\0'){
		if(islower(*sPtr)){
			*sPtr = toupper(*sPtr);
		}
	++sPtr;	
	}
}

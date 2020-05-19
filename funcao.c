#include<stdio.h>
#include<stdlib.h>

int main(){
	
	void estrelinhas(void);
	
	estrelinhas();
	printf("BrunoBatalha\n");
	estrelinhas();
	
	return 0;
}

void estrelinhas(void){
	int i;
	for (i=1;i<20;i++){
		printf("*");
	}
	printf("\n");
}

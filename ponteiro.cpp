#include <stdio.h>

int main(){
	void troca(int*,int*);
	int a = 4 ,b = 8;
	troca(&a,&b);
	printf("%d - %d\n",a,b);
	
return 0;
}

void troca(int *i , int *j){
	int temp;
	 temp= *i;
	 *i = *j;
	 *j = temp;
}

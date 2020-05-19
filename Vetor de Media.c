#include<stdio.h>

int main(){
	float media=0, nota[2];
	int i;
	for(i=0;i<2;i++){
		printf("nota %i: ",i+1);
		scanf("%f",&nota[i]);
		media = media+nota[i];
	}	
	printf("Media: %.1f",media/2);
return 0;
}

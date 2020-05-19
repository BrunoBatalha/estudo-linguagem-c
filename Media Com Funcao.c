#include<stdio.h>
#include<stdlib.h>

int main(){
	float a, b;
	float media(float , float );
	
	printf("Avaliacao 1: ");
	scanf("%f",&a);
	printf("Avaliacao 2: ");
	scanf("%f",&b);
	
	printf("Media: %.1f",media(a, b));
	
	return 0;
} 
float media(float av1, float av2){	
 	return ((av1 + av2)/2);
}

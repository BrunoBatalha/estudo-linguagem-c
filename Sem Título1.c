#include<stdio.h>
#include<math.h>

main(){
	float total;
	float quant;
	float perc;

	
	printf("TOTAL: ");
	scanf("%f", &total);
	printf("QUANTIDADE: ");
	scanf("%f",&quant);
	
	perc = (quant/total)*100;
	
	printf("\n\nPERCENTUAL: %%%.f \n\n",perc);
	
}

#include<stdio.h>
#include <stdlib.h>
double fatorial(int);
main(){  
      system("color a");
	   int N;
       printf ("Informe o numero: ");
       scanf("%d",&N);
      
       printf("fatorial: %.lf\n",fatorial(N));   
       system("pause");
}

double fatorial(int n){
       int I; 
       double fat=1.0;
       for (I=1;I<=n;I++)
                fat=fat*I;
       return(fat);
} 


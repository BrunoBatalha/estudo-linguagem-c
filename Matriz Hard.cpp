#include <stdio.h>

int main(){

	int m[4][4];
	int k;
	int m1[4][4];
	int i,j;
 	
	for(i=0;i<4;i++){
 		for(j=0;j<4;j++){
 			printf("m[%d][%d]:",i+1,j+1);
 			scanf("%d",&m[i][j]);
		 }
	 }printf("Veja como ficou a matriz -> m[4][4]\n");
	 for(i=0;i<4;i++){
 		for(j=0;j<4;j++){
 			printf("%d ",m[i][j]);
		 }printf("\n");
	 }printf("\n");

    for(i=0;i<4;i++){
 		for(j=0;j<4;j++){
 			m1[i][j]= 0;
		 }
	 }
	
	 printf("Digite o valor da constante que k: ");
	 scanf("%d",&k);
	 printf("\n");
	 for(i=0;i<4;i++){
	 	m1[i][i] = m[i][i]*k;
	 }
	printf("Veja como ficou o valor da matriz -> m1[4][4]\n\n");
	for(i=0;i<4;i++){
 		for(j=0;j<4;j++){
 		    printf("%d ",m1[i][j]);
		}printf("\n");
	}printf("\n");
	return 0;
}


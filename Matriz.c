/*PROGRAMA TOP DE MATRIZ*/

#include<stdio.h>

int main(){
	
	int a;
	int L,C;
	int m1[2][2];
	int m2[2][2];

/*Entrada de dados*/
	printf("Digite os valores da Matriz 1:\n");
	for(L=0;L<2;L++){
		for(C=0;C<2;C++){
			printf("M1[%d][%d]= ",L,C,m1[L][C]);
			scanf("%d",&m1[L][C]);
		}
	}
	printf("Digite os valores da Matriz 2:\n");
	for(L=0;L<2;L++){
		for(C=0;C<2;C++){
			printf("M2[%d][%d]= ",L,C,m2[L][C]);
			scanf("%d",&m2[L][C]);
		}
	}printf("\n");
	

/*exibir na tela*/
	printf("Matriz 1 veja como ficou:\n");
	for(L=0;L<2;L++){
		for(C=0;C<2;C++){
			printf("%d ",m1[L][C]);
		}printf("\n");
	}
	
	printf("\nMatriz 2 veja como ficou:\n");	
		for(L=0;L<2;L++){
			for(C=0;C<2;C++){
				printf("%d ",m2[L][C]);
		}printf("\n");
	}
	
/*soma da matrizes*/
	printf("\nVeja a soma das duas matrizes: \n");
	for(L=0;L<2;L++){
			for(C=0;C<2;C++){
				printf("%d ",m2[L][C]+m1[L][C]);
		}printf("\n");
	}
	
	getch();
	return 0;
}




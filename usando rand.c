#include<stdio.h>

int main()
{
	int i;

	printf("Valores aleatorios criados entre 0 e 200\n");
	for(i=0;i<10;i++){
		printf("%i ", rand() % 700);
	}
	getch();
	return 0;
}

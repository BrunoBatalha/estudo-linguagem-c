#include<stdio.h>
#include<conio.h>

int main(void)
{
	
	int i;
	
	for(i=1;i<10;i++)
	{
		if(i%2==0)
		{
			continue;	
		}else 
		{
			printf("Numero: %d \n",i);
		}
		printf("Numero impar!\n\n");

	}
	printf("Final do programa!\n\n");
	
	getch();
	return 0;
}

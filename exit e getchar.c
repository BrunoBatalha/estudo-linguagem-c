#include<stdio.h>

int main(){
	char ch;

	printf("(1) Iniciar\n");
	printf("(2) Sair\n");

	do{
		ch = getchar();
		switch(ch){
			case '1':
				printf("Ok...");
				getch();
				printf("Mas ainda estou fazendo isso heuhue...\n");
				getch();
			case '2': break;
		}
	}while(ch!='1' && ch !='2');
return 0;
}

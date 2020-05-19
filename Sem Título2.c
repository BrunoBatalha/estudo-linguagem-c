#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	char tecla;
	int x=50,y=50;
	do{
		gotoxy(x,y); printf("@");
		
		tecla = getch();
		
		if(tecla=='a')x--;
		if(tecla=='d')x++;
		if(tecla=='w')y--;
		if(tecla=='s')y++;
		
	system("cls");
	}while(x==0);
	return 0;
}

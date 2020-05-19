#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void  Loading(){
	int coluna = 10;
  	int linha  = 50;
	int i;

	for(i=0;i<50;i++){
		
		system("color a");
		gotoxy(coluna, linha);
		printf("%c",219);
		Sleep(0.5);
		coluna++;
	}
}



	
int main() {
	

	Loading();

    printf("\nAprovado!!!\n");
	return 0;
}

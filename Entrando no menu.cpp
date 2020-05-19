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

void  BarraDeCarregamento(){
	int coluna = 0;
  	int linha  = 1;
	int i;
	int P=0;
	for(i=0;i<40;i++){
		
		system("color a");
		gotoxy(coluna, linha);
		printf("%c",219);
		printf("%i%%",P);
		P++;
		P++;
		P++;
		if(P>100)P-=17;		
		Sleep(10);
		coluna++;
	}
	getch();
	system("cls");
}
	
int main() {
	//TELA DE CARREGAMENTO INICIAL
	
	int x, y;
	printf("Inicializando sistema...\n");
	BarraDeCarregamento();

	
	FILE *ADMleia;
	FILE *ADMmodificar;
	
	ADMleia = fopen("Administrador.txt","rt");
	ADMmodificar = fopen("Administrador.txt","a");
	
	if(	(ADMmodificar = fopen("Administrador.txt","a"))==NULL)printf("Nao foi possivel abri o arquivo!\n");
	
	getch();
	return 0;
}

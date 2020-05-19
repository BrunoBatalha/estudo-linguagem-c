#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#define OPCOES 100


void gotoxy(int, int);
void Parar_e_LimparTela(void);
int MovendoSeta(int, int, int);
void loading(void);

char tecla ;
int y;
int opcao[OPCOES];

int main(){

	printf("\t\t\t\t      ____JOGO DE ESCOLHAS____\n");puts("\n");
										gotoxy(50,2);
	Sleep(2000);gotoxy(0,1);
	printf("\t\t\t\tPressione qualquer tecla para iniciar");
	
	Parar_e_LimparTela();
	loading();
	Parar_e_LimparTela();
	
	gotoxy(15,0);printf("Eram 3:00 h da madrugada, e voce ja estava cansado de passar a noite estudando,");
	gotoxy(10,1);printf("porem naquela noite, bem no momento em que ja iria se deitar, escuta algo no portao");
	gotoxy(10,2);printf("de sua casa, como se fossem batidas, acha estranho entao decide...");
	
	gotoxy(17,4);printf(" )Ir ate o  portao e verificar o que era...");// 4
	gotoxy(17,5);printf(" )Apenas observar da janela...");				 // 5
	tecla=0;
	
	opcao[0] = MovendoSeta(5,4,16);
	
	switch(opcao[0]){
		case 4:{
			system("cls");
			gotoxy(15,0);printf("Voce entao, pega suas chaves, e vai em direcao a sua porta e...");Sleep(5000);
			gotoxy(15,1);printf("Escuta novamente as batidas, mas desta vez parecem mais fortes!");
			gotoxy(15,2);printf("Assustado, da um passo para tras, escuta outra batida porem desta vez...");Sleep(5000);
			gotoxy(15,3);printf("A batida vem da porta do seu banheiro!");
			
			gotoxy(17,5);printf(" )Voce fica assustado, e decide sair correndo de sua casa...");// 5
			gotoxy(17,6);printf(" )Olha para tras, e vai verificar o banheiro...");				   // 6
			tecla=0;
			
			opcao[1] = MovendoSeta(6,5,16);
			break;
		}
		case 5:{
			system("cls");
			printf("NAO VE NADA E DEPOIS MORRE EHEUHEUE");
			break;
		}
	}
	switch(opcao[1]){
		case 5:{
			printf("foi");
			break;
		}
		case 6:{
			system("cls");
			gotoxy(15,0);printf("Ao se aproximar, ficando diante da porta, as batidas param!");Sleep(5000);
			gotoxy(15,1);printf("Voce fica em silencio, e aproxima seu ouvido da porta, e escuta");
			gotoxy(10,2);printf("uma respiracao, como se houvesse alguem do outro lado");Sleep(5000);
			
			gotoxy(17,4);printf(" )Voce fica assustado, e decide sair correndo de sua casa...");// 4
			gotoxy(17,5);printf(" )Olha para tras, e vai verificar o banheiro...");				   // 5
			tecla=0;
			
			opcao[1] = MovendoSeta(5,4,16);
			break;
		}
	}
	
	gotoxy(0,25);
return 0;
}
void loading(void){
	gotoxy(43,10);printf("Loading");
	for(int i = 0 ; i < 6 ; i++){
		gotoxy(50,10);printf("   ");
		gotoxy(50,10);printf(".");Sleep(200);
		gotoxy(50+1,10);printf(".");Sleep(200);
		gotoxy(50+2,10);printf(".");Sleep(200);
	}
}

int MovendoSeta(int max, int min, int parado){
	int y = min;
	do{
		gotoxy(parado,y);printf(">>\b\b");
		
		tecla = getch();
		tecla = tolower(tecla);
		
		if( tecla == 's' && y == min ){
			y++;
			gotoxy(16,y-1);printf("  ");
		}
		if( tecla == 'w' && y == max ){
			y--;
			gotoxy(16,y+1);printf("  ");
		}
	}while(tecla != 32);
	
	return y;
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Parar_e_LimparTela(void){
	getch();
	system("cls");
	setbuf(stdin,NULL);
}

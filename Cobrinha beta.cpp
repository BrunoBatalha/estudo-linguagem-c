#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    system("color 5b");
	int i;
	char tecla,taclando;
	int x=0,y=0;
	int n = 150;
	char teclaGuardada;
	do{

		system("cls");
		gotoxy(x,y);
		printf("00000");
		tecla = getch();
		tecla = tolower(tecla);

        if(tecla != 's' && tecla != 'w' && tecla != 'd' && tecla != 'a'){
            tecla = teclaGuardada;

		}
		//setbuf(stdin,NULL);
		if( tecla == 's' && y != 40 )	{
                teclaGuardada = tecla;
			while(y != 40 ){
				y++;
                kbhit();
                if(kbhit())break;
				system("cls");
				gotoxy(x,y);printf("0");
				gotoxy(x,y-1);printf("0");
				gotoxy(x,y-2);printf("0");
				gotoxy(x,y-3);printf("0");
				Sleep(n);
			}
			 system("cls");
                    gotoxy(x,y);printf("0");
                    gotoxy(x-1,y+1);printf("0");
                    gotoxy(x-2,y+2);printf("0");
                    gotoxy(x-3,y+3);printf("0");
                     Sleep(n);
                    gotoxy(x-3,y-3);printf("0");
                    gotoxy(x-2,y-2);printf("0");
                    gotoxy(x-1,y-1);printf("0");
                    gotoxy(x,y);printf("0");
                    Sleep(n);
		}
		if( tecla == 'w' && y != 0  ){
		    teclaGuardada = tecla;
			while(1 && y != 0 ){
				y--;
                kbhit();
                if(kbhit())break;
				system("cls");
				gotoxy(x,y);printf("0");
				gotoxy(x,y-1);printf("0");
				gotoxy(x,y-2);printf("0");
				gotoxy(x,y-3);printf("0");
				Sleep(n);
			}
		}


		if( tecla == 'a' && x != 0  ){
                teclaGuardada = tecla;
			while(1 && x != 0){
				x--;
                kbhit();
                if(kbhit())break;
				system("cls");
				gotoxy(x,y);printf("0");
				gotoxy(x-1,y);printf("0");
				gotoxy(x-2,y);printf("0");
				gotoxy(x-3,y);printf("0");
				Sleep(n);
			}
		}
		if( tecla == 'd' && x != 100){
            teclaGuardada = tecla;
			while(1 && x != 100){
				x++;
                kbhit();
                if(kbhit())break;
				system("cls");
				gotoxy(x,y);printf("0");
				gotoxy(x-1,y);printf("0");
				gotoxy(x-2,y);printf("0");
				gotoxy(x-3,y);printf("0");
				Sleep(n);
			}
		}


	}while(tecla != 27);


return 0;
}



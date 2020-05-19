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
	int i;
	char tecla,taclando;
	int x=0,y=0;
	
	do{
		system("cls");
		printf("  1 - opcao\n"
				 "  2 - opcao\n"
		   	 "  3 - opcao\n");
		gotoxy(x,y);
		printf("->\b\b");
		tecla = getch();
		tecla = tolower(tecla);
		

		if( tecla == 's' && y != 2 ){
			y++;
		}
		if( tecla == 'w' && y != 0  ){
			y--;
		}
		
		
		if(tecla == 'd'){
				
			int h = 15;			
			switch(y){
				case 0:{
					
					do{	
							system("cls");
							printf("  1 - opcao\n"
									 "  2 - opcao\n"
		   				 		 "  3 - opcao\n");
					
							gotoxy(11,y);printf("----->>>CONFIRMAR ?"); 
							gotoxy(11,y+1);printf("\t  Sim    Nao");
							
							gotoxy(h,y+1);printf("->\b\b");
	
							tecla = getch();
							tecla = tolower(tecla);
						if(tecla == 27)break;
						if( tecla == 'd' && h != 23){
							h+=8;
						
						}
						if( tecla == 'a' && h != 15  ){
							h-=8;
						}
					}while(tecla != 32);
					if(tecla == 32)exit(1);
					break;
				}
				case 1:{
					gotoxy(11,y);printf("----->>>CONFIRMAR ?");  getch();
					break;
				}
				case 2:{
					gotoxy(11,y);printf("------>>>CONFIRMAR ?");  getch();
					break;
				}
			}
		}
	}while(tecla != 27);

	 gotoxy(10,10);("Tchau");
	
	 for(;;){
	 	gotoxy(10,10);printf("Tchau");
	 	gotoxy(16,10);printf("   ");Sleep(100);
	 	gotoxy(16,10);printf(".");Sleep(200);
	 	gotoxy(17,10);printf(".");Sleep(200);
	 	gotoxy(18,10);printf(".");Sleep(200);
		
		i++;
		if(i == 6)break;
		}
return 0;
}

/*do{
		gotoxy(x,y);
		printf("+\b");
		tecla = getch();
		
		if(tecla=='a')x--;
		if(tecla=='d')x++;
		if(tecla=='s')y++;
		if(tecla=='w')y--;

	}while(1);*/

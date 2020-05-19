#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 100
using namespace std;

int vidas = 5;
char palavra_secreta[TAM];
int i; 
int acertouUMA = 0;
char nada[TAM]; 
int tamanho_palavra; 
char letra_escolhida[10];
int ponto=0;
int j = 0;
int JaEscolhida=0;
int opcao;
int x;int y;
char tecla;

void gotoxy(int , int);
void pontos(const char[] , int);
void Jogo(void);
int MovendoSeta(int , int , int, int );
void EscolhendoPalavra(void);
void hub(void);

int main(){	
	do{
		for(i = 0 ; i < TAM ; i++)nada[i] = '-';
		system("cls");
		Jogo();
		setbuf(stdin,NULL);
		tecla = 0;
		printf("  Jogar novamente ? \n");
		printf("  Sim");printf("\n  Nao");
		opcao=MovendoSeta(2,1,0,0);
	}while(opcao != 2);
	
return 0;
}

void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void pontos(const char carregando[],int Yparado){
	int fim;int time = 100;
	for(fim = 0 ; fim < strlen(carregando) ; fim++){
	}
	for(int i = 0 ; i < 4 ; i++){
	gotoxy(fim,Yparado);cout<<"   ";
	gotoxy(fim,Yparado);cout<<".";Sleep(time);
	gotoxy(fim+1,Yparado);cout<<".";Sleep(time);
	gotoxy(fim+2,Yparado);cout<<".";Sleep(time);
	}
}

void Jogo(void){

	EscolhendoPalavra();
  vidas = 5;
  ponto = 0;
   while(vidas > 0){
   	
		cout << "***Palavra de " << x << " letras***\n";
		printf("\n%c>>>",201); 
		
		while(j+1 <  strlen(palavra_secreta)){
			cout << nada[j];
			j++;
		}
			
		hub();
		
		if(ponto == x){
			if(vidas > 0){
				gotoxy(0,20); cout << "Voce ganhou!\n";
				system("pause");
			}	
		break;
		}
		
		gotoxy(8,7); scanf("%s",letra_escolhida);
		letra_escolhida[0] = toupper(letra_escolhida[0]);
		
		for(i = 0 ; i <strlen(nada) ; i++){ //PRA VER SE A LETRA JA FOI ESCOLHIDA
			if(letra_escolhida[0] == nada[i]){
				cout << "\n*Esta letra ja foi escolhida.*\n";getch();
				JaEscolhida++;
			}
		}
		
		if(JaEscolhida == 0)
			for(i = 0 ; i < strlen(palavra_secreta) ; i++){ //SE A LETRA É CERTA
				if(letra_escolhida[0] == palavra_secreta[i]){
					nada[i] = letra_escolhida[0];
					acertouUMA++;
					ponto++;
				}
			}
		
		if(acertouUMA == 0 && JaEscolhida != 1)vidas--;	//SE ERRA, PERDE UMA VIDA
			
		j = 0; acertouUMA = 0; JaEscolhida = 0;
		
		setbuf(stdin,NULL);
		system("cls");
	}
	system("cls");
	if(vidas == 0){
		cout << "Voce perdeu!\n";
		system("pause");
	}
	system("cls");
}

int MovendoSeta(int max, int min,int parado, int x_parado){
	int y = min;
	do{
		gotoxy(x_parado,y);printf(">>\b\b");
		
		tecla = getch();
		tecla = tolower(tecla);
		
		if( tecla == 's' && y == min ){
			y++;
			gotoxy(x_parado,y-1);printf("  ");
		}
		if( tecla == 'w' && y == max ){
			y--;
			gotoxy(x_parado,y+1);printf("  ");
		}
	}while(tecla != 32);
	
	return y;
}

void EscolhendoPalavra(void){
	cout << "*****JOGO DA FORCA******\n\n";
	cout << "Escolha quem sera o adivinhador...";pontos("Escolha quem sera o adivinhador",2);
	cout << "\n";
	cout << "Digite a palavra secreta: ";
	fgets(palavra_secreta,TAM,stdin);
	for(i = 0 ; i < strlen(palavra_secreta) ; i++) {
		palavra_secreta[i] = toupper(palavra_secreta[i]);
		if(palavra_secreta[i]==' ') palavra_secreta[i] = '\0';
		//if(palavra_secreta[i] < 65 || palavra_secreta[i]>119){
		//	printf("INVALIDO!\n\n");
		//	system("pause");
		//	exit(1);
		//}
	}
	cout << "Processando...";pontos("Processando",4);
	cout << "\nOkay!..";Sleep(250);

	for( x = 0 ; x < strlen(palavra_secreta) ; x++ ){	
		system("cls");
		cout << "***Palavra de " << x << " letras***";
	}
	x--;	
	system("cls");
}

void hub(void){
		gotoxy(0,3); printf("%c",186);
		gotoxy(0,4); printf("%c",186);
	   gotoxy(0,5); printf("%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,205,205,205,205,187);
		gotoxy(0,6); printf("%cVidas: %d",204,vidas);					gotoxy(10,6); printf("%c",186);
		gotoxy(0,7); printf("%cLetra: ",204);		      				gotoxy(10,7); printf("%c",186);
	   gotoxy(0,8); printf("%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,188);
}

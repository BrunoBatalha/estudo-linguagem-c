#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>//fiz um teste tirei e nao deu erro
#include <windows.h>
#include <locale.h>

#define BORDA 30
//setlocale (LC_ALL,"portuguese");

void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void  BarraDeCarregamento(){
	int coluna = 40;
  	int linha  = 16;
	int i;
	int P=0;
	for(i=0;i<40;i++){
		
		system("color a");
		
		gotoxy(49,20);printf("Inicializando sistema...\n");
		gotoxy(coluna, linha);printf("%c",219);
		printf("%i%%",P);
		P++;
		P++;
		P++;
		if(P>100)P-=17;		
		Sleep(10);
		coluna++;
	}
	//do{
		//gotoxy(49,21);printf("Pressione qualquer tecla para continuar...");
	//	system("cls");
	//	Sleep(200);	
	//}while(1);
	
	Sleep(400);
	system("cls");
}
	
FILE* AbrirArquivo(char modo, char arquivo1[50]){
	FILE *arquivo;
	switch(modo){
		case 'w':
			arquivo = fopen(arquivo1,"wt");
			break;
		case 'r':
			arquivo = fopen(arquivo1,"rt");
			break;
		case 'a':
			arquivo = fopen(arquivo1, "a");
			break;
	}
	if(	arquivo == NULL) {
		printf("Nao foi possivel abrir o arquivo!\n");
	exit(0);
	}
return arquivo;
}

void FecharArquivo(FILE *arquivo){
	fclose(arquivo);	
}

void BordaSuperior(){
	int i;
	printf("%c",201);
	for(i=0;i<BORDA;i++){
		printf("%c",205);
	}
	printf("%c",187);
}

void BordaInferior(int tamX){
	int i;
	printf("%c",200);
	for(i=0;i<BORDA;i++){
		printf("%c",205);
	}
	printf("%c\n",188);
}

void CriarMenuItem(int tamX, char str[]){
	int contaLetras=0;
	int i;
	
	for(i=0;i<tamX;i++){
		if(str[i] == '\0')
			break;
		else
			contaLetras++;
	}
	//	gotoxy(41,16);printf("\n%c",186);
	//for(i=0;i<30;i++){
	gotoxy(41,16);printf("%s",str);
	while(contaLetras<tamX){
		printf("%c",32);
		contaLetras++;
	}
	//printf("%c\n",186);
}

void ExibirCriarContaADM(){
	gotoxy(40,15);BordaSuperior();
   CriarMenuItem(30,"  CRIAR CONTA ADMINISTRADORA");   
	gotoxy(40,17);BordaInferior(30);
	printf("\n");
	getch();
	system("cls");
}

void Informar(char enunciado[],FILE *arquivo){
	char Resp[50];
	printf(enunciado);
	fprintf(arquivo,enunciado);
	fprintf(arquivo,gets(Resp));
	fprintf(arquivo,"\n");
	fflush(stdin);
//	fprintf(arq1,gets(palavra));
}

int main() {
	//TELA DE CARREGAMENTO INICIAL
	
	BarraDeCarregamento();

	FILE *ADMleia;
	FILE *ADMmodificar;
	
	ADMmodificar = AbrirArquivo('a',"Administrador.txt");
	ADMleia = AbrirArquivo('r',"Administrador.txt");
	
	//Depois eu vejo como fazer paara verificar se um arquivo esta vazio
	
	ExibirCriarContaADM();
	
	//pular parte de conferir se ja se tem um conta adm
	
	BordaSuperior();
   CriarMenuItem(20,"Nome:");//Informar("NOME:",ADMmodificar);
	BordaInferior(20);
	getch();
	return 0;
}


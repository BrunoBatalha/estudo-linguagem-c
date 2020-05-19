/* Mudar a cor do texto do terminal, e depois de volta ao normal. */
#include <stdio.h>
#include <windows.h>
//innclude <conio.c>
#include <locale.h>

void Mudar_Cor_Texto(const char Frase[]){

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        WORD saved_attributes;

        /* Salvar estado atual */
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        saved_attributes = consoleInfo.wAttributes;

        SetConsoleTextAttribute(hConsole,RED);
        //SetConsoleTextAttribute(hConsole,BACKGROUND_RED);
        printf("%s",Frase);
        /* Voltando ao estado original */
        SetConsoleTextAttribute(hConsole, saved_attributes);
	
}

int main() {
//    Mudar_Cor_Texto("OI");
    int i = 1000;
    Mudar_Cor_Texto("EITA");
    return 0;
}



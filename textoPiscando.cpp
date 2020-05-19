#include <stdio.h>
#include <conio.h>
#include <dos.h>//fiz um teste tirei e nao deu erro
#include <windows.h>
int main(){
	int i=0;
	
	while(i < 10){
		putxy(10,10,"Texto");
		Sleep(300)
		putxy(10,10,"     ");
		sleep(300)
		i++;
	}
return 0;
}


#include <stdio.h>
#include <stdlib.h>
int main(){
	
	FILE* arq = fopen("Vamo_ver.bat","w");
	if(arq == NULL)exit(0);
	
	fprintf(arq,"cd desktop \nmd TEST\ncd TEST \nmd Deu_Certo \ntaskkill /IM cmd.exe ");
	system("start Vamo_ver.bat");

	
	//FILE* arq2 = fopen("saindo.bat","w");
	//if(arq2 == NULL)exit(0);
	
	//fprintf(arq2,"taskkill /IM cmd.exe exit");
	//system("start saindo.bat");
	
return 0;
}


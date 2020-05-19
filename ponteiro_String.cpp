#include <stdio.h>

int main(){
	char *a, *b;  
	
	a = "abacate";  
	b = "uva";
	
		if (a[0] < b[0])    //[ ] CONFERE A PRIMEIRA LETRA E VE QUEM VEM PRIMEIRO, SEM ISSO ELE APENAS CONFERE, QUEM VEM PRIMEIRO NA MEMORIA
			printf ("%s vem antes de %s no dicionário", a, b); 
	 	else  
		 	printf ("%s vem depois de %s no dicionário", a, b); 
return 0;
}


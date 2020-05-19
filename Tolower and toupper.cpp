#include <stdio.h>
#include <ctype.h>
int main(){
	char a = 'A';
	char b = 'a';
	
	printf("%c - tolower -> %c",a,tolower(a));
	puts(" ");
	printf("%c - toupper -> %c",b,toupper(b));
return 0;
}


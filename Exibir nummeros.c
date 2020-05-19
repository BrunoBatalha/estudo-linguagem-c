#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int sequencia(int);
	int num;
	system ("color 70");
	scanf("%d",&num);
	sequencia(num);
	
	return 0;
}

int sequencia(int n){
	int i=n-1;
	for(;i>=n-(n+n);i--)
		printf("%i\n",i);
		
	return i;
}
	






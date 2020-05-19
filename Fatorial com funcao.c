#include<stdio.h>
#include<stdlib.h>

int main(){
	int fatorial(int, int);
	int a;
	system("color 70");
	scanf("%d",&a);
	printf("Fatorial de %d:\n",a);
	fatorial(a,a);
return 0;
}
//funcao
int fatorial(int i,int a){
	a = 1;
	for(i;i!=0;i--){
		a = i * a;
		printf("%d ",i);
		printf(i!=1?"* ":"= ");
	}
		printf("%d",a);
return i;
return a;

}

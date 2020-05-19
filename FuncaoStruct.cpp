#include <stdio.h>
struct a{
	int x;
	int y;
}b;
int main(){
	b.x=100;b.y=100;
	struct a funcao(struct a x);
	
	printf(" - %d\n",b.x);
	printf(" - %d\n\n",b.y);
	
	b = funcao(b);
	
	printf(" - %d\n",b.x);
	printf(" - %d\n\n",b.y);
	
return 0;
}

struct a funcao(struct a x){
	x.x=5;
	x.y=5;
	return x;
}


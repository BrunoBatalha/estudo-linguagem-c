#include <stdio.h>

struct i{
	int y ;
}I;


int main(){


	//testando funcao "enum" //ATENCAO isso e constante
	enum dias{
		segunda = 1 ,// se dou valor 1 pra esse o resto recebe na ordem  2, 3...
		terca,		// se não dou valor o primeiro recebe 0, e segue 1, 2..	
	};
	 
	 int i;
	 scanf("%d",&i);
	 if(i == segunda)printf("escolhido segunda\n");
	 if(i == terca)printf("escolhido terca\n");
	 
	
	
	//testando variaveis dentro de blocos 
	I.y=5;
	printf("Fora do bloco y = %d\n", I.y);
	 {
	 	int y = 123;
	 	printf("Dentro do bloco x = %d\n",y);
	 	int x = 674;	
	y = I.y;
	 	printf("Dentro do bloco x = %d\n",y);
	 	I.y=x;
	 }
	 printf("Fora do bloco y = %d\n", I.y);
	 

return 0;
}


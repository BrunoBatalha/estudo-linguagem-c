#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	struct tm *ptr;
	time_t lt;
	
	lt = time(NULL);
	ptr = localtime(&lt);
	printf(asctime(ptr));
	printf("-------------------\n\n");
	//{char str[100];
	//
	//	strftime(str,100,"Agora sao %H %p",ltime);
	//	printf(str);
	//}
		printf("-------------------\n\n");

	{//gera numero aleatorio
		int i, stime;
		long ltime;
		
//		ltime = time(NULL);
//		stime = (unsigned) ltime/2;
//		srand(stime);
		srand(time(NULL));
		for (int i=0;i<10;i++)printf("%d ",rand()%10);
	}
	
return 0;
}



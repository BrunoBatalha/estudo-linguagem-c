#include<stdio.h>
#include <stdlib.h>
int main(void)
{
   int i;
   for(i = 0; i < 256; i++)
   {
      printf("%2d = %2c|", i, i);
      if(i%5==0)printf("\n");
      //if(i==5)printf("\n");
   }
   system("pause");
   return 0;
}

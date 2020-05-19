#include <stdio.h>
#include <string.h>

char *p = "subi no onibus";

main(void)
{
     int t;

    /* imprime o conteúdo da string de trás para frente */
    printf("%s\n", p);
    for (t=strlen(p)-1; t > -1; t--)
        printf("%c", p[t]);
}


#include <stdio.h>
#include <string.h>

main(){
    FILE* arq=fopen("Arq.txt","a");
        fprintf(arq,"ata\n");
    fclose(arq);
    arq=fopen("Arq.txt","r+");

    char nome[10];
        while(!feof(arq)){
            if(strcmp("ata\n","ata\n")==0){
                fseek(arq,3,SEEK_CUR);
                fprintf(arq,"c");
                break;
            }
        }
    fclose(arq);

}

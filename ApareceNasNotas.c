#include <stdio.h>
#include <string.h>

int main(){
	
	FILE *arq, *arq1;
	char palavra[50];
	
	arq1 = fopen("Bruno.txt","a");
	
	printf("Palavra que deseja add: ");	gets(palavra);
	
	fprintf(arq1,"%s\n",palavra);         //ou fprintf(arq1,gets(palavra));
 	fclose(arq1);
						


 //system("type Bruno.txt | find \"bruno\"");	 /*ACESSA O PROPRIO SISTEMA USANDO O CMD E REPRODUZ AQUI*/

	
	arq = fopen("Bruno.txt","r");
	
//	while(fgets(palavra,50,arq)!=NULL){	       /*marromenos*/
//		if(strcmp(palavra,"bruno")==1){
//			printf("%s",palavra);
//		}
//	}

	char nome[100];
	printf("Digite o nome que deseja exibir caso ele esteja no bloco: ");
	gets(nome);
	fflush(stdin);
	int i;
	
	for(i=0;i<100;i++){
		if(nome[i]==' '){
			nome[i]='\0';    //caso haja espaco em branco ele tira e coloca o fim ali ('\0')
			break;
		}
	}
	
 //while(fscanf(arq,"%s",palavra)!=EOF){		 /*PULA ESPACOS EM BRANCOS DO BLOCO DE NOTAS DEIXANDO MUITO JUNTO*/
	//	if(strcmp(palavra,nome)==0){
	//	 	printf("nome: %s\n",palavra);  
	 //	}              
	//}
	
	while(!feof(arq)){
		fscanf(arq,"%s",&palavra);
		if(strcmp(palavra,nome)==0){
		 	printf("NOME: %s\n",palavra); 
		}
	}
	fclose(arq);

return 0;
}


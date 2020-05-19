#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct Cadastro{
       int num;
       char nome[100];
       char endereco[100];
       char email[100];
       char data[30];
       char tel[10];
       }C;

FILE *arquivo;

char menu();
void cad();
void listar();
int busca(int);
void buscar();
void alterar();
void sair();
void Enter(char[]);
void EscrevendoNoArq();
void LendoArq();

main(){
      char op;
          while(op!='s'){
               op = menu();
               switch(op){
                  case'1': cad(); break;
                  case'2': listar(); break;
                  case'3': buscar(); break;
                  case'4': alterar(); break;
                  case'5': sair(); break;
               }
       	getchar();
       	getchar();
       }
}

char menu(){
    system ("cls");
    printf("______________________________ *** AGENDA ***________________________________\n\n");
    printf("1- Cadastrar\n");
    printf("2- Listar\n");
    printf("3- Buscar\n");
    printf("4- Alterar\n");
    printf("5- Sair\n\n");
    printf("\nOpcao:\n");
    system ("color 70");
    return (getchar());
}

/*Cadastro de Clientes*/

void cad(){  
	 printf("\n\nNumero de Inscricao:");
    C.num++;
    printf("000%d",C.num);
    setbuf(stdin,NULL);
           printf("\n\nNome:");
           fgets(C.nome,sizeof(C.nome),stdin);
			  setbuf(stdin,NULL);
           printf("\nData de Nascimento:");
           fgets(C.data,sizeof(C.data),stdin);
			  setbuf(stdin,NULL);
           printf("\nEndereco:");
           fgets(C.endereco,sizeof(C.endereco),stdin);
			  setbuf(stdin,NULL);
           printf("\nEmail:");
           fgets(C.email,sizeof(C.email),stdin);
			  setbuf(stdin,NULL);
           printf("\nTelefone:");
           fgets(C.tel,sizeof(C.tel),stdin);
			  setbuf(stdin,NULL);
           
			  EscrevendoNoArq();
           
			  getchar();
         
}

/*Listar*/

void listar(){
   printf("\nRelacao de Clientes\n");
   arquivo= fopen("Agenda.txt","r");if(arquivo==NULL){printf("Erro ao abrir o arquivo");return;}
   char fim;char linha[80];
   int f = 0;
	while(1){
		if(f==20){getchar();break;}
		if((fim=fgetc(arquivo))==EOF)break;
		f++;
		for(int i = 0 ; i < 7 ; i++){
			switch(i){
				case 0:fgets(C.nome,sizeof(C.nome),arquivo);break;
				case 1:fgets(C.data,sizeof(C.data),arquivo);break;
				case 2:fgets(C.endereco,sizeof(C.endereco),arquivo);break;
				case 3:fgets(C.email,sizeof(C.email),arquivo);break;
				case 4:fgets(C.tel,sizeof(C.tel),arquivo);break;
				case 5:fscanf(arquivo,"%d",&C.num);fim = fgetc(arquivo);break;
				case 6:fgets(linha,sizeof(linha),arquivo);break;
			}
		}
		Enter(C.nome);
		Enter(C.data);
		Enter(C.endereco);
		Enter(C.email);
		Enter(C.tel);
		printf("\n-------------------------------------------");
      printf("\nInscricao: %d\nNome: %s\nEndereco: %s\nEmail: %s\nTelefone: %s\nData de Nascimento: %s", C.num, C.nome, C.endereco, C.email, C.tel, C.data);
      printf("\n");
	}    
}

/*Buscar Clientes*/

void buscar(){
     int insc;
     arquivo = fopen("Agenda.txt","r");
     if(arquivo==NULL){
	 	 printf("\nErro ao abrir o arquivo\n");
	  }
	  
     printf("\n");
     printf("\nDigite o Numero da Inscricao do Cliente\n");
     scanf("%d",&insc);
     
     char fim;int verif=0;char linha [80];
     while(1){
     	if((fim = fgetc(arquivo))==EOF)break;
     	 for(int i = 0 ; i < 7 ; i++){
     		switch(i){
				case 0:fgets(C.nome,sizeof(C.nome),arquivo);break;
				case 1:fgets(C.data,sizeof(C.data),arquivo);break;
				case 2:fgets(C.endereco,sizeof(C.endereco),arquivo);break;
				case 3:fgets(C.email,sizeof(C.email),arquivo);break;
				case 4:fgets(C.tel,sizeof(C.tel),arquivo);break;
				case 5:fscanf(arquivo,"%d",&C.num);fim = fgetc(arquivo);break;
				case 6:fgets(linha,sizeof(linha),arquivo);break;
			}
	  	 }
			if(C.num == insc){
				verif++;
				break;
			}  	
	  }
	  if(verif!=0){
	  	Enter(C.nome);
		Enter(C.data);
		Enter(C.endereco);
		Enter(C.email);
		Enter(C.tel);
				printf("\nInscricao: %d\n", C.num);
            printf("Nome: %s\n", C.nome);
         	printf("Data de Nascimento: %s\n", C.data);
            printf("Endereco: %s\n", C.endereco);
         	printf("Email: %s\n", C.email);
            printf("Telefone: %s\n", C.tel);  
            
             getchar();
	  }else{
	  		printf("\nNumero de inscricao invalido\n");
	  		 getchar(); 	
	  }                     
   fclose(arquivo);
}

/*Alterar*/

void alterar(){
     arquivo= fopen("Agenda.txt","r");
     if(arquivo==NULL){
                       printf("Erro ao abrir o arquivo");
                       return;
     }
     char fim;
	 char linha [80];
	 int q=0; 
    while(1){
     	if((fim = fgetc(arquivo))==EOF)break;
     	q++;
     	 for(int i = 0 ; i < 7 ; i++){
     		switch(i){
				case 0:fgets(C.nome,sizeof(C.nome),arquivo);break;
				case 1:fgets(C.data,sizeof(C.data),arquivo);break;
				case 2:fgets(C.endereco,sizeof(C.endereco),arquivo);break;
				case 3:fgets(C.email,sizeof(C.email),arquivo);break;
				case 4:fgets(C.tel,sizeof(C.tel),arquivo);break;
				case 5:fscanf(arquivo,"%d",&C.num);fim = fgetc(arquivo);break;
				case 6:fgets(linha,sizeof(linha),arquivo);break;
			}
	 	 }	
	}
	struct Cadastro Copia[q];
	int v=0;
	rewind(arquivo);
	while(1){
    if((fim = fgetc(arquivo))==EOF)break;
     	 for(int i = 0 ; i < 7 ; i++){
     		switch(i){
				case 0:fgets(Copia[v].nome,sizeof(Copia[v].nome),arquivo);break;
				case 1:fgets(Copia[v].data,sizeof(Copia[v].data),arquivo);break;
				case 2:fgets(Copia[v].endereco,sizeof(Copia[v].endereco),arquivo);break;
				case 3:fgets(Copia[v].email,sizeof(Copia[v].email),arquivo);break;
				case 4:fgets(Copia[v].tel,sizeof(Copia[v].tel),arquivo);break;
				case 5:fscanf(arquivo,"%d",&Copia[v].num);fim = fgetc(arquivo);break;
				case 6:fgets(linha,sizeof(linha),arquivo);break;
			}
	 	 }
		  v++;	
	}
	fclose(arquivo);
   int num;int verif=0;
    printf("\nAlteracao de Cadastro\n");
    printf("\n\nNumero de Inscricao:");
    scanf("%d",&num);
    for(int i=0 ; i<q ; i++){
    	if(num == Copia[i].num){
    		printf("\n\nNome:");
           setbuf(stdin,NULL);
           fgets(Copia[i].nome,sizeof(Copia[i].nome),stdin);
           printf("\nData de Nascimento:");
           setbuf(stdin,NULL);
			  fgets(Copia[i].data,sizeof(Copia[i].data),stdin);
           printf("\nEndereco:");
           setbuf(stdin,NULL);
           fgets(Copia[i].endereco,sizeof(Copia[i].endereco),stdin);
           printf("\nEmail:");
           setbuf(stdin,NULL);
           fgets(Copia[i].email,sizeof(Copia[i].email),stdin);
           printf("\nTelefone:");
           setbuf(stdin,NULL);
           fgets(Copia[i].tel,sizeof(Copia[v].tel),stdin);
           verif++;
           break;
		 }
	 }
    if(verif == 0){
    		printf("\nNumero de inscricao invalido\n");
	  		 getchar();	
	 }else{
	 	arquivo = fopen ("Agenda.txt", "w");
    	if(arquivo==NULL){printf("\nErro ao abrir o arquivo \n");return;}
    	
    	for(int i = 0 ;i<q;i++){
    		fprintf(arquivo," %s",Copia[i].nome);
    		fprintf(arquivo,"%s",Copia[i].data);
    		fprintf(arquivo,"%s",Copia[i].endereco);
    		fprintf(arquivo,"%s",Copia[i].email);
    		fprintf(arquivo,"%s",Copia[i].tel);
    		fprintf(arquivo,"%d\n",Copia[i].num);
    		fprintf(arquivo,"________________________________\n");
		 }
    	fclose(arquivo);
	 }

         

}

void sair(){
       int i;
       printf("\nFinalizandoo");
       for (i=0; i<35; i++){
           Sleep(500);
       system ("color a");

       printf(" . ");
       }
       exit(1);
       }

void Enter(char string[]){
	for (int i = 0 ; i < strlen(string) ; i++)
		if(string[i]=='\n')string[i]='\0';
}

void EscrevendoNoArq(void){
	 arquivo = fopen ("Agenda.txt", "a");
    if(arquivo==NULL){printf("\nErro ao abrir o arquivo \n");return;}
    fprintf(arquivo," %s",C.nome);
    fprintf(arquivo,"%s",C.data);
    fprintf(arquivo,"%s",C.endereco);
    fprintf(arquivo,"%s",C.email);
    fprintf(arquivo,"%s",C.tel);
    fprintf(arquivo,"%d\n",C.num);
    fprintf(arquivo,"________________________________\n");
    fclose(arquivo);
}

//






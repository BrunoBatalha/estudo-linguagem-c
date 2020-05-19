
//PROGRAMA DESENVOLVIDO NO 1° ANO DO ENSINO MÉDIO POR: BRUNO BATALHA | CAROLINE BRAZ | ANA PAULA | GABRIEL SANTIAGO

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
//#include <conio.c> usando isso modifica o gotoxy :(
#define TAMANHO 1000
//STRUCTS
struct dados{
	char nomecompleto[50];
	char email[30];
	char senha[10];
}informacoes;

struct Dados_pessoas{
	char Nome[100];
	char DataDeNascimento[12];
	char Sexo[10];
	char Nacionalidade[30];
	char CPF[10];
	char RG[11];
	char TipoSanguineo[4];
	char Endereco[60];
	char Email[45];
	float Salario;
	int Turno;
	int Carga_Horaria;
	char Cargo[20];

}dados[TAMANHO];

//DECLARAÇÕES DAS VARIÁVEIS GLOBAIS
int contador_struct=0;

//DECLARÇÕES DOS PONTEIROS GLOBAIS
FILE *funcionarios;

//DECLARAÇÕES DAS FUNÇÕES GLOBAIS
FILE* AbrirArquivo(char,const char[]);
void FecharArquivo(FILE*);
void RemoverArquivo(const char[]);
void QuantidadeDeFuncionarios(char);
void Criar_Perfil(void);
void lendo_dados_para_struct(void);
void Menu(int);
void Listar_Perfis(int);
void Alterar(int);
void Demitir(int);
void BarraDeCarregamento();
void gotoxy(int, int);
int MovendoSetaVertical( int, int, int, int,int);
void lacuna(int);
void copiandoParaFiles(int);
void OpenALLFile(char);
void ClosedALLFile(void);
void RemoveALLFIle(void);
void Grade2(void);
void Grade(void);
void quadrado(int);
int TelaDeConfirmacao(int);
void QuantidadeSexo(void);
void MediaCargaHoraria(void);
void QuantTurno(void);
void MediaSalarios(void);
void entradaadm();
void Grade3(void);
void msgs(int);
void InfomacaoInvalida(void);
void Mudar_Cor_Texto(const char[],int,float);
void mostrardadosdemo(void);
void Validar_datadenascimento(const  char[]);
void Validar_sexo(char[]);
void Validar_turno(int);
void Validar_salario(float);
void Validar_tiposanguineo(char[]);
void barra2(void);
void ZerosUnsCOR(const char[]);
void zerouns(void);
void desenho(void);
void imprimirdados(int);
void busca_funcionario(void);

//PRINCIPAL
int main(){
	system("title *GERENCIAMENTO DE FUNCIONÁRIOS*");
	system("type INSTRUÇÕES_DE_USO_PROGRAMA.DAT");printf("\nOBRIGADO!\n");
	system("pause");system("cls");
   system("color E");
	
	entradaadm();
	gotoxy(33,24);printf("PRESSIONE [W] PARA SUBIR\t\t PRESSIONE [S] PARA DESCER");setbuf(stdin,NULL);
	gotoxy(32,26);printf("PRESSIONE [A] PARA DIREITA\t\tPRESSIONE [D] PARA ESQUERDA");setbuf(stdin,NULL);
	lendo_dados_para_struct();
	//system("alan_walker_faded_aac_45162.m4a");
	BarraDeCarregamento();
	Menu(9);
return 0;
}

//FUNÇÕES
void Menu(int home){
	int opcao;
	do{
		system("cls");
        zerouns();desenho();
                                        ///      /
         gotoxy(59,5 );      printf("             ");
        gotoxy(57,6 );     printf("      MENU       ");
        gotoxy(55,7 );   printf("                     ");
        gotoxy(54,8 );  printf("                       ");
		gotoxy(53,9 ); printf("  CADASTRAR FUNCION%cRIO  ", 181);
 		gotoxy(53,10); printf("  LISTA DE FUNCION%cRIOS  ", 181);
		gotoxy(53,11); printf("        PESQUISAR         ", 128);
		gotoxy(53,12); printf("    DADOS DA EMPRESA     ");
		gotoxy(53,13); printf("          SAIR           ");
		gotoxy(54,14);  printf("                       ");
		gotoxy(57,15);     printf("     WEBTECH     ");
        gotoxy(55,16);   printf("                     ");
        gotoxy(54,17);  printf("                       ");
		opcao=MovendoSetaVertical(13,9,53,1,home);

		switch(opcao){
			case 9:{
				if(TelaDeConfirmacao(0)==2)Menu(9);
				Criar_Perfil();
				break;
			}
			case 10:{
				Listar_Perfis(2);
				break;
			}
			case 11:{
				system("cls");
				busca_funcionario();
				break;
			}
			case 12:{
				int i=1;
				system("cls");
				zerouns();int pos=52;
				gotoxy(pos,0);     printf("              ");
				gotoxy(pos-2,1);   printf("                  ");
				gotoxy(pos-3,2);printf(" DADOS DEMOGR%cFICOS ", 181);
				gotoxy(pos-4,3);printf("                      ");
				gotoxy(pos-3,4); printf("                    ");
				QuantidadeSexo();
				MediaCargaHoraria();
				QuantTurno();
				MediaSalarios();
				gotoxy(0,0);getch();
				setbuf(stdin,NULL);
				break;
			}
			case 13:{
			    if(TelaDeConfirmacao(-1)==1)exit(0);
			    Menu(13);
         break;
			}
			default: opcao = 'i';break;
		}
		setbuf(stdin, NULL);
	}while (opcao != 'x');
}


void PassaPraMaiusculo(char Nome[]){
    for(int i=0;i<strlen(Nome);i++){
        Nome[i]=toupper(Nome[i]);
    }
}


void Criar_Perfil(void){
	system("cls");
	setbuf(stdin, NULL);
	QuantidadeDeFuncionarios('r');
    zerouns();
	int opcao1 = 3;
	while(opcao1 != 1){
				if (contador_struct >= TAMANHO){
					printf("\t\tº°°°°°°°°°°°°°°°°°°°°°°°°°°°°°º\n\t\tº°°TOTAL DE VAGAS PREENCHIDAS°°º\n\t\tº°°°°°°°°°°°°°°°°°°°°°°°°°°°°°º");
					getch();
					break;
				}

		{		//variaveis temporarias
					char Nome[100];char DataDeNascimento[12];char Sexo[10];
					char Nacionalidade[30];char CPF[14];char RG[11];
					char TipoSanguineo[4];char Pai[100];char Mae[100];
					char Endereco[60];char Email[45];float Salario;
					int Turno;int Carga_Horaria;char Cargo[20];
				Grade();
				gotoxy(52,1);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220,220,220,
                                    220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220);
				gotoxy(52,2 );printf("%c   CADASTRO DE FUNCION%cRIO   %c",219,181,219);
                gotoxy(52,3);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,220,220,220,220,220,220,220,220,220,
                                    220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,220,219);
				gotoxy(25,6 );printf("NOME:");					        gotoxy(70,6 );printf("SEXO(M/F):");
				gotoxy(25,8 );printf("DATA DE NASCIMENTO(DD/MM/AAAA):");gotoxy(70,8 );printf("EMAIL:");
				gotoxy(25,10);printf("CARGO NA EMPRESA:");	            gotoxy(70,10);printf("CPF:");
				gotoxy(25,12);printf("TURNO(1%c,2%c,3%c):",248,248,248);gotoxy(70,12);printf("RG(XXXXXXX-X):");
				gotoxy(25,14);printf("CARGA HOR%cRIA (h):", 181);	    gotoxy(70,14);printf("ENDERE%cO:", 128);
				gotoxy(25,16);printf("SAL%cRIO R$:", 181);			    gotoxy(70,16);printf("TIPO SANGU%cNEO:", 214);       //
				gotoxy(25,18);printf("NACIONALIDADE:");

				gotoxy(31,6 );fgets(Nome,100,stdin);setbuf(stdin,NULL);if(Nome[0]== '2' && Nome[1]=='4')break;if(strcmp(Nome,"time7\n")==0){msgs(0);break;}
					PassaPraMaiusculo(Nome);
				gotoxy(57,8 );fgets(DataDeNascimento,12,stdin);setbuf(stdin,NULL); Validar_datadenascimento(DataDeNascimento);
				gotoxy(43,10);fgets(Cargo,20,stdin);setbuf(stdin,NULL);
					PassaPraMaiusculo(Cargo);
				gotoxy(42,12);scanf("%d",&Turno);setbuf(stdin,NULL);gotoxy(43,12);putc(248,stdout); Validar_turno(Turno);
				gotoxy(44,14);scanf("%d",&Carga_Horaria);setbuf(stdin,NULL);
				gotoxy(37,16);scanf("%f",&Salario);setbuf(stdin,NULL); Validar_salario(Salario);
				gotoxy(40,18);fgets(Nacionalidade,30,stdin);setbuf(stdin,NULL);
					PassaPraMaiusculo(Nacionalidade);
				gotoxy(81,6 );fgets(Sexo,10,stdin);Validar_sexo(Sexo);
				gotoxy(77,8 );fgets(Email,45,stdin);setbuf(stdin,NULL);
				gotoxy(74,10);fgets(CPF,14,stdin);setbuf(stdin,NULL);
				gotoxy(85,12);fgets(RG,11,stdin);setbuf(stdin,NULL);
				gotoxy(80,14);fgets(Endereco,60,stdin);setbuf(stdin,NULL);
					PassaPraMaiusculo(Endereco);
				gotoxy(86,16);fgets(TipoSanguineo,4,stdin);setbuf(stdin,NULL);
				Validar_tiposanguineo(TipoSanguineo);
				while(opcao1 != 2 && opcao1 != 1){                      //
                    gotoxy(70,18);printf("FECHANDO MENU DE CADASTRO...");
                    opcao1 = TelaDeConfirmacao(0);
					//gotoxy(103,18);scanf("%d",&opcao1);
						if(opcao1 == 1){
							//Passando para a struct
							strcpy(dados[contador_struct].Nome,Nome);
							strcpy(dados[contador_struct].DataDeNascimento,DataDeNascimento);
							strcpy(dados[contador_struct].Sexo,Sexo);
							strcpy(dados[contador_struct].Nacionalidade,Nacionalidade);
							strcpy(dados[contador_struct].CPF,CPF);
							strcpy(dados[contador_struct].RG,RG);
							strcpy(dados[contador_struct].TipoSanguineo,TipoSanguineo);
							strcpy(dados[contador_struct].Endereco,Endereco);
							strcpy(dados[contador_struct].Email,Email);
							dados[contador_struct].Turno = Turno;
							dados[contador_struct].Salario = Salario;
							dados[contador_struct].Carga_Horaria = Carga_Horaria;
							strcpy(dados[contador_struct].Cargo,Cargo);

							//Passando pros arquivos
							funcionarios = AbrirArquivo('a',"Funcionários.txt");
							copiandoParaFiles(contador_struct);
							FecharArquivo(funcionarios);
							contador_struct++;
							QuantidadeDeFuncionarios('w');
                            printf("\a\a");
							Menu(9);
					}else if(opcao1 == 2) break;
			}
		if(opcao1 == 2)break;
		}
	}
}

//Funcoes para verificar se ta tudo ceertinho :)
void Validar_datadenascimento(const char DataDeNascimento[]){
     int quantCarac = strlen(DataDeNascimento);
    if(quantCarac<11||quantCarac>11){InfomacaoInvalida();Menu(9);}
        for(int cont=0;cont<12;cont++){
            if(DataDeNascimento[2] =='/' && DataDeNascimento[5] =='/')continue;
            else {InfomacaoInvalida();Menu(9);}
            if(DataDeNascimento[cont]>='0')continue;
            else {InfomacaoInvalida();Menu(9);}
        }
}
void Validar_turno(int Turno){
    if(Turno < 1 || Turno > 3){InfomacaoInvalida();Menu(9);}
}
void Validar_sexo(char Sexo[]){
    Sexo[0]=toupper(Sexo[0]);setbuf(stdin,NULL);if(Sexo[0]!= 'M' && Sexo[0]!='F'){InfomacaoInvalida();Menu(9);}
}
void Validar_salario(float Salario){
    if(Salario>=0){}
    else {InfomacaoInvalida();Menu(9);}
}
void Validar_tiposanguineo(char TipoSanguineo[]){
    // o ab  a
    for(int i=0;i<2;TipoSanguineo[i]=toupper(TipoSanguineo[i]),i++){}
    if(strcmp(TipoSanguineo,"O\n") != 0 &&
       strcmp(TipoSanguineo,"AB\n") != 0&&
       strcmp(TipoSanguineo,"A\n") != 0 &&
       strcmp(TipoSanguineo,"B\n"))
    {InfomacaoInvalida();Menu(9);}
}


void Listar_Perfis(int home){
  	QuantidadeDeFuncionarios('r');
  	system("cls");setbuf(stdin, NULL);
	zerouns();
	int j=0;
	int posVertical=3;
	int matriz[contador_struct][2];
    gotoxy(27,0);putc(218,stdout);
	gotoxy(28,0);for(int cont=28;cont<94;printf("%c",196),cont++){} printf("%c",191);
	gotoxy(27,1);printf("%c                      LISTA DE FUNCION%cRIOS                       %c",179,181,179);
    gotoxy(27,2);printf("%c                                                                  %c",179,179);
    gotoxy(30,2);printf("   ------------->>VOLTAR AO MENU PRINCIPAL<<----------------");
	gotoxy(27,posVertical);printf("%c",195);gotoxy(94,posVertical);printf("%c",180);

	int i;
	int g = contador_struct-2;
	for(int i=28 ; i<94 ;gotoxy(i,posVertical),printf("%c",196), i++){}
	while(j < contador_struct){
		posVertical++;
		matriz[j][0] = j;	matriz[j][1] = posVertical;
		gotoxy(27,posVertical);printf("%c",179);gotoxy(45,posVertical);for(int w=0;w<48;w++)printf(" ");printf(" %c",179);
		gotoxy(28,posVertical);printf("   %d.FUNCION%cRIO: %s", j+1, 181, dados[j].Nome);
		posVertical++;
		for(int i = 27 ; i < 95 ; i++){
			if(i==27){gotoxy(i,posVertical);printf("%c",195);
			}else if(i==94){gotoxy(i,posVertical);printf("%c",180);
					}else{gotoxy(i,posVertical);printf("%c",196);}
		}
		Sleep(100);
		j++;
	}
	gotoxy(27,posVertical);printf("%c",192);gotoxy(94,posVertical);printf("%c",217);
	 i=0;int x;int opcaoX;
	int opcao= MovendoSetaVertical(posVertical-1,2,28,2,home);
	int cursor=opcao;
	if(opcao==2)Menu(10);
	while(i < contador_struct){
		if(opcao == matriz[i][1]){
			x=matriz[i][0];
			quadrado(opcao); //CRIA O QUADRADO QUE APARECE QUANDO CLICA EM ALGUM FUNCIONARIO
			gotoxy(60,opcao); printf(" NOME: "); Mudar_Cor_Texto(dados[x].Nome,-1,-1);opcao++;
			gotoxy(60,opcao); printf(" DATA DE NASCIMENTO: "); Mudar_Cor_Texto(dados[x].DataDeNascimento,-1,-1);opcao++;
			gotoxy(60,opcao); printf(" SEXO: "); Mudar_Cor_Texto(dados[x].Sexo,-1,-1);opcao++;
			gotoxy(60,opcao); printf(" NACIONALIDADE: "); Mudar_Cor_Texto(dados[x].Nacionalidade,-1,-1);opcao++;
			gotoxy(60,opcao); printf(" CPF: "); Mudar_Cor_Texto(dados[x].CPF,-1,-1);opcao++;
			gotoxy(60,opcao); printf(" RG: "); Mudar_Cor_Texto(dados[x].RG,-1,-1);opcao++;
			gotoxy(60,opcao); printf(" TIPO SANGU%cNEO: ", 214); Mudar_Cor_Texto(dados[x].TipoSanguineo,-1,-1);opcao++;
			gotoxy(60,opcao); printf(" ENDERE%cO: ", 128); Mudar_Cor_Texto(dados[x].Endereco,-1,-1);opcao++;
			gotoxy(60,opcao); printf(" EMAIL: "); Mudar_Cor_Texto(dados[x].Email,-1,-1);opcao++;
			gotoxy(60,opcao); printf(" SAL%cRIO: R$ ",181); Mudar_Cor_Texto("SEM STRING",-1,dados[x].Salario);opcao++;
			gotoxy(60,opcao); printf(" TURNO: "); Mudar_Cor_Texto("SEM STRING",dados[x].Turno,-1);printf(" %c",248);opcao++;
			gotoxy(60,opcao); printf(" CARGA HOR%cRIA: ",181); Mudar_Cor_Texto("SEM STRING",dados[x].Carga_Horaria,-1);puts(" HORA(s)");opcao++;
			gotoxy(60,opcao); printf(" CARGO NA EMPRESA: "); Mudar_Cor_Texto(dados[x].Cargo,-1,-1);opcao++;opcao++;opcao++;
			gotoxy(60,opcao); printf("   ALTERAR ");opcao++;
			gotoxy(60,opcao); printf("   DEMITIR ");opcao++;
			gotoxy(60,opcao); printf("   VOLTAR ");
			opcaoX = MovendoSetaVertical(opcao,opcao-2,61,1,opcao);
			if(opcaoX==opcao-2)Alterar(x);
			if(opcaoX==opcao-1){if(TelaDeConfirmacao(0)==2)Listar_Perfis(cursor);Demitir(x);}
			Listar_Perfis(cursor);
		}
		i++;
	}
}

void Alterar(int n_funcionario){
	int y=3;int i=1;
	int opcao;
	int c=35;
	int matriz[13][2];int j=0;
	system("cls");
    zerouns();
	Grade2();
	gotoxy(45,0); printf(" CLIQUE NA OP%cAO QUE DESEJA ALTERAR ", 128);
    gotoxy(45,1); printf("    ---VOLTAR AO MENU ANTERIOR---");
	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  NOME: ");Mudar_Cor_Texto(dados[n_funcionario].Nome,-1,-1);y++;y++;

    matriz[j][0]=j; matriz[j][1]=y; j++;
    gotoxy(c,y); printf("  DATA DE NASCIMENTO(dd/mm/aaaa): ");Mudar_Cor_Texto(dados[n_funcionario].DataDeNascimento,-1,-1);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  SEXO: ");Mudar_Cor_Texto(dados[n_funcionario].Sexo,-1,-1);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
    gotoxy(c,y); printf("  NACIONALIDADE: ");Mudar_Cor_Texto(dados[n_funcionario].Nacionalidade,-1,-1);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  CPF: ");Mudar_Cor_Texto(dados[n_funcionario].CPF,-1,-1);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  RG: "); Mudar_Cor_Texto(dados[n_funcionario].RG,-1,-1);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  TIPO SANGUINEO: ");  Mudar_Cor_Texto(dados[n_funcionario].TipoSanguineo,-1,-1);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  ENDERECO: "); Mudar_Cor_Texto(dados[n_funcionario].Endereco,-1,-1);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  EMAIL: ");Mudar_Cor_Texto(dados[n_funcionario].Email,-1,-1);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  SALARIO: R$ "); Mudar_Cor_Texto("SEM STRIN",-1,dados[n_funcionario].Salario);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  TURNO: "); Mudar_Cor_Texto("SEM STRING",dados[n_funcionario].Turno,-1);putc(248,stdout);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  CARGA HORARIA: "); Mudar_Cor_Texto("SEM STRING",dados[n_funcionario].Carga_Horaria,-1);printf(" HORA(S)");y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y;
	gotoxy(c,y); printf("  CARGO NA EMPRESA: ");Mudar_Cor_Texto(dados[n_funcionario].Cargo,-1,-1);



    char Nome[100];char DataDeNascimento[12];char Sexo[10];
    char Nacionalidade[30];char CPF[14];char RG[11];
    char TipoSanguineo[4];char Pai[100];char Mae[100];
    char Endereco[60];char Email[45];float Salario;
    int Turno;int Carga_Horaria;char Cargo[20];
	int aux=0;
	opcao = MovendoSetaVertical(y,1,c,2,1);
	int posY=3;
	setbuf(stdin,NULL);

	for(int i=0;i<13;i++){
		if(matriz[i][1]==opcao){
			switch(i){
				case 0 :{
						gotoxy(c+8,posY);printf("                              ");
						gotoxy(c+8,posY);fgets(Nome,sizeof(Nome),stdin);
						PassaPraMaiusculo(Nome);	if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						strcpy(dados[n_funcionario].Nome,Nome);aux++;
					break;
				}
				case 1:{
				    gotoxy(c+34,posY+2);printf("             ");
				    gotoxy(c+34,posY+2);fgets(DataDeNascimento,12,stdin);
				    Validar_datadenascimento(DataDeNascimento);	if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
				    strcpy(dados[n_funcionario].DataDeNascimento,DataDeNascimento);aux++;
              break;
				}
				case 2 :{
						gotoxy(c+8,posY+4);printf("                              ");
						gotoxy(c+8,posY+4);fgets(Sexo,10,stdin);
						Validar_sexo(Sexo);	if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						strcpy(dados[n_funcionario].Sexo,Sexo);aux++;
					break;
				}
				case 3 :{
						gotoxy(c+17,posY+6);printf("                             ");
						gotoxy(c+17,posY+6);fgets(Nacionalidade,sizeof(Nacionalidade),stdin);
						PassaPraMaiusculo(Nacionalidade);	if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						strcpy(dados[n_funcionario].Nacionalidade,Nacionalidade);aux++;
					break;
				}
				case 4 :{
					 	gotoxy(c+7,posY+8);printf("                              ");
						gotoxy(c+7,posY+8);fgets(CPF,14,stdin);   if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						strcpy(dados[n_funcionario].CPF,CPF);
					break;
				}
				case 5 :{
						gotoxy(c+6,posY+10);printf("                              ");
						gotoxy(c+6,posY+10);fgets(RG,11,stdin);   if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						strcpy(dados[n_funcionario].RG,RG);
					break;
				}
				case 6 :{
						gotoxy(c+18,posY+12);printf("                              ");
						gotoxy(c+18,posY+12);fgets(TipoSanguineo,4,stdin);
						Validar_tiposanguineo(TipoSanguineo);if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						strcpy(dados[n_funcionario].TipoSanguineo,TipoSanguineo);aux++;
					break;
				}
				case 7 :{
						gotoxy(c+12,posY+14);printf("                              ");
						gotoxy(c+12,posY+14);fgets(Endereco,sizeof(Endereco),stdin);
						PassaPraMaiusculo(Endereco);	if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						strcpy(dados[n_funcionario].Endereco,Endereco);aux++;
					break;
				}
				case 8 :{
						gotoxy(c+9,posY+16);printf("                              ");
						gotoxy(c+9,posY+16);fgets(Email,sizeof(Email),stdin);	if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						strcpy(dados[n_funcionario].Email,Email);aux++;
					break;
				}
				case 9 :{
						gotoxy(c+14,posY+18);printf("                              ");
						gotoxy(c+14,posY+18);scanf("%f",&Salario);
						Validar_salario(Salario);if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						dados[n_funcionario].Salario = Salario;
					break;
				}
				case 10 :{
						gotoxy(c+8,posY+20);printf("                              ");
						gotoxy(c+8,posY+20);scanf("%d",&Turno);
						Validar_turno(Turno);if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						dados[n_funcionario].Turno=Turno;
					break;
				}
				case 11:{
						gotoxy(c+16,posY+22);printf("   ");
						gotoxy(c+17,posY+22);scanf("%d",&dados[n_funcionario].Carga_Horaria);	
						if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						dados[n_funcionario].Carga_Horaria = Carga_Horaria;aux++;
					break;
				}
				case 12:{
						gotoxy(c+20,posY+24);printf("                              ");
						gotoxy(c+20,posY+24);fgets(Cargo,sizeof(Cargo),stdin);
						PassaPraMaiusculo(Cargo);	if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
						strcpy(dados[n_funcionario].Cargo,Cargo);aux++;
					break;
				}
			}
			if(TelaDeConfirmacao(0)==2)Alterar(n_funcionario);
			gotoxy(0,6 );printf("         ");
			gotoxy(0,7 );printf("                ");
			gotoxy(0,8 );printf("                   ");
         gotoxy(0,9 );printf("                     ");
         gotoxy(0,10);printf("SALVANDO DADOS...    ");
         gotoxy(0,11);printf("                   ");
         gotoxy(0,12);printf("                ");
         gotoxy(0,13);printf("         ");
			barra2();
           // RemoveALLFIle();
         gotoxy(0,10);printf("                     ");Sleep(100);
			gotoxy(0,10);printf("SALVO\a");Sleep(100);
            QuantidadeDeFuncionarios('r');
            funcionarios = AbrirArquivo('w',"Funcionários.txt");
            for(int i=0;i<contador_struct;i++){
                copiandoParaFiles(i);
            }
            FecharArquivo(funcionarios);
           // lendo_dados_para_struct();
		}
	}
}

void Demitir(int n_funcionario){
	system("cls");setbuf(stdin,NULL);
	QuantidadeDeFuncionarios('r');
	//RemoveALLFIle();
	funcionarios = AbrirArquivo('w',"Funcionários.txt");
	int j;
	for(j = 0 ; j < contador_struct ; j++){
			if(n_funcionario != j){
					fprintf(funcionarios , "%s" , dados[j].Nome);
					fprintf(funcionarios , "%s" , dados[j].DataDeNascimento);
					fprintf(funcionarios , "%s\n" , dados[j].Sexo);
					fprintf(funcionarios, "%s", dados[j].Nacionalidade);
					fprintf(funcionarios, "%s\n", dados[j].CPF);
					fprintf(funcionarios, "%s\n", dados[j].RG);
					fprintf(funcionarios, "%s", dados[j].TipoSanguineo);
					fprintf(funcionarios, "%s", dados[j].Endereco);
					fprintf(funcionarios, "%s", dados[j].Email);
					fprintf(funcionarios, "%.2f\n", dados[j].Salario);
					fprintf(funcionarios, "%d\n", dados[j].Turno);
					fprintf(funcionarios, "%d\n",dados[j].Carga_Horaria);
					fprintf(funcionarios, "%s",dados[j].Cargo);
			}
	}
	FecharArquivo(funcionarios);
	contador_struct--;
	QuantidadeDeFuncionarios('w');
	lendo_dados_para_struct();
	printf("+++DEMITIDO!+++\n");Sleep(200);
	Listar_Perfis(2);
}


void lendo_dados_para_struct(void){
	funcionarios = AbrirArquivo('r',"Funcionários.txt");
	QuantidadeDeFuncionarios('r');
	int i=0;
	char num[81];
	while(1){
		if(i==contador_struct)break;
	 for(int x= 0 ; x < 14 ; x++){
		switch(x){
			case 0:{
				fgets(dados[i].Nome,sizeof(dados[i].Nome),funcionarios);
				printf("\nx = %d | %s",x,dados[i].Nome);
				break;
			}
			case 1:{
				fgets(dados[i].DataDeNascimento,sizeof(dados[i].DataDeNascimento),funcionarios);
				printf("x = %d | %s\n",x,dados[i].DataDeNascimento);
				break;
			}
			case 2:{
				fgets(dados[i].Sexo,sizeof(dados[i].Sexo),funcionarios);
				printf("x = %d | %s\n",x,dados[i].Sexo);
				break;
			}
			case 3:{
				fgets(dados[i].Nacionalidade,sizeof(dados[i].Nacionalidade),funcionarios);
				printf("x = %d | %s\n",x,dados[i].Nacionalidade);
				break;
			}
			case 4:{
				fgets(dados[i].CPF,sizeof(dados[i].CPF),funcionarios);
				printf("x = %d | %s\n",x,dados[i].CPF);
				break;
			}
			case 5:{
				fgets(dados[i].RG,11,funcionarios);
				printf("x = %d | %s\n",x,dados[i].RG);
				break;
			}
			case 6:{
				fgets(dados[i].TipoSanguineo,4,funcionarios);
				printf("x = %d | %s\n",x,dados[i].TipoSanguineo);
				break;
			}
			case 7:{
				fgets(dados[i].Endereco,60,funcionarios);
				printf("x = %d | endereco = %s\n",x,dados[i].Endereco);
				break;
			}
			case 8:{
				fgets(dados[i].Email,45,funcionarios);
				printf("x = %d | %s\n",x,dados[i].Email);
				break;
			}
			case 9:{
				fgets(num,81,funcionarios);
				dados[i].Turno = atoi(num);
				printf("x = %d | %d\n",x,dados[i].Turno);
				break;
			}
			case 10:{
				fgets(num,81,funcionarios);
				dados[i].Salario = atof(num);
				printf("x = %d | %.2f\n",x,dados[i].Salario);
				break;
			}
			case 11:{
				fgets(num,81,funcionarios);
				dados[i].Carga_Horaria = atoi(num);
				printf("x = %d | %d\n",x,dados[i].Carga_Horaria);
				break;
			}
			case 12:{
				fgets(dados[i].Cargo,20,funcionarios);
				printf("x = %d | %s\n",x,dados[i].Cargo);
				break;
			}
			case 13:{
				fgets(num,81,funcionarios);
				break;
			}
			}
		}
	 system("pause");
	 i++;
	}
	FecharArquivo(funcionarios);;
 }

void QuantidadeDeFuncionarios(char tipo){
	FILE *arq;
	switch(tipo){
		case 'w':{
			arq = AbrirArquivo('w',"Vagas.txt");
						fprintf(arq,"%d",contador_struct);
				FecharArquivo(arq);
			break;
		}
		case 'r':{
			arq = AbrirArquivo('r',"Vagas.txt");
					if(arq == NULL){
						arq = AbrirArquivo('w',"Vagas.txt");
							fprintf(arq,"%d",0);
						FecharArquivo(arq);
						arq = AbrirArquivo('r',"Vagas.txt");
					}
				fscanf(arq,"%d",&contador_struct);
				FecharArquivo(arq);
			break;
		}
	}
}

void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void copiandoParaFiles(int numero){
		fprintf(funcionarios,"%s",dados[numero].Nome);
		fprintf(funcionarios,"%s",dados[numero].DataDeNascimento);
		fprintf(funcionarios,"%s",dados[numero].Sexo);
		fprintf(funcionarios,"%s",dados[numero].Nacionalidade);
		fprintf(funcionarios,"%s",dados[numero].CPF);
		fprintf(funcionarios,"%s",dados[numero].RG);
		fprintf(funcionarios,"%s",dados[numero].TipoSanguineo);
		fprintf(funcionarios,"%s",dados[numero].Endereco);
		fprintf(funcionarios,"%s",dados[numero].Email);
		fprintf(funcionarios,"%d\n",dados[numero].Turno);
		fprintf(funcionarios,"%.2f\n",dados[numero].Salario);
		fprintf(funcionarios,"%d\n",dados[numero].Carga_Horaria);
		fprintf(funcionarios,"%s",dados[numero].Cargo);
		fputs("______________________________________\n",funcionarios);
}

int MovendoSetaVertical(int max, int min,int parado, int soma,int home){
	int seta = home;
	char tecla;
					do{
						gotoxy(parado,seta);printf(">>\b\b");
						tecla = getch();
						tecla = tolower(tecla);
						if( tecla == 's' && seta >= min && seta != max){
							seta+=soma;
							gotoxy(parado,seta-soma);printf("  ");
						}
						if( tecla == 'w' && seta <= max && seta != min){
							seta-=soma;
							gotoxy(parado,seta+soma);printf("  ");
						}
					}while(tecla != 13);
	return seta;
}


/*FUNÇÕES DE INTERFACE*/
void InfomacaoInvalida(void){
    gotoxy(50,10);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(50,11); printf("%cINFORMA%c%cO INV%cLIDA!%c\a",186,128,199,181,186);//gotoxy(50,11);printf("%c    SIM       N%cO    %c",186, 199, 186);
    gotoxy(50,12);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(0,0);printf("%c ",184);system("pause");
}

void Grade(void){
	int i;
	int s=0;
	for(int i=18;i<116;i++){//DEIXAR LIMPO ATRAS
        for(int x=3;x<22;x++){
            gotoxy(i,x);printf(" ");
        }
	}

    for(int y=2;y<22;gotoxy(17,y),putc(219,stdout),gotoxy(116,y),putc(219,stdout),y++){}//colunas esq e dir - quadrado exterior
	for(int x=17;x<117;gotoxy(x,2),putc(220,stdout),gotoxy(x,22),putc(220,stdout),x++){}//topo e baixo do quadrado exterior
    gotoxy(116,22);putc(219,stdout);gotoxy(17,22);putc(219,stdout);

	for( i = 5 ; i <= 19 ; i++){
		if(i==5){
			gotoxy(23,i);printf("%c",201);
		}else	if(i==19){
			gotoxy(23,i);printf("%c",200);
		}else{
			if(i % 2 != 0 ){
				gotoxy(23,i); printf("%c",204);
				Sleep(s);
			}else{
				gotoxy(23,i); printf("%c",186);
				Sleep(s);
			}

		}
	}
	for(int i = 24 ; i < 110 ; i++ ){
		if(i == 69){
			gotoxy(i,5);printf("%c",203);
			Sleep(s);
		}else {
			gotoxy(i,5);printf("%c",205);
			Sleep(s);
		}
	}


	//parte de baixo

	for( i = 5 ; i <= 19 ; i++){
		if(i==5){
			gotoxy(110,i);printf("%c",187);
		}else	if(i==19){
			gotoxy(110,i);printf("%c",188);
		}else{
			if(i % 2 != 0 ){
				gotoxy(110,i); printf("%c",185);
				Sleep(s);
			}else{
				gotoxy(110,i); printf("%c",186);
				Sleep(s);
			}

		}
	}
	for(int i = 24 ; i < 110 ; i++ ){
		if(i == 69){
			gotoxy(i,19);printf("%c",202);
			Sleep(s);
		}else {
			gotoxy(i,19);printf("%c",205);
			Sleep(s);
		}
	}


	//meio
	for(i = 6 ; i < 19 ; i++ ){
		if(i%2!=0){
			for(int j=24;j<110;j++){
				gotoxy(j,i);printf("%c",205);
				if(j==69){
					gotoxy(j,i);printf("%c",206);
				}
			}
		}else{
			gotoxy(69,i);printf("%c",186);
		}
	}
}

void Grade2(void){
	int y=3;
	int c=35;

	for(int i=25;i<100;i++){//DEIXAR LIMPO ATRAS
        for(int x=1;x<31;x++){
            gotoxy(i,x);printf(" ");
        }
	}


	for(int y=2;y<29;gotoxy(34,y),printf("%c\t\t\t\t\t\t\t  %c",219,219),y++){}//colunas esq e dir - quadrado inferior
	for(int x=34;x<91;gotoxy(x,2),printf("%c",220),x++){}//topo do quadrado inferior
	for(int y=3;y<28;y++){                              //linhas entre as opções (====)
		for(int x=35;x<90;x++){
			if(y%2==0){
				gotoxy(x,y);printf("%c",205);
			}
		}
	}
    for(int x=35;x<90;gotoxy(x,28),printf("%c",220),x++){}//parte de baixo do quadrado inferior

	for(int x=25;x<100;gotoxy(x,0),printf("%c",205),x++){}//parte de cima do quadrado exterior
	for(int x=25;x<100;gotoxy(x,30),printf("%c",205),x++){}//parte de baixo do quadrado exterior
	for(int y=0;y<31;gotoxy(24,y),printf("%c",186),y++){}//coluna esquerda - quadrado exterior
	for(int y=0;y<31;gotoxy(99,y),printf("%c",186),y++){}//coluna direita - quadrado exterior

	gotoxy(24,0);printf("%c",201);//quina de cima esquerda - quadrado exterior
	gotoxy(99,0);printf("%c",187);//quina de cima direita - quadrado exterior
	gotoxy(24,30);printf("%c",200);//quina de baixo esquerda - quadrado exterior
	gotoxy(99,30);printf("%c",188);//quina de baixo direita - quadrado exterior
}

void quadrado(int opcao){
	char ca=220;char la=219;int guarda;
	//SIMBOLOS EM DIRECAO AO QUADRADADO
			for(int cont = 30;cont<59;cont++){
				gotoxy(cont,opcao);printf(">");
			}
			//PARTE DE CIMA
			for(int cont=59 ; cont<100 ;gotoxy(cont,opcao-1),printf("%c",220),cont++){}
			//PARTE DO MEIO
			for(int cont=59 ; cont<100 ; cont++){
				for(int cont2=opcao ; cont2<opcao+18 ; cont2++){
					gotoxy(cont,cont2);printf(".");//meio
					if(cont==59||cont==99){gotoxy(cont,cont2);printf("%c",la);}//laterais
					}
				}
			//PARTE DE BAIXO
			gotoxy(59,opcao+18);printf("%c\t\t\t\t\t   %c",la,la);
			for(int cont=60 ; cont<99 ;gotoxy(cont,opcao+18),printf("%c",220), cont++){}

}

void barra2(void){
    int coluna = 40;
  	int linha  = 16;
	int i;
	int P=0;
    for(int i=40;i<83;gotoxy(i,15),printf("%c",196),i++){}
    for(int i=40;i<83;gotoxy(i,17),printf("%c",196),i++){}
    gotoxy(39,15);printf("%c",201);       gotoxy(83,15);printf("%c",187);
    gotoxy(39,16);printf("%c",186);
    gotoxy(39,17);printf("%c",200);
    gotoxy(83,17);printf("%c",188);
	for(i=0;i<45;i++){
		gotoxy(coluna, linha);printf("%c",219);
		gotoxy(82,linha);printf("%i%%",P);
		P++;P++;P++;
		if(P>100)P=100;
		Sleep(10);coluna++;
	}Sleep(200);
}

void BarraDeCarregamento(){
	int coluna = 40;
  	int linha  = 16;
	int i;
	int P=0;
	/*for(i=0;i<40;i++){
		gotoxy(49,20);printf("INICIALIZANDO SISTEMA...\n");
		gotoxy(coluna, linha);printf("%c",219);
		printf("%i%%",P);
		P++;P++;P++;
		if(P>100)P-=17;
		Sleep(10);coluna++;
	}
	Sleep(400);
	*/
	system("cls");
	gotoxy(49,13);printf("INICIALIZANDO SISTEMA...\n");
	for(int i=40;i<83;gotoxy(i,15),printf("%c",196),i++){}//205
    for(int i=40;i<83;gotoxy(i,17),printf("%c",196),i++){}//205
    gotoxy(39,15);printf("%c",201);       gotoxy(83,15);printf("%c",187);
    gotoxy(39,16);printf("%c",186);
    gotoxy(39,17);printf("%c",200);
    gotoxy(83,17);printf("%c",188);
	for(i=0;i<45;i++){
		gotoxy(coluna, linha);printf("%c",219);
		gotoxy(82,linha);printf("%i%%",P);
		P++;P++;
		if(i==43)P=100;
		Sleep(10);coluna++;
	}Sleep(400);


	for(int contapag=0;contapag<400;contapag++){
		if(kbhit())break;
		gotoxy(37,20);printf("PRESSIONE QUALQUER TECLA DUAS VEZES PARA CONTINUAR");Sleep(150);
		gotoxy(37,20);printf("                                                  ");Sleep(150);
	}
	//getch();
	gotoxy(39,20);system("PAUSE");
	setbuf(stdin,NULL);
	system("cls");
}

int TelaDeConfirmacao(int chave){
    gotoxy(54,10);printf("%c%c%c%c%c%c CONFIRMAR %c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,187);
    gotoxy(54,11);printf("%c    SIM       N%cO    %c",186, 199, 186);
    for(int i = 55;i<77;gotoxy(i,12),printf("%c",205),i++){}
    gotoxy(54,12);printf("%c",200);gotoxy(76,12);printf("%c",188);

    char tecla;
    int seta=57;
    int parado=11;
    do{
        gotoxy(seta,parado);printf(">>\b\b");

        tecla = getch();
        tecla = tolower(tecla);

        if( tecla == 'a'){
            seta=57;
            gotoxy(67,parado);printf("  ");
        }
        if( tecla == 'd'){
            seta=67;
            gotoxy(57,parado);printf("  ");
        }
    }while(tecla != 27&&tecla != 13);
    int opcao=-1;
    if(tecla==27&&chave==-1 && seta != 67){
            //system("som1.mp3");
            do{gotoxy(23,18);printf("VOLTAR");
                opcao=MovendoSetaVertical(18,14,15,1,14);
                quadrado(opcao);
                desenho();
                msgs(opcao);
            }while(opcao!=18);

            Menu(9);
    }
    if(seta == 67) return 2;
    else return 1;
    setbuf(stdin,NULL);
}

void Mudar_Cor_Texto(const char Frase[],int FraseNumeros, float FraseNumeros2){
	if(FraseNumeros == -1 && FraseNumeros2 == -1){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        WORD saved_attributes;

        /* Salvar estado atual */
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        saved_attributes = consoleInfo.wAttributes;

        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
        //SetConsoleTextAttribute(hConsole,BACKGROUND_RED);
        printf("%s",Frase);
        /* Voltando ao estado original */
        SetConsoleTextAttribute(hConsole, saved_attributes);
	}else if(FraseNumeros != -1){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        WORD saved_attributes;

        /* Salvar estado atual */
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        saved_attributes = consoleInfo.wAttributes;

        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
        //SetConsoleTextAttribute(hConsole,BACKGROUND_RED);
        printf("%d",FraseNumeros);
        /* Voltando ao estado original */
        SetConsoleTextAttribute(hConsole, saved_attributes);
	}else {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        WORD saved_attributes;

        /* Salvar estado atual */
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        saved_attributes = consoleInfo.wAttributes;

        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
        //SetConsoleTextAttribute(hConsole,BACKGROUND_RED);
        printf("%.2f",FraseNumeros2);
        /* Voltando ao estado original */
        SetConsoleTextAttribute(hConsole, saved_attributes);
	}
}

void ZerosUnsCOR(const char num[]){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        WORD saved_attributes;

        /* Salvar estado atual */
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        saved_attributes = consoleInfo.wAttributes;

        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
        //SetConsoleTextAttribute(hConsole,BACKGROUND_RED);
        printf("%s",num);
        /* Voltando ao estado original */
        SetConsoleTextAttribute(hConsole, saved_attributes);
}
void zerouns(void){

   int y=0; //int y2=49;int x2=129;
    for(int x=0;x<40;x++){
        for(int y=0;y<130;y++,y++){
            gotoxy(y,x);ZerosUnsCOR("01");//y2--;
             //gotoxy(x2,y);ZerosUnsCOR("01");
        }//x2--;x2--;
    //Sleep(0);
    }desenho();
    gotoxy(0,0);

}
void desenho(void){
       {
        int x=14;//49 fica na direcao do tela de confirmacao
        int y=10;
        gotoxy(x+6,y );      printf("             ");y++;
        gotoxy(x+4,y );    printf("                 ");y++;
        gotoxy(x+2,y );  printf("   DESENVOLVEDORES   ");y++;
        gotoxy(x+1,y ); printf("                       ");y++;
		gotoxy(x ,y  );printf("      BRUNO BATALHA      ");y++;
 		gotoxy(x ,y ); printf("   ANA PAULA DE ARAUJO   ");y++;
		gotoxy(x ,y ); printf("     CAROLINE BRAZ       ");y++;
		gotoxy(x ,y ); printf("    GABRIEL SANTIAGO     ");y++;
		gotoxy(x,y ); printf("                         ");y++;
		gotoxy(x+2,y );  printf("                     ");y++;
		 gotoxy(x+4,y );   printf("                 ");y++;
        gotoxy(x+2,y );  printf("                     ");y++;
        gotoxy(x+1,y ); printf("                       ");
       }
        {
        int x=92;//49 fica na direcao do tela de confirmacao
        int y=10;// 15+ que o anterio pra nao cobrir
        gotoxy(x+6,y );      printf("             ");y++;
        gotoxy(x+4,y );    printf("                 ");y++;
        gotoxy(x+2,y );  printf("   DESENVOLVEDORES   ");y++;
        gotoxy(x+1,y ); printf("                       ");y++;
		gotoxy(x ,y  );printf("      BRUNO BATALHA      ");y++;
 		gotoxy(x ,y ); printf("   ANA PAULA DE ARAUJO   ");y++;
		gotoxy(x ,y ); printf("     CAROLINE BRAZ       ");y++;
		gotoxy(x ,y ); printf("    GABRIEL SANTIAGO     ");y++;
		gotoxy(x,y );  printf("                         ");y++;
		gotoxy(x+2,y );  printf("                     ");y++;
		 gotoxy(x+4,y );   printf("                 ");y++;
        gotoxy(x+2,y );  printf("                     ");y++;
        gotoxy(x+1,y ); printf("                       ");
       }


}

/*FUNÇÕES DE ARQUIVOS*/
FILE* AbrirArquivo(char modo,const char arquivo1[60]){
	FILE *arquivo;
	switch(modo){
		case 'w':{
			arquivo = fopen(arquivo1,"w+");
			if(arquivo == NULL){
				arquivo = fopen(arquivo1,"a");
				FecharArquivo(arquivo);
				arquivo = fopen(arquivo1,"w+");
			}
			break;
		}

		case 'r':{
			arquivo = fopen(arquivo1,"r+");
			if(arquivo == NULL){
				arquivo = fopen(arquivo1,"a");
				FecharArquivo(arquivo);
				arquivo = fopen(arquivo1,"r+");
			}
			break;
		}

		case 'a':{
			arquivo = fopen(arquivo1, "a");
			if(arquivo == NULL){
				puts("ERRO AO ABRIR O ARQUIVO");
				exit(0);
			}
			break;
		}

	}
}

void FecharArquivo(FILE *arquivo){
	fclose(arquivo);
}

void RemoverArquivo(const char arquivo1[60]){
	int arquivo;
	arquivo = remove(arquivo1);
	if(arquivo != 0){
        gotoxy(0,0);printf("                               ");
        gotoxy(0,1);printf("                               ");
		gotoxy(0,0);printf("ERRO RMR: ...\n");
        gotoxy(0,1);printf("VOLTANDO AO MENU PRINCIPAL...");Sleep(300);
        Menu(9);

	}
}



void QuantidadeSexo(void){
	int countmasc=0;
	int countfem=0;
	int counttotal=0;
	float porcentagemmasc=0;
	float porcentagemfem=0;
	QuantidadeDeFuncionarios('r');
    int x=0;// ve se tem funcionarios , pq se não tem da erro ;)
	for(int i=0; i<contador_struct;i++){
		counttotal++;
		if(dados[i].Sexo[0] =='M' || dados[i].Sexo[0] =='m'){
			countmasc++;
		}else if(dados[i].Sexo[0] == 'F' || dados[i].Sexo[0] == 'f') {
			countfem++;
		}x++;
	}
	if(x!=0){
        porcentagemmasc=(100*countmasc)/counttotal;
        porcentagemfem=(100*countfem)/counttotal;
	}
	Grade3();
	gotoxy(30,12 );printf(" QUANTIDADE DE FUNCION%cRIOS HOMENS:", 181); gotoxy(79,12);printf("%d [%.1f%%]", countmasc, porcentagemmasc);
	gotoxy(30,20 );printf(" QUANTIDADE DE FUNCION%cRIAS MULHERES:", 181); gotoxy(79,20);printf("%d [%.1f%%]", countfem, porcentagemfem);

}

void MediaCargaHoraria(void){
	float somacarga=0;
	float mediacarga=0;
	QuantidadeDeFuncionarios('r');
	int x=0;
	for(int i=0; i<contador_struct; i++){
		somacarga+=dados[i].Carga_Horaria;
		x++;
	}if(x!=0)mediacarga=somacarga/contador_struct;
	gotoxy(31,22);printf("M%cDIA DE CARGA HOR%cRIA DOS FUNCION%cRIOS:", 144, 181, 181);	gotoxy(79,22);printf("%.1f", mediacarga);
}

void QuantTurno(void){
	int homensturno1=0;
	int homensturno2=0;
	int homensturno3=0;
	int mulheresturno1=0;
	int mulheresturno2=0;
	int mulheresturno3=0;

	QuantidadeDeFuncionarios('r');
	for(int i=0; i<contador_struct;i++){
		if(dados[i].Sexo[0] =='M' || dados[i].Sexo[0] =='m'){
			if(dados[i].Turno == 1){
				homensturno1++;
			}else if(dados[i].Turno == 2){
				homensturno2++;
			}else if(dados[i].Turno == 3){
				homensturno3++;
			}
		}else if(dados[i].Sexo[0] == 'F' || dados[i].Sexo[0] == 'f') {
			if(dados[i].Turno == 1){
				mulheresturno1++;
			}else if(dados[i].Turno == 2){
				mulheresturno2++;
			}else if(dados[i].Turno == 3){
				mulheresturno3++;
			}
		}
	}
	gotoxy(31,6);printf("HOMENS [TURNO 1]:"); gotoxy(79,6);printf("%d", homensturno1);
	gotoxy(31,8);printf("HOMENS [TURNO 2]:");	gotoxy(79,8);printf("%d", homensturno2);
	gotoxy(31,10);printf("HOMENS [TURNO 3]:"); gotoxy(79,10);printf("%d", homensturno3);
	gotoxy(31,14);printf("MULHERES [TURNO 1]:"); gotoxy(79,14);printf("%d", mulheresturno1);
	gotoxy(31,16);printf("MULHERES [TURNO 2]:");	gotoxy(79,16);printf("%d", mulheresturno2);
	gotoxy(31,18);printf("MULHERES [TURNO 3]:"); gotoxy(79,18);printf("%d", mulheresturno3);
}

void Grade3(void){
	int i;
	int s=0;

    for(int i=29;i<89;i++){//DEIXAR LIMPO ATRAS
        for(int x=5;x<25;x++){
            gotoxy(i,x);printf(" ");
        }
	}

	for( i = 5 ; i <= 25 ; i++){
		if(i==5){
			gotoxy(29,i);printf("%c",201);
		}else	if(i==25){
			gotoxy(29,i);printf("%c",200);
		}else{
			if(i % 2 != 0 ){
				gotoxy(29,i); printf("%c",204);
				Sleep(s);
			}else{
				gotoxy(29,i); printf("%c",186);
				Sleep(s);
			}

		}
	}
	for(int i = 30 ; i < 88 ; i++ ){
		if(i == 75){
			gotoxy(i,5);printf("%c",203);
			Sleep(s);
		}else {
			gotoxy(i,5);printf("%c",205);
			Sleep(s);
		}
	}


	//parte de baixo

	for( i = 5 ; i <= 25 ; i++){
		if(i==5){
			gotoxy(88,i);printf("%c",187);
		}else	if(i==25){
			gotoxy(88,i);printf("%c",188);
		}else{
			if(i % 2 != 0 ){
				gotoxy(88,i); printf("%c",185);
				Sleep(s);
			}else{
				gotoxy(88,i); printf("%c",186);
				Sleep(s);
			}

		}
	}
	for(int i = 30 ; i < 76 ; i++ ){
		if(i == 76){
			gotoxy(i,19);printf("%c",202);
			Sleep(s);
		}else {
			gotoxy(i,19);printf("%c",205);
			Sleep(s);
		}
	}


	//meio
	for(i = 6 ; i < 26 ; i++ ){
		if(i%2!=0){
			for(int j=30;j<88;j++){
				gotoxy(j,i);printf("%c",205);
				if(j==75){
					gotoxy(j,i);printf("%c",206);
				}
			}
		}else{
			gotoxy(75,i);printf("%c",186);
		}
	}
	gotoxy(75,25);printf("%c",202);
}

void MediaSalarios(void){
	float somasalarios=0;
	float mediasalarios=0;
	int i=0;
	int x=0;
	QuantidadeDeFuncionarios('r');
	for(int i=0; i<contador_struct;i++){
		somasalarios+=dados[i].Salario;
		x++;
	}if(x!=0)mediasalarios=somasalarios/contador_struct;
	gotoxy(31,24);printf("M%cDIA GERAL DOS SAL%cRIOS:", 144, 181); gotoxy(77,24);printf("R$ %.1f", mediasalarios);
}

void entradaadm(void){
	FILE *arquivoadm;

	char senha[10];
	char confsenha[10];
	char nomeusu[50];
	char senhausu[10];
	int x;
	int g;

	if((arquivoadm = fopen("administrador.txt","r"))==NULL){

		do{
			arquivoadm = fopen("administrador.txt","a");

			setbuf(stdin,NULL);
			printf("NOME COMPLETO: "); fgets(informacoes.nomecompleto,sizeof(informacoes.nomecompleto),stdin);
			setbuf(stdin,NULL);
			fprintf(arquivoadm,"%s",informacoes.nomecompleto);

			printf("EMAIL: "); fgets(informacoes.email,sizeof(informacoes.email), stdin);
    		setbuf(stdin,NULL);

			printf("SENHA: ");
			fgets(senha,sizeof(senha),stdin);
    		setbuf(stdin,NULL);

			printf("CONFIRME SUA SENHA: ");
			fgets(confsenha,sizeof(confsenha),stdin);

			setbuf(stdin,NULL);

			if(strcmp (senha,confsenha) == 0){
				fprintf(arquivoadm,"%s",senha);
				fclose(arquivoadm);
				g=1;
			}else{
				printf("\nAS SENHA N%cO COINCIDEM! CADASTRO CANCELADO! \n", 199);
				system("pause");
				system("cls");
				fclose(arquivoadm);
				g=0;
				remove ("administrador.txt");
		}
		}while(g==0);
	}else{
		do{
			arquivoadm = fopen("administrador.txt","r");
			while(1){

				fgets(informacoes.nomecompleto,sizeof(informacoes.nomecompleto),arquivoadm);
				fgets(informacoes.senha,sizeof(informacoes.senha),arquivoadm);
				if(feof(arquivoadm))break;
			}

			gotoxy(45,10);printf("%c%c%c%c%c%c%c%c%c LOGIN %c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
			gotoxy(45,13);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
			gotoxy(47,11);printf("NOME DO USU%cRIO: ", 181);
			fgets(nomeusu,sizeof(nomeusu),stdin);
			setbuf(stdin,NULL);

			gotoxy(47,12);printf("SENHA: ");
			fgets(senhausu,sizeof(senhausu),stdin);
			setbuf(stdin,NULL);
			fclose(arquivoadm);
			setbuf(stdin,NULL);

			if(strcmp(nomeusu,informacoes.nomecompleto)==0 && strcmp(senhausu,informacoes.senha)==0){
				setbuf(stdin,NULL);
				gotoxy(47,15);printf("BEM VINDO ADMISTRADOR\n\n");
				x=0;
			}else{
				gotoxy(39,15);printf("NOME DE USU%cRIO OU SENHA INCORRETOS\n\n", 181);
				gotoxy(37,16);system("pause");
				x=1;
				system("cls");
			}
		}while(x!=0);
	}
	for(int contapag=0;contapag<400;contapag++){
		if(kbhit())break;
		gotoxy(54,18);printf("[ENTER]                                                                                                                    ");Sleep(150);
		gotoxy(54,18);printf("                                                                                                                           ");Sleep(150);
		setbuf(stdin,NULL);
	}
}

void msgs(int opcao){
    int opcao1=opcao;
    if(opcao == 14){
        for(int i=0;i<5;gotoxy(60,opcao1),printf("                                     "),i++,opcao1++){}

        gotoxy(61,opcao);printf("""Julgar um codigo pela quantidade"); opcao++;
        gotoxy(61,opcao);printf("de linhas e a mesma coisa que"); opcao++;
        gotoxy(61,opcao);printf("julgar um aviao pelo peso");opcao++;
        gotoxy(61,opcao);printf("de sua construcao."" - Bill Gates.");
    	opcao=0;
		}
    if(opcao == 15){
        for(int i=0;i<5;gotoxy(60,opcao1),printf("                                     "),i++,opcao1++){}
        gotoxy(61,opcao);printf("                                 e"); opcao++;
        gotoxy(61,opcao);printf("                             "); opcao++;
        gotoxy(61,opcao);printf("                         ");opcao++;
        gotoxy(61,opcao);printf("                                  ");
    	opcao=0;
		}
    if(opcao == 16){
        for(int i=0;i<5;gotoxy(60,opcao1),printf("                                     "),i++,opcao1++){}

        gotoxy(61,opcao);printf("");opcao++;
        gotoxy(61,opcao);printf("");
		opcao=0;
    }
    if(opcao == 17){
        for(int i=0;i<5;gotoxy(60,opcao1),printf("                                     "),i++,opcao1++){}
        gotoxy(61,opcao);printf("                                 e"); opcao++;
        gotoxy(61,opcao);printf("                             "); opcao++;
        gotoxy(61,opcao);printf("                         ");opcao++;
        gotoxy(61,opcao);printf("                                  ");
		opcao=0;
    }
 }

//void mostrardadosdemo(void){
//	system("cls");
//	printf("\n\t\t\t\t\t    DADOS DEMOGR%cFICOS\n\n", 181);
//	Grade3();
//	QuantidadeSexo();
//	MediaCargaHoraria();
//	QuantTurno();
//	MediaSalarios();
//	getch();
//}

//



void busca(void){
	char nomebusca[100];
	system("cls");
	printf("DIGITE O NOME: ");
	fgets(nomebusca, 100, stdin);
	int countbusca;
	QuantidadeDeFuncionarios('r');
	for(countbusca=0; countbusca<contador_struct; countbusca++){
		if(strcmp(nomebusca,dados[countbusca].Nome)==0){
			imprimirdados(countbusca);
			printf("\n\n\n");
		}
	}

		system("pause");

}

void instrucoes(void){
	gotoxy(33,24);printf("PRESSIONE [W] PARA SUBIR\t\t PRESSIONE [S] PARA DESCER");setbuf(stdin,NULL);
	gotoxy(32,26);printf("PRESSIONE [A] PARA DIREITA\t\tPRESSIONE [D] PARA ESQUERDA");setbuf(stdin,NULL);
}

void busca_funcionario (void)
{ 
  char nomeP[100];
  char CPFP[14];
  int opcao1;
  int contP;
     printf("\nDigite 1 para realizar a pesquisa por meio do nome do funcion&rio ou digite 2 para realiz%c-la pelo CPF e 0 para voltar: ");
     scanf("%d",&opcao1);setbuf(stdin,NULL);	
     switch(opcao1){
        case 1:{
        	printf("\nDigite o nome completo do funcion%crio: ");
        fgets(nomeP,100,stdin);
        PassaPraMaiusculo(nomeP);
        for(contP=0;contP<100;contP++)
        {
            if(strcmp(nomeP,dados[contP].Nome) == 0)
            {
            system("cls");
              imprimirdados(contP);
	  busca_funcionario();	
	}
           
        }
	break;
        }
         
        case 2:
        printf("\nDigite o CPF: ");
        fgets(CPFP,14,stdin);
        for(contP=0;contP<100;contP++)
        {
           if(strcmp(CPFP,dados[contP].CPF)==0){
	system("cls");
	imprimirdados(contP);
	busca_funcionario ();
           }
        }	
        
        break;
        case 0:
        	break;
        default:
        printf("\n Função indefinida ");
        system("pause");
         break;  	
     }
}



void imprimirdados(int n_funcionario){
	int y=3;int i=y;
	int opcao;
	int c=35;
	int matriz[12][2];int j=0;

	Grade2();

	//gotoxy(45,0); printf(" CLIQUE NA OP%cAO QUE DESEJA ALTERAR ", 128);

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  NOME: %s",dados[n_funcionario].Nome);y++;y++;
				//data de nascimento temos um problema Bruno

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  SEXO: %c",dados[n_funcionario].Sexo[0]);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  NACIONALIDADE: %s",dados[n_funcionario].Nacionalidade);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  CPF: %s",dados[n_funcionario].CPF);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  RG: %s",dados[n_funcionario].RG);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  TIPO SANGU%cNEO: %s", 214, dados[n_funcionario].TipoSanguineo);y++;y++;
				//printf("Nome do pai: %s\n",dados[j].Pai);//printf("Nome da mae: %s\n",dados[j].Mae);
	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  ENDERECO: %s", dados[n_funcionario].Endereco);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  EMAIL: %s",dados[n_funcionario].Email);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  SAL%cRIO: R$ %.2f", 181, dados[n_funcionario].Salario);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  TURNO: %d%c",dados[n_funcionario].Turno,248);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y; j++;
	gotoxy(c,y); printf("  CARGA HOR%cRIA: %d HORA(S)", 181, dados[n_funcionario].Carga_Horaria);y++;y++;

	matriz[j][0]=j;	matriz[j][1]=y;
	gotoxy(c,y); printf("  CARGO NA EMPRESA: %s",dados[n_funcionario].Cargo);
	gotoxy(21,31);system("pause");
	system("cls");
}

















//

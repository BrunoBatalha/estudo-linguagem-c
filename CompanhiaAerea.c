#include<stdio.h>

int main(){
	void linha(void);
	int Voos[5],
		LDisp[5];
	int Cliente, NVoo, Apont, i, x;
	
	printf("Escolha o voo desejado e sua poltrona:\n");
	for(i=0;i<5;i++){
		printf("Voo = ");
		scanf("%d",&Voos[i]);
		//puts ("\n");
		printf("LugaresDisponiveis = ");
		scanf("%d",&LDisp[i]);
		printf("\n");
	}
	linha();
	printf("Entre com a identidade do cliente: ");
	scanf("%d",&Cliente);
	printf("Entre com o numero do voo desejado: ");
	scanf("%d",&NVoo);
	while(Cliente != 9999){
		i = 0;
		while((i < 5) && (NVoo != Voos[i]))
			i++;
		if(NVoo == Voos[i]){
			Apont = i;
		}else {
			printf("Caro cliente %d o voo %d eh inexistente.\n",Cliente, NVoo);
			Apont=0;
			x= -1;
		}
		if(x!=-1){
			if(LDisp[Apont] > 0){
				printf("Caro cliente %d o voo %d foi reservado com sucesso.\n",Cliente, NVoo);
				LDisp[Apont] = LDisp[Apont] - 1;
			}else 
				printf("Caro cliente %d o voo %d esta lotado.\n",Cliente, NVoo);
		}
		linha();
		printf("Entre com a identidade do cliente: ");
		scanf("%d",&Cliente);
		printf("Entre com o numero do voo desejado: ");
		scanf("%d",&NVoo);
	}	
	return 0;
}

void linha(void){
	int i;
	for(i=1;i<=25;i++)
		printf("*");
}

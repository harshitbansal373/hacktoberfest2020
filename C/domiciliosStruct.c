#include<stdio.h>

struct domicilios{
	float renda;
	int nOcupantes;
	char endereco[100];
	int nOcupantesEscolar;
};

int main(){
	struct domicilios domicilios[100];
	int opc,contador,i,N,oNormal=0,oEstudantes=0;
	float media=0.0,porcentagem;
	printf("Vamos cadastrar os domicilios!\n");
	printf("Digite quantos enderecos serao digitados:\n");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		printf("Digite a renda ->");
		scanf("%f",&domicilios[i].renda);	
		printf("\nDigite o numero de ocupantes ->");
		scanf("%d",&domicilios[i].nOcupantes);
		printf("\nDigite o numero de ocupantes em idade escolar ->");
		scanf("%d",&domicilios[i].nOcupantesEscolar);
		printf("\nDigite o endereco ->");
		scanf("%s%*c",&domicilios[i].endereco);
	}
	printf("Opcoes:\n(1) - Lista de todos os endereços\n(2) - Renda media dos domicilios na cidade\n(3) - Porcentagem do numero de ocupantes em idade escoalar\n");
	scanf("%d",&opc);
	switch (opc){
		case 1: printf("A lista de enderecos:\n");
				for(i=0;i<N;i++){
					printf("Endereco->%s%*c\tRenda->%.2f\tOcupantes->%d\tOcupantes em idade escolar->%d\n",domicilios[i].endereco,domicilios[i].renda,domicilios[i].nOcupantes,domicilios[i].nOcupantesEscolar);
				}
				break;
				
		case 2: printf("A renda media dos domicilios da cidade:\n");
			    for(i=0;i<N;i++){
			    	media+=domicilios[i].renda;
				}
				printf("%.2f",media/N);
				break;
		
		case 3:	printf("Porcentagem de ocupantes em idade escolar:\n");
				for(i=0;i<N;i++){
					oNormal+= domicilios[i].nOcupantes;
					oEstudantes+= domicilios[i].nOcupantesEscolar;
				}
				porcentagem =(float)(oEstudantes * 100) / oNormal;
				printf("%.1f%",porcentagem);	
				break;
	}
		
}

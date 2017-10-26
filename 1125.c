#include <stdio.h>
#include <stdlib.h>

#define TAMVET 102
typedef struct{
	int pontos[TAMVET]; //pontos daquela corrida
	int qtdeMax; //maximo da pontuacao que tem
}SistemaPontuacao;

typedef struct{
	int corredores[TAMVET];
	int qtdeMax;
}Corredores;

void mostraPonto(Corredores *pontuacao, int qtdeCorridas, int qtdeCorredores){
	int i, j;
	
	for(i=0; i<qtdeCorridas; i++){
		for(j=0; j<qtdeCorredores; j++){
			printf("%d ", pontuacao[i].corredores[j]);
		}
		printf("\n");
	}
}

//mostra maiores valores
void mostraMaiores(Corredores *corredores, int lin, int col){
	int i, j;
	int maior = -1;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			if (corredores[i].corredores[j] > maior){
				maior = corredores[i].corredores[j];
			}
		}
	}
	int cont = 0;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			if(corredores[i].corredores[j] == maior){
				if (cont == 0)
					printf("%d", j+1);
				else
					printf(" %d", j+1);
				cont++;
			}
		}
	}
	printf("\n");
}

//zera o vetor antes da contagem de pontos
void zeraVet(Corredores *vet, int linha, int col){
	int i, j;
	for(i=0; i<linha; i++){
		for(j=0; j<col; j++)
			vet[i].corredores[j] = 0;	
	}
}

void zera1D(Corredores *pont, int tamVet){
	int i;
	for(i=0; i<tamVet; i++)
		(*pont).corredores[i] = 0;
}

//calcula os pontos da corrida
void calcPont(Corredores *corredores, Corredores *raiz, int qtdeCorridas, int qtdeCorredores, int ponto, int posicao){
	int i, j;
	
	for(i=0; i<qtdeCorridas; i++){
		for(j=0; j<qtdeCorredores; j++){
			if(raiz[i].corredores[j] == posicao)
				corredores[i].corredores[j] += ponto;
		}
	}
}

void somaColunas(Corredores *pont1D, Corredores *pontuacao, int qtdeCorridas, int qtdeCorredores){
	int i,j;
	for(i=0; i<qtdeCorridas; i++){
		for(j=0; j<qtdeCorredores; j++){
			(*pont1D).corredores[j] += pontuacao[i].corredores[j];
		}
	}
}

void mostraVencedores(Corredores vet, int tamVet){
	int i, maior=-1;
	for(i=0; i<tamVet; i++){
		if (vet.corredores[i] > maior)
			maior = vet.corredores[i];
	}
	int cont=0;
	for(i=0; i<tamVet; i++){
		if (vet.corredores[i] == maior){
			if (cont == 0)
				printf("%d", i+1);
			else
				printf(" %d", i+1);
			cont++;
		}
	}
	printf("\n");
}

int main(){
	int qtdeCorridas, qtdeCorredores, qtdeSisPont, qtdePont;
	Corredores corredores[TAMVET], pontuacao[TAMVET], pont1D;
	SistemaPontuacao sisPontuacao[TAMVET];
	int i, j;
	
	while(1){
		//lê os valores iniciais
		scanf("%d %d", &qtdeCorridas, &qtdeCorredores);
		
		//sai do laco caso necessario
		if (qtdeCorridas == 0 && qtdeCorredores == 0)
			break;
	
	
		//lê os valores
		for(i=0; i<qtdeCorridas; i++){
			for(j=0; j<qtdeCorredores; j++){
				scanf("%d", &corredores[i].corredores[j]);							
			}
			corredores[i].qtdeMax = qtdeCorredores;
		}
		
		//lê a quantidade de sistema de pontuacoes
		scanf("%d", &qtdeSisPont);
		
	
		//le os dados de sistema de pontuacao
		for(i=0; i<qtdeSisPont; i++){			
			scanf("%d", &qtdePont);
			sisPontuacao[i].qtdeMax = qtdePont;
			
			//le os dados
			for(j=0; j<qtdePont; j++){
				scanf("%d", &sisPontuacao[i].pontos[j]);
			}
			
		}
		
		
		
	
		int cont=0;
	
		//calcula a pontucao
		for(i=0; i<qtdeSisPont; i++){
			zeraVet(pontuacao, qtdeCorridas, qtdeCorredores);
			zera1D(&pont1D, qtdeCorredores);
			
			for (j=0; j<sisPontuacao[i].qtdeMax; j++){ // j = pontuacao
				calcPont(pontuacao, corredores, qtdeCorridas, qtdeCorredores, sisPontuacao[i].pontos[j], j+1);
			}
			
		
			
			somaColunas(&pont1D, pontuacao, qtdeCorridas, qtdeCorredores);
			
			
			mostraVencedores(pont1D, qtdeCorredores);
		
		}
		
	}
	
	return 0;
}

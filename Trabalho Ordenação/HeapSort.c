//Lucas de Figueiredo, Mateus Freitas, Elias J�nior
//HeapSort Ordenado de maneira N�o Crescente
#include <stdio.h>
#include <time.h>
#define A 5000
#define B 10000
#define C 20000
#define D 30000

void lerVetor(FILE *arqA, FILE *arqB, FILE *arqC, FILE *arqD, int vetorA[], int vetorB[], int vetorC[], int vetorD[]);
void ordenaHeap(int vetor[], int tam);
void cria_heap(int vetor[], int TAM, int indice_raiz);
void imprimeVetorOrdenado(int vetorA[], int vetorB[], int vetorC[], int vetorD[], FILE *arqSaida);

void inicioTempo(float *timer);
void fimTempo(float timer);

int main(){
	FILE *arqA, *arqB, *arqC, *arqD, *arqSaida;
	int vetorA[A], vetorB[B], vetorC[C], vetorD[D];
	float timer;
	//Leiruta dos arquivos
	lerVetor(arqA, arqB, arqC, arqD, vetorA, vetorB, vetorC, vetorD);
	
	//Ordena��o dos vetores lidos
	printf("\nVetor A:");
	inicioTempo(&timer);
	ordenaHeap(vetorA, A-1);
	fimTempo(timer);

	printf("\nVetor B:");
	inicioTempo(&timer);
	ordenaHeap(vetorB, B-1);
	fimTempo(timer);

	printf("\nVetor C:");
	inicioTempo(&timer);
	ordenaHeap(vetorC, C-1);
	fimTempo(timer);

	printf("\nVetor D:");
	inicioTempo(&timer);
	ordenaHeap(vetorD, D-1);
	fimTempo(timer);
	
	//Impress�o em novos arquivos de maneira ordenada
	imprimeVetorOrdenado(vetorA, vetorB, vetorC, vetorD, arqSaida);

	return 0;
}

//Leitura dos arquivos em vetor para ordena��o
void lerVetor(FILE *arqA, FILE *arqB, FILE *arqC, FILE *arqD, int vetorA[], int vetorB[], int vetorC[], int vetorD[]){
	//Leitura A
	int i=0;
	arqA=fopen("A.txt", "r");
	while(!feof(arqA)){
		fscanf(arqA, "%d", &vetorA[i]);
		i++;
	}
	fclose(arqA);
	printf("\nArquivo A lido.");
	//Leitura B
	i=0;
	arqB=fopen("B.txt", "r");
	while(!feof(arqB)){
		fscanf(arqB, "%d", &vetorB[i]);
		i++;
	}
	fclose(arqB);
	printf("\nArquivo B lido.");
	//Leitura C
	i=0;
	arqC=fopen("C.txt", "r");
	while(!feof(arqC)){
		fscanf(arqC, "%d", &vetorC[i]);
		i++;
	}
	fclose(arqC);
	printf("\nArquivo C lido.");
	//Leitura D
	i=0;
	arqD=fopen("D.txt", "r");
	while(!feof(arqD)){
		fscanf(arqD, "%d", &vetorD[i]);
		i++;
	}
	fclose(arqD);
	printf("\nArquivo D lido.");
}

//Ordena��o utilizando HeapSort
void cria_heap(int *vetor, int TAM, int indice_raiz){
	int ramificacao, valor;
    valor = vetor[indice_raiz];
    
    while(indice_raiz <= TAM/2){    
    	ramificacao = 2 * indice_raiz;
    
    if(ramificacao < TAM && vetor[ramificacao] > vetor[ramificacao+1])
    	ramificacao++;
        if(valor <= vetor[ramificacao])
     		break;

    	vetor[indice_raiz] = vetor[ramificacao];
    	indice_raiz = ramificacao;
	}

    vetor[indice_raiz] = valor;
}

void ordenaHeap(int vetor[], int TAM){
	int indice, troca;
	for(indice = TAM/2; indice >= 0; indice--)
    	cria_heap(vetor, TAM, indice);    
	    
	    while(TAM > 0){
			troca = vetor[0];
			vetor[0] = vetor[TAM];
			vetor[TAM] = troca;
			cria_heap(vetor, --TAM, 0);
 		}
}

//Impress�o dos vetores j� ordenados no novo arquivo.
void imprimeVetorOrdenado(int vetorA[], int vetorB[], int vetorC[], int vetorD[], FILE *arqSaida){
	int i;
	//Imprime A
	arqSaida=fopen("HeapOrdenado-A.txt", "w");
	for(i=0; i<A; i++){
		fprintf(arqSaida, "%d ", vetorA[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo A impresso.");

	//Imprime B
	arqSaida=fopen("HeapOrdenado-B.txt", "w");
	for(i=0; i<B; i++){
		fprintf(arqSaida, "%d ", vetorB[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo B impresso.");

	//Imprime C
	arqSaida=fopen("HeapOrdenado-C.txt", "w");
	for(i=0; i<C; i++){
		fprintf(arqSaida, "%d ", vetorC[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo C impresso.");

	//Imprime D
	arqSaida=fopen("HeapOrdenado-D.txt", "w");
	for(i=0; i<D; i++){
		fprintf(arqSaida, "%d ", vetorD[i]);
	}
	fclose(arqSaida);
	printf("\nArquivo D impresso.");

}
//Fun��es de In�cio e fim do calculo de tempo
void inicioTempo(float *timer){
	*timer = clock();
}

void fimTempo(float timer){
	timer = clock() - timer;
	printf("\nOrdenado em %0.3f segundos.", (timer/CLOCKS_PER_SEC));
}

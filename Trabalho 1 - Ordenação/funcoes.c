#include "funcoes.h"

/*Troca as posições de dois vetores com a ajuda de uma variável auxiliar*/
void swap(int *a, int *b) {
    
	int aux;
	
	aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int *vet, int vetSize) {
	
	int trocou = 0, aux, i;
	
	/*Enquanto o sinal de trocar for verdadeiro, o programa 
	continua percorrendo o vetor. Quando não for mais verdadeira
	a troca, interrompe o laço de repetição*/
	do {
		trocou = 0;
		for (i = 0; i < vetSize; i++) { 
			if (vet[i] > vet[i+1]) { // Se o elemento na posição i for maior que o elemento da posição i+1
				aux = vet[i];		 // os elementos trocam de posição 
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				trocou = 1;			 // A variável continua positiva com o trocar dos elementos do vetor
			}						 // e só irá mudar quando não houver mais trocas
		}
	} while (trocou == 1);
	
	
}


void insertion_sort(int *vet, int vetSize) {
	
	int i, j, aux;

	for (i = 1; i < vetSize; i++) { //i começa em 1 para o primeiro elemento do vetor ser utilizado como base
		j = i;						//iguala-se j ao i para poder percorrer o laço de repetição
		while (j > 0 && vet[j] < vet[j-1]) { //se o elemento na posição j é menor que o elemento anterior
			aux = vet[j];			//realiza-se a troca dos elementos no vetor, para que ele só tenha 
			vet[j] = vet[j-1];		//elementos ordenados do lado esquerdo do vetor
			vet[j-1] = aux;
			j--;
		}
	}
}

void selection_sort(int *vet, int vetSize) {
	
	int i, j, minimo, aux;
	
	for (i = 0; i < vetSize-1; i++) {
		minimo = i;						//Toma-se o mínimo como a primeira posição
		for (j = (i+1); j < vetSize; j++) { //conforme é percorrido o vetor
			if (vet[j] < vet[minimo]) { // caso tenha um elemento do vetor que tenha uma posição
				minimo = j;				// menor que o elemento mínimo, há uma atualização da posição
			}							// do mínimo
		}
		if (minimo != i) {				// Se o elemento mínimo não está mais na posição i
			aux = vet[i];				// há uma troca na posição dos elementos
			vet[i] = vet[minimo];
			vet[minimo] = aux;
		}
	}
}

void quick_sort(int *vet, int start, int end) {
	
	int ordena;
	
	if (start < end) {
		ordena = quick_sort_pivo(vet, start, end); // chama a função que escolhe o pivo
		quick_sort(vet, start, ordena-1);			// faz uma chamada recursiva para ordenar as duas partes
		quick_sort(vet, ordena+1, end);				//de um vetor
    }
}

int quick_sort_pivo(int *vet, int start, int end) {
	
	int pivo = vet[end];				//escolhe o pivo como o último elemento do vetor
	int index = (start-1);				//e o index como o número anterior a primeira posição do vetor
	int i;
 
    for (i = start; i <= end-1; i++) {
        if (vet[i] <= pivo) {			//Caso o elemento do vetor seja menor que o pivô
			index++;					//incrementa-se o index
			swap(&vet[index], &vet[i]); // e troca-se as posições do vetor e do index
        }
    }
    swap(&vet[index + 1], &vet[end]);
    return (index + 1);					//O resultado é enviado para a função quick_sort
	
}

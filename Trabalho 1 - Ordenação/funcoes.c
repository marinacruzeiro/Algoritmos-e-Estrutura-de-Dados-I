#include "funcoes.h"

/*Troca as posi��es de dois vetores com a ajuda de uma vari�vel auxiliar*/
void swap(int *a, int *b) {
    
	int aux;
	
	aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort(int *vet, int vetSize) {
	
	int trocou = 0, aux, i;
	
	/*Enquanto o sinal de trocar for verdadeiro, o programa 
	continua percorrendo o vetor. Quando n�o for mais verdadeira
	a troca, interrompe o la�o de repeti��o*/
	do {
		trocou = 0;
		for (i = 0; i < vetSize; i++) { 
			if (vet[i] > vet[i+1]) { // Se o elemento na posi��o i for maior que o elemento da posi��o i+1
				aux = vet[i];		 // os elementos trocam de posi��o 
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				trocou = 1;			 // A vari�vel continua positiva com o trocar dos elementos do vetor
			}						 // e s� ir� mudar quando n�o houver mais trocas
		}
	} while (trocou == 1);
	
	
}


void insertion_sort(int *vet, int vetSize) {
	
	int i, j, aux;

	for (i = 1; i < vetSize; i++) { //i come�a em 1 para o primeiro elemento do vetor ser utilizado como base
		j = i;						//iguala-se j ao i para poder percorrer o la�o de repeti��o
		while (j > 0 && vet[j] < vet[j-1]) { //se o elemento na posi��o j � menor que o elemento anterior
			aux = vet[j];			//realiza-se a troca dos elementos no vetor, para que ele s� tenha 
			vet[j] = vet[j-1];		//elementos ordenados do lado esquerdo do vetor
			vet[j-1] = aux;
			j--;
		}
	}
}

void selection_sort(int *vet, int vetSize) {
	
	int i, j, minimo, aux;
	
	for (i = 0; i < vetSize-1; i++) {
		minimo = i;						//Toma-se o m�nimo como a primeira posi��o
		for (j = (i+1); j < vetSize; j++) { //conforme � percorrido o vetor
			if (vet[j] < vet[minimo]) { // caso tenha um elemento do vetor que tenha uma posi��o
				minimo = j;				// menor que o elemento m�nimo, h� uma atualiza��o da posi��o
			}							// do m�nimo
		}
		if (minimo != i) {				// Se o elemento m�nimo n�o est� mais na posi��o i
			aux = vet[i];				// h� uma troca na posi��o dos elementos
			vet[i] = vet[minimo];
			vet[minimo] = aux;
		}
	}
}

void quick_sort(int *vet, int start, int end) {
	
	int ordena;
	
	if (start < end) {
		ordena = quick_sort_pivo(vet, start, end); // chama a fun��o que escolhe o pivo
		quick_sort(vet, start, ordena-1);			// faz uma chamada recursiva para ordenar as duas partes
		quick_sort(vet, ordena+1, end);				//de um vetor
    }
}

int quick_sort_pivo(int *vet, int start, int end) {
	
	int pivo = vet[end];				//escolhe o pivo como o �ltimo elemento do vetor
	int index = (start-1);				//e o index como o n�mero anterior a primeira posi��o do vetor
	int i;
 
    for (i = start; i <= end-1; i++) {
        if (vet[i] <= pivo) {			//Caso o elemento do vetor seja menor que o piv�
			index++;					//incrementa-se o index
			swap(&vet[index], &vet[i]); // e troca-se as posi��es do vetor e do index
        }
    }
    swap(&vet[index + 1], &vet[end]);
    return (index + 1);					//O resultado � enviado para a fun��o quick_sort
	
}

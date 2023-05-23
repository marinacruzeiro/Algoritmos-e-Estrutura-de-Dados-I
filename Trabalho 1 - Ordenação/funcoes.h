#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubble_sort(int *vet, int vetSize);//

void insertion_sort(int *vet, int vetSize);//

void selection_sort(int *vet, int vetSize);//

void quick_sort(int *vet, int start, int end);

int quick_sort_pivo(int *vet, int start, int end);

void merge_sort(int *vet, int start, int end);

/*Função que faz a troca de 2 inteiros 
utilizando passagem por referencia*/
void troca(int *a, int *b);

/*Imprime o vetor na tela*/
void mostra(int *vet, int vetSize);

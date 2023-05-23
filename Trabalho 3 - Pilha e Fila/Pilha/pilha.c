// 3º Trabalho de Algoritmos e Estrutura de Dados - Pilha
// Marina Cruzeiro

#include "pilha.h"

/** Cria uma pilha
 * @return  um descritor ou NULL*/
Pilha *cria_pilha() {
	Pilha *p;	
	p = malloc (sizeof(Pilha));
	p->qtd = 0;
	return (p);
}


/* Insere um elemento no topo da pilha
 * @param p descritor de pilha
 * @param val elemento a ser inserido
 * @return 1 se OK, 0 se erro*/
int push(Pilha *p, int val) {
	if (p == NULL) {		// Verifica se a pilha está cheia
		return(0);
	}
	p->dados[p->qtd] = val; // Insere o valor desejado no topo da pilha
	p->qtd++;
	return (1);
}


/* Retorna o elemento no topo da pilha, ou -1 se não existir
 * @param p descritor da pilha
 * @return o elemento ou -1*/
int top(Pilha *p) {
	if (p->qtd == 0) {           // Verifica se a pilha está vazia
		return (-1);
	}
	return (p->dados[p->qtd-1]); /* Retorna o elemento do topo da pilha
									(tamanho da pilha menos 1, que é
									onde está o último dado)*/
}

/* Descarta o topo da pilha
 * @param p descritor de pilha
 * @return 1 se OK, -1 se nao existir elementos para apagar*/
int pop(Pilha *p) {
	if (p->qtd == 0) {			// Verifica se a pilha está vazia
		return (-1);
	}
	p->qtd--;					// Diminui a quantidade de elementos da pilha
	return (1);
}


/** Apaga todos elementos da pilha
 * usar funcao pop para limpar
 * @param p descritor da pilha
 * @return 1 se OK, -1 se erro*/
int limpa_pilha(Pilha *p) {
	if (p->qtd == 0) {			// Verifica se a pilha está vazia
		return (-1);
	}
	while (p->qtd != 0) {		// Enquanto a quantidade de elementos não for 0
		pop(p);					// Chama-se a função de remoção de elementos da pilha
	}
	return (1);
}


/*Retorna o comprimento da pilha
 * @param head 	-> descritor da pilha
 * @return	 	-> comprimento da pilha*/
int length(Pilha *head) {
	return (head->qtd);			// Retorna a quantidade de elementos da pilha
}


/* Desaloca a pilha
 * @param head 	-> descritor da pilha*/
void destroi_pilha(Pilha *head) {
	free(head);					// Libera a pilha da memória com a função free
}


// 3º Trabalho de Algoritmos e Estrutura de Dados - Fila
// Marina Cruzeiro

#include "fila.h"

/* Cria uma fila
 * @return -> um descritor ou NULL caso nao conseguir alocar*/
Fila *cria_fila() {
	Fila *p;
	p = (Fila*) malloc(sizeof(Fila));	// Aloca o espaço para a fila
	if (p != NULL) {					// Verifica se foi alocado corretamente
		p->first = NULL;				// Faz os ponteiros de inicio e fim da fila
		p->last = NULL;					// apontarem para NULL, mostrando que ela está vazia
	}
	return (p);
}

/* Insere um elemento no fim da fila
 * Nesta função deve-se alocar um novo Nodo, 
 * inserir val e direcionar os ponteiros da cabeça da fila
 * @param head 	-> descritor da fila
 * @param val 	-> elemento a ser inserido
 * @return 1 se OK, 0 se erro*/
int queue(Fila *head, int val) {
	
	nodo *nova;								// Cria um nodo nov para auxiliar a inserção
	nova = (nodo*) malloc (sizeof(nodo));	// Aloca o espaço para esse novo nodo
	if (nova == NULL) {						// Verifica se a criação deu certo
		return (0);
	}
	nova->val = val;						// O valor desejado é inserido neste novo nodo
	nova->prox = NULL;						// E este novo nodo se torna o último a entrar na fila
	if (head->last == NULL) {				// Se o ponteiro para o último elemento é nulo e a fila era vazia
		head->first = nova;					// o ponteiro de para o primeiro elemento vai apontar para o nova
	} else {
		head->last->prox = nova;			// Senão, o prox do ponteiro para o último elemento passa a ser o nova
	}
	head->last = nova;						// O ponteiro que aponta para o último elemento aponta agora para o nova
	return (1);
}


/* Retorna e descarta o elemento no inicio da fila
 * (Não esquecer de dar "free" no elemtento descartado)
 * @param head	-> descritor da fila
 * @return 		-> O elemento ou -1 caso nao exista*/
int dequeue(Fila *head) {
	
	if (head->first != NULL) {			// Verifica se a fila não é vazia
	return (head->first->val);			// Retorna o primeiro elemento
	nodo *apaga;						// Cria um nodo auxiliar
	apaga = head->first;				// O nodo auxiliar recebe o primeiro elemento da fila
	head->first = head->first->prox;	// E o primeiro elemento da fila passa a ser o antigo segundo elemento
	if (head->first == NULL) {			// Se o primeiro elemento era o único elemento da fila
		head->last = NULL;				// Ele também era o último, logo o ponteiro last é nulo
	}
	free (apaga);						// Libera o primeiro elemento da fila
	} else {
		return (-1);					// Caso o contrário, retorna erro
	}	
}

/* Apaga todos elementos da fila
 * usar funcao dequeue para limpar
 * @param head 	-> descritor da fila
 * @return 1 	-> se OK, -1 se erro*/
int limpa_fila(Fila *head) {
	
	if (head->first != NULL) {					// Se o ponteiro first não for nulo
		while (head->first != NULL) {			// E enquanto ele não for nulo
			dequeue(head);						// Apaga-se um por um dos elementos da fila com a função dequeue
			head->first = head->first->prox;	// Passa-se para o próximo elemento da fila
		}
		return (1);
	} else {
		return (-1);
	}
	
}



/*Retorna o comprimento da fila
 * @param head 	-> descritor da fila
 * @return	 	-> comprimento da fila*/
int length(Fila *head) {
	
	int tam = 0;
	nodo *aux = head->first;		// Cria um nodo auxiliar
	while (aux != NULL) {			// Que irá percorrer a fila até ele ser nulo
		tam++;						// Contantando o seu tamanho
		aux = aux->prox;			// Passa para o próximo elemento
	}
	return (tam);
}


/* Apaga todos elementos da fila
 * (usar limpa_fila)
 * e depois desaloca a cabeça da fila
 * @param head 	-> descritor da fila*/
void destroi_fila(Fila *head) {
	limpa_fila(head);
	free(head);
}

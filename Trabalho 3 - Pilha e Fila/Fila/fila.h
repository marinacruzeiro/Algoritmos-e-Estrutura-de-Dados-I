#include <stdio.h>
#include <stdlib.h>

/* Estrutura de um Nodo 
 * qualquer da pilha*/
typedef struct nodo{
   int val;
   struct nodo *prox;
}Nodo;


/* Estrutura da cabeça da pilha 
 * Usada para a chamada das funções,
 * inserções e remoções*/
typedef struct fila{
   struct nodo *first;
   struct nodo *last;
}Fila;



/* Cria uma fila
 * @return -> um descritor ou NULL caso nao conseguir alocar*/
Fila *cria_fila();


/* Insere um elemento no fim da fila
 * Nesta funçao deve-se alocar um novo Nodo, 
 * inserir val e direcionar os ponteiros da cabeça da fila
 * @param head 	-> descritor da fila
 * @param val 	-> elemento a ser inserido
 * @return 1 se OK, 0 se erro*/
int queue(Fila *head, int val);


/* Retorna e descarta o elemento no inicio da fila
 * (Não esquecer de dar "free" no elemtento descartado)
 * @param head	-> descritor da fila
 * @return 		-> O elemento ou -1 caso nao exista*/
int dequeue(Fila *head);



/* Apaga todos elementos da fila
 * usar funcao dequeue para limpar
 * @param head 	-> descritor da fila
 * @return 1 	-> se OK, -1 se erro*/
int limpa_fila(Fila *head);



/*Retorna o comprimento da fila
 * @param head 	-> descritor da fila
 * @return	 	-> comprimento da fila*/
int length(Fila *head);


/* Apaga todos elementos da fila
 * (usar limpa_fila)
 * e depois desaloca a cabeça da fila
 * @param head 	-> descritor da fila*/
void destroi_fila(Fila *head);
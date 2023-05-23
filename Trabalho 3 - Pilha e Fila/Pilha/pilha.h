#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct pilha{
   int qtd;
   int dados[MAX];
}Pilha ;


/** Cria uma pilha
 * @return  um descritor ou NULL*/
Pilha *cria_pilha();


/* Insere um elemento no topo da pilha
 * @param p descritor de pilha
 * @param val elemento a ser inserido
 * @return 1 se OK, 0 se erro*/
int push(Pilha *p, int val);


/* Retorna o elemento no topo da pilha, ou -1 se não existir
 * @param p descritor da pilha
 * @return o elemento ou -1*/
int top(Pilha *p);

/* Descarta o topo da pilha
 * @param p descritor de pilha
 * @return 1 se OK, -1 se nao existir elementos para apagar*/
int pop(Pilha *p);


/** Apaga todos elementos da pilha
 * usar funcao pop para limpar
 * @param p descritor da pilha
 * @return 1 se OK, -1 se erro*/
int limpa_pilha(Pilha *p);


/*Retorna o comprimento da pilha
 * @param head 	-> descritor da pilha
 * @return	 	-> comprimento da pilha*/
int length(Pilha *head);


/* Desaloca a pilha
 * @param head 	-> descritor da pilha*/
void destroi_pilha(Pilha *head);
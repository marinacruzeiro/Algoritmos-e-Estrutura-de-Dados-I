#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	struct node *left, *right;
}nodo;

//Funcao ja implementada no arquivo arvore.c
void print_tab(int level);

//Funcao ja implementada no arquivo arvore.c
void print_tree( struct node *current, int level );



/** Insere um nodo na árvore ITERATIVAMENTE
 * @param root a raiz da árvore
 * @param key chave a ser inserida
 * @return raiz se inseriu, ou ponteiro NULL se erro */
nodo *insere_iterativo(nodo *root, int key);



/** Insere um nodo na árvore RECURSIVAMENTE
 * @param current a raiz da árvore (e consequentemente os nodos ao avançar)
 * @param key chave a ser inserida
 * @return raiz se inseriu, ou ponteiro NULL se erro */
nodo *insere_recursivo(nodo *current, int key);



 /** Remove um nodo na árvore e operacoes necessarias
 PODE SER RESOLVIDO TANTO ITERATIVO COMO RECURSIVO (ESCOLHA DO ALUNO)
  * @param current a raiz da árvore
  * @param key chave a ser removida
  * @return nova raiz se removeu, NULL se árvore vazia*/ 
nodo *deleta(nodo *current, int key);



/** Imprime a árvore na saida em ordem de menor para maior 
	com a chaves separadas por espaço
  PODE SER RESOLVIDO TANTO ITERATIVO COMO RECURSIVO (ESCOLHA DO ALUNO)
    @param current a raiz da árvore */
void print_inOrder(nodo *current);



/** Retorna o numero de elementos de uma arvore
PODE SER RESOLVIDO TANTO ITERATIVO COMO RECURSIVO (ESCOLHA DO ALUNO)
    @param current raiz da arvore
    @return numero de elementos*/ 
int treeSize(nodo *current);


/** Destrói a arvore, liberando toda a memoria
	PODE SER RESOLVIDO TANTO ITERATIVO COMO RECURSIVO (ESCOLHA DO ALUNO)
	@param current raiz da arvore
    @return Ponteiro NULL*/  
nodo *destroyTree(nodo *current);



/** Busca se um nodo esta inserido na arvore
	PODE SER RESOLVIDO TANTO ITERATIVO COMO RECURSIVO (ESCOLHA DO ALUNO)
	@param current raiz da arvore
    @return 1 se encontrou, 0 caso contrário*/  
int searchNodo(nodo *current, int n);






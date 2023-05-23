// 5º Trabalho de Algoritmos e Estrutura de Dados
// Arvore AVL
// Marina Cruzeiro

#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

Nodo_AVL *rotation_LL(Nodo_AVL *raiz);  //(Rotacao Simples a Direita)
Nodo_AVL *rotation_RR(Nodo_AVL *raiz);  //(Rotacao Simples a Esquerda)
Nodo_AVL *rotation_LR(Nodo_AVL *raiz);  //(Rotacao Dupla a Direita)
Nodo_AVL *rotation_RL(Nodo_AVL *raiz);  //(Rotacao Dupla a Esquerda)
int balanceamento (Nodo_AVL *current); 	// Faz o cálculo do balanceamento
int maior(int A, int B);				// Faz o cálculo do maior número

void print_tab(int level){
  int i;
  for (i = 0; i < level; i++ )
    printf("\t");
}

void print_tree( Nodo_AVL *current, int level ){
  if ( current == NULL ) {
    print_tab(level );
    printf("~\n");
  } else {
    print_tree( current->right, level + 1 );
    print_tab(level);
    printf ("%d\n", current->key );
    print_tree( current->left, level + 1 );
  }
}

/** Insere um nodo na arvore e realiza as rotacoes necessarias
 * @param root a raiz da arvore
 * @param key chave a ser inserida
 * @return nova raiz se inseriu, NULL se erro */
Nodo_AVL *avl_insert(Nodo_AVL *current, int key) {
	
    if (current == NULL) {				// Se e a raiz da arvore ou folha, insere
    	current = (Nodo_AVL *) malloc(sizeof(Nodo_AVL));
        current->key = key;
        current->left = NULL;
        current->right = NULL; 
	}
 
    if (key < current->key) {			// Se o valor a ser inserido e menor que o current,
    	current->left  = avl_insert(current->left, key); // percorre a arvore ate achar um lugar adequado
	}
	
	if (key > current->key) {			// Se o valor a ser inserido e maior que o current,
		current->right = avl_insert(current->right, key); // percorre a arvore ate achar um lugar adequado
	}

    if (balanceamento(current) < -1) {		// Caso o balanceamento seja menor que 1, entra nos seguintes casos:
    	if (key > current->right->key) { 	// Caso RR (Simples Esquerda)
			return (rotation_RR(current));
		}else {								// Caso RL (Dupla Esquerda)
			current->right = rotation_LL(current->right);
        	return (rotation_RR(current));
		}
	}
    
    if (balanceamento(current) > 1) {		// Caso o balanceamento seja maior que 1, entra nos seguintes casos:
    	if (key < current->left->key) { 	// Caso LL (Simples Direita)
			return (rotation_LL(current));
		} else {							// Caso LR (Dupla Direita)
			current->left =  rotation_RR(current->left);
       		return (rotation_LL(current));
		}
	}
											// Calcula a nova altura de current
	current->height = maior(avl_height(current->left), avl_height(current->right)) +1; 

    return (current);						// Retorna o resultado
}	
	


int balanceamento (Nodo_AVL *current) {
	
	int aux;
	
	if (current == NULL) {
		return (0);
	}
    
    // Calcula o balanceamento atraves da subtracao da altura do no da esquerda - altura do no da direita
    aux = avl_height(current->left) - avl_height(current->right);
    
    return (aux);
	
}

// Rotacao Simples a Direita:
Nodo_AVL *rotation_LL(Nodo_AVL *raiz) {
	
    Nodo_AVL *aux;
    
    aux = raiz->left;					// Rotaciona os nos
    raiz->left = aux->right;
    aux->right = raiz;    				
										// Calcula a nova altura
    raiz->height = maior(avl_height(raiz->left), avl_height(raiz->right)) +1;
    aux->height = maior(avl_height(aux->left), raiz->height) +1;
    
	return (aux);
    
}

// Rotacao Simples a Esquerda
Nodo_AVL *rotation_RR(Nodo_AVL *raiz) {
	
    Nodo_AVL *aux;
    
    aux = raiz->right;					// Rotaciona os nos
    raiz->right = aux->left;
    aux->left = raiz;
    									// Calcula a altura nova
    raiz->height = maior(avl_height(raiz->left), avl_height(raiz->right)) + 1;
    aux->height = maior(avl_height(aux->right),raiz->height) + 1;
    
    return (aux);
}

//(Rotacao Dupla a Direita)
Nodo_AVL *rotation_LR(Nodo_AVL *raiz) {
	
	Nodo_AVL *aux;
												// São necessárias duas rotaces
	raiz->left = rotation_RR (raiz->left);		// Utiliza a função da Rotacao Simples a Esquerda,
	aux = rotation_LL (raiz);					// após isso, utiliza a Rotacao Simples a Direita
	
	return (aux);
}

// Rotacao Dupla a Esquerda
Nodo_AVL *rotation_RL(Nodo_AVL *raiz) {
	
	Nodo_AVL *aux;
													// Sao necessarias duas rotacoes,
	raiz->right = rotation_LL(raiz->right);			// Utiliza-se a Rotacao Simples a Direita,
	aux = rotation_RR(raiz);						// apos, utiliza-se a Rotacao Simples a Esquerda
	return (aux);									
	
}



 /** Busca uma chave na arvore
  * @param root a raiz da arvore
  * @param key chave a ser removida
  * @return ponteiro para nodo se encontrou, NULL se erro ou arvore vazia*/  
 Nodo_AVL *avl_search(Nodo_AVL *current, int key) {
 	
 	if (current == NULL) {		// Verifica se e arvore vazia
		return (NULL);
	}
	
	Nodo_AVL *aux;
	aux = current;		// Cria um no auxiliar que recebe a raiz da arvore
	
	while (aux != NULL) {		// Enquanto o auxiliar for diferente de NULL
		if (key == aux->key) {	// Se o valor que deseja-se enontrar for igual ao do valor do auxiliar,
			return (aux);			// retorna o valor 1;
		}
		if (key > aux->key) {		// Caso contrário, se o valor for maior que o do auxiliar,
			aux = aux->right;	// anda-se para a direita da arvore.
		} else {				// Se o valor for menor que o do auxiliar,
			aux = aux->left;	// anda-se para a esquerda da arvore.
		}
	}
	return (NULL);					// Se saiu do while é porque não existe o valor, retorna-se NULL.
 	
 }



 /** Remove um nodo na arvore e realiza as rotacoes necessarias
  * @param root a raiz da arvore
  * @param key chave a ser removida
  * @return nova raiz se removeu, NULL se erro ou arvore vazia*/  
 Nodo_AVL *avl_delete(Nodo_AVL *current, int key) {
}

/** Remove todos os elementos de uma arvore
  * @param root a raiz da arvore*/
 void avl_destroy(Nodo_AVL *current) {
 	
 	if (current == NULL) {			// Verifica se a arvore e vazia
		return;
	}
	avl_destroy (current->left);	// Atravez da recursao anda-se para a esquerda,
	avl_destroy (current->right);	// e para a direita da arvore,
	free (current);					// liberando cada no.
	return;
 	
 }



/** Retorna a altura de uma arvore 
 * @param root a raiz da arvore
 * @return altura*/
 int avl_height(Nodo_AVL *current) {
 	
 	if (current == NULL) {
        return (-1);
    } else {
    	return (current->height); // Retorna a altura da raiz
	}
	
}


// Compara os números e retorna o maior
int maior(int a, int b) {
    
	if (a > b) {
        return (a);
    } else {
        return b;
    }
    
}

/** Imprime a arvore na saida no formato inOrder com chaves separadas por espaco
 * @param root a raiz da arvore*/
 void print_inOrder(Nodo_AVL *current) {
 	
 	if (current != NULL) {				// Enquanto current nao e NULL;
		print_inOrder (current->left);	// Atravez da recursao, anda-se para a esquerda, imprimindo o valor
		printf ("%d ", current->key);	
		print_inOrder (current->right); // Atravez da recursao, anda-se para a direita, imprimindo o valor
	}
 	
 }

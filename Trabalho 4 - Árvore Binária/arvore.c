// 4º Trabalho de Algoritmos e Estrutura de Dados - Árvore Binária
// Marina Cruzeiro

#include "arvore.h"

void insere(nodo * current, int key); // Funcao insere para auxiliar no insere recursivo

void print_tab(int level){
  int i;
  for (i = 0; i < level; i++ )
    printf("\t");
}

void print_tree( struct node *current, int level ){
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

/** Insere um nodo na arvore ITERATIVAMENTE
 * @param root a raiz da arvore
 * @param key chave a ser inserida
 * @return raiz se inseriu, ou ponteiro NULL se erro */
nodo *insere_iterativo(nodo *root, int key) {
	
	//Cria um no que é uma folha, filhos direita e esquerda apontando para nulo
	nodo *nova;
	nova = malloc(sizeof(nodo));
	nova->key = key;
	nova->right = NULL;
	nova->left = NULL;
	if (root == NULL) {					// Verifica se a arvore e vazia
		root = nova;					// caso seja, insere o no novo como raiz da arvore
	} else {							// Se já existe arvore
		nodo *noatual = root;			// Cria dois ponteiros, um que vai apontar para o no atual
		nodo *nopai = NULL;				// e um que aponta para o no anterior (pai).
		while (noatual != NULL) {			// Neste ponto, se anda pela arvore ate o atual ser nulo.
			nopai = noatual;			// O ponteiro nopai vai apontar para o atual,
			if (key > noatual->key) {		// e se o valor que deseja inserir for maior que a do no atual,
				noatual = noatual->right;	// o ponteiro atual anda para a direita,
			} else {					// caso contrario, o valor é menor que o valor do ponteiro atual,
				noatual = noatual->left;	// o ponteiro anda para a esquerda da arvore.
			}
		}
		if (key > nopai->key) {			// Se o valor que deseja inserir é maior que o valor do ponteiro nopai
			nopai->right = nova;		// o filho direito do ponteiro nopai recebe o no nova.
		}
		else {							// Se o valor é menor que o ponteiro nopai,
			nopai->left = nova;			// o filho esquerdo é quem recebe nova.
		}
	}
	return (root);
}



/** Insere um nodo na arvore RECURSIVAMENTE
 * @param current a raiz da arvore (e consequentemente os nodos ao avancar)
 * @param key chave a ser inserida
 * @return raiz se inseriu, ou ponteiro NULL se erro */
nodo * insere_recursivo(nodo * current, int key) {
	if (current == NULL) {						// Verifica se e uma arvore vazia.
		current = (nodo*) malloc(sizeof(nodo));	// Se for, aloca um novo no,
		current->key = key;						// o valor desse novo no é o desejado inserir,
		current->left = NULL;					// e seus filhos da direita e da esqueda
		current->right = NULL;					// são NULL.
	}
	else {										// Se não for uma arvore vazia,
		insere(current, key);					// chama a funçao insere.
	}

	return current;
}

void insere(nodo *current, int key) {
	
	if (key > current->key) {						// Se o valor desejado é maior que o valor do no,
		if (current->right == NULL) {				// E se o filho da direita for nulo,
			current->right = malloc (sizeof(nodo));	// Aloca-se espaco para o no,
			current->right->key = key;				// e esse novo no vai receber o valor que se deseja inserir.
			current->right->left = NULL;			// Seus filhos da direita e da esquerda serao NULL.
			current->right->right = NULL;
		}
		else {
			insere(current->right, key);			// Caso tenha filhos a direita, chama a funcao
													// até encontrar um no que os filhos sejam NULL.
		}
	}
	else {
		if (current->left == NULL) {				// Se o valor desejado é menor que o do no,
			current->left = malloc (sizeof(nodo));	// mesma coisa acontece como no caso anterior, apenas
			current->left->key = key;				// mudando para esquerda.
			current->left->left = NULL;
			current->left->right = NULL;
		}
		else {
			insere(current->left, key);
		}
	}	
}

 /** Remove um nodo na arvore e operacoes necessarias
 PODE SER RESOLVIDO TANTO ITERATIVO COMO RECURSIVO (ESCOLHA DO ALUNO)
  * @param current a raiz da arvore
  * @param key chave a ser removida
  * @return nova raiz se removeu, NULL se arvore vazia*/ 
nodo *deleta(nodo *current, int key) {

	nodo *aux;
	nodo *nopai;

	if (current == NULL) {				// Verifica se existe arvore.
		return NULL;
	}

	if (current->key == key) { 			// Se encontrou o valor a ser removido:
		
		// Nao tem filhos
		if (current->left == NULL && current->right == NULL) { // Se ambos os filhos são NULL
			free(current);				// libera o no
			current = NULL;				// e aponta para NULL
		}
		else {
			
			// Um filho so
			if (current->left == NULL || current->right == NULL) { // Se um dos filhos for NULL
				if (current->right == NULL) {	// Se o filho direito é nulo,
					aux = current->left;		// o ponteiro auxiliar recebe o filho esquerdo e
					free (current);				// libera o no desejado.
					current = aux;				// O ponteiro current passa a ter o valor do auxiliar.
				} else {						// Caso o filho esquerdo seja nulo,
					aux = current->right;		// o ponteiro auxiliar recebe o valor do filho direito,
					free (current);				// libera o no com o valor desejado,
					current = aux;				// e current passa a ter o valor do auxiliar.
				}
			}
			
			// Dois filhos
			else {
				nopai = current->right;			// Ponteiro que vai apontar para o no pai do que vai mudar
				aux = current->right;			// de posicao. Ira seguir o ponteiro auxiliar.
				while (aux->left != NULL) {		// Enquanto não encontrar o ultimo no da esquerda que segue o
					nopai = aux;				// da direita apos encontrar o no que deseja-se remover
					aux = aux->left;			// segue andando pela arvore. 
				}								// Quando encontra esse ultimo no,
				aux->right = current->right;	// Filho direito do auxiliar recebe o filho direito do
												// no que deseja-se remover.
				aux->left = current->left;		// Filho esquerdo do auxiliar recebe o filho esquerdo do
												// no que deseja-se remover.
				free (current);					// Libera o no que deseja-se remover.
				current = aux;					// Current agora recebe o aux
				nopai->left = NULL;				// O no pai do que agora e o current tem seu filho esquerdo nulo 

			}
		}
	}
	else {								// Se não encontrou o valor a ser removido
		if (current->key > key) {		// Se o valor for menor que o atual, continua andando para a
			current->left = deleta(current->left, key);	// esquerda da arvore.
		}
		if (current->key < key) {		// Se o valor for menor que o atual, continua andando para a
		current->right = deleta(current->right, key); // direita da arvore.
		}
	}

	return current;

	
}


/** Imprime a arvore na saida em ordem de menor para maior 
	com a chaves separadas por espaco
  PODE SER RESOLVIDO TANTO ITERATIVO COMO RECURSIVO (ESCOLHA DO ALUNO)
    @param current a raiz da arvore */
void print_inOrder(nodo *current) {
	if (current != NULL) {				// Enquanto current nao e NULL;
		print_inOrder (current->left);	// Atravez da recursao, anda-se para a esquerda, imprimindo o valor
		printf ("%d ", current->key);	
		print_inOrder (current->right); // Atravez da recursao, anda-se para a direita, imprimindo o valor
	}
}


/** Retorna o numero de elementos de uma arvore
PODE SER RESOLVIDO TANTO ITERATIVO COMO RECURSIVO (ESCOLHA DO ALUNO)
    @param current raiz da arvore
    @return numero de elementos*/ 
int treeSize(nodo *current) {
	
	int qtdesquerda, qtddireita, qtd;
	
	if (current == NULL) {					// Verifica se a arvore e vazia
		return (0);
	}
	
	qtdesquerda = treeSize (current->left);	// Atravez da recursao, anda-se para a esquerda contando,
	qtddireita = treeSize (current->right);	// e para a direita, também contando.
	qtd = qtdesquerda+qtddireita+1;			// Soma-se os dois valores.
	return (qtd);							// Retorna a quantidade de elementos.
}


/** Destroi a arvore, liberando toda a memoria
	PODE SER RESOLVIDO TANTO ITERATIVO COMO RECURSIVO (ESCOLHA DO ALUNO)
	@param current raiz da arvore
    @return Ponteiro NULL*/  
nodo * destroyTree(nodo *current) {
	if (current == NULL) {			// Verifica se a arvore e vazia
		return;
	}
	destroyTree (current->left);	// Atravez da recursao anda-se para a esquerda,
	destroyTree (current->right);	// e para a direita da arvore,
	free (current);					// liberando cada no.
	return NULL;
}


/** Busca se um nodo esta inserido na arvore
	PODE SER RESOLVIDO TANTO ITERATIVO COMO RECURSIVO (ESCOLHA DO ALUNO)
	@param current raiz da arvore
    @return 1 se encontrou, 0 caso contrario*/  
int searchNodo(nodo *current, int n) {
	
	if (current == NULL) {		// Verifica se e arvore vazia
		return (0);
	}
	
	nodo* aux = current;		// Cria um no auxiliar que recebe a raiz da arvore
	
	while (aux != NULL) {		// Enquanto o auxiliar for diferente de NULL
		if (n == aux->key) {	// Se o valor que deseja-se enontrar for igual ao do valor do auxiliar,
			return (1);			// retorna o valor 1;
		}
		if (n > aux->key) {		// Caso contrário, se o valor for maior que o do auxiliar,
			aux = aux->right;	// anda-se para a direita da arvore.
		} else {				// Se o valor for menor que o do auxiliar,
			aux = aux->left;	// anda-se para a esquerda da arvore.
		}
	}
	return (0);					// Se saiu do while é porque não existe o valor, retorna-se 0.
}

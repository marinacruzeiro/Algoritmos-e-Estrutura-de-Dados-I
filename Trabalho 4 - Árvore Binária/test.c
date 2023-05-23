#include "simpletest.h"
#include "arvore.h"

#define MAX 7

//Vetor para insercao balanceada
int vet[MAX] = {4,2,1,3,6,5,7};


void test_insert_iterative();
void test_insert_recursive();
void test_delete();

//Sugerivel comentar e testar uma por vez...fica muito poluido o terminal ao examinar todas
int main () {
	test_insert_iterative();
	test_insert_recursive();
	test_delete();
}




void test_insert_iterative(){
	int i;
	nodo* root = NULL;

	DESCRIBE("ARVORE - INSERE ELEMENTOS (Iterativo)");
	WHEN("Eu insiro elementos");
		IF("Insiro MAX elementos ordenados");
		THEN("Deve inserir todos");

			for(i=0; i<(MAX); i++){
				root = insere_iterativo(root,i);
				isEqual_Spaced(searchNodo(root,i),1);
			}
			printf("\n");

		THEN("Deve ter tamanho MAX");
			isEqual(treeSize(root),MAX);


		THEN("Consegue imprimir a arvore desbalanceada para a direita");
			print_tree(root,0);



		WHEN("Destruo a arvore");
			THEN("Ponteiro deve ser NULL");
				root = destroyTree(root);
				isNull(root);
	printf("\n|-----------------------------------------------------------------------------|\n\n");

	WHEN("Eu insiro elementos");
		IF("Insiro MAX elementos balanceados");
		THEN("Deve inserir todos");

			for(i=0; i<MAX; i++){
				root = insere_iterativo(root,vet[i]);
				isEqual_Spaced(searchNodo(root,vet[i]),1);
			}
			printf("\n");

		THEN("Consegue imprimir a arvore BALANCEADA");
			print_tree(root,0);

		THEN("Funcao print_inOrder deve imprimir todos os elementos na ordem");
			printf("\t");
			print_inOrder(root);
			printf("\n\n");

		WHEN("Destruo a arvore");
			THEN("Ponteiro deve ser NULL");
				root = destroyTree(root);
				isNull(root);
	printf("\n|-----------------------------------------------------------------------------|\n\n");
}

void test_insert_recursive(){
	int i;
	nodo* root = NULL;

	DESCRIBE("ARVORE - INSERE ELEMENTOS (Recursivo)");
	WHEN("Eu insiro elementos");
		IF("Insiro MAX elementos ordenados");
		THEN("Deve inserir todos");

			for(i=0; i<(MAX); i++){
				root = insere_recursivo(root,i);
				isEqual_Spaced(searchNodo(root,i),1);
			}
			printf("\n");

		THEN("Deve ter tamanho MAX");
			isEqual(treeSize(root),MAX);


		THEN("Consegue imprimir a arvore desbalanceada para a direita");
			print_tree(root,0);



		WHEN("Destruo a arvore");
			THEN("Ponteiro deve ser NULL");
				root = destroyTree(root);
				isNull(root);
	printf("\n|-----------------------------------------------------------------------------|\n\n");

	WHEN("Eu insiro elementos");
		IF("Insiro MAX elementos balanceados");
		THEN("Deve inserir todos");

			for(i=0; i<MAX; i++){
				root = insere_recursivo(root,vet[i]);
				isEqual_Spaced(searchNodo(root,vet[i]),1);
			}
			printf("\n");

		THEN("Consegue imprimir a arvore BALANCEADA");
			print_tree(root,0);

		THEN("Funcao print_inOrder deve imprimir todos os elementos na ordem");
			printf("\t");
			print_inOrder(root);
			printf("\n\n");

		WHEN("Destruo a arvore");
			THEN("Ponteiro deve ser NULL");
				root = destroyTree(root);
				isNull(root);
	printf("\n|-----------------------------------------------------------------------------|\n\n");
}


void test_delete(){
	int i;
	nodo* root = NULL;

	DESCRIBE("ARVORE - DELETA ELEMENTOS");
	WHEN("Eu insiro os elementos ordenados, Deve ter tamanho MAX");
		for(i=0; i<MAX; i++){
			root = insere_recursivo(root,vet[i]);
		}
		isEqual(treeSize(root),MAX);
		print_tree(root,0);
	
	WHEN("Eu deleto um elemento");
		IF("Nodo nao possui filhos");
			THEN("Apenas remove, sem precisar alterar a arvore");
				root = deleta(root, 1);
			print_tree(root,0);

			THEN("Tamanho deve ser MAX-1");
				isEqual(treeSize(root),MAX-1);


		printf("\n|-----------------------------------------------------------------------------|\n\n");
		IF("Nodo possui 1 filho");
			THEN("Deve remanejar a arvore para o 'pai' do nodo a ser destruido apontar para o filho do mesmo");
				root = deleta(root, 2);
			print_tree(root,0);

			THEN("Tamanho deve ser MAX-2");
				isEqual(treeSize(root),MAX-2);


		printf("\n|-----------------------------------------------------------------------------|\n\n");
		IF("Nodo possui 2 filhos");
			THEN("Deve procurar o menor filho à direita para substituir seu lugar na arvore");
				root = deleta(root, 4);
			print_tree(root,0);

			THEN("Tamanho deve ser MAX-3");
				isEqual(treeSize(root),MAX-3);

	printf("\n|-----------------------------------------------------------------------------|\n\n");
	WHEN("Eu apago os elementos restantes");
		root = deleta(root, 3);
		root = deleta(root, 5);
		root = deleta(root, 6);
		root = deleta(root, 7);
	THEN("Tamanho deve ser 0");
		isEqual(treeSize(root),0);
	THEN("ponteiro deve ser NULL");
		isNull(root);
}





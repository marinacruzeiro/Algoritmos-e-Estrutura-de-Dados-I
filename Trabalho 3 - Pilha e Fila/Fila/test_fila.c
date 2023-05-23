#include "simpletest.h"
#include "fila.h"

#define MAX 100


void test_create(){
	DESCRIBE("CRIA Fila");
	WHEN("Eu crio uma Fila");


	IF("Sem parâmetros");
	THEN("Resultado deve ser ponteiro");
	struct fila *p = cria_fila();
	isNotNull(p);

	THEN("Deve ser vazia");
	isEqual(length(p),0);

	destroi_fila(p);
}

void test_queue(){
	int i;
	struct fila *p = cria_fila();

	DESCRIBE("INSERE ELEMENTOS");
	WHEN("Eu insiro elementos");
	IF("Insiro um número razoável MAX");
	THEN("Deve inserir todos");
	for(i=1; i<=MAX; i++){
		isEqual_Spaced(queue(p,i), 1);
	}
	printf("\n");
	THEN("Comprimento deve ser MAX");
	isEqual(length(p),MAX);

	THEN("Primeiro elemento deve ser o primeiro inserido");
	isEqual(dequeue(p),1);

	WHEN("Eu limpo a fila");
	limpa_fila(p);

	THEN("Deve retornar uma lista vazia");
	isNull(p->first);
	
	THEN("Comprimento deve ser 0");
	isEqual(length(p),0);

	destroi_fila(p);
}

void test_dequeue(){

	int i;
	struct fila *p = cria_fila();


	DESCRIBE("REMOVE ELEMENTOS");
	WHEN("Eu removo os elementos de uma fila");
	for(i=1; i<=MAX; i++){
		queue(p,i);
	}
	THEN("Elemento retornado deve ser os inseridos por primeiro");
	for(i=1; i<=MAX; i++){
		isEqual_Spaced(dequeue(p),i);
	}
	printf("\n");
	
	THEN("Comprimento deve ser 0");
	isEqual(length(p),0);

	destroi_fila(p);
}



int main () {
	test_create();
	test_queue();
	test_dequeue();
}

#include "simpletest.h"
#include "pilha.h"

void test_create(){
	DESCRIBE("CRIA PILHA");
	WHEN("Eu crio uma pilha");


	IF("Sem parâmetros");
	THEN("Resultado deve ser ponteiro");
	Pilha *p = cria_pilha();
	isNotNull(p);

	THEN("Deve ser vazia");
	isEqual(length(p),0);

	destroi_pilha(p);
}

void test_push(){
	int i;
	Pilha *p = cria_pilha();

	DESCRIBE("INSERE ELEMENTOS");
	WHEN("Eu insiro elementos");
	IF("Insiro um número razoável MAX");
	THEN("Deve inserir todos");
	for(i=1; i<=MAX; i++){
		isEqual_Spaced(push(p,i), 1);
	}
	printf("\n");

	THEN("Comprimento deve ser MAX");
	isEqual(length(p),MAX);

	THEN("Topo deve ser MAX");
	isEqual(top(p),MAX);

	WHEN("Eu limpo a pilha");
	limpa_pilha(p);
	
	THEN("Comprimento deve ser 0");
	isEqual(length(p),0);

	destroi_pilha(p);
}

void test_pop(){

	int i;
	Pilha *p = cria_pilha();


	DESCRIBE("REMOVE ELEMENTOS");
	WHEN("Eu removo os elementos de uma pilha");
	for(i=1; i<=MAX; i++){
		push(p,i);
	}
	THEN("Elemento retornado deve ser os inseridos por ultimo");
	for(i=MAX; i>0; i--){
		isEqual_Spaced(top(p),i);
		isEqual_Spaced(pop(p),1);
	}
	printf("\n");

	THEN("Deve ser vazia");
	isEqual(length(p),0);
	destroi_pilha(p);
}



int main () {
	test_create();
	test_push();
	test_pop();
}

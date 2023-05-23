#include "simpletest.h"
#include "ListaSequencial.h"

void test_create(){
	DESCRIBE("CRIA LISTA");
	IF("Eu crio uma lista");
	THEN("Resultado deve ser ponteiro");
	Lista *l = cria_lista();
	isNotNull(l);
	
	IF("Eu Testo o tamanho");
	THEN("Comprimento deve ser 0");
	isEqual(length(l),0);
	
	destroi_Lista(l);
}

void test_inserts(){
	int i;

	Lista *l = cria_lista();

	DESCRIBE("INSERE ELEMENTOS");
	WHEN("Eu insiro elementos no começo");
	IF("Insiro tantos quanto o máximo");
	THEN("Deve inserir todos");
	for(i=0; i<MAX; i++){
		isEqual(insere(l, i, i), 1);
	}
	THEN("Comprimento deve ser MAX");
	isEqual(length(l),MAX);

	THEN("Deve estar cheia");
	isEqual(lista_cheia(l),1);

	IF("Insiro mais que a capacidade");
	THEN("Resultado deve ser erro");
	isEqual(insere(l,MAX+1, MAX+1), 0);

	destroi_Lista(l);
	l = cria_lista();

	destroi_Lista(l);
}

void test_delete(){

	int i;

	Lista * l = cria_lista();
	for(i=0; i<MAX; i++){
		insere(l, i, i);
	}

	DESCRIBE("REMOVE ELEMENTOS");
	WHEN("Eu removo os elementos de uma lista");
	THEN("Deve remover");
	for(i=0; i < MAX; i++){
		isEqual(deleta(l, 0),1);
	}
	THEN("Comprimento deve ser 0");
	isEqual(length(l),0);
	destroi_Lista(l);
}

void test_get_set(){
	int i;

	Lista * l = cria_lista();
	for(i=0; i < MAX; i++){
		insere(l, i, i);
	}

	DESCRIBE("CONSULTANDO E MUDANDO ELEMENTOS");

	WHEN("Eu consulto um elemento inserido");
	THEN("Ele deve estar presente");
	isEqual(get(l,1), 1);

	WHEN("Eu consulto uma posição inexistente");
	THEN("Ele deve retornar Zero");
	isEqual(get(l,MAX),0);

	WHEN("Eu mudo o valor de um elemento existente");
	THEN("Ele deve mudar");
	isEqual(set(l,1,99), 1);
	isEqual(get(l,1), 99);

	WHEN("Eu mudo o valor de um elemento inexistente");
	THEN("Ele deve retornar erro");
	isEqual(set(l,MAX,1),0);

	destroi_Lista(l);
}

void test_locate(){
	int i;

	Lista * l = cria_lista();
	for(i=0; i<MAX; i++){
		insere(l, i, i);
	}
	DESCRIBE("LOCALIZANDO ELEMENTOS");
	WHEN("Procuro elemento inexistente");
	THEN("Não deve achar");
	isEqual(locate(l,-1),0);

	WHEN("Procuro elemento existente");
	THEN("Deve retornar a posição correta na lista");
	isEqual(locate(l,0),0);
	isEqual(locate(l,MAX/2),MAX/2);
	isEqual(locate(l,MAX-1),MAX-1);

	destroi_Lista(l);

}



int main () {
	test_create();
	test_inserts();
	test_delete();
	test_get_set();
	test_locate();
}

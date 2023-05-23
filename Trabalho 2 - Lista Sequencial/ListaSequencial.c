// 2º Trabalho de AED - Marina Cruzeiro

#include "ListaSequencial.h"

/** Cria uma lista com capacidade definida
 * @Capacidade da lista ajustado no #define MAX
 * @L->qtd deve ser ajustado para 0 (lista vazia)
 * @return descritor de lista ou NULL*/
Lista *cria_lista {
	cria_lista = malloc (MAX * sizeof(Lista));
	cria_lista->qtd = NULL;
}

/* Testa se a lista esta cheia */
int lista_cheia(Lista *L) {
	
	//verifica se o tamanho da lista é igual ao máximo estabelecido
	if (L->dados == MAX) {
		return (1);
	} else {
		return (0);
	}
}


/* Testa se a lista esta vazia*/
int lista_vazia(Lista *L) {
	
	//verifica se o tamanho da lista é igual a zero
	if (L->qtd == 0) {
		return (1);
	} else {
		return (0);
	}
}

/* Destroi a lista, liberando a memoria.*/
void destroi_Lista(Lista *L) {
	
	//Enquanto a lista não tem tamanho zero, cria-se uma struct, que vai apagando 
	//desde a primeira celula até não sobrar mais nenhuma
	while (L->dados > 0) {
		Lista *apaga_inicio;
		apaga_inicio = L->dados;
		L->dados = apaga_inicio->dados;
		free (apaga_inicio);
	}
}


/* Insere um elemento na lista em uma posiçao*/
int insere(Lista *L, int pos, int valor) {
	
	int i;
	
	if(pos>0 && pos <= MAX) {
		//Se quer inserir na primeira posição da lista
		if(pos==1) {
			//Cria-se uma nova celula que vai apontar para a antiga primeira celula
			//fazendo com que esta nova celula seja a primeira da lista
			Lista *nova;
			nova = malloc (sizeof(Lista));
			nova->qtd = valor;
			nova->dados = L->dados;
			L->dados = nova;
			return (1);
		} else {
			//Inserir no meio da lista, cria-se três novas celulas, a atual, anterior e a nova
			Lista *atual = L->dados;
			Lista *anterior=L; 
			Lista *nova;
			nova = malloc (sizeof(Lista));
	
			//Deve-se guardar a posição anterior e a atual e fazer elas correrem
			//pela lista até encontrarem a posição desejada para a inserção da
			//nova celula
			for(i = 1; i < pos; i++) {
					anterior=atual;
					atual=atual->dados;
			}
			anterior->dados=nova;
			nova->dados = atual;
			return (1);
			} else {
				return (0);
			}
	}
}


/* Remove um elemento de uma posiçao*/
int deleta(Lista *L, int pos) {
	
	int i;
	
	if(pos > 0 && pos <= MAX){
		//Se a celula que se deseja remover for a primeira
		//Cria-se uma nova celula que vai apontar para a primeira celula e removê-la
		if(pos == 1) {
			Lista *apaga;
			apaga = L->dados;
			L->dados = apaga->dados;
			free (apaga);
			return (1);
		}else{
			//Deve-se guardar a posição anterior e a atual e fazer elas correrem
			//pela lista até encontrarem a posição desejada para a remoção da
			//nova celula			
			Lista *atual = L->dados;
			Lista *anterior = L; 
				 
			for(i = 1; i < pos; i++) {
				anterior=atual;
				atual=atual->dados;
			}
			
			anterior->dados = atual->dados;
			return (1);
		}else{
			return (0);
		}
	}
}


/* Encontra um elemento com um determinado valor*/
int locate(Lista *L, int numero) {
	
	int contador=0;
	
	//Percorre-se a lista ate encontrar o conteudo desejado
	while (L->dados->qtd != numero && L->dados->dados != NULL) {
		L = L->dados;
		contador++;
	}
	//caso encontrado este conteudo, retorna-se o valor do contador
	//que marcava a posiçao
	if (L->dados->qtd == numero) {
		return (contador);
	} else {
		return (0);
	}
}


/* Retorna o valor do elemento.*/
 int get(Lista *L, int pos) {
 	
 	int contador=1;
 	
 	if(pos > 0 && pos <= MAX){
		//caso a posição desejada seja a primeira celula, retorna-se o elemento
		if(pos == 1) {
			return (L->qtd);
		} else {
			//Caso o contrário, percorre-se a lista com um contador de posiçoes até
			//a posicao desejada. Quando encontrada, o laço é interrompido
			while (L->dados->dados != NULL)	{
				L = L->dados;
				contador++;
				if (contador = pos) {
					return (L->qtd);
					break;
				}
			}
		}
	}
}


/* Muda o valor do elemento.*/
int set(Lista *L, int pos, int valor) {
		
 	int contador=1;
 	
 	if(pos > 0 && pos <= MAX){
 		//caso a posição desejada seja a primeira celula, troca-se o elemento
		if(pos == 1) {
			L->qtd = valor;
			return(1);
		} else {
			//caso a posicao desejada seja no meio da lista, percorre-se ela
			//com um contador ate encontrar a posiçao desejada para a troca
			//quando ela ocorre, o laço é interrompido
			while (L->dados->dados != NULL)	{
				L = L->dados;
				contador++;
				if (contador = pos) {
					L->qtd = valor;
					return (0);
					break;
				}
			}
		} else {
			return (0);
		}
	}
	
}


/* Retorna o comprimento da lista*/
int length(Lista *L) {

	int contador = 0;
	//Percorre-se a lista até o final, juntamente com um contador. 
	//Ao chegar no final, retorna-se o valor do contador.
	while (L->dados != NULL) {
		L = L->dados;
		contador++;
	}
	return (contador);
	
}


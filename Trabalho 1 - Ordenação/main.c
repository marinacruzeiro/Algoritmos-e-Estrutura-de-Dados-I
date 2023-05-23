#include "funcoes.h"

int main(int argc, char const *argv[])
{
    int *vet,k,i,n, m;
    char fileName[20] = "quickde.txt";
    FILE *arq;
    clock_t inicio, fim;
    double duracao;
    long int longRand;
    
	srand(time(NULL));   // should only be called once
    

    /*-------------------------

    Caso Aleatório = Gera 10 vetores com cada tamanho, ordena e escreve
    no arquivo
    -------------------------*/
    arq = fopen(fileName,"w");
    if (arq == NULL){
       printf("ERRO: Não foi possível abrir o arquivo.\n");
       printf("Terminando a Execução.\n");
       exit(1);
    }
    printf("Arquivo \"%s\" criado com sucesso.\n",fileName);

    
    printf("Pior Caso.\n");
    for (n = 1000; n <= 100000; ){
        printf("\t%d: ",n);
        fprintf( arq, "%d;", n);

        //for (k = 1; k <= 10; k++){

            vet = (int *)malloc(n * sizeof(int));
            if(vet == NULL){
                printf("ERRO: Memoria Insuficiente.\n");
                printf("Terminando a Execução.\n");
                exit(1);
            }
            
            m = n;
            
            for(i = 0; i < n; i++) {
                vet[i] = m;
                m--;
           }
    
            inicio = clock();
            quick_sort(vet, 0, n);
            fim = clock();
    
            duracao = (double)(fim - inicio)/CLOCKS_PER_SEC;

            fprintf( arq, "%f;", duracao);
            free(vet);
        //}
        fprintf( arq, "\n");
        printf("OK\n");

        if(n == 1000)
            n+=4000;
        else
            n+=5000;
    
    }
    fclose(arq);
   
}

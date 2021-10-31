// QUESTÃO 09:
// Implementar uma função que, dado um
// número inteiro, calcule (e retorne) a soma e a
// média de seus divisores.

//Inclusão de bibliotecas
#include <stdio.h>

//Declaração das funções
void somaMediaDivisor(int numero, int* soma, float* media);


//Programa main
void main(){
    	
	//Declaração de variáveis
	int numero, soma;
    float media;
	
	//Corpo do programa

	//Solicitação de variáveis
	printf("DIgite um numero inteiro: ");
    scanf("%d", &numero);

    //chamando funcao
    somaMediaDivisor(numero, &soma, &media);

    //exibindo resultado
    printf("Soma dos divisores = %d\n", soma);
    printf("Media dos divisores = %f", media);
}

//Chamando função
void somaMediaDivisor(int numero, int* soma, float* media){
    *soma = numero;//o maior primo é sempre o próprio número
    int cont = 1;
    for(int i = numero/2; i >= 1; i--){//procurando divisores
        if(numero % i == 0){
           *soma += i;//somando 
           cont++;//contando para a média
        }
    }
    *media = (float) *soma / cont;
}
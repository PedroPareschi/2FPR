// QUESTÃO 03:
// Desenvolver uma função que calcule o n-ésimo
// termo da sequência de Fibonacci.

//Inclusão de bibliotecas
#include <stdio.h>

//Declaração das funções
int ler();
int fibonnaci(int n);

//Programa main
void main(){
    	
	//Declaração de variáveis
	int termo, posicao;
	
	//Corpo do programa
    
	//Solicitação de variáveis
	posicao = ler();

    termo = fibonnaci(posicao);//chamando funcao

    //imprimindo resultado
    printf("Termo na posicao %d: %d", posicao, termo);
}

//funão para leitura
int ler(){
    int n;
    do{
        printf("Digite a posicao do termo: ");
        scanf("%d", &n);
        if(n<0){
            printf("\nErro: digite um numero nao negativo\n");
        }
    }while (n < 0);//garantindo que o numero passado seja nao negativo
    
    return n;
}

//encontrando termo na funcao recursivamente
int fibonnaci(int n){
    if(n == 0){//se o numero for 0, o resultado é 0
        return 0;
    } if(n == 1){//se for 1, 1
        return 1;
    }
    return fibonnaci(n-1) + fibonnaci(n-2);//se for outro, o resultado é a soma dos dois anteriores
}
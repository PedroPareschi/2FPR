// QUESTÃO 01:
// Desenvolver uma função que exiba os múltiplos
// de N compreendidos no intervalo definido por
// A e B.

//Inclusão de bibliotecas
#include <stdio.h>

//Declaração das funções
void exibirMultiplos(int n, int a, int b);

//Programa main
void main(){
    	
	//Declaração de variáveis
	int n, a, b;
    
	//Corpo do programa
    //lendo do teclado
    printf("Digite o numero cujos multiplos derivarao: ");
    scanf("%d", &n);
    printf("\nDigite o valor minimo do intervalo: ");
    scanf("%d", &a);
    printf("\nDigite o valor maximo do intervalo: ");
    scanf("%d", &b);

    //chamando função
    exibirMultiplos(n, a, b);
}

//função para exibir os valores
void exibirMultiplos(int n, int a, int b){
    int i;
    for(i = a; i<=b; i++){
        if(i%n==0){
            printf("%d ", i);
        }
    }
}

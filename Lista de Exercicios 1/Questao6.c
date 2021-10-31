// QUESTÃO 06:
// Implementar uma função que, dado um
// número inteiro N, exiba uma sequência de
// números como as ilustradas nos exemplos a
// seguir:
// Exemplo 1: N = 3
// (1 2) (1 3) (2 1) (2 3) (3 1) (3 2)
// Exemplo 2: N = 5
// (1 2) (1 3) (1 4) (1 5) (2 1) (2 3) (2 4) (2 5) (3 1)
// (3 2) (3 4) (3 5) (4 1) (4 2) (4 3) (4 5) (5 1) (5 2) (5
// 3) (5 4)

//Inclusão de bibliotecas
#include <stdio.h>

//Declaração das funções
void exibirSequencia(int n);

//Programa main
void main(){
    	
	//Declaração de variáveis
	int n;
	
	//Corpo do programa

	//Solicitação de variáveis
	printf("Digite o valor de n: ");
    scanf("%d", &n);

    //chamando função
    exibirSequencia(n);
}


//função para exibir sequência
void exibirSequencia(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i!=j){
                printf("(%d %d) ", i, j);
            }
        }
    }
}
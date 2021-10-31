// QUESTÃO 08:
// Desenvolver uma função que exiba todos os
// números primos inferiores a determinado valor
// inteiro N.


//Inclusão de bibliotecas
#include <stdio.h>

//Declaração das funções
int ler();
void exibirPrimos(int n);

//Programa main
void main(){
    	
	//Declaração de variáveis
	int n;
	
	//Corpo do programa

	//Solicitação de variáveis
    n = ler();
	

    //imprimindo na tela
    exibirPrimos(n);
}
//Função para ler o algorismo
int ler(){
    int n;
    do{
        printf("Digite o valor máximo para imprimir os numeros primos: ");
        scanf("%d", &n);
        if(n <= 0){
            printf("\nErro: digite um numero positivo\n");
        }
    }while(n <= 0);
}
//Função para exibir os primos
void exibirPrimos(int n){
    for(int i = 2; i <= n; i++){
        for(int j = i/2; j >= 1; j--){//conferindo se é primo, numero por numero 
            if(j == 1){
                printf("%d ", i);
            } else if(i % j == 0){
                break;
            }
        }
    }
}



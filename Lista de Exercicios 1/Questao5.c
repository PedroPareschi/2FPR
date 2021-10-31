// QUESTÃO 05:
// Fazer uma função que calcule o MMC (mínimo
// múltiplo comum) entre dois números.

//Inclusão de bibliotecas
#include <stdio.h>

//Declaração das funções
int mmc(int a, int b);

//Programa main
void main(){
    	
	//Declaração de variáveis
	int num1, num2;
	
	//Corpo do programa

	//Solicitação de variáveis
	printf("Digite o valor do primeiro numero: ");
    scanf("%d", &num1);

    printf("Digite o valor do segundo numero: ");
    scanf("%d", &num2);

    //imprimindo resultado
    printf("\n\nMMC entre %d e %d: %d", num1, num2, mmc(num1, num2));

}

int mmc(int a, int b){
    int i, valorMmc;
    for(i=1; ;i++){
        valorMmc = a * i;
        if(valorMmc % b==0){
            return valorMmc;
        }
    }
}
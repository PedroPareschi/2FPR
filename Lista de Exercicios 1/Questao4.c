// QUESTÃO 04:
// Fazer uma função que calcule o MDC (máximo
// divisor comum) entre dois números.

//Inclusão de bibliotecas
#include <stdio.h>

//Declaração das funções
int mdc(int a, int b);

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
    printf("\n\nMDC entre %d e %d: %d", num1, num2, mdc(num1, num2));

}

//euclides
int mdc(int a, int b){
    if(a % b == 0){
        return b;
    }
    return mdc(b, (a % b));
}

// //maneira padrao
// int mdc(int num1, int num2){
//     int i;
//     for(i = num2; i > 0; i--){
//         if((num1%i == 0) && (num2%i == 0)){
//             return i;
//         }
//     }
// }
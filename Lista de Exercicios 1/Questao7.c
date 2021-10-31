// QUESTÃO 07:
// Implementar uma função que, dado um
// número inteiro n, e o intervalo definido pelos
// números a e b, determine quantos valores do
// intervalo possuem divisores (sendo estes
// diferentes de 1) que também sejam divisores
// de n.
// Exemplo:
// n = 6
// a = 10 e b = 20
// Resposta = 7 (pois os números 10, 12, 14,
// 15, 16, 18 e 20 possuem divisores em
// comum com o número 6).

//Inclusão de bibliotecas
#include <stdio.h>

//Declaração das funções
int possuiDivisoresEmComum(int n, int a, int b);
int mdc(int numMaior, int numMenor);

//Programa main
void main(){
    	
	//Declaração de variáveis
	int n, a, b;
	
	//Corpo do programa

	//Solicitação de variáveis
    printf("Digite o valor do algorismo: ");
    scanf("%d", &n);
    printf("Digite o inicio do intervalo: ");
    scanf("%d", &a);
    printf("Digite o final do intervalo: ");
    scanf("%d", &b);

    //chamando funcao
    printf("\nQuantidade de numeros no intervalo que possuem divisores em comum com %d: %d", n, possuiDivisoresEmComum(n, a, b));
	
}

//Função para descobrir a quantidade de numeros com divisores em comum no intervalo dado
int possuiDivisoresEmComum(int n, int a, int b){
    int cont = 0;
    for(int i = a; i <= b; i++){
        if(mdc(n, i) != 1){
            cont++;
        }
    }
    return cont;
}

//euclides para mdc
int mdc(int a, int b){
    if(a % b == 0){
        return b;
    }
    return mdc(b, (a % b));
}
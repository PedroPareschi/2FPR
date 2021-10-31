// QUESTÃO 02:
// Implementar uma função que converta
// determinada temperatura em graus Celsius
// para graus Fahrenheit.

// c/5 = (f-32) / 9
//f = (c*9/5) + 32

//Inclusão de bibliotecas
#include <stdio.h>

//Declaração das funções
float converter(float celsius);

//Programa main
void main(){
    	
	//Declaração de variáveis
	float celsius, fahrenheit;
	
	//Corpo do programa

	//Solicitação de variáveis
    printf("Digite a temperatura em celsius: ");
    scanf("%f", &celsius);

    //chamando funcao
    fahrenheit = converter(celsius);

    //exibindo resultado
    printf("Temperatura em fahrenheit: %.1f F", fahrenheit);
	
}

//Função para converter temp
float converter(float celsius){
    return (celsius * 9.0/5) + 32;
}
 




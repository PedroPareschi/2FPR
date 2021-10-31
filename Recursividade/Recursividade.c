
//Inclusão de bibliotecas
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define TRUE 1
#define TAM 50


//Declaração das funções
int multiplos(int n, int v);
int imprimirEmBinario(int n, int* binario);
void reverter(int *binario);
int exibirPg(int a1, int n, int q);
int ehPalindromo(char* s);
int ehPalindromoAux(char* string);
void removerEspacoToUpper(char* string, char* novaString);

//Programa main
void main(){

    //Declaração de variáveis
    int binario;
    char novaS[TAM];
    //Corpo do programa
    removerEspacoToUpper("Socorram ME SUBI NO ONIBUS EM MARROCOS", novaS);
    printf("%s\n", novaS);
    printf("%d", ehPalindromo(novaS));

    //Solicitação de variáveis
}


//Questão 02: Desenvolver uma função recursiva
//que exiba todos os múltiplos do número N,
//        inferiores ao valor V.

int multiplos(int n, int v) {
    if(v==n){
        printf("%d ", v);
        return n;
    }
    if(v % n == 0){
        printf("%d ", v);
        return multiplos(n, v - n);
    }
    return multiplos(n, v - 1);
}

//Questão 03: Fazer uma função recursiva que,
//dado um número inteiro N, exiba o mesmo na
//base 2 (binária).
int imprimirEmBinario(int n, int* binario){
    if(n < 2){
        *binario =(*binario * 10) + n;
        reverter(binario);
        printf("%d", *binario);
        return 1;
    }
    *binario = (*binario * 10) + (n % 2);
    return imprimirEmBinario(n/2, binario);
}

void reverter(int *num) {
    int numero = *num, reverso = 0, ultimoDigito;
    while(numero > 0){
        ultimoDigito = numero % 10;
        reverso = (reverso * 10) + ultimoDigito;
        numero /= 10;
    }
    *num = reverso;
}

//Questão 04: Pede-se a implementação de uma função recursiva que exiba os n primeiros
//termos de uma PG (Progressão Geométrica), onde a1 é o seu primeiro termo e q a razão.
//Observação: uma PG consiste em uma sequência de valores, iniciadas pelo valor a1. Os
//demais elementos são definidos como o anterior multiplicado pela razão.

int exibirPg(int a1, int n, int q){
    if(n < 1){
        return -1;
    }
    if(n == 1){
        printf("%d", a1);
        return a1;
    }
    int termo = a1 * q;
    printf("%d ", termo);
    return exibirPg(a1 * q, n - 1, q);
}

//Questão 05:
//Dada uma string s, desenvolver uma função
//recursiva que determine se s é ou não um
//palíndromo.

int ehPalindromo(char* s){
    char string[TAM];
    removerEspacoToUpper(s, string);
    return ehPalindromoAux(string);
}
int ehPalindromoAux(char* string){
    int tam = (int) strlen(string);//tamanho da string
    if(tam < 2){//se o tamanho for menor que dois
        return TRUE;
    }
    if(string[0] != string[tam - 1]){//se ocorrer alguma diferenca na letra
        return FALSE;
    }
    char newS[TAM];
    strncpy(newS, string + 1, tam - 2);//criando nova string sem a letra inicial e final
    newS[tam - 2] = '\0';//caractere especial
    return ehPalindromoAux(newS);
}

void removerEspacoToUpper(char* string, char* novaString){
    int i, j, tam = (int) strlen(string);
    strcpy(novaString, string);
    for(i = 0; i < tam; ) {
        if (' ' == novaString[i]) {
            for (j = i + 1; j <= tam; j++) {
                novaString[j - 1] = novaString[j];
            }
        } else {
            novaString[i] = (char) toupper(novaString[i]);
            i++;
        }
    }
}







#include <stdio.h>
#define TRUE 1
#define FALSE 0

//Declaração de funções
int tamanhoString(char* string);
void copiarString(char* stringDestino, char* stringOrigem);
void concatenarStrings(char* stringDestino, char* stringOrigem);
int compararStrings(char* s1, char* s2);
int ehPalindromo(char* string);
void substring(char* substring, char* s, int p, int n);
void removerCaracter(char* string, char caracter);


//Programa main
void main(){

    //Corpo do programa
	printf("%d", compararStrings("pedr1", "pedr0"));
}

//Questão 01:
//Suponha que não existissem as funções strlen,
//strcpy, strcat e strcmp. Pede-se, então, a
//implementação de funções que tenham o
//mesmo objetivo daquelas.

//strlen
int tamanhoString(char* string){
    int contador = 0;
    while(string[contador] != '\0'){
        contador++;//contando até o caractere especial
    }
    return contador;
}

//strcpy
void copiarString(char* stringDestino, char* stringOrigem){
    if(stringDestino[0] != '\0'){//se a string vazia não estiver nula, anula-la
        stringDestino[0] = '\0';
    }
    int i = 0;
    while(stringOrigem[i] != '\0'){
        stringDestino[i] = stringOrigem[i];
        i++;
    }
    stringDestino[i] = '\0';
}

//strcat
void concatenarStrings(char* stringDestino, char* stringOrigem){
    int i = tamanhoString(stringDestino);//i comeca do final da string original
    int j = 0;
    while (stringOrigem[j] != '\0'){
        stringDestino[i] = stringOrigem[j];
        i++;
        j++;
    }
    stringDestino[i] = '\0';
}

//strcmp
int compararStrings(char* s1, char* s2){
    int i;
    for(i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++){//enquanto nenhuma das strings chegarem ao final
    	
    }
    return s2[i] - s1[i];
}

//Questão 02:
//Dada uma string s, desenvolver uma função
//que determine se s é ou não um palíndromo.
//Observação: uma string s será um palíndromo
//quando seus caracteres formarem a mesma
//sequência, independente se s é percorrida da
//esquerda para direita ou vice-versa.
int ehPalindromo(char* string){
    int i = 0;
    int j = tamanhoString(string) - 1;//j começa do final da string
    while (j > i){//enquanto as variaveis nao chegam na metade
        if(string[i] != string[j]){//caso haja alguma diferenca
            return FALSE;
        }
        i++;
        j--;
    }
    return TRUE;
}

//Questão 03:
//Desenvolver uma função que, dada uma string
//s, crie uma substring que inicie na posição p de
//s e contenha n caracteres.
//Observações: se p e/ou n forem inválidos, a substring será vazia;
// ii) se s não possuir n caracteres além de p, a substring a ser criada começará em p e terminará no final de s.

void substring(char* substring, char* s, int p, int n){
    int tamanho = tamanhoString(s);
    if((p < 0) || (p > tamanho) || (n < 0)){//Observações: se p e/ou n forem inválidos, a substring será vazia;
        substring[0] = '\0';
    } else {
        int i = 0, j = p;
        while((i < n) && (s[j] != '\0')){//enquanto chega a n ou até o final da string original
            substring[i] = s[j];
            i++;
            j++;
        }
    }
}

//Questão 04:
//Implementar uma função que remova todas as
//ocorrências de determinado caracter em uma
//string.
void removerCaracter(char* string, char caracter){
    int i = 0, j;
    while (string[i] != '\0'){
        if(string[i] == caracter){
            j = i;
            //APAGANDO O CARACTERE
            while(string[j] != '\0'){
                string[j] = string[j+1];
                j++;
            }
            i--;//GARANTIDO QUE CARACTERES SEGUIDOS SEJAM APAGADOS
        }
        i++;
    }
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 50
#define TRUE 1
#define FALSE 0

int numCharComuns(char* s1, char* s2);
void removerCharactere(char* string, char charactere);
void removerCharacteresRepetidos(char* string, char* novaString);
int numCharComunsAux(char* s1, char* s2);
int pesquisa (char s1[], char s2[], int ordem);
int verificarIgualdade(char* s1, char* s2, int i);
void maiusculas(char* destino, char* resulado);
void exibirInvertida(char* string);
int exibirInvertidaAux(char* string, int fim);
int ehPAritmetica(int V[], int quant);
int ehPAritmeticaAux(int V[], int quant, int razao);
int removerChar(char* str, char ch);

int main() {
    char string[TAM] = "Saara";
    printf("%d\n", removerChar(string, 'a'));
    printf("%s", string);
}

//Questão 01:
//Desenvolver uma função recursiva que
//determine o número de caracteres comuns
//entre duas strings s1 e s2.

//função principal
int numCharComuns(char* s1, char* s2){
    char novaS1[TAM];
    removerCharacteresRepetidos(s1, novaS1);
    return numCharComunsAux(novaS1, s2);
}
//função recursiva
int numCharComunsAux(char* s1, char* s2){
    if(strlen(s1) == 0 || strlen(s2) == 0){
        return 0;//até uma das strings terem tamanho nulo
    }
    for(int i = 0; i < strlen(s2); i++){
        if(s1[0] == s2[i]){//caso haja um charactere em cum
            return 1 + numCharComunsAux(s1 + 1, s2);//recursivamente contar mais um e continuar
        }
    }
    return numCharComunsAux(s1 + 1, s2);//caso não continuar sem contar
}

//função auxiliar para remover caracteres repetidos da primeira string e evitar assim contabilizações desnecessárias
void removerCharacteresRepetidos(char* string, char* novaString){
    int i, j;
    strcpy(novaString, string);
    for(i = 0; i < strlen(novaString); i++){
        for(j = i + 1; j <= strlen(novaString); j++){
            if(novaString[i] == novaString[j]){//caso haja repetição de caractere remover
                removerCharactere(novaString + i + 1, novaString[i]);
            }
        }
    }
}

//funcao auxiliar para remover caracteres
void removerCharactere(char* string, char charactere){
    int i, j, tam = (int) strlen(string);
    for(i = 0; i < tam; ){
        if(charactere == string[i]){
            for(j = i + 1; j <= tam; j++){
                string[j-1] = string[j];
            }
        } else {
            i++;
        }
    }
}

//Questão 03:
//Considere a função cuja assinatura é
//apresentada a seguir:
//int pesquisa (char s1[], char s2[], int ordem)
//onde:

//s1 string contendo diversas informações
//sobre uma pessoa, separadas pelo
//caracter | (também termina com |)

//s2 uma informação a ser buscada em s1

//ordem ordem na qual s2 deve ser buscada
//em s1.
//Por exemplo, se for igual a 3,
//a função deve verificar se s2 é a
//terceira informação dentro de s1.

//Pede-se a implementação desta função,
//sabendo que ela deve retornar 1 se s2 estiver
//em s1 na posição definida por ordem; caso
//contrário, deve retornar 0.

//Função principal
int pesquisa (char s1[], char s2[], int ordem){
    if(ordem == 1){//se o dado for o primeiro, não precisa percorrer a lista
        return verificarIgualdade(s1, s2, 0);
    }
    int count = ordem - 1, i = 0;
    while(s1[i] != '\0'){//ate a lista acabar
        if(s1[i] == '|'){//caso ache o caractere especial
            count--;//conta até a achar a ordem
            if(count == 0){
                return verificarIgualdade(s1, s2, i + 1);
            }
        }
        i++;
    }
    return FALSE;//caso a ordem seja maior que a quantidade de dados disponivel
}

//Funcao auxiliar para remover o dado e verificar a igualdade
int verificarIgualdade(char* s1, char* s2, int i){
    char info[TAM];//string para reservar o dado
    int j = i, k = 0;
    while((s1[j] != '\0') && (s1[j] != '|')){//ate o fim da string ou ate chegar no char especial
        info[k] = s1[j];//copiando letra por letra
        j++;
        k++;
    }
    info[k] = '\0';
    char capsS2[TAM];
    maiusculas(info, info);
    maiusculas(s2, capsS2);
    if(strcmp(info, capsS2) == 0){//comparando as strings
        return TRUE;
    }
    return FALSE;//caso nao equivalem
}

//função basica para colocar os nomes em caps
void maiusculas(char* destino, char* resulado){
    int i;
    for(i = 0; i < strlen(destino); i++){
        resulado[i] = (char) toupper(destino[i]);
    }
}

//Questão 04:
//Desenvolver uma função recursiva que, dada
//uma string, exiba-a invertida.
void exibirInvertida(char* string){
    exibirInvertidaAux(string, (int) strlen(string));
}

int exibirInvertidaAux(char* string, int fim){
    if(fim <=  0){
        return TRUE;//parar a funcao qunado o tamanho dela chega igual a 0
    }
    printf("%c", string[fim-1]);//imprimir a ultima letra
    return exibirInvertidaAux(string, fim-1);
}

//Questão 05:
//Desenvolver uma função recursiva que, dado
//um vetor V com quant números inteiros,
//determine se seus elementos estão dispostos
//de maneira a representar uma progressão
//aritmética.
int ehPAritmetica(int V[], int quant){
    if(quant < 2){//se o vetor conter apenas um numerop, não é PA
        return FALSE;
    }
    int razao = V[1] - V[0];//a razão pode ser tirada dos dois primeiros numeros
    return ehPAritmeticaAux(V, quant, razao);
}

int ehPAritmeticaAux(int V[], int quant, int razao) {
    if(V[1] - V[0] != razao){//se os dois primeiros numeros nao valerem a razão
        return FALSE;
    }
    if(quant <= 2){//se a quantidade de numeros for menor ou igual a 2
        return TRUE;
    }
    return ehPAritmeticaAux(V + 1, quant - 1, razao);//continuar do proximo elemento do vetor
}

//Questão 06:
//Implementar uma função recursiva que,
//dados uma string str e um caracter ch,
//remova de str todas as ocorrências de ch,
//retornando o total de remoções realizadas.
int removerChar(char* str, char ch){
    if(strlen(str) < 1){
        return 0;
    }
    if(str[0] == ch){
        int i;
        for(i = 1; i < strlen(str); i++){
            str[i-1] = str[i];//copia o valor de um endereco para o outro
        }
        str[i-1] = '\0';
        return 1 + removerChar(str, ch);
    }
    return removerChar(str + 1, ch);//pula para o proximo endereco de memoria
}

// Questão 04:
// Desenvolver uma função que, dado um arquivo
// texto contendo números, determine se estes
// encontram-se ordenados crescentemente.
#include <stdio.h>
#define TRUE 1;
#define FALSE 0;

int ehCrescente(FILE* arquivo);

void main(){
    char titulo[] = "numeros.txt";
    FILE* arquivo;
    arquivo = fopen(titulo, "r");
    if (arquivo != NULL){
        printf("%d", ehCrescente(arquivo));
    } else {
        printf("Erro ao abrir arquivo");
    }
    fclose(arquivo);
}

int ehCrescente(FILE* arquivo){
    int i, ant = -9999;
    while(fscanf(arquivo, "%d", &i) != EOF){
        if(i < ant){
            return FALSE;
        }
        ant = i;
    }
    return TRUE;
}
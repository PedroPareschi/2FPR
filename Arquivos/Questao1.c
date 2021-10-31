// Questão 01:
// Desenvolver uma função que, dado um arquivo
// texto, verifique o número de caracteres no
// mesmo.

#include <stdio.h>

int quantidadeCaracteres(FILE *arquivo);

void main(){
    char titulo[] = "texto.txt";
    FILE* arquivo;
    arquivo = fopen(titulo, "r");
    if (arquivo != NULL){
        printf("%d", quantidadeCaracteres(arquivo));
    } else {
        printf("Erro ao abrir arquivo");
    }
    fclose(arquivo);
}

int quantidadeCaracteres(FILE *arquivo){
    char ch;
    int cont = 0;
    while(fscanf(arquivo, "%c", &ch) != EOF){
        cont++;
    }
    return cont;
}
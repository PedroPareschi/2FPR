// Questão 02:
// Desenvolver uma função que, dado um arquivo
// texto, verifique o número de vezes que um
// determinado caracter aparece no arquivo.

#include <stdio.h>

int contarCaractere(FILE *arquivo, char caractere);

void main(){
    char titulo[] = "texto.txt";
    FILE* arquivo;
    arquivo = fopen(titulo, "r");
    char caractere = 'b';
    if (arquivo != NULL){
        printf("%d", contarCaractere(arquivo, caractere));
    } else {
        printf("Erro ao abrir arquivo");
    }
    fclose(arquivo);
}

int contarCaractere(FILE *arquivo, char caractere){
    char ch;
    int cont = 0;
    while(fscanf(arquivo, "%c", &ch) != EOF){
        if(caractere==ch){
            cont++;
        }
    }
    return cont;
}
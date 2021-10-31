// Questão 03:
// Desenvolver uma função que, dado um arquivo
// texto, verifique o número de letras existentes
// no mesmo (entendendo que no arquivo podem
// existir letras, algarismos e símbolos).

#include <stdio.h>

int contarLetras(FILE *arquivo);

void main(){
    char titulo[] = "texto.txt";
    FILE* arquivo;
    arquivo = fopen(titulo, "r");
    if (arquivo != NULL){
        printf("%d", contarLetras(arquivo));
    } else {
        printf("Erro ao abrir arquivo");
    }
    fclose(arquivo);
}

int contarLetras(FILE *arquivo){
    char ch;
    int cont = 0;
    while(fscanf(arquivo, "%c", &ch) != EOF){
        if((ch >= 'a' && ch <= 'z') || (ch>='A' && ch<='Z')){
            cont++;
        }
    }
    return cont;
}
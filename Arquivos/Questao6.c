// Questão 06:
// Desenvolver uma função que, dados dois
// arquivos textos arqA e arqB, crie um novo
// arquivo arqC, considerando que:
//  arqA e arqB contém números reais,
// um por linha, ordenados
// crescentemente e sem repetição no
// arquivo;
//  arqC deve conter todos os números
// dos dois arquivos originais;
//  Assim como arqA e arqB, arqC
// também não possuirá repetições de
// elementos e estes deverão estar
// ordenados de forma crescente.

#include <stdio.h>

void juntarArquivos(FILE* arqA, FILE* arqB, FILE* arqC);

void main(){
    FILE* arqA;
    FILE* arqB;
    FILE* arqC;
    arqA = fopen("arqA.txt", "r");
    arqB = fopen("arqB.txt", "r");
    arqC = fopen("arqC.txt", "w");

    if (arqA != NULL && arqB != NULL && arqC != NULL){
        juntarArquivos(arqA, arqB, arqC);
    } else {
        printf("Erro ao abrir arquivo");
    }
    fclose(arqA);
    fclose(arqB);
    fclose(arqC);
}

void juntarArquivos(FILE* arqA, FILE* arqB, FILE* arqC){
    float numA, numB, verA, verB;
    verA = fscanf(arqA, "%f", &numA);
    verB = fscanf(arqB, "%f", &numB);
    while(verA != EOF|| verB != EOF){
        if((numA < numB && verA != EOF)|| verB == EOF){
            fprintf(arqC, "%.1f ", numA);
            verA = fscanf(arqA, "%f", &numA);
        } else if((numB < numA && verB != EOF) || verA == EOF){
            fprintf(arqC,"%.1f ", numB);
            verB = fscanf(arqB, "%f", &numB);
        } else {
            fprintf(arqC,"%.1f ", numB);
            verA = fscanf(arqA, "%f", &numA);
            verB = fscanf(arqB, "%f", &numB);
        }
    }
}
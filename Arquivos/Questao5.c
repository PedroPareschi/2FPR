// Questão 05:
// Faça uma função que, dado um arquivo A
// contendo números reais, um por linha, crie um
// novo arquivo B contendo os mesmos
// elementos de A, porém ordenados
// decrescentemente e sem repetição.

#include <stdio.h>
#include <float.h>

void juntarArquivos(FILE* arquivoA, FILE* arquivoB);

void main(){
    FILE* arquivoA;
    FILE* arquivoB;
    arquivoA = fopen("arquivoA.txt", "r");
    arquivoB = fopen("arquivoB.txt", "w");
    if (arquivoA != NULL && arquivoB != NULL){
        juntarArquivos(arquivoA, arquivoB);
    } else {
        printf("Erro ao abrir arquivo");
    }
    fclose(arquivoA);
    fclose(arquivoB);

}

void juntarArquivos(FILE* arquivoA, FILE* arquivoB){
    int i = 0;
    float num;
    float maior, maiorAnt;

    maiorAnt = FLT_MAX;
    while(maior != FLT_MIN){
        maior = FLT_MIN;
        while (fscanf(arquivoA, "%f", &num) != EOF){
            if(num > maior && num < maiorAnt){
                maior = num;
            }
        }
        fprintf(arquivoB, "%f ", maior);
        maiorAnt = maior;
        rewind (arquivoA);
    } 
}
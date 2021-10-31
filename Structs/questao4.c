// Questão 04:
// Suponha a existência de um vetor de tamanho
// TAM, cada posição armazenando o nome da
// pessoa e a sua data de aniversário
// (representada por um struct do tipo TData,
// contendo os campos dia e mes). Pede-se o
// desenvolvimento das seguintes funções:


#include <stdio.h>
#define TAM 5
#define MAX 25

typedef struct 
{
    int dia;
    int mes;

}TData;


typedef struct 
{
    char* nome;
    TData aniversario;

}TPessoa;

//  Determinar a quantidade de pessoas que
// fazem aniversário no mês M;
//  Exibir os nomes de todas pessoas que fazem
// aniversário entre as datas d1 e d2, ambas
// do tipo Tdata.

int aniversariosDoMes(int mes, TPessoa* pessoas);
void aniversariosDoIntervalo(TData d1, TData d2, TPessoa* pessoas);

void main(){

    TPessoa pessoas[TAM];

    pessoas[0].nome = "Peter";
    pessoas[0].aniversario.dia = 15;
    pessoas[0].aniversario.mes = 6;
    pessoas[1].nome = "Amanda";
    pessoas[1].aniversario.dia = 21;
    pessoas[1].aniversario.mes = 6;
    pessoas[2].nome = "Lucas";
    pessoas[2].aniversario.dia = 6;
    pessoas[2].aniversario.mes = 2;
    pessoas[3].nome = "Daniel";
    pessoas[3].aniversario.dia = 10;
    pessoas[3].aniversario.mes = 4;
    pessoas[4].nome = "Kate";
    pessoas[4].aniversario.dia = 24;
    pessoas[4].aniversario.mes = 2;

    printf("%d pessoas fazem aniversarios no mes %d\n", aniversariosDoMes(6, pessoas), 6);
    TData d1;
    d1.dia = 6;
    d1.mes = 2;

    TData d2;
    d2.dia = 24;
    d2.mes = 2;

    aniversariosDoIntervalo(d1, d2, pessoas);
}

int aniversariosDoMes(int mes, TPessoa* pessoas){
    int i, cont = 0;
    for(i = 0; i < TAM; i++){
        if(pessoas[i].aniversario.mes == mes){
            cont++;
        }
    }
    return cont;
}

void aniversariosDoIntervalo(TData d1, TData d2, TPessoa* pessoas){
    int i;

    printf("Aniversarios do intervaldo %d/%d - %d/%d\n", d1.dia, d1.mes, d2.dia, d2.mes);

    for(i = 0; i < TAM; i++){
        if(pessoas[i].aniversario.mes >= d1.mes && pessoas[i].aniversario.mes <= d2.mes){
            if(pessoas[i].aniversario.mes == d1.mes){
                if(pessoas[i].aniversario.dia >= d1.dia){
                    printf("%s\n", pessoas[i].nome);
                }
            } else if(pessoas[i].aniversario.mes == d2.mes){
                if(pessoas[i].aniversario.dia <= d2.dia){
                    printf("%s\n", pessoas[i].nome);
                }
            } else {
                printf("%s\n", pessoas[i].nome);
            }
        }
    }
}
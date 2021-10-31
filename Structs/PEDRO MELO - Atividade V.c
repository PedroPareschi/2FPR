#include <stdio.h>
#define MAX 6


typedef struct 
{
    int codigo_disciplina;
    int semestre;
    int ano;
    float mediaFinal;
}TRendimento;


typedef struct 
{
    int codigo;
    char* nome;
    int numeroCreditos;
}TDisciplina;

void imprimirHistorico(TRendimento* historico, TDisciplina* disciplinas);

void main(){
    TDisciplina disciplinas[MAX];
    TRendimento historico[MAX];
    disciplinas[0].codigo = 0;
    disciplinas[0].nome = "FAC";
    disciplinas[0].numeroCreditos = 4;
    disciplinas[1].codigo = 1;
    disciplinas[1].nome = "IAS";
    disciplinas[1].numeroCreditos = 4;
    disciplinas[2].codigo = 2;
    disciplinas[2].nome = "IHM";
    disciplinas[2].numeroCreditos = 2;
    disciplinas[3].codigo = 3;
    disciplinas[3].nome = "LPO";
    disciplinas[3].numeroCreditos = 4;
    disciplinas[4].codigo = 4;
    disciplinas[4].nome = "MAC";
    disciplinas[4].numeroCreditos = 4;
    disciplinas[5].codigo = 5;
    disciplinas[5].nome = "ORG";
    disciplinas[5].numeroCreditos = 4;

    historico[0].codigo_disciplina = 0;
    historico[0].mediaFinal = 9.5;
    historico[0].semestre = 1;
    historico[0].ano = 2020;
    historico[1].codigo_disciplina = 1;
    historico[1].mediaFinal = 7.8;
    historico[1].semestre = 1;
    historico[1].ano = 2020;
    historico[2].codigo_disciplina = 2;
    historico[2].mediaFinal = 9.3;
    historico[2].semestre = 1;
    historico[2].ano = 2020;
    historico[3].codigo_disciplina = 3;
    historico[3].mediaFinal = 9.3;
    historico[3].semestre = 1;
    historico[3].ano = 2020;
    historico[4].codigo_disciplina = 4;
    historico[4].mediaFinal = 9.2;
    historico[4].semestre = 1;
    historico[4].ano = 2020;
    historico[5].codigo_disciplina = 5;
    historico[5].mediaFinal = 8.0;
    historico[5].semestre = 1;
    historico[5].ano = 2020;

    imprimirHistorico(historico, disciplinas);
}


void imprimirHistorico(TRendimento* historico, TDisciplina* disciplinas){
    int i, j;
    float cr, somatorio = 0, pesos;
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            if(historico[i].codigo_disciplina == disciplinas[j].codigo){
                printf("%s (%d): %.1f\n", disciplinas[j].nome, historico[i].codigo_disciplina, historico[i].mediaFinal);
                somatorio += historico[i].mediaFinal * disciplinas[j].numeroCreditos;
                pesos += disciplinas[j].numeroCreditos;
                break;
            }
        }
    }
    cr = somatorio / pesos;
    printf("Coeficiente de rendimenro: %.1f", cr);
}


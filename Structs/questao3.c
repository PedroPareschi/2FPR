// Questão 03:
// Determinada instituição de ensino armazena,
// sob a forma de vetores (de structs), as
// seguintes informações:
//  Alunos: nome, matrícula;
//  Disciplinas do curso: nome, código;
//  Inscrições realizadas: matrícula do aluno,
// código da disciplina, semestre da inscrição
// (semestre/ano).
// Pede-se o desenvolvimento de funções que
// realizem as seguintes operações:


#include <stdio.h>
#define ALUNOS 3
#define DISCIPLINAS 4
#define INSCRICOES 8

typedef struct 
{
    char* nome;
    int matricula;
}Aluno;

typedef struct 
{
    char* nome;
    int codigo;
}Disciplina;

typedef struct 
{
    int semestre;
    int ano;
}Periodo;

typedef struct 
{
    int matricula_aluno;
    int codigo_disciplina;
    Periodo periodo;
}Inscricao;

//i. Exibir, para cada aluno, o total de inscrições
// já realizadas;


void imprimirInscricoesPorAluno(Aluno* alunos, Inscricao* inscricoes);
void imprimirNumeroDeInscricoesPorDisciplinaEmUmSemestre(Periodo periodo, Inscricao* inscricoes, Disciplina* disciplinas);

void main(){
    Aluno alunos[ALUNOS];
    alunos[0].nome = "Pedro";
    alunos[0].matricula = 123;
    alunos[1].nome = "Lucas";
    alunos[1].matricula = 456;
    alunos[2].nome = "Daniel";
    alunos[2].matricula = 789;
    

    Disciplina disciplinas[DISCIPLINAS];
    disciplinas[0].codigo = 0;
    disciplinas[0].nome = "Matematica";
    disciplinas[1].codigo = 1;
    disciplinas[1].nome = "Portugues";
    disciplinas[2].codigo = 2;
    disciplinas[2].nome = "Fisica";
    disciplinas[3].codigo = 3;
    disciplinas[3].nome = "Historia";

    Inscricao inscricoes[INSCRICOES];
    inscricoes[0].matricula_aluno = 123;
    inscricoes[0].codigo_disciplina = 0;
    inscricoes[0].periodo.semestre = 1;
    inscricoes[0].periodo.ano = 2021;
    inscricoes[1].matricula_aluno = 123;
    inscricoes[1].codigo_disciplina = 1;
    inscricoes[1].periodo.semestre = 2;
    inscricoes[1].periodo.ano = 2021;
    inscricoes[2].matricula_aluno = 123;
    inscricoes[2].codigo_disciplina = 2;
    inscricoes[2].periodo.semestre = 1;
    inscricoes[2].periodo.ano = 2021;
    inscricoes[3].matricula_aluno = 123;
    inscricoes[3].codigo_disciplina = 3;
    inscricoes[3].periodo.semestre = 1;
    inscricoes[3].periodo.ano = 2021;
    inscricoes[4].matricula_aluno = 456;
    inscricoes[4].codigo_disciplina = 0;
    inscricoes[4].periodo.semestre = 1;
    inscricoes[4].periodo.ano = 2021;
    inscricoes[5].matricula_aluno = 456;
    inscricoes[5].codigo_disciplina = 1;
    inscricoes[5].periodo.semestre = 2;
    inscricoes[5].periodo.ano = 2021;
    inscricoes[6].matricula_aluno = 456;
    inscricoes[6].codigo_disciplina = 2;
    inscricoes[6].periodo.semestre = 2;
    inscricoes[6].periodo.ano = 2021;
    inscricoes[7].matricula_aluno = 789;
    inscricoes[7].codigo_disciplina = 0;
    inscricoes[7].periodo.semestre = 1;
    inscricoes[7].periodo.ano = 2021;

    imprimirInscricoesPorAluno(alunos, inscricoes);
    Periodo periodo1;
    periodo1.semestre = 1;
    periodo1.ano = 2021;

    Periodo periodo2;
    periodo2.semestre = 2;
    periodo2.ano = 2021;
    printf("\n--------------------------------------------------\n");
    imprimirNumeroDeInscricoesPorDisciplinaEmUmSemestre(periodo1, inscricoes, disciplinas);
    printf("\n--------------------------------------------------\n");
    imprimirNumeroDeInscricoesPorDisciplinaEmUmSemestre(periodo2, inscricoes, disciplinas);

}


void imprimirInscricoesPorAluno(Aluno* alunos, Inscricao* inscricoes){
    int i, j;
    for(i = 0; i < ALUNOS; i++){
        printf("\n%s:\n", alunos[i].nome);
        for(j = 0; j < INSCRICOES; j++){
            if(inscricoes[j].matricula_aluno == alunos[i].matricula){
                printf("%d : %d/%d\n", inscricoes[j].codigo_disciplina, inscricoes[j].periodo.semestre, inscricoes[j].periodo.ano);
            }
        }
    }
}

// ii. Dado um semestre, informar para cada
// disciplina o número de alunos inscritos.

void imprimirNumeroDeInscricoesPorDisciplinaEmUmSemestre(Periodo periodo, Inscricao* inscricoes, Disciplina* disciplinas){
    int i, j;
    int contDisciplinas[DISCIPLINAS];

    for(i = 0; i < DISCIPLINAS; i++){
        contDisciplinas[i] = 0;
    }

    for(i = 0; i < INSCRICOES; i++){
        if(inscricoes[i].periodo.semestre == periodo.semestre && inscricoes[i].periodo.ano == periodo.ano){
            for(j = 0; j < DISCIPLINAS; j++){
                if(inscricoes[i].codigo_disciplina == disciplinas[j].codigo){
                    contDisciplinas[j]++;
                }
            }
        }
    }

    for(i = 0; i < DISCIPLINAS; i++){
        printf("%s: %d aluno(s)\n", disciplinas[i].nome, contDisciplinas[i]);
    }
}


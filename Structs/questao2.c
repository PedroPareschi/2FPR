//Questão 02:
//Determinada zona eleitoral possui N eleitores
//inscritos que poderão votar, uma única vez, em
//um dos C candidatos para o único cargo a ser
//definido. Pede-se:
//a. A declaração de todo(s) o(s) tipo(s) de
//        dados necessário(s) para o armazenamento
//        dos números dos candidatos, assim como a
//        quantidade de votos brancos, nulos e votos
//        para cada candidato;
//b. Uma função que leia o voto de cada eleitor,
//considerando que o processo terminará
//        quando os N eleitores votarem ou quando o
//        número -1 for digitado como voto;
//c. Uma função que exiba:
//i. O total de votos para cada candidato,
//assim com a quantidade de votos
//brancos (código 0) e de nulos (código
//sem candidato associado);
//ii. A quantidade de abstenções (eleitores
//                                que não votaram);
//iii. O número do candidato vencedor (caso
//                                     tenha mais de 50% dos votos válidos) ou
//
//        dos que irão para o segundo turno (os
//                                           dois mais votados).
//Notas:
//a) o número do candidato deve conter dois
//algarismos apenas;
//b) podem considerar que não haverá mais de
//        um candidato com a mesma quantidade de
//votos.

#include <stdio.h>


typedef struct 
{
    int numero;
    int votos;
}TCandidato;

void lerCandidatos(TCandidato* candidatos, int C);
int numeroJaExiste(int numero, TCandidato* candidatos, int posAtual);
void contagemVotos(TCandidato* candidatos, int C, int N, int* brancos, int* nulos, int* abstencoes);
void imprimirResultados(TCandidato* candidatos, int C, int brancos, int nulos, int abstencoes);

void main(){
    int brancos, nulos, abstencoes, C = 4, N = 10;
    TCandidato candidatos[4];
    lerCandidatos(candidatos, C);
    contagemVotos(candidatos, C, N, &brancos, &nulos, &abstencoes);
    imprimirResultados(candidatos, C, brancos, nulos, abstencoes);
}

void lerCandidatos(TCandidato* candidatos, int C){
    int i, numero;
    for(i = 0; i < C; i++){
        do{
            printf("Digite o numero do candidato (%d): ", i+1);
            scanf("%d", &numero);
            if(numero < 1 || numero > 99 || numeroJaExiste(numero, candidatos, i)){
                printf("Numero invalido\n");
            }
        }while(numero < 1 || numero > 99 || numeroJaExiste(numero, candidatos, i));
        candidatos[i].numero = numero;
        candidatos[i].votos = 0;
    }
}

int numeroJaExiste(int numero, TCandidato* candidatos, int posAtual){
    int i;
    for(i = 0; i < posAtual; i++){
        if(candidatos[i].numero == numero){
            return 1;
        }
    }
    return 0;
}

void contagemVotos(TCandidato* candidatos, int C, int N, int* brancos, int* nulos, int* abstencoes){
    int i, j, voto;
    *brancos = 0;
    *nulos = 0;
    for(i = 0; i < N; i++){
        printf("Vote: ");
        scanf("%d", &voto);
        if(voto == 0){
            (*brancos)++;
        } else if(voto == -1){
            *abstencoes = N - i;
            break;
        } else if(voto < 1 || voto > 99 ){
            (*nulos)++;
        } else {
            for(j = 0; j < C; j++){
                if(candidatos[j].numero == voto){
                    candidatos[j].votos++;
                    break;
                }
            }
            if(j == C){
                (*nulos)++;
            }
        }
    }
}

void imprimirResultados(TCandidato* candidatos, int C, int brancos, int nulos, int abstencoes){
    int i, totalVotos = 0;

    TCandidato maior;
    maior.numero = -1;
    maior.votos = -1;

    TCandidato segundoMaior;
    segundoMaior.numero = -1;
    segundoMaior.votos = -1;

    for(i = 0; i < C; i++){
        printf("Candidato: %d\n", candidatos[i].numero);
        printf("Voto(s): %d\n\n", candidatos[i].votos);
        totalVotos += candidatos[i].votos;

        if(candidatos[i].votos > maior.votos){
            maior.votos = candidatos[i].votos;
            maior.numero = candidatos[i].numero;
        } else if(candidatos[i].votos > segundoMaior.votos){
            segundoMaior.votos = candidatos[i].votos;
            segundoMaior.numero = candidatos[i].numero;
        }
    }
    printf("Votos validos: %d\n\n", totalVotos);
    printf("Brancos: %d\n\n", brancos);
    printf("Nulos: %d\n\n", nulos);
    printf("Abstencoes: %d\n\n", abstencoes);

    if((float) maior.votos / totalVotos > 0.5){
        printf("Candidato %d venceu o primeiro turno com %.2f%% dos votos validos", maior.numero, ((float)maior.votos / totalVotos) * 100);
    } else {
        printf("Os candidatos %d e %d vao para o segundo turno", maior.numero, segundoMaior.numero);
    }
}
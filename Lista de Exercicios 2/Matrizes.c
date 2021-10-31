//Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Definição de tamanho
#define LIN 12
#define COL 10

//Definição de verdadeiro ou falso
#define TRUE 1
#define FALSE 0

//Definições das funções
void lerMatriz(int matriz[LIN][COL], int *linha, int *coluna);
void imprimirMatriz(int matriz[LIN][COL], int linha, int coluna);
void gerarMatrizAleatoria(int matriz[LIN][COL], int linha, int coluna);
void gerarMatrizTransposta(float matriz[LIN][COL], float transposta[COL][LIN]);
int numeroEstaNaLinha(int matriz[15][20], int x, int L);
void gerarMatriz(int matriz[5][5]);
int ehSimetrica(int matriz[6][6]);
void somaColunas(int matriz[10][8], int vetor[]);
void zerarVetor(int vetor[], int tamanho);
float calcularTotalVendido(float vendasPorFuncMensal[12][10]);
float calcularVendasNoMes(float vendasPorFuncMensal[12][10], int mes);
float calcularVendasDoFunc(float vendasPorFuncMensal[12][10], int funcionario);
int getMesComMaisVendas(float vendasPorFuncMensal[12][10]);
int getFuncComMenosVendas(float vendasPorFuncMensal[12][10]);
void gerarVendasAleatorias(float vendasPorFuncMensal[12][10]);



//Programa main
void main(){

	//Declaração de variáveis
    float vendasPorFuncMensal[LIN][COL];

	//Corpo do programa

	//Solicitação de variáveis
    gerarVendasAleatorias(vendasPorFuncMensal);
    imprimirMatrizFloat(vendasPorFuncMensal, LIN, COL);
    printf("Vendas totais no ano = RS %.2f", calcularTotalVendido(vendasPorFuncMensal));
    printf("\n================================\n");
    printf("Vendas no mes de dezembro = RS %.2f", calcularVendasNoMes(vendasPorFuncMensal, 11));
    printf("\n================================\n");
    printf("Vendas do funcionario 0 = RS %.2f", calcularVendasDoFunc(vendasPorFuncMensal, 0));
    printf("\n================================\n");
    printf("Mes com mais vendas = %d", getMesComMaisVendas(vendasPorFuncMensal));
    printf("\n================================\n");
    printf("Funcionario com menos venda= %d", getFuncComMenosVendas(vendasPorFuncMensal));
    
}

//***********************************FUNCOES DE AUXILIO*****************************************************************************

//Função para ler matriz
void lerMatriz(int matriz[LIN][COL], int *linha, int *coluna){
    //declaracao de variaveis
    int i, j;
    //corpo da função

    do{//solicitando tamanho da matriz
        printf("Digite a quantidade de linhas: ");
        scanf("%d", linha);
        if((*linha < 0) || (*linha > LIN)){
            printf("\nErro, matriz com numero de linhas invalido. Deve ser igual ou inferior ao tamanho maximo e nao negativo\n");
        }
    }while((*linha < 0) || (*linha > LIN));//caso o tamanho seja invalido

    do{//solicitando tamanho da matriz
        printf("Digite a quantidade de colunas: ");
        scanf("%d", coluna);
        if((*coluna < 0) || (*coluna > COL)){
            printf("\nErro, matriz com numero de colunas invalido. Deve ser igual ou inferior ao tamanho maximo e nao negativo\n");
        }
    }while((*coluna < 0) || (*coluna > COL));//caso o tamanho seja invalido

    for(i = 0; i < *linha; i++){
        for(j = 0; j < *coluna; j++){
            printf("Digite o valor [%d][%d] da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}


//Função para imprimir matriz
void imprimirMatriz(int matriz[LIN][COL], int linha, int coluna){
    int i, j;//declaração de variaveis
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("%d ", matriz[i][j]);//imprimindo cada elemento do matriz
        }
        printf("\n");//espaco a mais no final da matriz
    }
}

//Função para imprimir matriz de float
void imprimirMatrizFloat(float matriz[LIN][COL], int linha, int coluna){
    int i, j;//declaração de variaveis
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("%.2f ", matriz[i][j]);//imprimindo cada elemento do matriz
        }
        printf("\n");//espaco a mais no final da matriz
    }
}


//Funcao para gerar matriz aleatoria com tamanho definido pelo usuario
void gerarMatrizAleatoria(int matriz[LIN][COL], int linha, int coluna){
    srand(time(NULL));
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            matriz[i][j] = rand()%2;
        }
    }
}

//Função para imprimir vetor
void imprimirVetor(int vetor[], int tamanho){
    printf("[");
    int i;//declaração de variaveis
    for(i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);//imprimindo cada elemento do vetor
    }
    printf("]\n");//espaco a mais no final do vetor
}
//***********************************QUESTOES*****************************************************************************

// QUESTÃO 01:
// Faça um função que, dada uma matriz M8×5 de
// reais, gere a matriz Mt, sua transposta.

void gerarMatrizTransposta(float matriz[LIN][COL], float transposta[COL][LIN]){
    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 5; j++){
            transposta[j][i] = matriz[i][j];
        }
    }
}

// QUESTÃO 02:
// Desenvolver uma função que, dada uma matriz
// M15×20, determine se um número X se encontra
// na linha L da matriz.

int numeroEstaNaLinha(int matriz[15][20], int x, int L){
    if((L < 0) || (L > 14)){//se a linha nao estiver entre os limites da matriz
        printf("Valor de linha invalido: matriz L tem 15 linhas");
        return -1;
    }
    int j;
    for(j = 0; j < 20; j++){
        if(matriz[L][j] == x){
            printf("%d se encontra na coluna %d da linha %d", x, j, L);
            return j;
        }
    }
    printf("%d nao se encontra na linha %d", x, L);
    return -1;
}

// QUESTÃO 03:
// Desenvolver uma função que gere a seguinte
// matriz M5x5:
// 1 2 3 4 5
// 2 3 4 5 6
// 3 4 5 6 7
// 4 5 6 7 8
// 5 6 7 8 9
void gerarMatriz(int matriz[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            matriz[i][j] = i + j + 1;//cada elemento da matriz é a soma de sua linha e coluna acrescido de 1
        }
    }
}

// QUESTÃO 04:
// Fazer uma função que, dada uma matriz M6×6,
// determine se ela é simétrica.
int ehSimetrica(int matriz[6][6]){
    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 6; j++){
            if(matriz[i][j] != matriz[j][i]){//se houver alguma diferenca, nao eh simetrica
                printf("A matriz nao eh simetrica");
                return FALSE;
            }
        }
    }
    printf("A matriz eh simetrica");
    return TRUE;
}

// QUESTÃO 05:
// Implementar uma função que, dada uma matriz
// M10×8, gere um vetor V de tamanho 8, onde
// cada elemento do vetor consiste na soma dos
// elementos de uma coluna de M. Ou seja, o
// elemento V[1] consiste na soma dos elementos
// da primeira coluna de M, o elemento V[2]
// consiste na soma dos elementos da segunda
// coluna de M, e assim por diante.

void somaColunas(int matriz[10][8], int vetor[]){
    zerarVetor(vetor, 8);//zerando vetor 
    int i, j;
    for(j = 0; j < 8; j++){//para cada coluna
        for(i = 0; i < 10; i++){//somar as linhas
            vetor[j] += matriz[i][j];
        }
    }
}

//Função para zerar vetor
void zerarVetor(int vetor[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        vetor[i] = 0;
    }
}

// QUESTÃO 06:
// Considere uma loja que mantém em uma
// matriz o total vendido por cada funcionário
// pelos diversos meses do ano. Ou seja, uma
// matriz de 12 linhas (uma por mês) e 10 colunas
// (10 funcionários). Pede-se o desenvolvimento
// de uma função para cada item abaixo:

// a. Calcular o total vendido durante o ano;
float calcularTotalVendido(float vendasPorFuncMensal[12][10]){
    float soma = 0;
    int i, j;
    for(i = 0; i < 12; i++){
        for(j=0; j < 10; j++){
            soma += vendasPorFuncMensal[i][j];
        }
    }
    return soma;
}

// b. Dado um mês fornecido pelo usuário,
// determinar o total vendido nesse mês;
float calcularVendasNoMes(float vendasPorFuncMensal[12][10], int mes){
    if(mes < 0 || mes > 11){//testando para evitar erros
        printf("Mes invalido");
        return -1.0;
    }
    int j;
    float soma = 0;
    for(j = 0; j < 10; j++){
        soma += vendasPorFuncMensal[mes][j];
    }
    return soma;
}

// c. Dado um funcionário fornecido pelo
// usuário, determinar o total vendido por ele
// durante o ano;
float calcularVendasDoFunc(float vendasPorFuncMensal[12][10], int funcionario){
    if(funcionario < 0 || funcionario > 9){//testando para evitar erros
        printf("Funcionario invalido");
        return -1.0;
    }
    int i;
    float soma = 0;
    for(i = 0; i < 12; i++){
        soma += vendasPorFuncMensal[i][funcionario];
    }
    return soma;
}

// d. Determinar o mês com maior índice de
// vendas;
int getMesComMaisVendas(float vendasPorFuncMensal[12][10]){
    //Definição de variáveis
    int mesComMaisVendas = 0,//iniciando com primeiro mes
    i;
    float maisVendas = calcularVendasNoMes(vendasPorFuncMensal, mesComMaisVendas),//calculando as vendas do primeiro mes
    vendas;//variavel de vendas por mes

    //Corpo da função
    for(i = 1; i < 12; i++){
        vendas = calcularVendasNoMes(vendasPorFuncMensal, i);//calculando a venda do mes i
        if(vendas > maisVendas){//comparando com as vendas maximas
            maisVendas = vendas;//atribuindo
            mesComMaisVendas = i;
        }
    }
    return mesComMaisVendas;//retornando resultado
}

// e. Determinar o funcionário que menos
// vendeu durante o ano.
int getFuncComMenosVendas(float vendasPorFuncMensal[12][10]){

    //Definição de variáveis
    int funcComMenosVendas = 0,//iniciando com primeiro funcionario
    j;
    float menosVendas = calcularVendasDoFunc(vendasPorFuncMensal, funcComMenosVendas),//calculando as vendas do primeiro funcionario
    vendas;//variavel de vendas por funcionario

    //Corpo da função
    for(j = 1; j < 10; j++){
        vendas = calcularVendasDoFunc(vendasPorFuncMensal, j);//calculando a venda do mes i
        if(vendas < menosVendas){//comparando com as vendas minimas
            menosVendas = vendas;//atribuindo
            funcComMenosVendas = j;
        }
    }
    return funcComMenosVendas;//retornando resultado
}

//Funcao para gerar vendas mensais aleatorias para fins de teste
void gerarVendasAleatorias(float vendasPorFuncMensal[12][10]){
    float aleatorio;
    srand(time(NULL));
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 10; j++){
            //tecnica para gerar floats aleatorios com duas casas decimais até mil
             aleatorio = (float)rand()/(RAND_MAX/1001.0);
             vendasPorFuncMensal[i][j] = floorf(aleatorio * 100) / 100;
        }
    }
}
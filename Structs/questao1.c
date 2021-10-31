#include <stdio.h>
#include <string.h>

#define MAX 5
#define TAM 25


//Questão 01:
//Uma loja de automóveis mantém os carros à
//venda sob a forma de um vetor de structs
//contendo as seguintes informações, para cada
//veículo: placa, modelo, marca, cor,
//quilometragem, ano modelo/fabricação (deve
//ser um struct), valor e tipo (usado ou 0 km,
//conforme o valor do campo quilometragem).
//Pede-se a declaração de uma variável que
// represente o estoque de veículos da loja,
// incluindo todas as declarações de tipos que
//possam ser necessárias.


typedef struct {
    int modelo;
    int fabricacao;
}TAno;


typedef struct {
    char placa[TAM];
    char modelo[TAM];
    char marca[TAM];
    char cor[TAM];
    float quilometragem;
    TAno ano;
    float valor;
    char tipo[TAM];
}TCarro;

void lerEstoque(TCarro estoque[MAX], int tam);
void imprimirCarro(TCarro carro);
void imprimirEstoque(TCarro estoque[MAX], int tam);
void filtrar(TCarro estoque[MAX], int tam, char* m, int a1, int a2, float x);
void reajustarValor(TCarro* estoque, int tam);
int retirar(TCarro* estoque, int tam, char* placa);


void main() {
    TCarro estoque[MAX];
    lerEstoque(estoque, 3);
    retirar(estoque, 3, "abc123");
    imprimirEstoque(estoque, 2);
}

void lerEstoque(TCarro estoque[MAX], int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("%d\n", i+1);
        printf("Placa: ");
        setbuf(stdin, NULL);
        gets(estoque[i].placa);
        setbuf(stdin, NULL);
        printf("Modelo: ");
        gets(estoque[i].modelo);
        setbuf(stdin, NULL);
        printf("Marca: ");
        gets(estoque[i].marca);
        setbuf(stdin, NULL);
        printf("Cor: ");
        gets(estoque[i].cor);
        setbuf(stdin, NULL);
        printf("Quilometragem: ");
        scanf("%f", &estoque[i].quilometragem);
        if(estoque[i].quilometragem > 0){
            strcpy(estoque[i].tipo, "Usado");
        } else {
            strcpy(estoque[i].tipo, "0 km");
        }
        printf("Ano do modelo: ");
        scanf("%d", &estoque[i].ano.modelo);
        printf("Ano de fabricacao: ");
        scanf("%d", &estoque[i].ano.fabricacao);
        printf("Valor: ");
        scanf("%f", &estoque[i].valor);
    }
}

void imprimirCarro(TCarro carro){
    printf("\tPlaca: %s\n", carro.placa);
    printf("\tModelo: %s\n", carro.modelo);
    printf("\tMarca: %s\n", carro.marca);
    printf("\tCor: %s\n", carro.cor);
    printf("\tQuilometragem: %f\n", carro.quilometragem);
    printf("\tAno de modelo: %d\n", carro.ano.modelo);
    printf("\tAno de fabricao: %d\n", carro.ano.fabricacao);
    printf("\tValor: RS %.2f\n", carro.valor);
    printf("\tTipo: %s\n", carro.tipo);
}

void imprimirEstoque(TCarro estoque[MAX], int tam){
    int i;
    for(i = 0; i < tam; i++){
        printf("Carro %d:\n", i + 1);
        imprimirCarro(estoque[i]);
    }
}

//Além disso, implementar as seguintes funções:
//i. Exibir todos os carros do modelo m, ano de
//fabricação entre a1 e a2 (inclusive), com
//valor não superior a x reais;
void filtrar(TCarro estoque[MAX], int tam, char* m, int a1, int a2, float x){
    int i;
    for(i = 0; i < tam; i++){
        if(!strcmp(estoque[i].modelo, m) && estoque[i].ano.fabricacao >= a1 && estoque[i].ano.fabricacao <= a2 && estoque[i].valor <= x){
            printf("Carro %d:\n", i + 1);
            imprimirCarro(estoque[i]);
        }
    }
}
//ii. Reajustar os valores de todos os carros 0
//km, considerando um aumento de 2.5%;
void reajustarValor(TCarro* estoque, int tam){
    int i;
    for(i = 0; i < tam; i++){
        if(strcmp(estoque[i].tipo, "0 km") == 0){
            estoque[i].valor *= 1.025F;
        }
    }
}
//iii. Retirar do estoque um determinado veículo,
//dada a sua placa.
int retirar(TCarro* estoque, int tam, char* placa){
    int i;
    for(i = 0; i < tam; i++){
        if(strcmp(estoque[i].placa, placa) == 0){
            int j, aux;
            for(j = i + 1; j < tam; j++){
                estoque[j-1] = estoque[j];
            }
            tam--;
            printf("\nRemocao feita com sucesso\n");
            return 1;
        }
    }
    printf("\nPlaca nao encontrada\n");
    return 0;
}




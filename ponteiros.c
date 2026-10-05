#include <stdio.h>

/* protótipos */
void trocar(int *a, int *b);
void calcularSoma(int a, int b, int *soma);
void calcularProduto(int a, int b, int *produto);
void determinarMaiorMenor(int a, int b, int *maior, int *menor);
void mostrarResultados(int a, int b, int soma, int produto, int maior, int menor);

int main(void) {
    /* declaração das variáveis */
    int a, b, soma, produto, maior, menor;

    /* leitura */
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    /* chamadas às funções */
    trocar(&a, &b);
    calcularSoma(a, b, &soma);
    calcularProduto(a, b, &produto);
    determinarMaiorMenor(a, b, &maior, &menor);
    mostrarResultados(a, b, soma, produto, maior, menor);

    return 0;
}

/* definições das funções */
void trocar(int *a, int *b) {
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void calcularSoma(int a, int b, int *soma) {
    *soma = a + b;
}

void calcularProduto(int a, int b, int *produto) {
    *produto = a * b;
}

void determinarMaiorMenor(int a, int b, int *maior, int *menor) {
    if (a >= b) {
        *maior = a;
        *menor = b;
    } else {
        *maior = b;
        *menor = a;
    }
}

void mostrarResultados(int a, int b, int soma, int produto, int maior, int menor) {
    printf("\nValor A após a troca: %d\n", a);
    printf("Valor B após a troca: %d\n", b);
    printf("Soma: %d\n", soma);
    printf("Produto: %d\n", produto);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
}

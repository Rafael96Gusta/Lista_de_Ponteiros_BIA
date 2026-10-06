#include <stdio.h>

/* protótipos */
void trocar(int *a, int *b);
void calcularSoma(int a, int b, int *soma);
void calcularProduto(int a, int b, int *produto);
void determinarMaiorMenor(int a, int b, int *maior, int *menor);
void mostrarResultados(int a, int b, int soma, int produto, int maior, int menor);

/* funções adicionais */
void incrementar(int *x);
void contarMaioresQueMedia(int *v, int n, float media, int *qtdMaiores);


int main(void) {

    /* declaração das variáveis */
    int a, b, soma, produto, maior, menor;
    int valores[2];
    int qtdMaiores;
    float media;

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


    /* funções adicionais */

    /* coloca a e b dentro de um vetor */
    valores[0] = a;
    valores[1] = b;

    /* calcula a média */
    media = soma / 2.0;

    /* conta quantos são maiores que a média */
    contarMaioresQueMedia(valores, 2, media, &qtdMaiores);

    printf("Media: %.2f\n", media);
    printf("Quantidade de valores maiores que a media: %d\n",
           qtdMaiores);

    return 0;
}


/* ================= FUNÇÕES PRINCIPAIS ================= */

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


void mostrarResultados(int a, int b, int soma,
                       int produto, int maior, int menor) {

    printf("\nValor A apos a troca: %d\n", a);
    printf("Valor B apos a troca: %d\n", b);
    printf("Soma: %d\n", soma);
    printf("Produto: %d\n", produto);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
}


/* ================= FUNÇÕES ADICIONAIS ================= */

/* incrementa o valor recebido */
void incrementar(int *x) {
    *x = *x + 1;
}


/* conta elementos maiores que a média */
void contarMaioresQueMedia(int *v, int n,
                           float media, int *qtdMaiores) {

    *qtdMaiores = 0;

    for (int i = 0; i < n; i++) {

        if (v[i] > media) {
            incrementar(qtdMaiores);
        }

    }
}
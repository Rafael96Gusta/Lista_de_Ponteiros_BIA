#include <stdio.h>

/* PROTÓTIPOS */
void trocar(int *a, int *b);
void calcularSoma(int a, int b, int *soma);
void calcularProduto(int a, int b, int *produto);
void determinarMaiorMenor(int a, int b, int *maior, int *menor);
void mediaTres(int a, int b, int c, float *media);

void mostrarResultados(int a, int b, int soma,
                       int produto, int maior, int menor);

void incrementar(int *x);
void contarMaioresQueMedia(int *v, int n,
                           float media, int *qtdMaiores);


int main(void) {

    /* DECLARAÇÃO DAS VARIÁVEIS */
    int a, b, c;
    int soma, produto, maior, menor;
    int valores[3];
    int qtdMaiores;
    float media;


    /* LEITURA */
    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    printf("Digite o valor de c: ");
    scanf("%d", &c);


    /* FUNÇÕES PRINCIPAIS */
    trocar(&a, &b);

    calcularSoma(a, b, &soma);

    calcularProduto(a, b, &produto);

    determinarMaiorMenor(a, b, &maior, &menor);

    mediaTres(a, b, c, &media);


    /* VETOR COM OS VALORES */
    valores[0] = a;
    valores[1] = b;
    valores[2] = c;


    /* FUNÇÃO ADICIONAL */
    contarMaioresQueMedia(valores, 3, media, &qtdMaiores);


    /* RESULTADOS */
    mostrarResultados(a, b, soma, produto, maior, menor);

    printf("C: %d\n", c);
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


void determinarMaiorMenor(int a, int b,
                          int *maior, int *menor) {

    if (a >= b) {

        *maior = a;
        *menor = b;

    } else {

        *maior = b;
        *menor = a;
    }
}


/* MÉDIA DE A, B E C */

void mediaTres(int a, int b, int c, float *media) {

    *media = (a + b + c) / 3.0;
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


/* INCREMENTAR */

void incrementar(int *x) {

    *x = *x + 1;
}


/* CONTAR VALORES MAIORES QUE A MÉDIA */

void contarMaioresQueMedia(int *v, int n,
                           float media, int *qtdMaiores) {

    *qtdMaiores = 0;

    for (int i = 0; i < n; i++) {

        if (v[i] > media) {

            incrementar(qtdMaiores);
        }
    }
}
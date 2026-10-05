# Lista de Algoritimos e Programação 2 - BIA-UFU

Resolução de Lista de exercícios em C

PESEUDO CODIGO:

PROCEDIMENTO trocar(ENDEREÇO *a, ENDEREÇO *b)
    // *a e *b são endereços de variáveis inteiras
    VARIÁVEL aux : inteiro
    aux ← *a
    *a  ← *b
    *b  ← aux
FIM PROCEDIMENTO


PROCEDIMENTO calcularSoma(VALOR a, VALOR b, ENDEREÇO *soma)
    // a e b são valores; *soma é o endereço onde guardar o resultado
    *soma ← a + b
FIM PROCEDIMENTO


PROCEDIMENTO calcularProduto(VALOR a, VALOR b, ENDEREÇO *produto)
    *produto ← a × b
FIM PROCEDIMENTO


PROCEDIMENTO determinarMaiorMenor(VALOR a, VALOR b, ENDEREÇO *maior, ENDEREÇO *menor)
    SE a >= b ENTÃO
        *maior ← a
        *menor ← b
    SENÃO
        *maior ← b
        *menor ← a
    FIM SE
FIM PROCEDIMENTO


PROCEDIMENTO mostrarResultados(VALOR a, VALOR b, VALOR soma, VALOR produto, VALOR maior, VALOR menor)
    // apenas exibe; não modifica nada
    ESCREVER "Valor A após a troca: ", a
    ESCREVER "Valor B após a troca: ", b
    ESCREVER "Soma: ", soma
    ESCREVER "Produto: ", produto
    ESCREVER "Maior: ", maior
    ESCREVER "Menor: ", menor
FIM PROCEDIMENTO


ALGORITMO principal
    VARIÁVEIS a, b, soma, produto, maior, menor : inteiro

    ESCREVER "Digite o valor de a: "
    LER a
    ESCREVER "Digite o valor de b: "
    LER b

    trocar(&a, &b)                          // passa ENDEREÇOS
    calcularSoma(a, b, &soma)               // a, b por VALOR; &soma por ENDEREÇO
    calcularProduto(a, b, &produto)
    determinarMaiorMenor(a, b, &maior, &menor)
    mostrarResultados(a, b, soma, produto, maior, menor)   // tudo por VALOR
FIM ALGORITMO

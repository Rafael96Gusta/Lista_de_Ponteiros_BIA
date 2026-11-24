
    int registrarLeitura(const char *nomeArquivo, const char *robo, int valor);int listarLeituras(const char *nomeArquivo);int calcularMedia(const char *nomeArquivo, double *media, int *quantidade);int copiarArquivo(const char *origem, const char *destino);int removerLeituras(const char *arquivo, const char *robo);
/* Cria historico novo e vazio ("w" trunca). 1 = sucesso, 0 = falha. */int iniciarArquivo(const char *nomeArquivo){    FILE *fp = fopen(nomeArquivo, "w");    if (fp == NULL)        return 0;    if (fclose(fp) != 0)        return 0;    return 1;}
/* Acrescenta "robo valor\n" ao final ("a"). 1 = sucesso, 0 = falha. */int registrarLeitura(const char *nomeArquivo, const char *robo, int valor){    FILE *fp;    int i, ok;
    if (robo == NULL || robo[0] == '\0' || strlen(robo) > 15)        return 0;    for (i = 0; robo[i] != '\0'; i++)        if (isspace((unsigned char)robo[i]))            return 0;    if (valor < 0 || valor > 100)        return 0;
    fp = fopen(nomeArquivo, "a");    if (fp == NULL)        return 0;
    ok = (fprintf(fp, "%s %d\n", robo, valor) > 0);    if (fclose(fp) != 0)        ok = 0;    return ok ? 1 : 0;}
/* Exibe os registros. -1 se o arquivo nao existe; senao a quantidade. */int listarLeituras(const char *nomeArquivo){    FILE *fp;    char robo[16];    int valor, quantidade;
    fp = fopen(nomeArquivo, "r");    if (fp == NULL)        return -1;
    quantidade = 0;    while (fscanf(fp, "%15s %d", robo, &valor) == 2) {        printf("%s %d\n", robo, valor);        quantidade = quantidade + 1;    }    fclose(fp);    return quantidade;}
/* Media e quantidade por referencia. 1 = leitura possivel, 0 = nao abriu. */int calcularMedia(const char *nomeArquivo, double *media, int *quantidade){    FILE *fp;    char robo[16];    int valor, soma;
    fp = fopen(nomeArquivo, "r");    if (fp == NULL)        return 0;
    soma = 0;    *quantidade = 0;    *media = 0.0;    while (fscanf(fp, "%15s %d", robo, &valor) == 2) {        soma = soma + valor;        *quantidade = *quantidade + 1;    }    fclose(fp);
    if (*quantidade > 0)        *media = (double)soma / *quantidade;    return 1;}
/* Copia caractere por caractere. 1 = sucesso, 0 = falha. */int copiarArquivo(const char *origem, const char *destino){    FILE *entrada, *saida;    int c;      /* int para representar tambem EOF */    int ok;
    if (strcmp(origem, destino) == 0)        return 0;
    entrada = fopen(origem, "r");    if (entrada == NULL)        return 0;    saida = fopen(destino, "w");    if (saida == NULL) {        fclose(entrada);        return 0;    }
    ok = 1;    while ((c = fgetc(entrada)) != EOF) {        if (fputc(c, saida) == EOF) {            ok = 0;            break;        }    }    if (ferror(entrada))        ok = 0;    if (fclose(entrada) != 0)        ok = 0;    if (fclose(saida) != 0)        ok = 0;    return ok ? 1 : 0;}
/* Remove todas as leituras do robo indicado, preservando a ordem dos * demais. Processa o arquivo sequencialmente com um arquivo temporario * (sem vetores). Retorna a quantidade removida ou -1 em caso de falha. */int removerLeituras(const char *arquivo, const char *robo){    FILE *entrada, *saida;    char id[16];    int valor, removidos, erro;
    if (arquivo == NULL || robo == NULL)        return -1;
    entrada = fopen(arquivo, "r");    if (entrada == NULL)        return -1;    saida = fopen("temporario.txt", "w");    if (saida == NULL) {        fclose(entrada);        return -1;    }
    removidos = 0;    erro = 0;    while (fscanf(entrada, "%15s %d", id, &valor) == 2) {        if (strcmp(id, robo) == 0) {            removidos = removidos + 1;        } else {            if (fprintf(saida, "%s %d\n", id, valor) < 0) {                erro = 1;                break;            }        }    }
    if (ferror(entrada))        erro = 1;    if (fclose(entrada) != 0)        erro = 1;    if (fclose(saida) != 0)        erro = 1;
    if (erro) {        remove("temporario.txt");        return -1;    }
    /* substitui o original pelo temporario */    if (remove(arquivo) != 0) {        remove("temporario.txt");        return -1;    }    if (rename("temporario.txt", arquivo) != 0)        return -1;
    return removidos;}/* Programa de teste (slide do desafio presencial) */int main(void){    double media;    int quantidade, removidos;
    iniciarArquivo("telemetria.txt");    registrarLeitura("telemetria.txt", "R1", 80);    registrarLeitura("telemetria.txt", "R2", 20);    registrarLeitura("telemetria.txt", "R1", 60);    registrarLeitura("telemetria.txt", "R3", 90);    registrarLeitura("telemetria.txt", "R2", 50);
    printf("--- Antes (R1 80, R2 20, R1 60, R3 90, R2 50) ---\n");    listarLeituras("telemetria.txt");
    removidos = removerLeituras("telemetria.txt", "R2");    printf("Removidos = %d\n", removidos);
    printf("--- Depois (R1 80, R1 60, R3 90) ---\n");    listarLeituras("telemetria.txt");
    if (calcularMedia("telemetria.txt", &media, &quantidade) == 1)        printf("qtd = %d, media = %.2f\n", quantidade, media);    else        printf("erro ao calcular a media\n");
    return 0;}
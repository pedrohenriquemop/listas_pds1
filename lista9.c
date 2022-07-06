#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>

void criaArquivoMatriz(int nLin, int nCol){
    FILE *arq;
    if((arq = fopen("lista9_pasta/matriz.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    };
    fprintf(arq, "%d\n", nLin);
    fprintf(arq, "%d\n", nCol);
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            fprintf(arq, "%d", rand() % 10);
            if(j < nCol - 1) fprintf(arq, "\t");
        }
        if(i < nLin - 1) fprintf(arq, "\n");
    }
    fclose(arq);
}

void printaMatrizInt(int nl, int nc, int (*matrix)[nc]){
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            printf("%d", matrix[i][j]);
            if(j < nc - 1) printf("\t");
        }
        if(i < nl - 1) printf("\n");
    }
    printf("\n");
}

void printaMatrizFloat(int nl, int nc, float (*matrix)[nc]){
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            printf("%.2f", matrix[i][j]);
            if(j < nc - 1) printf("\t");
        }
        if(i < nl - 1) printf("\n");
    }
    printf("\n");
}

void questao1(){
    FILE *arq;
    if((arq = fopen("lista9_pasta/matriz.txt", "r")) == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    int nl, nc;
    fscanf(arq, "%d", &nl);
    fscanf(arq, "%d", &nc);
    int matrix[nl][nc];
    for(int i = 0; i < nl; i++){
        for(int j = 0; j < nc; j++){
            fscanf(arq, "%d", &matrix[i][j]);
        }
    }
    printaMatrizInt(nl, nc, matrix);
}

float media_matriz(int n, float A[][n]){
    float soma = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            soma += A[i][j];
        }
    }
    return soma / (n * n);
}

void questao2(){
    float matrix[3][3] = {{1.8, 9.3, 7.2},{9.5, 4.0, 4.8},{7.2, 6.8, 5.5}};
    printaMatrizFloat(3, 3, matrix);
    printf("Media da matriz: %.2f\n", media_matriz(3, matrix));
}

void identiade(int n, float A[][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) A[i][j] = 1;
            else A[i][j] = 0;
        }
    }
}

void questao3(){
    float matrix[3][3] = {{1.8, 9.3, 7.2},{9.5, 4.0, 4.8},{7.2, 6.8, 5.5}};
    printf("Matriz antes:\n");
    printaMatrizFloat(3, 3, matrix);
    identiade(3, matrix);
    printf("Matriz depois:\n");
    printaMatrizFloat(3, 3, matrix);
}

void transposta(int n, float A[][n], float T[][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            T[j][i] = A[i][j];
        }
    }
}

void questao4(){
    float matrix[3][3] = {{1.8, 9.3, 7.2},{9.5, 4.0, 4.8},{7.2, 6.8, 5.5}};
    float matrixT[3][3];
    transposta(3, matrix, matrixT);
    printf("Matriz normal:\n");
    printaMatrizFloat(3, 3, matrix);
    printf("Matriz transposta:\n");
    printaMatrizFloat(3, 3, matrixT);
}

bool simetrica(int n, float A[][n]){
    float T[n][n];
    transposta(n, A, T);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] != T[i][j]) return false;
        }
    }
    return true;
}

void questao5(){
    float matrix[3][3] = {{1.8, 9.3, 7.2},{9.5, 4.0, 4.8},{7.2, 6.8, 5.5}};
    printf("Matriz:\n");
    printaMatrizFloat(3, 3, matrix);
    printf("Eh simetrica? %s\n", simetrica(3, matrix) ? "sim" : "nao");
}

void soma_matriz(int n, float A[][n], float B[][n], float S[][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            S[i][j] = A[i][j] + B[i][j];
        }
    }
}

void questao6(){
    float matrix[3][3] = {{1.8, 9.3, 7.2},{9.5, 4.0, 4.8},{7.2, 6.8, 5.5}};
    float matrix2[3][3] = {{1.9, 3.7, 4.2},{5.0, 2.1, 0.5},{2.8, 6.8, 1.5}};
    float soma[3][3];
    soma_matriz(3, matrix, matrix2, soma);
    printf("Matriz 1:\n");
    printaMatrizFloat(3, 3, matrix);
    printf("Matriz 2:\n");
    printaMatrizFloat(3, 3, matrix2);
    printf("Soma:\n");
    printaMatrizFloat(3, 3, soma);
}

float produto_linha_coluna(int n, int lin, int col, float A[][n], float B[][n]){
    float produto = 0;
    for(int i = 0; i < n; i++){
        produto += A[lin][i] * B[i][col];
    }
    return produto;
}

void mult_matriz(int n, float A[][n], float B[][n], float P[][n]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            P[i][j] = produto_linha_coluna(3, i, j, A, B);
        }
    }
}

void questao7(){
    float matrix[3][3] = {{1.8, 9.3, 7.2},{9.5, 4.0, 4.8},{7.2, 6.8, 5.5}};
    float matrix2[3][3] = {{1.9, 3.7, 4.2},{5.0, 2.1, 0.5},{2.8, 6.8, 1.5}};
    float produto[3][3];
    mult_matriz(3, matrix, matrix2, produto);
    printf("Matriz 1:\n");
    printaMatrizFloat(3, 3, matrix);
    printf("Matriz 2:\n");
    printaMatrizFloat(3, 3, matrix2);
    printf("Produto:\n");
    printaMatrizFloat(3, 3, produto);
}

int main(){
    mkdir("lista9_pasta");
    criaArquivoMatriz(3, 3);
    int opcao = 0;
    while(opcao != -1){
        printf("Escolha uma opcao:\n");
        printf("-1 - Sair\n");
        printf(" 1 - Questao 1\n");
        printf(" 2 - Questao 2\n");
        printf(" 3 - Questao 3\n");
        printf(" 4 - Questao 4\n");
        printf(" 5 - Questao 5\n");
        printf(" 6 - Questao 6\n");
        printf(" 7 - Questao 7\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                questao1();
                break;
            case 2:
                questao2();
                break;
            case 3:
                questao3();
                break;
            case 4:
                questao4();
                break;
            case 5:
                questao5();
                break;
            case 6:
                questao6();
                break;
            case 7:
                questao7();
                break;
            case -1:
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }
    printf("Fim do programa");
    exit(0);
    return 0;
}
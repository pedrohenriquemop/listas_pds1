#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>

void criaArquivoNumeros(int max){
    FILE *arq;
    if((arq = fopen("lista7_pasta/numeros.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    };
    for(int i = 0; i <= max; i++){
        fprintf(arq, "%d", i);
        if(i <= max - 1) fprintf(arq, "\n");
    }
    fclose(arq);
}

void printaVetorInt(int *arr, int tam){
    for(int i = 0; i < tam; i++){
        if(i != 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

void printaVetorFloat(float *arr, int tam){
    for(int i = 0; i < tam; i++){
        if(i != 0) printf(", ");
        printf("%.2f", arr[i]);
    }
    printf("\n");
}

void questao1(){
    FILE *arq;
    int arr[50];
    if((arq = fopen("lista7_pasta/numeros.txt", "r")) == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    int i = 0;
    while(!feof(arq)){
        fscanf(arq, "%d", arr + i);
        i++;
    }
    printaVetorInt(arr, 50);
}

float mediaArranjo(float *arr, int tam){
    float soma = 0;
    for(int i = 0; i < tam; i++){
        soma += arr[i];
    }
    return soma / tam;
}

void questao2(){
    float arr[5] = {1.1, 5.8, 9.2, 56.9, 3.4};
    printf("Arranjo em questao:\n");
    printaVetorFloat(arr, 5);
    printf("Media dos elementos:\n");
    printf("%.2f\n", mediaArranjo(arr, 5));
}

float varianciaArranjo(float *arr, int tam){
    float soma = 0;
    for(int i = 0; i < tam; i++){
        soma += pow((arr[i] - mediaArranjo(arr, tam)), 2);
    }
    return soma / tam;
}

void questao3(){
    float arr[5] = {1.1, 5.8, 9.2, 56.9, 3.4};
    printf("Arranjo em questao:\n");
    printaVetorFloat(arr, 5);
    printf("Variancia dos elementos:\n");
    printf("%.2f\n", varianciaArranjo(arr, 5));
}

float maior(float *arr, int tam){
    if(tam == 1) return arr[0];
    float maior;
    if(arr[1] > arr[0]) maior = arr[1];
    else maior = arr[0];
    for(int i = 2; i < tam; i++){
        if(arr[i] > maior) maior = arr[i];
    }
    return maior;
}

void questao4(){
    float arr[5] = {1.1, 5.8, 9.2, 56.9, 3.4};
    printf("Arranjo em questao:\n");
    printaVetorFloat(arr, 5);
    printf("Maior dos elementos:\n");
    printf("%.2f\n", maior(arr, 5));
}

float menor(float *arr, int tam){
    if(tam == 1) return arr[0];
    float menor;
    if(arr[1] < arr[0]) menor = arr[1];
    else menor = arr[0];
    for(int i = 2; i < tam; i++){
        if(arr[i] < menor) menor = arr[i];
    }
    return menor;
}

void questao5(){
    float arr[5] = {1.1, 5.8, 9.2, 56.9, 3.4};
    printf("Arranjo em questao:\n");
    printaVetorFloat(arr, 5);
    printf("Menor dos elementos:\n");
    printf("%.2f\n", menor(arr, 5));
}

float produtoEscalar(float *arr1, float *arr2, int dim){
    float soma = 0;
    for(int i = 0; i < dim; i++){
        soma += arr1[i] * arr2[i];
    }
    return soma;
}

void questao6(){
    float arr1[5] = {1.1, 5.8, 9.2, 56.9, 3.4},
    arr2[5] = {2.9, 1.8, 0.1, -0.6, 7.9};
    printf("Arranjos em questao:\n");
    printaVetorFloat(arr1, 5);
    printaVetorFloat(arr2, 5);
    printf("Produto escalar dos arranjos:\n");
    printf("%.2f\n", produtoEscalar(arr1, arr2, 5));
}

int main(){
    mkdir("lista7_pasta");
    criaArquivoNumeros(50);
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
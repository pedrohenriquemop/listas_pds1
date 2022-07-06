#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void readNumber(char* txt, int* num){
    printf("%s", txt);
    scanf("%d", num);
}

bool isPrimo(int n){
    if(n < 2) return false;
    int aux;
    for(aux = n / 2; aux > 1; aux--){
        if(n % aux == 0) return false;
    }
    return true;
}

FILE* abreArquivo(char* path, char* mode){
    FILE* arq;
    if((arq = fopen(path, mode)) == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    return arq;
}

void criaArquivoNaturais(int max){
    FILE *arq;
    arq = abreArquivo("lista6_pasta/naturais.txt", "w");
    for(int i = 0; i <= max; i++){
        fprintf(arq, "%d", i);
        if(i <= max - 1) fprintf(arq, "\n");
    }
    fclose(arq);
}

void criaArquivoReais(float max, int qtd){
    FILE *arq;
    arq = abreArquivo("lista6_pasta/reais.txt", "w");
    for(int i = 0; i < qtd; i++){
        fprintf(arq, "%f", (float)rand()/(float)(RAND_MAX/max));
        if(i < qtd - 1) fprintf(arq, "\n");
    }
    fclose(arq);
}

void questao1(){
    FILE *arq;
    int n;
    readNumber("Digite um numero: ", &n);
    int count = 0, x = 2;
    arq = abreArquivo("lista6_pasta/q1.txt", "w");
    while(count < n){
        if(isPrimo(x)){
            fprintf(arq, "%d\n", x);
            count++;
        }
        x++;
    }
    fclose(arq);
}

void questao2(){
    FILE *arq, *naturais;
    int num;
    arq = abreArquivo("lista6_pasta/q2.txt", "w");
    naturais = abreArquivo("lista6_pasta/naturais.txt", "r");
    while(!feof(naturais)){
        fscanf(naturais, "%d", &num);
        fprintf(arq, "%d: ", num);
        if(isPrimo(num)) fprintf(arq, "primo\n");
        else fprintf(arq, "nao eh primo\n");
    }
    fclose(arq);
    fclose(naturais);
}

void questao3(){
    FILE *primos, *outros, *naturais;
    int num;
    primos = abreArquivo("lista6_pasta/primos.txt", "w");
    outros = abreArquivo("lista6_pasta/outros.txt", "w");
    naturais = abreArquivo("lista6_pasta/naturais.txt", "r");
    while(!feof(naturais)){
        fscanf(naturais, "%d", &num);
        if(isPrimo(num)) fprintf(primos, "%d\n", num);
        else fprintf(outros, "%d\n", num);
    }
    fclose(primos);
    fclose(outros);
    fclose(naturais);
}

void questao4(){
    FILE *arq, *reais;
    float num;
    arq = abreArquivo("lista6_pasta/q4.txt", "w");
    reais = abreArquivo("lista6_pasta/reais.txt", "r");
    while(!feof(reais)){
        fscanf(reais, "%f", &num);
        fprintf(arq, "%f\n", (num * num) - (5 * num) + 1);
    }
    fclose(arq);
    fclose(reais);
}

void questao5(){
    FILE *arq, *reais;
    float num, a, b, c, d;
    printf("Digite os valores de a, b, c e d:\n");
    scanf("%f%f%f%f", &a, &b, &c, &d);
    arq = abreArquivo("lista6_pasta/q5.txt", "w");
    reais = abreArquivo("lista6_pasta/reais.txt", "r");
    while(!feof(reais)){
        fscanf(reais, "%f", &num);
        fprintf(arq, "%f\n", (a * num * num * num) + (b * num * num) + (c * num) + d);
    }
    fclose(arq);
    fclose(reais);
}

int main(){
    mkdir("lista6_pasta");
    criaArquivoNaturais(100);
    criaArquivoReais(20, 5);
    int opcao = 0;
    while(opcao != -1){
        printf("Escolha uma opcao:\n");
        printf("-1 - Sair\n");
        printf(" 1 - Questao 1\n");
        printf(" 2 - Questao 2\n");
        printf(" 3 - Questao 3\n");
        printf(" 4 - Questao 4\n");
        printf(" 5 - Questao 5\n");
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
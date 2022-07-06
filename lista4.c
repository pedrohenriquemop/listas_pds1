#include <stdio.h>
#include <stdbool.h>

long unsigned int fatorial(int n){
    if(n <= 1) return 1;
    return n * fatorial(n - 1);
}

int mdc(int a, int b){
    if(b == 0){
        return a;
    }
    if(a > b){
        return mdc(b, a % b);
    } else{
        return mdc(a, b % a);
    }
}

int mdc3(int a, int b, int c){
    return mdc(a, mdc(b, c));
}

int fib(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

bool primo(int n, int test){
    if(test == 1) return true;
    if(n % test == 0) return false;
    primo(n, test - 1);
}

void decrescente(int n){
    if(n == 0){
        printf("\n");
        return;
    }
    printf("%d ", n);
    decrescente(n - 1);
}

int res(int a, int b){
    if(a < b) return a;
    return res(a - b, b);
}

long int form(int n){
    if(n == 1) return 1;
    return n * n + form(n - 1);
}

int mmc(int a, int b, int adder){
    if(a > b){
        if(a * adder % b == 0) return a * adder;
        return mmc(a, b, adder + 1);
    } else{
        if(b * adder % a == 0) return b * adder;
        return mmc(b, a, adder + 1);
    }
}

int div(int a, int b, int adder){
    if(a == b * adder) return adder;
    if(a < b * adder) return adder - 1;
    return div(a, b, adder + 1);
}

double raiz(float n, float c){
    if(c * c > n + 0.001) return raiz(n, c / 2);
    if(c * c < n - 0.001) return raiz(n, c * 1.5);
    return c;
}

int dig(int n){
    if(n / 10 == 0) return n % 10;
    return n % 10 + dig(n / 10);
}

double potencia(float k, int n){
    if(n == 0) return 1;
    return k * potencia(k, n - 1);
}

void crescente(int n, int adder){
    if(adder > n){
        printf("\n");
        return;
    }
    printf("%d ", adder);
    crescente(n, adder + 1);
}

int main(){
    int a, b, c;
    float x;
    int opcao = 0;
    while(opcao != -1){
        printf("Digite uma opcao (-1 para sair)\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 0:
                printf("Digite um inteiro\n");
                scanf("%d", &a);
                printf("Fatorial de %d: %ld\n", a, fatorial(a));
                break;
            case 1:
                printf("Digite dois inteiros\n");
                scanf("%d%d", &a, &b);
                printf("mdc(%d, %d) = %d\n", a, b, mdc(a, b));
                break;
            case 2:
                printf("Digite tres inteiros\n");
                scanf("%d%d%d", &a, &b, &c);
                printf("mdc(%d, %d, %d) = %d\n", a, b, c, mdc3(a, b, c));
                break;
            case 3:
                printf("Digite um inteiro\n");
                scanf("%d", &a);
                printf("%d-esimo inteiro da seq de Fibonacci: %d\n", a, fib(a));
                break;
            case 4:
                printf("Digite um inteiro\n");
                scanf("%d", &a);
                printf("%d eh primo? %s\n", a, primo(a, a - 1) ? "sim" : "nao");
                break;
            case 5:
                printf("Digite um inteiro\n");
                scanf("%d", &a);
                decrescente(a);
                break;
            case 6:
                printf("Digite dois inteiros\n");
                scanf("%d%d", &a, &b);
                printf("Resto da divisao de %d e %d: %d\n", a, b, res(a, b));
                break;
            case 7:
                printf("Digite um inteiro\n");
                scanf("%d", &a);
                printf("Somatorio de i*i com i variando de 1 ate %d: %ld\n", a, form(a));
                break;
            case 8:
                printf("Digite dois inteiros\n");
                scanf("%d%d", &a, &b);
                printf("mmc(%d, %d) = %d\n", a, b, mmc(a, b, 1));
                break;
            case 9:
                printf("Digite dois inteiros\n");
                scanf("%d%d", &a, &b);
                printf("%d dividido por %d eh: %d\n", a, b, div(a, b, 1));
                break;
            case 10:
                printf("Digite um numero\n");
                scanf("%f", &x);
                printf("Raiz quadrada de %.3f: %.3f\n", x, raiz(x, x / 2));
                break;
            case 11:
                printf("Digite um inteiro\n");
                scanf("%d", &a);
                printf("Soma dos digitos de %d: %d\n", a, dig(a));
                break;
            case 12:
                printf("Digite um numero e seu expoente\n");
                scanf("%f%d", &x, &a);
                printf("%.2f elevado a %d: %.2f\n", x, a, potencia(x, a));
                break;
            case 13:
                printf("Digite um inteiro\n");
                scanf("%d", &a);
                crescente(a, 1);
                break;
            default:
                if(opcao != -1) printf("Opcao invalida\n");
                break;
        }
    }
    printf("Fim do programa\n");
}

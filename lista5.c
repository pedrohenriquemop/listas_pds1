#include <stdio.h>
#include <stdbool.h>

long unsigned int fatorial(int n){
	int fat = 1;	
   	for(int i = 1; i <= n; i++){
   		fat *= i;
   	}
	return fat;
}

int mdc(int a, int b){
	while(a % b != 0){
        if(a > b){
            b = a % b;
        } else{
            b = b % a;
        }
    }
    return b;
}

int mdc3(int a, int b, int c){
    return mdc(a, mdc(b, c));
}

int fib(int n){
	if(n == 0) return 0;
	int anterior, atual, aux;
	anterior = aux = 0;
	atual = 1;
	for(int i = 1; i < n; i++){
		aux = atual;
		atual = anterior + atual;
		anterior = aux;
	}
	return atual;
}

bool primo(int n){
	for(int i = n / 2; i > 1; i--){
		if(n % i == 0) return false;
	}
	return true;
}

void decrescente(int n){
    for(int i = n; i >= 1; i--){
    	printf("%d ", i);
	}
	printf("\n");
}

int res(int a, int b){
	while(a >= b){
		a -= b;
	}
	return a;
}

long int form(int n){
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += i * i;
	}
	return sum;
}

int mmc(int a, int b){
    int adder;
    for(adder = 1; a * adder % b != 0; adder++);
    return a * adder;
}

int div(int a, int b, int adder){
    int i;
    for(i = 1; b * i <= a; i++);
    return i - 1;
}

double raiz(float n){
    int x = n / 2;
    while(x * x > n + 0.001 || x * x < n - 0.001){
        if(x * x > n + 0.001) x /= 2;
        if(x * x < n + 0.001) x *= 1.5;
    }
    return x;
}

int dig(int n){
    int adder = 0;
    while(n / 10 != 0){
        adder += n % 10;
        n /= 10;
    }
    adder += n % 10;
    return adder;
}

double potencia(float k, int n){
    if(n == 0) return 1;
    for(int i = 1; i < n; i++){
        k *= k;
    }
    return k;
}

void crescente(int n){
    for(int i = 1; i <= n; i++){
    	printf("%d ", i);
	}
	printf("\n");
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
                printf("%d eh primo? %s\n", a, primo(a) ? "sim" : "nao");
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
                printf("mmc(%d, %d) = %d\n", a, b, mmc(a, b));
                break;
            case 9:
                printf("Digite dois inteiros\n");
                scanf("%d%d", &a, &b);
                printf("%d dividido por %d eh: %d\n", a, b, div(a, b, 1));
                break;
            case 10:
                printf("Digite um numero\n");
                scanf("%f", &x);
                printf("Raiz quadrada de %.3f: %.3f\n", x, raiz(x));
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
                crescente(a);
                break;
            default:
                if(opcao != -1) printf("Opcao invalida\n");
                break;
        }
    }
    printf("Fim do programa\n");
}


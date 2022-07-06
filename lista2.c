#include <stdio.h>
#include <math.h>

float media(float a, float b, float c){
	return (a + b + c) / 3;
};

float mediaPonderada(float a, float b, float c){
	return (a * 3 + b * 4 + c * 5) / 12;
}

float perimetroC(float r){
	return 2 * M_PI * r;
}

float areaC(float r){
	return M_PI * pow(r, 2);
}

float areaT(float b, float h){
	return b * h / 2;
}

float areaCaixa(float a, float b, float c){
	return 2 * (a * b) + 2 * (a * c) + 2 * (b * c);
}

float volumeCaixa(float a, float b, float c){
	return a * b * c;
}

float areaCilindro(float r, float h){
	return (perimetroC(r) * h) + 2 * areaC(r);
}

float volumeCilindro(float r, float h){
	return areaC(r) * h;
}

float hipotenusa(float a, float b){
	return sqrt(pow(a, 2) + pow(b, 2));
}

float raizPositiva(float a, float b, float c){
	float delta = pow(b, 2) - 4 * a * c;
	if(delta < 0){
		return -9999;
	}
	return -b + sqrt(delta) / (2 * a);
}

int main(){
	float a, b, c;
	printf("Informe os valores de a, b e c\n");
	scanf("%f%f%f", &a, &b, &c);
	printf("Media: %f\n", media(a, b, c));
	printf("Media ponderada (a peso 3, b peso 4, c peso 5): %f\n", mediaPonderada(a, b, c));
	printf("Perimetro circulo (raio a): %f\n", perimetroC(a));
	printf("Area circulo (raio a): %f\n", areaC(a));
	printf("Area triangulo (base a, altura b): %f\n", areaT(a, b));
	printf("Area caixa (dimensoes a, b e c): %f\n", areaCaixa(a, b, c));
	printf("Volume caixa: %f\n", volumeCaixa(a, b, c));
	printf("Area cilindro (raio a, altura b): %f\n", areaCilindro(a, b));
	printf("Volume cilindro (raio a, altura b): %f\n", volumeCilindro(a, b));
	printf("Hipotenusa (catetos a e b): %f\n", hipotenusa(a, b));
	float raizP = raizPositiva(a, b, c);
	if(raizP == -9999){
		printf("Raizes nao reais\n");
	} else{
		printf("Raiz positiva (equacao de segundo grau): %f\n", raizP);
	}
	printf("Fim do programa.\n");
	return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

void printResults(float arr[], int size){
    for(int i = 0; i < size; i++){
        if(isinf(arr[i]) || isnan(arr[i])){
            cout << (char) (97 + i) << ") ERRO\n";
        } else{
            cout << (char) (97 + i) << ") " << arr[i] << "\n";
        }
    }
}

void exercicio1(){
    cout << "Exercicio 1:\n";

    float results[19] = {
        3 + 4,
        7 / 4,
        pow(3, 2),
        5.3 * 2.1,
        2 * 5 - 2,
        2 + 2 * 5,
        (2 + 5) * 3,
        sin(3.141502),
        sqrt(5),
        1 + 2 + 3,
        1 * 2 * 3,
        (1 + 2 + 3) / 3.0,
        (2 + 4) * (3 - 1),
        (9 / 3) + (3 * 2),
        sin(4.5) + cos(3.7),
        log(2.3) - log(3.1),
        log (7) + (log(7) * log(7) - cos(log(7))),
        (10.3 + 8.4)/50.3 - (10.3 + 8.4),
        (cos(0.8) + sin(0.8)) * (cos(0.8) - sin(0.8))
    };

    printResults(results, 19);

    cout << "\n";
}

void exercicio2(){
    cout << "Exercicio 2:\n";

    float a, b, c, d; 

    cout << "Insira o valor de a:\n";
    cin >> a;
    cout << "Insira o valor de b:\n";
    cin >> b;
    cout << "Insira o valor de c:\n";
    cin >> c;
    cout << "Insira o valor de d:\n";
    cin >> d;

    float results[19] = {
        a + b,
        a / c,
        pow(a, 2),
        b * c,
        a * b - c,
        a + b * c,
        (a + b) * c,
        sin(a),
        sqrt(b),
        a + b + c,
        a * b * c,
        (a + b + c) / d,
        (a + b) * (a - d),
        (b / c) + (a * d),
        sin(b) + cos(c),
        log(a) - log(c),
        log(a) + (log(b) * log(d) - cos(log(c))),
        (b + a)/c - (d + a),
        (cos(d) + sin(c)) * (cos(b) - sin(a)),
    };

    printResults(results, 19);

    cout << "\n";
}

void exercicio3(){
    cout << "Exercicio 3:\n";

    float a, b, c; 

    cout << "Insira o valor de a:\n";
    cin >> a;
    cout << "Insira o valor de b:\n";
    cin >> b;
    cout << "Insira o valor de c:\n";
    cin >> c;

    cout << "Media: " << (a + b + c) / 3 << "\n";
    cout << "Media ponderada de a, b e c onde a tem peso 3, b 4 e c 5: " << (a * 3 + b * 4 + c * 5) / 12 << "\n";
    cout << "Perimetro de um circulo de raio a: " << (2 * M_PI * a) << "\n";
    cout << "Area de um circulo de raio a: " << (M_PI * pow(a, 2)) << "\n";
    cout << "Area de um triangulo de base b e altura c: " << (b * c) / 2 << "\n";
    cout << "Hipotenusa de um triangulo retangulo, cujos lados conhecidos sao b e c: " << sqrt(pow(b, 2) + pow(c, 2)) << "\n";

    cout << "Raizes da equacao do segundo grau definida por a.x2 + b.x + c: ";

    float delta = pow(b, 2) - (4 * a * c);
    if(delta < 0){
        cout << "Equacao nao possui valores reais.\n";
    }
    else{
        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);

        cout << "\nx1: " << x1 << "\nx2: " << x2 << "\n";
    }

    cout << "\n";
}

int main(){
    int itemLista;
    do{
        cout << "Selecione um item da lista:\n1\n2\n3\n";
        cout << "-1 para sair\n";
        cin >> itemLista;
        switch (itemLista)
        {
        case 1:
            exercicio1();
            break;
        case 2:
            exercicio2();
            break;
        case 3:
            exercicio3();
            break;
        default:
            break;
        }
    } while(itemLista >= 0);
    cout << "Fim do programa";
    
    return 0;
}
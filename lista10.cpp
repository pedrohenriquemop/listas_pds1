#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

float determinante(float m[3][3])
{
    return ((m[0][0] * m[1][1] * m[2][2]) +
            (m[0][1] * m[1][2] * m[2][0]) +
            (m[0][2] * m[1][0] * m[2][1])) -
           ((m[0][2] * m[1][1] * m[2][0]) +
            (m[0][0] * m[1][2] * m[2][1]) +
            (m[0][1] * m[1][0] * m[2][2]));
}

struct Ponto
{
    float x;
    float y;

    float distancia(Ponto p)
    {
        return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
    };

    void atribuir(float a, float b)
    {
        this->x = a;
        this->y = b;
    };
};

struct Triangulo
{
    Ponto a, b, c;

    float perimetro()
    {
        return a.distancia(b) + b.distancia(c) + c.distancia(a);
    }

    float area()
    {
        float m[3][3] = {
            {a.x, a.y, 1},
            {b.x, b.y, 1},
            {c.x, c.y, 1}};

        return abs(determinante(m)) /
               2;
    }

    bool equilatero()
    {
        return a.distancia(b) == b.distancia(c) && b.distancia(c) == c.distancia(a);
    }

    bool semelhante(Triangulo t)
    {
        float ladoA = a.distancia(b);
        float ladoB = b.distancia(c);
        float ladoC = c.distancia(a);
        float ladoA2 = t.a.distancia(t.b);
        float ladoB2 = t.b.distancia(t.c);
        float ladoC2 = t.c.distancia(t.a);

        return ladoA / ladoA2 == ladoB / ladoB2 && ladoB / ladoB2 == ladoC / ladoC2;
    }
};

struct Retangulo
{
    Ponto a, b, c, d;

    float perimetro()
    {
        a.distancia(b) + b.distancia(c) + c.distancia(d) + d.distancia(a);
    }

    float area()
    {
        return a.distancia(b) * b.distancia(c);
    }

    float quadrado()
    {
        return a.distancia(b) == b.distancia(c);
    }
};

struct Circunferencia
{
    Ponto c;
    float r;

    float perimetro()
    {
        return 2 * M_PI * r;
    }

    float area()
    {
        return M_PI * r * r;
    }

    bool contem(Ponto p)
    {
        return c.distancia(p) <= r;
    }

    bool contem(Triangulo t)
    {
        return this->contem(t.a) && this->contem(t.b) && this->contem(t.c);
    }

    bool contem(Retangulo ret)
    {
        return this->contem(ret.a) && this->contem(ret.b) && this->contem(ret.c) && this->contem(ret.d);
    }

    bool pertence(Ponto p)
    {
        return c.distancia(p) == r;
    }

    bool circunscrita(Triangulo t)
    {
        return this->pertence(t.a) && this->pertence(t.b) && this->pertence(t.c);
    }

    bool circunscrita(Retangulo ret)
    {
        return this->pertence(ret.a) && this->pertence(ret.b) && this->pertence(ret.c) && this->pertence(ret.d);
    }
};

int main()
{
    cout << "A lista pedia so a implementacao das structs e metodos, portanto nao vai ter nada aqui.";

    return 0;
}
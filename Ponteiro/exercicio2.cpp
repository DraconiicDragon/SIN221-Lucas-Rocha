#include <iostream>

using namespace std;

void ordenar(int *a, int *b, int *c) {
    int maior,menor,meio;
    maior = max(*a,max(*b,*c));
    menor = min(*a,min(*b,*c));
    if(*a > menor && *a < maior) {
        meio = *a;
    } else if(*b > menor && *b < maior) {
        meio = *b;
    } else {
        meio = *c;
    }
    *a = menor;
    *b = meio;
    *c = maior;
}

int main() {
    int a = 3,b = 1,c = 2;
    ordenar(&a,&b,&c);
    cout << a << " " << b << " " << c;
    return 0;
}
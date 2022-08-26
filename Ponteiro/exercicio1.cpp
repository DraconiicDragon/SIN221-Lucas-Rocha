#include <iostream>

using namespace std;

int main() {
    float v[10];
    for(int i = 0; i < 10; i++) {
        cout << &v[i] << endl;
    }
    return 0;
}
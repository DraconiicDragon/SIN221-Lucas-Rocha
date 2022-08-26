#include <iostream>

using namespace std;

int main() {
    int p = 1;

    int i[p];
    i[0] = 10;
    i[1] = 20;

    cout << i[1] << endl;
    cout << 1[i] << endl;
    cout << *(i+1);
}
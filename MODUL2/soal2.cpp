#include <iostream>
using namespace std;

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

int main() {
    int x = 10, y = 20, z = 30;

    cout << "Nilai Awal        -> x: " << x << ", y: " << y << ", z: " << z << endl;

    tukarReference(x, y, z);
    cout << "Setelah Reference -> x: " << x << ", y: " << y << ", z: " << z << endl;

    tukarPointer(&x, &y, &z);
    cout << "Setelah Pointer   -> x: " << x << ", y: " << y << ", z: " << z << endl;

    return 0;
}
#include <iostream>

using namespace std;

void tampilkanArray2D(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray2D(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int val1 = 15;
    int val2 = 45;
    int *p1 = &val1;
    int *p2 = &val2;

    cout << "=== ARRAY 2D SEBELUM DITUKAR ===" << endl;
    cout << "Array A:\n";
    tampilkanArray2D(A);
    cout << "\nArray B:\n";
    tampilkanArray2D(B);

    tukarArray2D(A, B, 1, 1);

    cout << "\n=== ARRAY 2D SETELAH DITUKAR (Posisi [1][1]) ===" << endl;
    cout << "Array A:\n";
    tampilkanArray2D(A);
    cout << "\nArray B:\n";
    tampilkanArray2D(B);

    cout << "\n=== POINTER SEBELUM DITUKAR ===" << endl;
    cout << "Nilai *p1: " << *p1 << endl;
    cout << "Nilai *p2: " << *p2 << endl;

    tukarPointer(p1, p2);

    cout << "\n=== POINTER SETELAH DITUKAR ===" << endl;
    cout << "Nilai *p1: " << *p1 << endl;
    cout << "Nilai *p2: " << *p2 << endl;

    return 0;
}
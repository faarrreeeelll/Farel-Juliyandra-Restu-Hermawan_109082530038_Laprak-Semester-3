#include <iostream>
using namespace std;

void tampilkanMatriks(int M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int hasil[3][3];

    cout << "Matriks 1:" << endl;
    tampilkanMatriks(mat1);
    cout << "\nMatriks 2:" << endl;
    tampilkanMatriks(mat2);

    cout << "\n--- Penjumlahan Matriks ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    tampilkanMatriks(hasil);

    cout << "\n--- Pengurangan Matriks ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    tampilkanMatriks(hasil);

    cout << "\n--- Perkalian Matriks ---" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                hasil[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    tampilkanMatriks(hasil);

    return 0;
}
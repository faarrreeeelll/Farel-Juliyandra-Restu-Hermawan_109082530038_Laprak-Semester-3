#include <iostream>
using namespace std;

int cariMaksimum(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int cariMinimum(int arr[], int size) {
    int min = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void hitungRataRata(int arr[], int size, float &rata_rata) {
    int total = 0;
    for(int i = 0; i < size; i++) {
        total += arr[i];
    }
    rata_rata = (float)total / size;
}

int main() {
    int arrA[] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int size = sizeof(arrA) / sizeof(arrA[0]);
    int pilihan;
    float rata_rata = 0;

    do {
        cout << "\nMenu Program Array" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. cari nilai maksimum" << endl;
        cout << "3. cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Isi Array: ";
                for(int i = 0; i < size; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, size) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, size) << endl;
                break;
            case 4:
                hitungRataRata(arrA, size, rata_rata); 
                cout << "Nilai rata-rata: " << rata_rata << endl; 
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while(pilihan != 0);

    return 0;
}
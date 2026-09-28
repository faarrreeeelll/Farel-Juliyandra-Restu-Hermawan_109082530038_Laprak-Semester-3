#include <iostream>
#include <string>
using namespace std;

string terbilang(int n) {
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                       "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};
    
    if (n < 12) {
        return satuan[n];
    } else if (n < 20) {
        return satuan[n - 10] + " belas";
    } else if (n < 100) {
        string hasil = satuan[n / 10] + " puluh";
        if (n % 10 != 0) {
            hasil += " " + satuan[n % 10];
        }
        return hasil;
    } else if (n == 100) {
        return "seratus";
    }
    return "";
}

int main() {
    int angka;

    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka harus berada di rentang 0 sampai 100!" << endl;
    } else if (angka == 0) {
        cout << angka << ": nol" << endl;
    } else {
        cout << angka << ": " << terbilang(angka) << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    float bil1, bil2;

    cout << "Masukkan bilangan pertama: ";
    cin >> bil1;
    cout << "Masukkan bilangan kedua  : ";
    cin >> bil2;

    cout << "\n=== HASIL OPERASI ARITMATIKA ===" << endl;
    cout << "Penjumlahan (" << bil1 << " + " << bil2 << ") = " << bil1 + bil2 << endl;
    cout << "Pengurangan (" << bil1 << " - " << bil2 << ") = " << bil1 - bil2 << endl;
    cout << "Perkalian   (" << bil1 << " * " << bil2 << ") = " << bil1 * bil2 << endl;
    
    if (bil2 != 0) {
        cout << "Pembagian   (" << bil1 << " / " << bil2 << ") = " << bil1 / bil2 << endl;
    } else {
        cout << "Pembagian   = Tidak terdefinisi (pembagi nol)" << endl;
    }

    return 0;
}
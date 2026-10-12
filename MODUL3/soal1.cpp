#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    char nim[15]; 
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    int n;
    cout << "Masukkan jumlah mahasiswa (maks. 10): ";
    cin >> n;

    if (n > 10 || n <= 0) {
        cout << "Jumlah mahasiswa tidak valid (maksimal 10)!" << endl;
        return 0;
    }

    Mahasiswa mhs[10];
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        cin >> mhs[i].nim;
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=== DAFTAR NILAI AKHIR MAHASISWA ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ". " << mhs[i].nama << " (" << mhs[i].nim << ") - Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}
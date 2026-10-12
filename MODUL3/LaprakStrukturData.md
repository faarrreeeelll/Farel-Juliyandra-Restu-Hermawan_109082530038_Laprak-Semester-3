# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>

<p align="center">Farel Juliyandra Restu Hermawan - 109082530038</p>

## Dasar Teori

Abstract Data Type (ADT) atau Tipe Data Abstrak adalah model matematika atau spesifikasi untuk tipe data dan operasi-operasinya, di mana perilaku tipe data tersebut didefinisikan dari sudut pandang pengguna (klien) terlepas dari bagaimana tipe data tersebut diimplementasikan. ADT terdiri dari tipe data dasar (TYPE) dan sekumpulan operasi dasar (primitif) seperti konstruktor, selektor, validator, destruktor, serta prosedur/fungsi input-output yang berlaku terhadap tipe tersebut.   

Dalam bahasa pemrograman C++, ADT biasanya diimplementasikan dengan memisahkan spesifikasi tipe dan header fungsi ke dalam file header (.h) serta realisasi/body dari fungsi tersebut ke dalam file implementasi (.cpp) agar prinsip enkapsulasi dan modularitas kode dapat diterapkan dengan baik.   

## Guided

### 1. Implementasi ADT Buku (Modular Programming)
### A. File Header (buku.h)

```C++
#ifndef BUKU_H
#define BUKU_H
#include<iostream>

using namespace std ;

struct buku
{
    string judul ;
    int halaman ;
    string penulis ;
};

void editIsi(string judul, int halaman, string penulis, buku &buku) ;
void tampilkanIsiBuku (buku buku) ;
bool checkPenulis(buku buku);

#endif
```
File header ini berfungsi sebagai wadah spesifikasi tipe dan prototipe fungsi/prosedur. Di dalamnya dideklarasikan sebuah struct bernama buku dengan tiga atribut (field), yaitu judul (string), halaman (integer), dan penulis (string). Selain itu, terdapat deklarasi header untuk prosedur editIsi, prosedur tampilkanIsiBuku, dan fungsi validator checkPenulis. Proteksi #ifndef, #define, dan #endif digunakan untuk mencegah multiple inclusion saat proses kompilasi.

### B. File Implementasi (pelajaran.cpp)
```C++
#include "buku.h"

void editIsi(string judul, int halaman, string penulis, buku &buku)
{
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void tampilkanIsiBuku(buku buku)
{
    cout << "Judul Buku : " << buku.judul << endl;
    cout << "Halaman Buku : " << buku.halaman << endl;
    cout << "Penulis Buku : " << buku.penulis << endl;
}

bool checkPenulis(buku buku)
{
    return buku.penulis == "";
}

File implementasi ini berfungsi untuk merealisasikan seluruh logika dan blok kode dari fungsi serta prosedur yang sebelumnya telah dideklarasikan di file header, di mana prosedur editIsi memanfaatkan pass by reference untuk memodifikasi data objek secara langsung di memori, prosedur tampilkanIsiBuku mengatur format keluaran data ke layar terminal, dan fungsi checkPenulis mengeksekusi validasi status kelengkapan nama penulis buku.

```
### C. File Driver (main.cpp)
```C++
#include <iostream>
#include "buku.h"
using namespace std;

int main()
{
    buku novel;

    string judul, penulis;
    int halaman;

    cout << "Masukan judul buku : ";
    cin >> judul;
    cout << "Masukan halaman buku : ";
    cin >> halaman;
    cout << "Masukan penulis buku : ";
    cin >> penulis;

    editIsi(judul, halaman, penulis, novel);
    tampilkanIsiBuku(novel);

    cout << checkPenulis(novel);

    return 0;
}
```

File utama ini berfungsi sebagai titik pusat eksekusi program (driver) yang mengatur jalannya alur interaksi dengan pengguna, mulai dari mendeklarasikan objek novel, menerima masukan data judul, halaman, dan penulis melalui terminal, hingga memanggil fungsi serta prosedur modular dari modul buku untuk memproses, menampilkan, dan memvalidasi informasi buku tersebut.

Penjelasan Keseluruhan Program:
File utama ini berfungsi sebagai titik pusat eksekusi program (driver) yang mengatur jalannya alur interaksi dengan pengguna, mulai dari mendeklarasikan objek novel, menerima masukan data judul, halaman, dan penulis melalui terminal, hingga memanggil fungsi serta prosedur modular dari modul buku untuk memproses, menampilkan, dan memvalidasi informasi buku tersebut.
## Unguided

### 1. Program Penyimpanan Data dan Perhitungan Nilai Akhir Mahasiswa

```C++
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL3/output/output-soal1.png)

Program di atas menggunakan struct bernama Mahasiswa untuk menampung atribut data mahasiswa. Kapasitas array dibatasi maksimal 10 elemen. Nilai akhir dihitung secara terpisah menggunakan fungsi hitungNilaiAkhir yang menerapkan bobot $30\%$ UTS, $40\%$ UAS, dan $30\%$ Tugas sesuai rumus yang diminta.

### 2. Implementasi ADT Pelajaran
### A. File Header (pelajaran.h)
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>

using namespace std;

struct pelajaran {
    string namamapel;
    string kodemapel;
};

pelajaran create_pelajaran(string namamapel, string kodemapel);
void tampil_pelajaran(pelajaran pel);

#endif
```
File header ini berfungsi sebagai antarmuka dan kontrak utama modul ADT Pelajaran yang mendefinisikan bentuk struktur data struct pelajaran beserta atributnya (namamapel dan kodemapel), sekaligus mendeklarasikan prototipe fungsi konstruktor create_pelajaran dan prosedur tampil_pelajaran agar dapat dikenali oleh file lain, lengkap dengan pengaman #ifndef untuk mencegah duplikasi definisi saat proses kompilasi.

### B. File Implementasi (pelajaran.cpp)
```C++
#include "pelajaran.h"
#include <iostream>

pelajaran create_pelajaran(string namamapel, string kodemapel) {
    pelajaran pel;
    pel.namamapel = namamapel;
    pel.kodemapel = kodemapel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran: " << pel.namamapel << endl;
    cout << "nilai: " << pel.kodemapel << endl;
}
```
File implementasi ini berfungsi untuk merealisasikan seluruh logika dan blok kode dari fungsi serta prosedur yang sebelumnya telah dideklarasikan di file header, di mana fungsi create_pelajaran bertindak sebagai konstruktor untuk menginisialisasi dan mengembalikan objek pelajaran baru, sedangkan prosedur tampil_pelajaran mengatur format keluaran data nama dan kode pelajaran ke layar terminal.

### C. File Driver (main.cpp)
```C++
#include <iostream>
#include <string>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodemapel = "STD";
    
    pelajaran pel = create_pelajaran(namapel, kodemapel);
    tampil_pelajaran(pel);
    
    return 0;
}
```
File utama ini berfungsi sebagai titik pusat eksekusi program (driver) yang mengatur jalannya alur program, mulai dari mendeklarasikan variabel data mata pelajaran seperti "Struktur Data" dan kode "STD", hingga memanggil fungsi konstruktor dan prosedur modular untuk menginisialisasi objek dan menampilkan informasi pelajaran tersebut ke layar.

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL3/output/output-soal2.png)

Pada soal nomor 2 ini, konsep ADT diterapkan secara modular. Definisi tipe dan header fungsi diletakkan di dalam file .h, sementara realisasi atau logika dari konstruktor create_pelajaran dan prosedur tampil_pelajaran diisolasi di dalam file .cpp agar program utama (main.cpp) tetap bersih dan hanya bertindak sebagai pemanggil modul.   

### 3. Manipulasi Array 2D dan Pointer

```C++
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
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL3/output/output-soal3.png)

Program ini mendemonstrasikan manipulasi struktur data matriks ($3 \times 3$) serta penggunaan variabel pointer di C++. Prosedur tukarArray2D mengakses koordinat baris dan kolom tertentu untuk menukar nilai antar dua matriks menggunakan variabel penampung sementara (temp), sedangkan tukarPointer memanfaatkan dereferensi pointer (*p1 dan *p2) untuk menukar nilai dari variabel yang ditunjuk secara langsung di memori.   

## Kesimpulan

Praktikum Modul 3 ini memberikan pemahaman mendalam mengenai penerapan Abstract Data Type (ADT) dalam bahasa C++. Melalui pemisahan file header (.h) dan implementasi (.cpp), mahasiswa dapat merancang struktur data kustom, mengelola array, serta mengimplementasikan fungsi dan prosedur secara terstruktur dan modular. Selain itu, penggunaan pointer dan array multidimensi melatih ketelitian dalam manajemen memori dan manipulasi data di dalam program.   

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
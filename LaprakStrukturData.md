# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Farel Juliyandra Restu Hermawan - 109082530038</p>

## Dasar Teori

Pada bagian ini, kita akan berkenalan dengan Code::Blocks, sebuah aplikasi IDE untuk pemrograman C/C++. Kita juga akan membahas bagaimana kerangka dasar dalam menulis program, mulai dari cara menyertakan pustaka standar (standard library), membuat fungsi utama main(), hingga aturan dasar dalam penulisan kode sintaksnya

### A. Code::Blocks dan Struktur Dasar C++ <br/>

Pengenalan dan konfigurasi IDE Code::Blocks untuk pengembangan C/C++, dipadukan dengan penguasaan arsitektur dasar program, pemanfaatan standard library, deklarasi fungsi main(), serta code convention / tata cara penulisan sintaks.

#### 1. Pengoperasian IDE

#### 2. Tipe Data dan Variabel

#### 3. Input dan Output

### B. Alur Kontrol, Operator, dan Modularisasi Program <br/>

Pembahasan mengenai penerapan logika pemrograman tingkat lanjut untuk mengatur alur eksekusi data, pemrosesan komputasi, serta pengorganisasian kode secara terstruktur dan modular.

#### 1. Operator Pemrograman (Aritmatika, Logika, Relasional, dan Penugasan)

#### 2. Struktur Kontrol (Percabangan/Kondisional dan Iterasi/Perulangan)

#### 3. Tipe Data Terstruktur (struct) dan Fungsi/Prosedur

## Guided

### 1. Operasi Aritmatika Dasar

```C++
#include<iostream>
using namespace std;
int main(){
    int w, x, y; float z;
    x = 7; y = 3; w = 1;
    z = (x + y)/(y + w);
    cout << "nilai z = "<< z << endl;
    return 0;
}
```

Program ini menghitung hasil operasi matematika $(x+y)/(y+w)$ dan menampilkan nilainya ke layar.

### 2. Operator Increment (Pre-Increment)


```C++
#include <iostream>
using namespace std;
int main(){
    int r = 10;
    int s;
    s=10 + ++r;
    cout<< "Nilai r= "<<r<<endl;
    cout<< "Nilai s= "<<s<<endl;
    return 0;
}
```

Program ini menaikkan nilai r sebesar 1 terlebih dahulu (++r), lalu menjumlahkannya untuk mengisi variabel s.

### 3. Percabangan Kondisional (if-else)


```C++
#include <iostream>
using namespace std;
int main(){
    double tot_pembelian, diskon;
    cout << " total pembelian : Rp";
    cin >> tot_pembelian;
    diskon = 0;
    if (tot_pembelian >= 100000)
        diskon = 0.05 * tot_pembelian;
    else
        diskon = 0;
    cout << "besar diskon = Rp"<<diskon;
}
```

Program ini mengecek total pembelian dan memberikan diskon 5% jika totalnya mencapai Rp100.000 atau lebih.

### 4. Percabangan Banyak Alternatif (switch-case)


```C++
#include <iostream>
using namespace std;
int main(){
    int kode_hari;
    puts("Menentukan hari kerja/libur\n");
    puts("1=senin 3=rabu 5=jumat 7=minggu ");
    puts("2=selasa 4=kamis 6=sabtu ");
    cin >> kode_hari;
    switch (kode_hari){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << ("Hari kerja");
            break;
        case 6:
        case 7:
            cout << ("Hari libur");
            break;
        default :
            cout << ("code masukan salah") << endl;
    }
    return 0;
}
```

Program ini mengelompokkan kode angka 1–5 sebagai hari kerja dan angka 6–7 sebagai hari libur.

### 5. OPerulangan do-while

```C++
#include <iostream>
using namespace std;
int main(){
    int i = 1;
    int jum;
    cout<<"masukan banyak baris: ";
    cin>>jum;
    do{
        cout << "baris ke-"<< (i+1)<<endl;
        i++;
    } while (i < jum);
    return 0;
}
```

Program ini mencetak baris secara berulang dengan menjalankan perintah minimal satu kali sebelum memeriksa syarat nilainya.

### 6. Perulangan while

```C++
#include <iostream>
using namespace std;
int main(){
    int i = 1;
    int jum;
    cout<<"masukan banyak baris: ";
    cin>>jum;
    while(i <= jum){
        cout << "baris ke-"<< i << endl;
        i++;
    }
    return 0;
}
```

Program ini mencetak baris secara berulang selama syarat perulangan i <= jum masih terpenuhi.

### 7. Perulangan for

```C++
#include <iostream>
using namespace std;
int main(){
    int jum;
    cout << "jumlah perulangan: ";
    cin >> jum;
    for(int i = 0; i < jum; i++){
        cout << "saya pintar\n";
    }
    return 0;
}
```

Program ini mencetak kalimat "saya pintar" berulang kali sesuai dengan jumlah input yang dimasukkan pengguna.

### 8. Array dan Struktur (Struct)

```C++
#include <iostream>
#define MAX 5
using namespace std;
int main(){
    int i;
    struct data{
        char nama[40];
        int nilai;
    };
    data siswa[MAX];
    for (i = 0; i < MAX; i++){
        cout << "masukkan data ke-"<<i+1<<endl;
        cout << "nama = ";
        cin >> siswa[i].nama;
        cout << "nilai = ";
        cin >> siswa[i].nilai;
    }
    cout << "\ndata siswa\n";
    cout << "=======";
    for (i = 0; i < MAX; i++){
        cout << "\n \ndata ke-"<<i+1;
        cout << "\n \nnama = "<<siswa[i].nama;
        cout << "\n \nnilai = "<<siswa[i].nilai;
    }
    return 0;
}
```

Program ini meminta data nama dan nilai 5 siswa, menyimpannya ke dalam struct array, lalu menampilkan seluruh data tersebut.

### 9. OModularisasi Program dengan Fungsi

```C++
#include <iostream>
using namespace std;

float ctof(float celcius);
int main() {
    float celcius, fahrenheit;
    cout <<"nilai Celcius? ";
    cin >> celcius;
    fahrenheit = ctof(celcius);
    cout<<celcius<<" Celcius adalah "<<fahrenheit<<" Fahrenheit"<<endl;
    return 0;
}

float ctof(float celcius){
    return (celcius * 1.8) + 32;
}
```

Program ini mengonversi input suhu Celcius ke Fahrenheit dengan memanggil fungsi terpisah bernama ctof().

## Unguided

### 1. Operasi Aritmatika Dua Bilangan Real (Float)

```C++
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL1/output/output-soal1.png)

Program ini menerima masukan dua bilangan real (float), lalu secara otomatis menghitung dan menampilkan hasil operasi penjumlahan, pengurangan, perkalian, serta pembagian. Selain itu, program ini dilengkapi dengan validasi kondisi if-else untuk memastikan bilangan pembagi tidak bernilai nol sehingga terhindar dari kesalahan kalkulasi (division by zero).

### 2. Konversi Angka ke Kata (Terbilang 0 s.d. 100)

```C++
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
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL1/output/output-soal2.png)

Program ini mengolah masukan angka bulat dari rentang $0$ hingga $100$ dan mengonversinya menjadi teks terbilang menggunakan fungsi terbilang(). Logika program ini memecah nilai numerik berdasarkan pemeriksaan kondisi serta operasi pembagian dan sisa bagi (modulus) untuk memetakan kombinasi kata satuan, belasan, puluhan, hingga ratusan.

### 3. Pola Angka Cermin (Mirror)

```C++
#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "input: ";
    cin >> n;

    cout << "output:" << endl;
    for (int i = n; i >= 1; i--) {
        for (int spasi = 0; spasi < n - i; spasi++) {
            cout << "  "; 
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        for (int k = 1; k <= i; k++) {
            cout << k << " ";
        }

        cout << endl; 
    }

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL1/output/output-soal3.png)

Program ini menerima input sebuah angka $n$ untuk membentuk dan mencetak pola matriks angka simetris berbentuk cermin menggunakan teknik perulangan bersarang (nested loop). Perulangan tersebut mengatur jarak spasi indentasi secara bertingkat, lalu mencetak deret angka menurun ke angka 1 sebelum melanjutkannya kembali dengan deret angka menaik secara vertikal dan horizontal.

## Kesimpulan

...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
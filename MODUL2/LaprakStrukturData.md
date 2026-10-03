# <h1 align="center">Laporan Praktikum Modul 2 - PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>

<p align="center">Farel Juliyandra Restu Hermawan - 109082530038</p>

## Dasar Teori

Pada praktikum Modul 2 ini, terdapat beberapa konsep utama dalam bahasa C++ yang dipelajari, yaitu Array, Pointer, Fungsi, dan Prosedur.
· Array: Array merupakan kumpulan data dengan nama yang sama di mana setiap elemennya memiliki tipe data yang sama. Array dapat diakses melalui indeksnya. Terdapat array satu dimensi (satu larik data), array dua dimensi (berbentuk seperti tabel), dan array berdimensi banyak. Dalam memori C++, data array disimpan pada lokasi yang berurutan dan elemen pertamanya selalu dimulai dari indeks 0.   
· Pointer: Pointer adalah variabel dasar yang berisi integer dalam format heksadesimal yang berfungsi untuk menyimpan alamat memori dari variabel lain. Agar dapat menunjuk ke suatu variabel, pointer harus diisi dengan alamat memori menggunakan simbol &, dan nilainya dapat diakses menggunakan simbol *. Pointer memiliki keterhubungan kuat dengan array, di mana pemanggilan array dapat digantikan dengan operasi pointer. Pointer juga digunakan untuk mengakses rentetan karakter pada tipe data string.   
· Fungsi dan Prosedur: Fungsi adalah blok kode yang dirancang untuk melaksanakan tugas khusus agar program menjadi terstruktur, modular, dan mengurangi duplikasi kode. Prosedur (dalam C++ dikenal sebagai fungsi void) adalah fungsi yang melakukan tugas tertentu tetapi tidak mengembalikan nilai (return value).   
· Parameter: Nilai masukan yang diolah oleh fungsi disebut parameter. Terdapat parameter formal (yang ada saat fungsi didefinisikan) dan parameter aktual (yang dipakai saat fungsi dipanggil). Terdapat tiga metode pelewatan parameter: Call by Value (menyalin nilai sehingga variabel asli tidak berubah), Call by Pointer (melewatkan alamat variabel dengan pointer), dan Call by Reference (melewatkan alamat variabel sebagai referensi sehingga variabel asli di luar fungsi bisa berubah).  

## Guided

### 1. Array

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai_total, rata_rata;
    float nilai [MAX];
    static int nilai_tahun [MAX] [MAX]=
    {
        {0,2,2,0,0},
        {0,1,1,1,0},
        {0,3,3,3,0},
        {4,4,0,0,4},
        {5,0,0,0,5}
    };

    for (i=0; i<MAX; i++) {
        cout<<"masukkan nilai ke-"<<i+1<<endl;
        cin>>nilai[i];
    }
    cout<<"\ndata nilai siswa :\n";

    for (i=0; i<MAX; i++)
        cout<<"nilai ke-"<<i+1<<"="<<nilai[i]<<endl;
    cout<<"\n nilai tahunan : \n";

    for (i=0; i<MAX; i++){
        for (j=0; j<MAX; j++)
            cout<<nilai_tahun[i] [j];
        cout<<"\n";
    }
    return 0;
}
```
Program ini berfungsi untuk meminta 5 input nilai dari pengguna, menyimpannya, lalu menampilkan kembali daftar nilai tersebut ke layar bersamaan dengan sebuah pola matriks angka 5x5 yang sudah ditentukan sebelumnya.

### 2. Pointer


```C++
#include <iostream>

using namespace std;

int main() {
    int x, y;    
    int *px;      

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x = " << &x << endl;
    cout << "Isi px = " << px << endl;
    cout << "Isi X = " << x << endl;
    cout << "Nilai yang ditunjuk px = " << *px << endl;
    cout << "Nilai y = " << y << endl;

    return 0;
}
```
Program ini berfungsi untuk mendemonstrasikan penggunaan pointer di C++, di mana program mengisi variabel x dengan angka 87, mengarahkan pointer px ke alamat memori x, menyalin nilainya ke variabel y, lalu menampilkan alamat serta isi dari masing-masing variabel tersebut ke layar.

### 3. Fungsi


```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c);

int main() {
    int x, y, z;

    cout << "Masukkan nilai bilangan ke-1 = ";
    cin >> x;
    cout << "Masukkan nilai bilangan ke-2 = ";
    cin >> y;
    cout << "Masukkan nilai bilangan ke-3 = ";
    cin >> z;

    cout << "Nilai maksimumnya adalah = " << maks3(x, y, z) << endl;

    return 0;
}

int maks3(int a, int b, int c) {
    int temp_max = a;

    if (b > temp_max) {
        temp_max = b;
    }
    if (c > temp_max) {
        temp_max = c;
    }

    return temp_max;
}
```
Program ini berfungsi untuk meminta 3 angka dari pengguna, lalu menggunakan fungsi maks3 untuk mencari dan menampilkan nilai terbesar di antara ketiganya ke layar.

### 4. Prosedur


```C++
#include <iostream>
using namespace std;

void tulis(int x);
int main() {
    int jum;
    
    cout << "jumlah baris kata = ";
    cin >> jum;
    
    tulis(jum);
    
    return 0;
}

void tulis(int x) {
    for (int i = 0; i < x; i++) {
        cout << "baris ke-" << i + 1 << endl;
    }
}
```
Program ini berfungsi untuk meminta jumlah baris dari pengguna, lalu menggunakan fungsi tulis untuk mencetak kalimat "baris ke-n" berulang kali sebanyak jumlah yang dimasukkan.

### 5. Parameter

```C++
#include <iostream>
using namespace std;

void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4, b = 6;

    tukarValue(a, b);
    cout << "Setelah Call by Value    -> a = " << a << ", b = " << b << " (Tetap)" << endl;

    tukarPointer(&a, &b);
    cout << "Setelah Call by Pointer  -> a = " << a << ", b = " << b << " (Berubah!)" << endl;

    tukarReference(a, b);
    cout << "Setelah Call by Reference -> a = " << a << ", b = " << b << " (Berubah lagi!)" << endl;

    return 0;
}
```

Program ini berfungsi untuk mendemonstrasikan perbedaan tiga metode pengiriman parameter (Call by Value, Call by Pointer, dan Call by Reference) saat mencoba menukar nilai dua buah variabel.

## Unguided

### 1. Operasi Aritmatika Matriks 3x3

```C++
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/PRAKTIKUM/MODUL2/output/output-soal1.png)

Program ini berfungsi untuk mengelola dua buah matriks berukuran 3x3 (mat1 dan mat2), lalu melakukan serangkaian operasi aritmatika dasar matriks meliputi penjumlahan, pengurangan, dan perkalian dengan bantuan fungsi khusus sebelum mencetak masing-masing hasilnya ke layar.

### 2. Pertukaran Tiga Variabel Menggunakan Pointer dan Reference

```C++
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
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/PRAKTIKUM/MODUL2/output/output-soal2.png)
Program ini berfungsi untuk mendemonstrasikan teknik perputaran nilai (swapping) pada tiga variabel sekaligus (x, y, dan z) dengan dua metode berbeda, yaitu menggunakan reference dan pointer, guna memperlihatkan bagaimana nilai variabel dapat diubah secara langsung di dalam memori.

### 3. Menu Interaktif Pengolahan Data Array (Maksimum, Minimum, dan Rata-rata)

```C++
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
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/PRAKTIKUM/MODUL2/output/output-soal31.png)

##### Output 2

![Screenshot Output Unguided 3_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/PRAKTIKUM/MODUL2/output/output-soal32.png)

Program ini berfungsi sebagai aplikasi menu interaktif berbasis array untuk mengolah sekumpulan data angka, di mana pengguna dapat memilih opsi untuk menampilkan isi array, mencari nilai maksimum, mencari nilai minimum, atau menghitung nilai rata-rata melalui fungsi-fungsi terpisah.

## Kesimpulan

Praktikum Modul 2 ini secara keseluruhan membahas dan mempraktikkan konsep-konsep fundamental dalam pemrograman C++ yang meliputi penggunaan array satu dimensi dan dua dimensi (matriks), pembuatan fungsi dan prosedur, serta teknik parameter passing—baik menggunakan Call by Value, Call by Pointer, maupun Call by Reference. Melalui berbagai latihan dan program unguided yang telah dibuat, dapat disimpulkan bahwa pemahaman mengenai manipulasi memori lewat pointer dan reference sangat krusial untuk mengubah nilai variabel secara langsung. Selain itu, implementasi fungsi dan penggunaan struktur kontrol seperti array terbukti sangat membantu dalam menyusun program yang modular, terstruktur, serta efisien untuk menyelesaikan berbagai kasus komputasi seperti operasi matriks dan pengolahan data numerik.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
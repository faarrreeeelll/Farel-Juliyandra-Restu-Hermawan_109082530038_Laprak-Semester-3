# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>

<p align="center">Farel Juliyandra Restu Hermawan - 109082530038</p>

## Dasar Teori

Singly Linked List merupakan salah satu bentuk Struktur Data Abstrak (ADT) linier berupa serangkaian elemen data (node/simpul) yang saling terhubung menggunakan pointer satu arah. Setiap elemen pada Singly Linked List terdiri dari dua komponen utama, yaitu komponen data/info untuk menyimpan nilai atau informasi, serta komponen suksesor/next berupa pointer yang menunjuk ke alamat elemen berikutnya di dalam memori.

Singly Linked List memiliki karakteristik dinamis karena ukuran kapasitas penyimpanannya dapat bertambah atau berkurang secara fleksibel sesuai kebutuhan saat program berjalan. Elemen pertama dari list ditunjuk oleh pointer First (atau Head), sedangkan pointer next pada node terakhir menunjuk ke nilai Nil (atau NULL) sebagai penanda akhir dari rantai elemen list. Operasi-operasi dasar (primitif) pada Singly Linked List meliputi inisialisasi list (createList), alokasi dan dealokasi memori (alokasi, dealokasi), penambahan elemen (insertFirst, insertLast, insertAfter), serta penelusuran data (printInfo / printList).   

## Guided

### 1. Deklarasi ADT dan Operasi Dasar Singly Linked List
### A. File Header (list.h)

```C++
#ifndef List_h
#define List_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty (linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list,address nodeBaru);
void insertAfter(linkedlist &list,address nodeBaru, address prev);
void insertLast(linkedlist &list,address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);
#endif
```
File header ini berfungsi sebagai wadah spesifikasi tipe data dan prototipe fungsi/prosedur untuk ADT Singly Linked List. Di dalamnya dideklarasikan struct mahasiswa yang direpresentasikan sebagai dataMahasiswa, struct node dengan komponen isidata dan pointer next, serta struct linkedlist yang memiliki pointer penunjuk first. Selain itu, terdapat deklarasi fungsi validator isEmpty, konstruktor createList, fungsi manajemen memori (alokasi & dealokasi), serta berbagai prosedur penambahan (insertFirst, insertAfter, insertLast), penghapusan (delFirst, delLast, delAfter), penelusuran (printList), perhitungan jumlah node (nbList), dan penghapusan seluruh list (deleteList).

### B. File Implementasi (list.cpp)
```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    {
        /* I.S. sembarang
        F.S. terbentuk list kosong */
        List.first = Nil;
    }
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    {
        /* I.S. sembarang
        F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
        address nodeBaru = new node;
        nodeBaru->isidata.nama = nama;
        nodeBaru->isidata.nim = nim;
        nodeBaru->isidata.umur = umur;
        nodeBaru->next = Nil;
        return nodeBaru;
    }
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
        /* I.S. P terdefinisi
        F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List)
{
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next !=Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist list)
{
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deletelist(linkedlist &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus." << endl;
}
```
File implementasi ini berfungsi untuk merealisasikan seluruh logika dan blok kode dari fungsi serta prosedur yang sebelumnya telah dideklarasikan di file header list.h, di mana fungsi isEmpty dan createList mengatur inisialisasi awal list kosong, fungsi alokasi dan dealokasi mengelola alokasi memori dinamis secara aman menggunakan operator new dan delete, prosedur penyisipan (insertFirst, insertAfter, insertLast) memanipulasi keterhubungan tautan pointer node secara presisi, prosedur penghapusan (delFirst, delLast, delAfter) serta deletelist membersihkan elemen list untuk mencegah memory leak, serta fungsi printList dan nbList masing-masing mengatur format keluaran data mahasiswa ke layar terminal dan menghitung jumlah total node yang aktif.

### C. File Driver (main.cpp)
```C++
#include "list.h"
using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
}
```

File utama ini bertindak sebagai titik pusat eksekusi program (driver) untuk menguji skenario operasional Singly Linked List. Program menginisialisasi list kosong, mengalokasikan data lima orang mahasiswa (nodeA sampai nodeE), lalu memasukkannya menggunakan kombinasi metode penyisipan insertFirst, insertLast, dan insertAfter. Setelah itu, program menampilkan seluruh isi list beserta jumlah total node menggunakan fungsi nbList, dan diakhiri dengan melakukan uji coba penghapusan node pertama melalui prosedur delFirst.

## Unguided

### 1. Implementasi ADT Singly Linked List
### A. File Header (pelajaran.h)
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif 
```
File header ini berfungsi sebagai antarmuka ADT Singly Linked List tipe integer sesuai spesifikasi latihan praktikum. Di dalamnya dideklarasikan tipe data infotype bertipe int, struktur simpul ElmList, tipe pointer address, serta struktur List dengan atribut First. Seluruh prototipe fungsi dasar seperti createList, alokasi, dealokasi, printInfo, dan insertFirst turut dideklarasikan di sini.   

### B. File Implementasi (Singlylist.cpp)
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    P->next = Nil;
    delete P;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```
File implementasi ini bertujuan untuk merealisasikan seluruh logika program dari file header Singlylist.h. Prosedur createList mengatur pointer First menjadi Nil, fungsi alokasi memesan memori dinamik untuk node baru dengan operator new, dealokasi mengembalikan memori ke sistem dengan delete, printInfo melakukan penelusuran (traversal) seluruh elemen hingga bertemu Nil, dan insertFirst menambahkan node baru tepat di posisi terdepan list.   

### C. File Driver (main.cpp)
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```
File driver utama ini menguji alur pembuatan dan penyisipan data Singly Linked List berdasarkan instruksi latihan modul. Program memasukkan data integer 2, 0, 8, 12, dan 9 menggunakan operasi insertFirst secara berurutan. Karena menggunakan skenario penyisipan pertama (insertFirst), urutan data yang tercetak pada layar akan terbalik dari urutan alokasi, menghasilkan keluaran rantai nilai 9 12 8 0 2.   

### Output Unguided  :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL4/output/output-soal1.png)

## Kesimpulan

Praktikum Modul 4 ini memberikan pemahaman yang komprehensif mengenai perancangan dan implementasi Singly Linked List menggunakan pointer dinamis dalam bahasa pemrograman C++. Pemisahan program ke dalam file spesifikasi header (.h), file implementasi (.cpp), dan file driver utama (main.cpp) secara konsisten menerapkan prinsip modularitas dan penyeragaman struktur ADT[cite: 7, 8]. Mahasiswa juga dilatih mengelola memori secara manual melalui operasi alokasi (new) dan dealokasi (delete) serta memanipulasi keterhubungan tautan pointer antar node baik pada proses penyisipan (insert) maupun penghapusan (delete) tanpa menyebabkan bahaya terputusnya rantai list atau kebocoran memori

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA)</h1>

<p align="center">Farel Juliyandra Restu Hermawan - 109082530038</p>

## Dasar Teori

Singly Linked List merupakan salah satu bentuk Struktur Data Abstrak (ADT) linier berupa serangkaian elemen data (node/simpul) yang saling terhubung menggunakan pointer satu arah. Setiap elemen pada Singly Linked List terdiri dari dua komponen utama, yaitu komponen data/info untuk menyimpan nilai atau informasi, serta komponen suksesor/next berupa pointer yang menunjuk ke alamat elemen berikutnya di dalam memori.

Operasi dasar pada Singly Linked List tidak hanya mencakup inisialisasi list, alokasi memori, dan penambahan atau penghapusan elemen, tetapi juga operasi lanjutan seperti Searching (pencarian node tertentu) dan penelusuran seluruh elemen (traversal). Searching merupakan proses mengunjungi setiap node secara berurutan untuk mencari nilai atau informasi tertentu di dalam list, yang kemudian berhenti ketika node tersebut ditemukan atau list habis ditelusuri. Dengan adanya operasi searching, fungsi-fungsi manipulasi lanjutan seperti pembaruan data (update) atau penghapusan berdasarkan kondisi tertentu dapat dilakukan dengan lebih mudah dan efisien.  

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

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

void updateFirst(linkedlist &list);
void updateLast(linkedlist &list);
void updateAfter(linkedlist list, address &prev);
void updateByNim(linkedlist &list, string nim);

address FindNodeByData(linkedlist List, string data);
#endif
```
File header ini berfungsi sebagai wadah spesifikasi tipe data dan prototipe fungsi/prosedur untuk ADT Singly Linked List dengan struktur data kompleks (mahasiswa). Di dalamnya dideklarasikan struct mahasiswa sebagai dataMahasiswa, struktur simpul node dengan komponen isidata dan pointer next, serta struktur linkedlist yang memiliki pointer penunjuk first. Selain itu, terdapat deklarasi fungsi validator isEmpty, konstruktor createList, fungsi manajemen memori (alokasi & dealokasi), prosedur penambahan (insertFirst, insertAfter, insertLast), penghapusan (delFirst, delLast, delAfter), pembaruan data (update), serta fungsi pencarian lanjutan (FindNodeByData).   

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
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
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
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
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
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist &list)
{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;
    list.first->isidata = newData;
}

void updateLast(linkedlist &list)
{
    if (isEmpty(list))
    {
        cout << "List kosong!" << endl;
        return;
    }else{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    address nodeBantu = list.first;
    while (nodeBantu->next != Nil)
    {
        nodeBantu = nodeBantu->next;
    }

    nodeBantu->isidata = newData;
    }
}

void updateAfter(linkedlist list, address &prev)
{
    if (isEmpty(list))
    {
        cout << "List kosong!" << endl;
    }else{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    prev->next->isidata = newData;
    }
}

void updateByNim(linkedlist &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = FindNodeByData(list, nim);

        if (nodeBantu != Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> newData.nama;
            cout << "Masukan nim baru : ";
            cin >> newData.nim;
            cout << "Masukan umur baru : ";
            cin >> newData.umur;

            nodeBantu->isidata = newData;
        }
    }else
    {
        cout << "List kosong!" << endl;
    }
}

// prosedur-prosedur untuk searching data didalam list
address FindNodeByData(linkedlist List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                return nodeBantu;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodeByAddress(linkedlist List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node  << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur > nilaiAwal && umur < nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```
File implementasi ini merealisasikan fungsi dan prosedur kompleks pada Guided, termasuk manajemen memori dinamis (alokasi dan dealokasi), berbagai variasi penyisipan (insertFirst, insertAfter, insertLast), penelusuran data (printList), serta fitur pembaruan dan pencarian node berdasarkan data tertentu.

### C. File Driver (main.cpp)
```C++
#include "list.h"
#include <iostream>
using namespace std;

int main(){
		linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
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

    updateFirst(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE FIRST ---" << endl;
    printList(List);

    updateLast(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    printList(List);

    updateAfter(List, nodeC);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER ---" << endl;
    printList(List);

    updateByNim(List, "2211102173");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);
    return 0;
}
```
File driver utama Guided menguji alur pembuatan list mahasiswa, penyisipan dengan berbagai posisi (insertFirst, insertLast, insertAfter), pengecekan jumlah node, serta pengujian fungsi pembaruan data (updateAfter dan updateByNim).

Penjelasan Keseluruhan Program Guided :
Program ini mendemonstrasikan implementasi Struktur Data Abstrak (ADT) Singly Linked List dengan struktur data kompleks berupa data mahasiswa (nama, NIM, dan umur) serta manajemen memori dinamis di C++. Berbagai prosedur dan fungsi primitif seperti inisialisasi list (createList), alokasi dan dealokasi memori secara aman, penambahan node di berbagai posisi (insertFirst, insertLast, insertAfter), penghapusan node, pembaruan data (update), hingga pencarian node lanjutan (FindNodeByData, FindNodeByAddress, FindNodeByRange) dijalankan secara modular menggunakan pemisahan file header dan file implementasi.

## Unguided

### 1. Deklarasi ADT dan Operasi Dasar Singly Linked List
### A. File Header (Singlylist.h)

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#define Nil NULL

typedef int infotype;

typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

address findElm(List L, infotype x);
int sumInfo(List L);

#endif
```
File header ini mendefinisikan ADT Singly Linked List bertipe data integer sesuai spesifikasi latihan praktikum modul 5. Di dalamnya terdapat struktur elmlist, tipe pointer address, struktur List, serta deklarasi fungsi pencarian (findElm) dan penjumlahan nilai (sumInfo).   

### B. File Implementasi (Singlylist.cpp)
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

int sumInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}
```
File implementasi ini merealisasikan fungsi dasar list seperti pembuatan list kosong, manajemen alokasi memori dinamis, penelusuran cetak data, penyisipan elemen di awal (insertFirst), serta penambahan fungsi pencarian node (findElm) dan kalkulasi total nilai keseluruhan elemen (sumInfo).   

### C. File Driver (main.cpp)
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

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
    
    cout << "=== LATIHAN 2: PRINT INFO ===" << endl;
    printInfo(L);
    cout << endl;
    
    cout << "=== LATIHAN 3: SEARCHING ===" << endl;
    address found = findElm(L, 8);
    if (found != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }
    cout << endl;
    
    cout << "=== LATIHAN 4: TOTAL INFO ===" << endl;
    int total = sumInfo(L);
    cout << "Total info dari kelima elemen adalah " << total << endl;
    
    return 0;
}
```
File driver utama unguided mengeksekusi urutan penyisipan data 2, 0, 8, 12, 9 menggunakan insertFirst sehingga menghasilkan urutan cetak 9 12 8 0 2, dilanjutkan dengan pengujian modul pencarian angka 8 serta fungsi penjumlahan total nilai seluruh elemen yang menghasilkan nilai 31.  

Penjelasan Keseluruhan Program Unguided :
Program ini mendemonstrasikan manipulasi dasar Singly Linked List bertipe data integer serta penerapan operasi penelusuran (traversal) di C++. Prosedur penyisipan memanfaatkan alokasi memori dinamis menggunakan operator new dan penambahan elemen di awal list (insertFirst), yang kemudian diintegrasikan dengan fungsi pencarian elemen tertentu (findElm) untuk memeriksa keberadaan nilai di dalam rantai node serta fungsi akumulasi (sumInfo) untuk menghitung total keseluruhan nilai info dari seluruh elemen list secara efisien.

### Output Unguided  :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL5/output/outputunguided.png)

## Kesimpulan

Praktikum Modul 5 mengenai Singly Linked List Bagian Kedua ini memperkuat pemahaman mengenai pengoperasian struktur data dinamis, khususnya penerapan teknik penelusuran (traversal), pencarian data (searching), serta kalkulasi agregat pada node-node yang saling terhubung melalui pointer satu arah. Pemisahan kode modular ke dalam file header (.h) dan file implementasi (.cpp) memastikan praktik rekayasa perangkat lunak yang bersih, terstruktur, dan terhindar dari kebocoran memori.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
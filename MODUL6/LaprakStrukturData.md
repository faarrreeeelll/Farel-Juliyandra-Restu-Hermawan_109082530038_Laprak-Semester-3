# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>

<p align="center">Farel Juliyandra Restu Hermawan - 109082530038</p>

## Dasar Teori

Doubly Linked List adalah linked list yang masing-masing elemennya memiliki 2 buah successor, yaitu successor yang menunjuk pada elemen sebelumnya (prev) dan successor yang menunjuk pada elemen sesudahnya (next). Doubly linked list juga menggunakan dua buah pointer utama yang terdapat pada list, yaitu first (pointer yang menunjuk elemen pertama) dan last (pointer yang menunjuk elemen terakhir).

Komponen-komponen dalam Doubly Linked List:

1. First: Pointer pada list yang menunjuk pada elemen pertama list.
2. Last: Pointer pada list yang menunjuk pada elemen terakhir list.
3. Next: Pointer pada elemen sebagai successor yang menunjuk pada elemen di depannya.
4 Prev: Pointer pada elemen sebagai successor yang menunjuk pada elemen di belakangnya.

Proses manipulasi data pada Doubly Linked List meliputi operasi penambahan (insert), penghapusan (delete), pembaruan data (update), serta pencarian data (searching).

## Guided

### 1. Deklarasi ADT dan Operasi Dasar Doubly Linked List
### A. File Header (listMakanan.h)

```C++
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include <iostream>
using namespace std;

struct makanan
{
    string nama;
    string jenis;
    float harga;
    float rating;
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node
{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist
{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```
File header ini berfungsi sebagai wadah spesifikasi tipe data dan prototipe fungsi/prosedur untuk ADT Doubly Linked List dengan struktur data kompleks (makanan). Di dalamnya dideklarasikan struct makanan sebagai dataMakanan, struktur simpul node dengan komponen isidata serta dua pointer penunjuk (next dan prev), dan struktur linkedlist yang memiliki pointer first dan last. Selain itu, terdapat deklarasi fungsi validator isEmpty, konstruktor createList, fungsi manajemen memori (alokasi & dealokasi), prosedur penambahan (insertFirst, insertLast, insertAfter, insertBefore), pencetakan (printList), pembaruan data (update), searching (findByName, findByJenis, findByMinRating), serta berbagai variasi fungsi penghapusan data.

### B. File Implementasi (list.cpp)
```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

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

void createList(linkedlist &List)
{
    List.first = Nil;
    List.last = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis;
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating = rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodePrev != Nil)
        {
            if (nodePrev == List.last)
            {
                insertLast(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodeNext != Nil)
        {
            if (nodeNext == List.first)
            {
                insertFirst(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl;
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); 
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); 
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); 
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodeNext != Nil && nodeNext->prev != Nil)
        {
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); 
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.nama == nama)
        {
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.jenis == jenis)
        {
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.rating >= minRating)
        {
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if (List.first == List.last)
    {
        List.first = List.last = Nil;
    }
    else
    {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if (List.first == List.last)
    {
        List.first = List.last = Nil;
    }
    else
    {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (Prev == Nil || Prev->next == Nil)
    {
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if (Prev->next == List.last)
    {
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (nodeNext == Nil || nodeNext->prev == Nil)
    {
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if (nodeNext->prev == List.first)
    {
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target)
{
    if (isEmpty(List) == true || target == Nil)
    {
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if (target == List.first)
    {
        deleteFirst(List);
    }
    else if (target == List.last)
    {
        deleteLast(List);
    }
    else
    {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama)
{
    if (isEmpty(List))
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while (target != Nil && target->isidata.nama != nama)
    {
        target = target->next;
    }
    if (target == Nil)
    {
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```
File implementasi ini merealisasikan fungsi dan prosedur kompleks pada Guided, termasuk manajemen memori dinamis (alokasi dan dealokasi), berbagai variasi penyisipan (insertFirst, insertLast, insertAfter, insertBefore), penelusuran data (printList), pembaruan data (updateFirst, updateLast, updateAfter, updateBefore), searching (findByName, findByJenis, findByMinRating), serta penghapusan node aman (deleteFirst, deleteLast, deleteAfter, deleteBefore, deleteByName).

### B. File Implementasi (list.cpp)
```C++
#include "listMakanan.h"
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokisi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");
    findByMinRating(List, 9.0);

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl
         << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```
File driver utama Guided menguji alur pembuatan list makanan, penyisipan dengan berbagai posisi (insertFirst, insertLast, insertAfter, insertBefore), pengujian pembaruan data (update), searching, hingga operasi penghapusan data (deleteByName, deleteFirst, deleteBefore).

Penjelasan Keseluruhan Program Guided :
Program ini mendemonstrasikan implementasi Struktur Data Abstrak (ADT) Doubly Linked List dengan struktur data kompleks berupa data makanan (nama, jenis, harga, dan rating) serta manajemen memori dinamis di C++. Berbagai prosedur dan fungsi primitif seperti inisialisasi list (createList), alokasi dan dealokasi memori secara aman dengan pointer next dan prev, penambahan node di berbagai posisi (insertFirst, insertLast, insertAfter, insertBefore), pembaruan data (update), pencarian node (findByName, findByJenis, findByMinRating), hingga penghapusan node dijalankan secara modular menggunakan pemisahan file header dan file implementasi.

## Unguided

### 1. Deklarasi ADT dan Operasi Dasar Doubly Linked List
### A. File Header (Doublylist.h)

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

using namespace std;

#define Nil NULL

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kendaraan infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct list {
    address first;
    address last;
};

void CreateList(list &L);
address alokasi(infotype X);
void dealokasi(address &P);
address findElm(list L, string nopol);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(address Prec, address &P);
void printInfo(list L);

#endif
```
File header ini mendefinisikan ADT Doubly Linked List bertipe data kendaraan (nopol, warna, thnBuat) sesuai spesifikasi latihan praktikum modul 6. Di dalamnya terdapat struktur elmlist dengan dua successor (next dan prev), tipe pointer address, struktur list dengan pointer first dan last, serta deklarasi fungsi pencarian (findElm), alokasi, dealokasi, insertFirst, insertLast, deleteFirst, deleteLast, dan deleteAfter.

### B. ile Implementasi & Operasi Dasar (Insert & Delete)
```C++
#include "Doublylist.h"

void CreateList(list &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype X) {
    address P = new elmlist;
    if (P != Nil) {
        P->info = X;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

address findElm(list L, string nopol) {
    address P = L.first;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void insertFirst(list &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(list &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirst(list &L, address &P) {
    P = L.first;
    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.first = L.first->next;
        L.first->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(list &L, address &P) {
    P = L.last;
    if (L.first == L.last) {
        L.first = Nil;
        L.last = Nil;
    } else {
        L.last = L.last->prev;
        L.last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        } else {
            
        }
        P->next = Nil;
        P->prev = Nil;
    }
}

void printInfo(list L) {
    address P = L.first;
    if (P == Nil) {
        cout << "List Kosong" << endl;
    } else {
        while (P != Nil) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl;
            P = P->next;
        }
    }
}
```
File implementasi ini merealisasikan fungsi dasar Doubly Linked List seperti pembuatan list kosong (CreateList), alokasi memori dinamis, penelusuran cetak data (printInfo), penyisipan elemen (insertFirst, insertLast), pencarian elemen (findElm), serta variasi prosedur penghapusan elemen (deleteFirst, deleteLast, deleteAfter).

### C. File Driver (main.cpp)
```C++
#include "Doublylist.h"

int main() {
    list L;
    CreateList(L);
    infotype X;
    address P;
    int n = 3; 

    int insertedCount = 0;
    while (insertedCount < 3) {
        cout << "masukkan nomor polisi: ";
        cin >> X.nopol;
        
        if (findElm(L, X.nopol) != Nil) {
            cout << "masukkan warna kendaraan: ";
            cin >> X.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> X.thnBuat;
            cout << "nomor polisi sudah terdaftar" << endl;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> X.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> X.thnBuat;

        P = alokasi(X);
        if (P != Nil) {
            insertFirst(L, P);
            insertedCount++;
        }
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    string cariNopol;
    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cariNopol;
    address found = findElm(L, cariNopol);
    if (found != Nil) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    cin >> hapusNopol;
    
    address target = findElm(L, hapusNopol);
    if (target != Nil) {
        address delP = Nil;
        if (target == L.first) {
            deleteFirst(L, delP);
        } else if (target == L.last) {
            deleteLast(L, delP);
        } else {
            deleteAfter(target->prev, delP);
        }
        dealokasi(delP);
        cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    return 0;
}
```
File driver utama unguided mengeksekusi alur input data kendaraan dengan penanganan duplikasi nomor polisi menggunakan findElm dan penyisipan insertFirst, dilanjutkan dengan pengujian pencarian data nomor polisi D001 serta penghapusan nomor polisi D003 yang menghasilkan daftar kendaraan terbarukan.

Penjelasan Keseluruhan Program Unguided :
Program ini mendemonstrasikan manipulasi Doubly Linked List bertipe data kendaraan (nomor polisi, warna, tahun buat) serta penerapan operasi penelusuran (traversal) di C++. Prosedur penyisipan memanfaatkan alokasi memori dinamis dan penambahan di awal list (insertFirst), yang diintegrasikan dengan fungsi pencarian (findElm) untuk mendeteksi nomor polisi duplikat saat input data serta mempermudah operasi pencarian dan penghapusan data secara presisi.

### Output Unguided  :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL6/output/outputunguided1.png)

![Screenshot Output Unguided 2_1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL6/output/outputunguided2.png)

## Kesimpulan

Praktikum Modul 6 mengenai Doubly Linked List Bagian Pertama ini memperkuat pemahaman mengenai pengoperasian struktur data dinamis berpenunjuk ganda (next dan prev). Adanya dua pointer successor ini memberikan kemudahan dalam proses penelusuran dua arah (maju dan mundur) serta manipulasi simpul di sembarang posisi. Pemisahan kode modular ke dalam file header (.h), file implementasi (.cpp), dan file driver (main.cpp) memastikan praktik rekayasa perangkat lunak yang bersih, terstruktur, dan terhindar dari kebocoran memori.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
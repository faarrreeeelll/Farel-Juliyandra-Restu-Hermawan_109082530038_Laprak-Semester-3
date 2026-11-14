# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>

<p align="center">Farel Juliyandra Restu Hermawan - 109082530038</p>

## Dasar Teori

Stack adalah salah satu bentuk struktur data linear yang menerapkan prinsip seperti tumpukan, di mana elemen yang terakhir kali masuk ke dalam tumpukan akan menjadi elemen pertama yang diambil atau dikeluarkan terlebih dahulu. Prinsip operasi ini dikenal sebagai LIFO (Last In First Out). Berbeda dengan linked list biasa yang memungkinkan akses di berbagai posisi, akses data pada stack hanya dapat dilakukan pada bagian paling atas saja yang disebut Top.

Implementasi struktur data stack dapat dilakukan menggunakan dua pendekatan:
1. Representasi Pointer: Menggunakan linked list dinamis di mana setiap elemen saling terhubung melalui pointer next, serta memiliki komponen utama Top yang menunjuk pada elemen paling awal.
2. Representasi Tabel: Menggunakan array berindeks dengan kapasitas maksimum tertentu (Imax atau MAX) dan penanda indeks Top untuk melacak posisi elemen teratas.

Operasi-operasi dalam Stack:
1. CreateStack: Menginisialisasi stack baru dalam kondisi kosong.
2. IsEmpty dan IsFull: Memeriksa apakah stack dalam keadaan kosong atau sudah penuh (khusus representasi tabel).
3. Push: Operasi menyisipkan atau menambahkan elemen baru pada posisi paling atas (Top).
4. Pop: Operasi mengambil sekaligus menghapus elemen yang berada pada posisi paling atas (Top).
5. Update, View, dan Searching: Operasi tambahan untuk memperbarui nilai pada posisi tertentu, menampilkan seluruh isi stack, serta mencari data di dalam stack.

## Guided

1. ### Implementasi ADT Stack Menggunakan Array (Representasi Tabel)
### A. File Header (stack.h)

```C++
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top;
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);
void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
```
File header ini berfungsi sebagai spesifikasi tipe data dan prototipe fungsi/prosedur untuk ADT Stack berbasis array statis dengan kapasitas maksimum MAX = 10. Di dalamnya dideklarasikan struct stackTable yang memiliki array data[MAX] dan penanda indeks teratas top, beserta fungsi validator (isEmpty, isFull), konstruktor (createStack), dan prosedur manipulasi data (push, pop, update, view, searchData).

### B. File Implementasi (stack.cpp)

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s)
{
    return s.top == -1;
}

bool isFull(stackTable s)
{
    return s.top == MAX - 1;
}

void createStack(stackTable &s)
{
    s.top = -1;
}

void push(stackTable &s, int angka)
{
    if (isFull(s))
    {
        cout << "Stack penuh!" << endl;
    }
    else
    {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
        return;
    }
    if (posisi <= 0)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    int idx = s.top - (posisi - 1);
    if (idx < 0 || idx > s.top)
    {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        for (int i = s.top; i >= 0; --i)
        {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for (int i = s.top; i >= 0; --i)
    {
        if (s.data[i] == data)
        {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if (!found)
    {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}
```
File implementasi ini merealisasikan seluruh operasi stack dengan representasi tabel. Stack kosong ditandai dengan nilai s.top = -1. Operasi push menggeser indeks top ke atas sebelum menyimpan data baru, sedangkan pop mengambil nilai pada indeks top lalu menurunkan nilai top. Prosedur update, view, dan searchData menelusuri array dari indeks s.top menuju indeks 0.

### C. File Driver (main.cpp)

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    update(s, 2);
    update(s, 1);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}
```
File driver utama Guided 1 menguji alur pembuatan stack berbasis array, penyisipan lima elemen data, penghapusan dua elemen teratas menggunakan pop, pembaruan data pada posisi tertentu, serta pencarian data di dalam stack.

Penjelasan Keseluruhan Program Guided 1 :
Program ini mendemonstrasikan implementasi Struktur Data Abstrak (ADT) Stack menggunakan representasi array (tabel) berkapasitas tetap di C++. Seluruh proses penambahan, pengambilan, pembaruan, dan pencarian data dikendalikan melalui pergeseran indeks top tanpa memerlukan manajemen memori dinamis.

2. ### Implementasi ADT Stack Menggunakan Pointer (Linked List)
### A. File Header (stack.h)

```C++
#ifndef STACK
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node
{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
File header ini mendefinisikan ADT Stack dengan representasi pointer dinamis. Di dalamnya dideklarasikan struktur simpul node yang menyimpan dataAngka dan pointer next, tipe pointer address, serta struktur stack yang memiliki pointer top untuk menunjuk elemen teratas.

### B. File Implementasi (stack.cpp)

```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack)
{
    if (listStack.top == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createStack(stack &listStack)
{
    listStack.top = Nil;
}

address alokasi(int angka)
{
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru)
{
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack)
{
    address nodeHapus;
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        cout << "Node " << nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
        dealokasi(nodeHapus);
    }
}

void update(stack &listStack, int posisi)
{
    if (isEmpty(listStack) == true)
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        if (posisi == 0)
        {
            cout << "Posisi tidak valid!" << endl;
        }
        else
        {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while (nodeBantu != Nil)
            {
                if (count != posisi)
                {
                    nodeBantu = nodeBantu->next;
                    count++;
                }
                else if (count == posisi)
                {
                    cout << "Update node posisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        while (nodeBantu != Nil)
        {
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data)
{
    if (isEmpty(listStack) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while (nodeBantu != Nil)
        {
            if (nodeBantu->dataAngka == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            }
            else
            {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if (found == false)
        {
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
File implementasi ini merealisasikan operasi stack berbasis pointer beserta manajemen memori dinamis (alokasi dan dealokasi). Operasi push bekerja seperti insert first dengan menyambungkan nodeBaru->next ke listStack.top lalu memindahkan listStack.top ke nodeBaru, sedangkan pop bekerja seperti delete first dengan melepaskan simpul paling atas dan mendealokasikan memorinya.

### C. File Driver (main.cpp)

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
File driver utama Guided 2 menguji alokasi simpul dinamis, penyisipan lima simpul ke dalam stack, pencetakan elemen dari top, penghapusan dua simpul teratas, pembaruan data pada posisi ke-2, ke-1, dan ke-4, serta pencarian data.

Penjelasan Keseluruhan Program Guided 2 :
Program ini mendemonstrasikan implementasi ADT Stack menggunakan representasi pointer dinamis di C++. Berbeda dengan representasi array yang kapasitasnya terbatas, pendekatan pointer memungkinkan ukuran tumpukan bertambah secara dinamis selama memori tersedia, dengan memanfaatkan prinsip insert first untuk push dan delete first untuk pop.

## Unguided

1. ### Implementasi ADT Stack Menggunakan Array
### A. File Header (stack.h)

```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```
File header ini mendefinisikan ADT Stack menggunakan array berkapasitas 20 elemen bertipe infotype (integer) sesuai spesifikasi latihan modul 7. Selain fungsi dan prosedur dasar (createStack, isEmpty, isFull, push, pop, printInfo, dan balikStack), ditambahkan pula prototipe prosedur pushAscending untuk penyisipan terurut menaik serta getInputStream untuk membaca aliran input karakter dari pengguna.

### B. File Implementasi (stack.cpp)

```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == 19;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i];
        if (i > 0) {
            cout << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp1, temp2;
    createStack(temp1);
    createStack(temp2);

    while (!isEmpty(S)) {
        push(temp1, pop(S));
    }
    while (!isEmpty(temp1)) {
        push(temp2, pop(temp1));
    }
    while (!isEmpty(temp2)) {
        push(S, pop(temp2));
    }
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }
    push(S, x);
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char ch = cin.get();
    while (ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            push(S, ch - '0');
        }
        ch = cin.get();
    }
}
```
File implementasi ini merealisasikan seluruh primitif dan operasi tambahan pada latihan modul 7. Prosedur balikStack membalik urutan elemen dengan memindahkan isi stack melalui dua stack sementara (temp1 dan temp2). Prosedur pushAscending memindahkan sementara elemen yang lebih besar dari x ke stack temp sebelum menyisipkan x sehingga elemen tersusun menaik dari dasar ke puncak. Prosedur getInputStream membaca karakter satu per satu menggunakan cin.get() hingga tombol Enter ditekan dan memasukkannya ke dalam stack.

### C. File Driver (main.cpp)

```C++
#include "stack.h"

int main() {
    {
        cout << "Hello world!" << endl;
        Stack S;
        createStack(S);
        push(S, 3);
        push(S, 4);
        push(S, 8);
        pop(S);
        push(S, 2);
        push(S, 3);
        pop(S);
        push(S, 9);
        printInfo(S);
        cout << "balik stack" << endl;
        balikStack(S);
        printInfo(S);
    }

    cout << endl;

    {
        cout << "Hello world!" << endl;
        Stack S;
        createStack(S);
        pushAscending(S, 3);
        pushAscending(S, 4);
        pushAscending(S, 8);
        pushAscending(S, 2);
        pushAscending(S, 3);
        pushAscending(S, 9);
        printInfo(S);
        cout << "balik stack" << endl;
        balikStack(S);
        printInfo(S);
    }

    cout << endl;

    {
        cout << "Hello world!" << endl;
        Stack S;
        createStack(S);
        getInputStream(S);
        printInfo(S);
        cout << "balik stack" << endl;
        balikStack(S);
        printInfo(S);
    }

    return 0;
}
```
File driver utama Unguided menguji ketiga bagian latihan modul 7 secara berurutan di dalam satu file main.cpp. Pengujian pertama menjalankan kombinasi operasi push, pop, printInfo, dan balikStack; pengujian kedua menguji penyisipan terurut melalui pushAscending dan pembalikan stack; serta pengujian ketiga membaca aliran karakter dari input pengguna menggunakan getInputStream hingga tombol Enter ditekan sebelum menampilkan dan membalik isi stack.

Penjelasan Keseluruhan Program Unguided :
Program ini mengimplementasikan ADT Stack berbasis array berkapasitas 20 elemen secara modular dengan pemisahan stack.h, stack.cpp, dan main.cpp. Seluruh operasi lanjutan seperti pembalikan urutan tumpukan (balikStack), penyisipan terurut menaik (pushAscending), dan pembacaan aliran karakter (getInputStream) diselesaikan dengan memanfaatkan stack sementara agar tetap mematuhi aturan akses tunggal pada elemen TOP.

### Output Unguided  :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL7/output/outputsoal1.png)

##### Output 2

![Screenshot Output Unguided 2](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL7/output/outputsoal2.png)

##### Output 3

![Screenshot Output Unguided 3](https://github.com/faarrreeeelll/Farel-Juliyandra-Restu-Hermawan_109082530038_Laprak-Semester-3/blob/main/MODUL7/output/outputsoal3.png)

## Kesimpulan

Praktikum Modul 7 mengenai Stack memberikan pemahaman mengenai pengoperasian struktur data bertipe LIFO (Last In First Out) di mana seluruh akses penyisipan (push) dan pengambilan (pop) hanya dilakukan melalui satu ujung, yaitu Top. Implementasi stack menggunakan representasi array (tabel) menawarkan pengelolaan indeks yang sederhana tanpa manajemen memori dinamis namun terbatas kapasitasnya, sedangkan representasi pointer memberikan fleksibilitas kapasitas memori secara dinamis. Penggunaan stack sementara terbukti efektif untuk membalikkan isi stack maupun menyisipkan data secara terurut tanpa melanggar prinsip dasar LIFO.

## Referensi

[1] Tim Asisten Praktikum Struktur Data. (2024). Modul 7: Stack. Bandung: Fakultas Informatika, Telkom University.
<br>[2] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[3] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
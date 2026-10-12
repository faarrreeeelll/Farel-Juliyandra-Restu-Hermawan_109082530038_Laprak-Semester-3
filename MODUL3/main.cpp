#include <iostream>
#include "buku.h"
using namespace std;

int main ()
{
    buku novel;

    string judul, penulis;
    int halaman;

    cout << "Masukan judul buku : ";
    cin >> judul ;
    cout << "Masukan halaman buku : ";
    cin >> halaman ;
    cout << "Masukan penulis buku : ";
    cin >> penulis ;

    editIsi(judul, halaman, penulis, novel);
    tampilkanIsiBuku(novel);

    cout << checkPenulis(novel);

    return 0;
}
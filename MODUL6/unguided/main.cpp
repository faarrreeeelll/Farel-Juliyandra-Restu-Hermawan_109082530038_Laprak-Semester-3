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
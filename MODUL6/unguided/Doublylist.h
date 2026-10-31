/* File: Doublylist.h */
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
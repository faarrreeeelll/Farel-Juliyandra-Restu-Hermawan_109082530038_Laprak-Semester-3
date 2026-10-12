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
#include <iostream>
#include <string>
#include "pelajaran.h"

using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodemapel = "STD";
    
    pelajaran pel = create_pelajaran(namapel, kodemapel);
    tampil_pelajaran(pel);
    
    return 0;
}
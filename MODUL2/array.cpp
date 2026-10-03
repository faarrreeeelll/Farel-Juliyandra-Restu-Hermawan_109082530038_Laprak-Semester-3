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
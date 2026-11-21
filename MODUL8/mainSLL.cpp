#include "queueSLL.h"
#include <iostream>
using namespace std;

int main (){
    queue Q;
    createQueue(Q);

    enqueue(Q, "Dominic");
    enqueue(Q, "Torr");
    enqueue(Q, "Retto");
    enqueue(Q, "Letty");
    enqueue(Q, "Brian");
    enqueue(Q, "Mia");
    cout << "---Isi Queue sebelum di dequeue:---"<< endl;
    viewQueue(Q);

    cout << "---Isi Queue setelah di dequeue: ---"<< endl;
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    cout << "Isi Queue setelah di dequeue: " << endl;
    viewQueue(Q);
    return 0;
}
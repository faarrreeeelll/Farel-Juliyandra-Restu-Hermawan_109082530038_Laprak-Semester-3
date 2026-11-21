#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "=== ALTERNATIF 1 (Head Diam, Tail Bergerak) ===" << endl;
    {
        Queue Q;
        createQueue(Q);
        cout << "-------------------------" << endl;
        cout << " H - T  | Queue Info" << endl;
        cout << "-------------------------" << endl;
        printInfo1(Q);
        enqueue1(Q, 5); printInfo1(Q);
        enqueue1(Q, 2); printInfo1(Q);
        enqueue1(Q, 7); printInfo1(Q);
        dequeue1(Q);    printInfo1(Q);
        dequeue1(Q);    printInfo1(Q);
        enqueue1(Q, 4); printInfo1(Q);
        dequeue1(Q);    printInfo1(Q);
        dequeue1(Q);    printInfo1(Q);
    }

    cout << endl;

    cout << "=== ALTERNATIF 2 (Head Bergerak, Tail Bergerak) ===" << endl;
    {
        Queue Q;
        createQueue(Q);
        cout << "-------------------------" << endl;
        cout << " H - T  | Queue Info" << endl;
        cout << "-------------------------" << endl;
        printInfo2(Q);
        enqueue2(Q, 5); printInfo2(Q);
        enqueue2(Q, 2); printInfo2(Q);
        enqueue2(Q, 7); printInfo2(Q);
        dequeue2(Q);    printInfo2(Q);
        dequeue2(Q);    printInfo2(Q);
        enqueue2(Q, 4); printInfo2(Q);
        dequeue2(Q);    printInfo2(Q);
        dequeue2(Q);    printInfo2(Q);
    }

    cout << endl;

    cout << "=== ALTERNATIF 3 (Circular Queue) ===" << endl;
    {
        Queue Q;
        createQueue(Q);
        cout << "-------------------------" << endl;
        cout << " H - T  | Queue Info" << endl;
        cout << "-------------------------" << endl;
        printInfo3(Q);
        enqueue3(Q, 5); printInfo3(Q);
        enqueue3(Q, 2); printInfo3(Q);
        enqueue3(Q, 7); printInfo3(Q);
        dequeue3(Q);    printInfo3(Q);
        dequeue3(Q);    printInfo3(Q);
        enqueue3(Q, 4); printInfo3(Q);
        dequeue3(Q);    printInfo3(Q);
        dequeue3(Q);    printInfo3(Q);
    }

    return 0;
}
#include "queueSLL.h"

void createQueue(queue &Q)
{
    Q.head = Q.tail = nullptr;
}

bool isEmpty(queue Q)
{
    return Q.head == nullptr && Q.tail == nullptr;
}

bool isFull(queue Q)
{
    int maxQueue = 20;
    int counter = 0;
    Node *nodeBantu = Q.head;

    while (nodeBantu != Q.tail)
    {
        counter++;
        nodeBantu -> next;
    }

    return counter >= maxQueue;
}

void enqueue(queue &Q, const string &nama)
{
    if (isEmpty(Q)) 
    {
        Node *nodeBaru = new Node{nama, nullptr};
        Q.head = Q.tail = nodeBaru;
    } 
    else 
    {
        Node *nodeBaru = new Node{nama, nullptr};
        Q.tail -> next = nodeBaru;
        Q.tail = nodeBaru;
    }
}

void dequeue(queue &Q)
{
    if (isEmpty(Q)) 
    {
        cout << "Queue kosong";
    }
    else
    {
        Node *nodeHapus = Q.head;
        Q.head = Q.head -> next;
        delete nodeHapus;
    }
}

void viewQueue(queue Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue kosong";
    }
    else
    {
        Node *nodeBantu = Q.head;

        while (nodeBantu != nullptr)
        {
            cout << "Nama : " << nodeBantu -> nama << endl;
            nodeBantu = nodeBantu -> next;
        }
    }
}

void clearQueue(queue &Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue kosong";
    }
    else
    {
        Node *nodeHapus = Q.head;

        while (nodeHapus != nullptr)
        {
            nodeHapus = nodeHapus -> next;
            dequeue(Q);
        }
    }
}
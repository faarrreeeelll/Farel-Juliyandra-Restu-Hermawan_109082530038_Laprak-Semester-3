#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

// Fungsi Umum
void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);

// Alternatif 1 (head diam, tail bergerak)
bool isFullQueue1(Queue Q);
void enqueue1(Queue &Q, infotype x);
infotype dequeue1(Queue &Q);
void printInfo1(Queue Q);

// Alternatif 2 (head bergerak, tail bergerak)
bool isFullQueue2(Queue Q);
void enqueue2(Queue &Q, infotype x);
infotype dequeue2(Queue &Q);
void printInfo2(Queue Q);

// Alternatif 3 (head dan tail berputar / Circular Queue)
bool isFullQueue3(Queue Q);
void enqueue3(Queue &Q, infotype x);
infotype dequeue3(Queue &Q);
void printInfo3(Queue Q);

#endif
//Mendefinisikan struktur data queue menggunakan linked list.
//Dependency: customer.h

#ifndef QUEUE_H
#define QUEUE_H

#include "customer.h"

typedef struct Node {
    Customer customer;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue* q);
void enqueue(Queue* q, Customer customer);
Customer dequeue(Queue* q);
void printQueue(Queue* q);
int isQueueEmpty(Queue* q);

#endif


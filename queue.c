//Berisi implementasi fungsi-fungsi yang dideklarasikan di queue.h.
//Menggunakan linked list untuk menyimpan antrian pelanggan.
//Dependency: queue.h

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

void enqueue(Queue* q, Customer customer) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->customer = customer;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

Customer dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Antrian kosong!\n");
        exit(EXIT_FAILURE);
    }

    Node* temp = q->front;
    Customer removedCustomer = temp->customer;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return removedCustomer;
}

void printQueue(Queue* q) {
    if (q->front == NULL) {
        printf("Antrian kosong!\n");
        return;
    }

    Node* temp = q->front;
    printf("Daftar Antrian:\n");
    while (temp != NULL) {
        printf("Nomor: %d | Nama: %s | Layanan: %s\n",
               temp->customer.id, temp->customer.name, temp->customer.service);
        temp = temp->next;
    }
}

int isQueueEmpty(Queue* q) {
    return q->front == NULL;
}


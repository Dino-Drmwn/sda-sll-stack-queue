// pasien.c

#include <stdio.h>
#include <stdlib.h>  // Tambahan untuk malloc dan free
#include <string.h>
#include "pasien.h"

// Queue (antrian)
char queue[MAX][50];
int front = -1, rear = -1;

// Stack (undo)
char stack[MAX][50];
int top = -1;

// SLL (singly linked list)
typedef struct Node {
    char nama[50];
    struct Node* next;
} Node;

Node* head = NULL;

// Queue functions
void enqueue(char* nama) {
    if (rear == MAX - 1) {
        printf("Antrian penuh!\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    strcpy(queue[rear], nama);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Antrian kosong!\n");
        return;
    }

    char nama[50];
    strcpy(nama, queue[front]);
    pushUndo(nama);
    tambahPasienSelesai(nama);
    front++;
}

void tampilQueue() {
    if (front == -1 || front > rear) {
        printf("Antrian kosong!\n");
        return;
    }

    int i;
    for (i = front; i <= rear; i++) {
        printf("- %s\n", queue[i]);
    }
}

// Stack functions
void pushUndo(char* nama) {
    if (top == MAX - 1) return;
    top++;
    strcpy(stack[top], nama);
}

char* popUndo() {
    if (top == -1) return NULL;
    return stack[top--];
}

int isUndoEmpty() {
    return top == -1;
}

// SLL functions
void tambahPasienSelesai(char* nama) {
    Node* baru = (Node*)malloc(sizeof(Node));
    if (baru == NULL) {
        printf("Gagal alokasi memori.\n");
        return;
    }
    strcpy(baru->nama, nama);
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = baru;
    }
}

void hapusPasienSelesai(char* nama) {
    Node *temp = head, *prev = NULL;
    while (temp != NULL && strcmp(temp->nama, nama) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void tampilPasienSelesai() {
    Node* temp = head;
    if (temp == NULL) {
        printf("(Belum ada pasien yang selesai)\n");
        return;
    }

    while (temp != NULL) {
        printf("- %s\n", temp->nama);
        temp = temp->next;
    }
}


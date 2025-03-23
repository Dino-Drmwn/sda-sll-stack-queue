// pasien.h

#ifndef PASIEN_H
#define PASIEN_H

#define MAX 100

// Queue
void enqueue(char* nama);
void dequeue();
void tampilQueue();

// Stack
void pushUndo(char* nama);
char* popUndo();
int isUndoEmpty();

// SLL (daftar pasien selesai)
void tambahPasienSelesai(char* nama);
void hapusPasienSelesai(char* nama);
void tampilPasienSelesai();

#endif


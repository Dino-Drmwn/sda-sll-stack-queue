// main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pasien.h"

int main() {
    int pilihan;
    char nama[50];

    do {
        printf("\n=== Sistem Antrian Pasien Modular ===\n");
        printf("1. Tambah Pasien ke Antrian\n");
        printf("2. Tampilkan Antrian\n");
        printf("3. Layani Pasien\n");
        printf("4. Undo Pelayanan Terakhir\n");
        printf("5. Tampilkan Pasien Selesai\n");
        printf("6. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &pilihan);
        getchar(); // buang newline

        switch (pilihan) {
            case 1:
                printf("Nama pasien: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
                enqueue(nama);
                break;
            case 2:
                tampilQueue();
                break;
            case 3:
                dequeue();
                break;
            case 4: {
                char* undoNama = popUndo();
                if (undoNama == NULL) {
                    printf("Tidak ada yang bisa di-undo.\n");
                } else {
                    enqueue(undoNama);
                    hapusPasienSelesai(undoNama);
                    printf("Undo berhasil: %s dikembalikan ke antrian.\n", undoNama);
                }
                break;
            }
            case 5:
                tampilPasienSelesai();
                break;
            case 6:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 6);

    return 0;
}


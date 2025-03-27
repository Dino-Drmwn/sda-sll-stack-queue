//Mengatur antarmuka utama pengguna untuk sistem antrian bank.
//Memanggil fungsi-fungsi dari queue.h, customer.h, dan utils.h.
//Dependency:
//queue.h, customer.h, utils.h


#include <stdio.h>
#include "queue.h"
#include "customer.h"
#include "utils.h"

int main() {
    Queue queue;
    initQueue(&queue);
    int choice, id = 1;
    char name[50], service[50];

    while (1) {
        clearScreen();
        printf("=== Sistem Antrian Bank ===\n");
        printf("1. Ambil Antrian\n");
        printf("2. Proses Antrian\n");
        printf("3. Cetak Antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan Nama: ");
                scanf(" %[^\n]", name);
                printf("Masukkan Jenis Layanan: ");
                scanf(" %[^\n]", service);
                enqueue(&queue, createCustomer(id++, name, service));
                printf("Antrian berhasil ditambahkan!\n");
                break;

            case 2:
                if (!isQueueEmpty(&queue)) {
                    Customer served = dequeue(&queue);
                    printf("Melayani Pelanggan: %s (Nomor %d)\n", served.name, served.id);
                } else {
                    printf("Tidak ada antrian.\n");
                }
                break;

            case 3:
                printQueue(&queue);
                break;

            case 4:
                printf("Terima kasih!\n");
                return 0;

            default:
                printf("Pilihan tidak valid!\n");
        }
        pauseProgram();
    }
    return 0;
}


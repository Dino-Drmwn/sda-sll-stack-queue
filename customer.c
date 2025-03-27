//Mengimplementasikan fungsi createCustomer() untuk menginisialisasi data pelanggan.
//Menggunakan strcpy() untuk menyalin string nama dan jenis layanan ke dalam struct Customer.
//Dependency: costumer.h

#include <stdio.h>
#include <string.h>
#include "customer.h"

Customer createCustomer(int id, const char* name, const char* service) {
    Customer newCustomer;
    newCustomer.id = id;
    strcpy(newCustomer.name, name);
    strcpy(newCustomer.service, service);
    return newCustomer;
}


#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct {
    int id;
    char name[50];
    char service[50];
} Customer;

Customer createCustomer(int id, const char* name, const char* service);

#endif


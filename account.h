#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    int account_number;
    char name[100];
    double balance;
} Account;

Account create_account_struct(int account_number, const char *name, double balance);

#endif // ACCOUNT_H

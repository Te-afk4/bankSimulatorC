#include "account.h"

// Define the Account structure
Account create_account_struct(int account_number, const char *name, double balance) {
    Account new_account;
    new_account.account_number = account_number;
    strncpy(new_account.name, name, sizeof(new_account.name) - 1);
    new_account.name[sizeof(new_account.name) - 1] = '\0'; // Ensure null-termination
    new_account.balance = balance;
    return new_account;
}

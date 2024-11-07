#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"
#include "account.h"

#define MAX_ACCOUNTS 100

static Account accounts[MAX_ACCOUNTS];
static int account_count = 0;

void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create more accounts.\n");
        return;
    }

    Account new_account;
    new_account.account_number = account_count + 1; // Simple account number assignment
    printf("Enter account holder's name: ");
    getchar(); // Clear newline from buffer
    fgets(new_account.name, sizeof(new_account.name), stdin);
    new_account.name[strcspn(new_account.name, "\n")] = 0; // Remove newline character
    new_account.balance = 0.0;

    accounts[account_count++] = new_account;
    printf("Account created successfully! Account Number: %d\n", new_account.account_number);
}

void deposit_money() {
    int account_number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    accounts[account_number - 1].balance += amount;
    printf("Deposited %.2lf to account number %d. New balance: %.2lf\n",
           amount, account_number, accounts[account_number - 1].balance);
}

void withdraw_money() {
    int account_number;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (account_number < 1 || account_number > account_count) {
        printf("Invalid account number.\n");
        return;
    }

    if (amount > accounts[account_number - 1].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Withdrew %.2lf from account number %d. New balance: %.2lf\n",
           amount, account_number, accounts[account_number - 1].balance);
}

void view_account_details() {
    int account_number;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    if (account_number < 1 ||


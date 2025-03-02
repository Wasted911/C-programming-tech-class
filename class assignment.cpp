//C++ 
/*
C++ Function to determine library fines
Author: Wambua Ebenezar Muuo
Reg No:BSCIT-05-0153/2024
Date:01/03/2025
Version 1.0
*/
#include <iostream>
#include <string>

class BankAccount {
protected:
    std::string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(const std::string& name, int number, double initialBalance)
        : accountHolderName(name), accountNumber(number), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }

    virtual void display() const {
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};
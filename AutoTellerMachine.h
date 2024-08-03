#ifndef AUTOTELLERMACHINE_H
#define AUTOTELLERMACHINE_H
#include<iostream>
#include <string>

using namespace std;

class AutoTellerMachine {
public:
    void CreateNewAccount(string newUsername, string newPassword);
    bool AccountLogin(string  loginUsername, string loginPassword);
    void DepositMoney(double depositAmount);
    bool WithdrawMoney(double withdrawalAmount);
    void DisplayAccountDetails();

private:
    double accountBalance = 0.0;
    double beginningBalance = 0.0;
    double lastMoneyMovement = 0.0;
    char lastOperation = ' ';
     string username;
     string password;

    friend class ATMSystem;
};

#endif

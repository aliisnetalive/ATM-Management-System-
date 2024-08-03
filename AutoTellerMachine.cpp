#include "AutoTellerMachine.h"
#include <iostream>
#include <iomanip>

using namespace std;
void AutoTellerMachine::CreateNewAccount(string newUsername, string newPassword) {
    username = newUsername;
    password = newPassword;
    accountBalance = 0.0;
    beginningBalance = 0.0;
    lastMoneyMovement = 0.0;
    lastOperation = ' ';
}

bool AutoTellerMachine::AccountLogin(string loginUsername, string loginPassword) {
    return (username == loginUsername && password == loginPassword);
}

void AutoTellerMachine::DepositMoney(double depositAmount) {
    beginningBalance = accountBalance;
    lastMoneyMovement = depositAmount;
    lastOperation = 'd';
    accountBalance += depositAmount;
}

bool AutoTellerMachine::WithdrawMoney(double withdrawalAmount) {
    if (withdrawalAmount > accountBalance) {
        return false;
    }
    beginningBalance = accountBalance;
    lastMoneyMovement = withdrawalAmount;
    lastOperation = 'w';
    accountBalance -= withdrawalAmount;
    return true;
}

void AutoTellerMachine::DisplayAccountDetails()  {
    cout << endl << "Beginning balance: $" << fixed << setprecision(2) << beginningBalance << endl;

    if (lastOperation == 'd') {
        cout << "Deposit amount: $" << fixed << setprecision(2) << lastMoneyMovement << endl;
    } else if (lastOperation == 'w') {
        cout << "Withdrawal amount: $" << fixed << setprecision(2) << lastMoneyMovement << endl;
    }

    cout << "Your balance is $" << fixed << setprecision(2) << accountBalance << endl;
}

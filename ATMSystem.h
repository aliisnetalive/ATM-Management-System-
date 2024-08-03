#ifndef ATMSYSTEM_H
#define ATMSYSTEM_H

#include "AutoTellerMachine.h"
#include <vector>
#include <iostream>
class ATMSystem {
public:
    void UserMenu();
    void AccountMenu();

private:
    std::vector<AutoTellerMachine> AccountList;
    int loggedInAccountLocation = -1;

    void DisplayWelcomeMessage() const;
    void CreateNewAccount();
    void Login();
};

#endif

#include "ATMSystem.h"
#include <iostream>

using namespace std;

void ATMSystem::DisplayWelcomeMessage() const {
    cout << "\t\t\t\t\t WELCOME TO BANK BROTHER \n\n\t\t\t\t\tATM AND BANKING SERVICES" << endl << endl;
    cout << "\n\n\t\t\t Please select an option from the menu below: " << endl << endl;
}

void ATMSystem::UserMenu() {
    char userSelection;

    DisplayWelcomeMessage();

    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl << endl << ">";
    cin >> userSelection;

    switch (userSelection) {
        case 'l':
        case 'L':
            Login();
            break;
        case 'c':
        case 'C':
            CreateNewAccount();
            break;
        case 'q':
        case 'Q':
            cout << endl << "You selected quit!" << endl << endl;
            break;
        default:
            cout << endl << "Invalid selection." << endl;
            UserMenu();
            break;
    }
}

void ATMSystem::CreateNewAccount() {
    string createUserId;
    string createUserPass;

    cout << endl << "Please enter your user name: " << endl;
    cin >> createUserId;
    cout << "Please enter your password: " << endl;
    cin >> createUserPass;

    AutoTellerMachine newAccount;
    newAccount.CreateNewAccount(createUserId, createUserPass);

    AccountList.push_back(newAccount);

    cout << endl << "Thank You! Your account has been created!" << endl << endl;

    UserMenu();
}

void ATMSystem::Login() {
    string usernameCheck;
    string passwordCheck;

    cout << endl << "Please enter your user name: " << endl;
    cin >> usernameCheck;
    cout << "Please enter your password: " << endl;
    cin >> passwordCheck;

    for (size_t i = 0; i < AccountList.size(); ++i) {
        if (AccountList[i].AccountLogin(usernameCheck, passwordCheck)) {
            loggedInAccountLocation = i;
            AccountMenu();
            return;
        }
    }

    cout << endl << "******** LOGIN FAILED! ********" << endl << endl;
    UserMenu();
}

void ATMSystem::AccountMenu() {
    if (loggedInAccountLocation == -1) {
        cout << "No account is currently logged in." << endl;
        return;
    }

    char userInput;
    double amount;

    cout << endl << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "z -> Logout" << endl;
    cout << "q -> Quit" << endl;
    cout << endl << ">";
    cin >> userInput;

    switch (userInput) {
        case 'd':
        case 'D':
            cout << endl << "Amount of deposit: " << endl;
            cin >> amount;
            AccountList[loggedInAccountLocation].DepositMoney(amount);
            AccountMenu();
            break;
        case 'w':
        case 'W':
            cout << endl << "Amount of withdrawal: " << endl;
            cin >> amount;
            if (!AccountList[loggedInAccountLocation].WithdrawMoney(amount)) {
                cout << endl << "******Insufficient Funds!*******" << endl;
            }
            AccountMenu();
            break;
        case 'r':
        case 'R':
            AccountList[loggedInAccountLocation].DisplayAccountDetails();
            AccountMenu();
            break;
        case 'z':
        case 'Z':
            cout << endl << "You have successfully logged out, " << AccountList[loggedInAccountLocation].username << "!" << endl << endl;
            loggedInAccountLocation = -1;
            UserMenu();
            break;
        case 'q':
        case 'Q':
            cout << endl << "Thanks for banking, " << AccountList[loggedInAccountLocation].username << "!" << endl;
            break;
        default:
            cout << endl << "Invalid selection." << endl;
            AccountMenu();
            break;
    }
}

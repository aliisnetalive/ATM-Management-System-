
# ATM Banking System

This project implements a basic ATM banking system with the following features:
- Create new account
- Login to an existing account
- Deposit money
- Withdraw money
- Request balance

The program is written in C++ and is split into separate class and implementation files for better organization and maintainability.

## File Structure

- `AutoTellerMachine.h` - Header file containing the declaration of the `AutoTellerMachine` class.
- `AutoTellerMachine.cpp` - Source file containing the implementation of the `AutoTellerMachine` class.
- `ATMSystem.h` - Header file containing the declaration of the `ATMSystem` class.
- `ATMSystem.cpp` - Source file containing the implementation of the `ATMSystem` class.
- `main.cpp` - The main entry point of the program.

## Classes

### AutoTellerMachine

The `AutoTellerMachine` class represents an individual ATM account with the following functionalities:
- `CreateNewAccount` - Creates a new account with a username and password.
- `AccountLogin` - Authenticates a user with a username and password.
- `DepositMoney` - Deposits a specified amount into the account.
- `WithdrawMoney` - Withdraws a specified amount from the account if sufficient funds are available.
- `DisplayAccountDetails` - Displays the account balance, last operation, and last money movement.

### ATMSystem

The `ATMSystem` class manages multiple `AutoTellerMachine` accounts and provides a menu-driven user interface with the following functionalities:
- `UserMenu` - Displays the main menu for user actions such as login, create account, and quit.
- `AccountMenu` - Displays the menu for logged-in users to perform operations such as deposit, withdraw, request balance, logout, and quit.

## How to Compile and Run

To compile and run the program, use the following commands in your terminal:

```sh
g++ -o atm main.cpp AutoTellerMachine.cpp ATMSystem.cpp
./atm
```

## Usage

Upon running the program, you will be presented with a menu that allows you to:
1. Login to an existing account
2. Create a new account
3. Quit the program

After logging in, you will have the following options:
1. Deposit Money
2. Withdraw Money
3. Request Balance
4. Logout
5. Quit

## Example

```
                WELCOME TO BANK BROTHER 

                ATM AND BANKING SERVICES



        Please select an option from the menu below: 

l -> Login
c -> Create New Account
q -> Quit

> c

Please enter your user name: 
JohnDoe
Please enter your password: 
password123

Thank You! Your account has been created!

l -> Login
c -> Create New Account
q -> Quit

> l

Please enter your user name: 
JohnDoe
Please enter your password: 
password123

Access Granted - JohnDoe

d -> Deposit Money
w -> Withdraw Money
r -> Request Balance
z -> Logout
q -> Quit

> d

Amount of deposit: 
1000

d -> Deposit Money
w -> Withdraw Money
r -> Request Balance
z -> Logout
q -> Quit

> r

Beginning balance: $0.00
Deposit amount: $1000.00
Your balance is $1000.00
```

## License

This project is open-source and available under the MIT License.

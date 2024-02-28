#include <iostream>
#include <cstdlib> // For exit()

class BankAccount {
private:
    std::string userId;
    std::string password;
    double balance;

public:
    BankAccount(const std::string& id, const std::string& pass) : userId(id), password(pass), balance(0.0) {}

    bool login(const std::string& enteredId, const std::string& enteredPass) {
        return userId == enteredId && password == enteredPass;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

void printIntroMenu() {
    std::cout << "Options:" << std::endl;
    std::cout << "l: Login" << std::endl;
    std::cout << "c: Create Account" << std::endl;
    std::cout << "q: Quit" << std::endl;
}

void login(BankAccount& account) {
    std::string enteredId, enteredPass;
    std::cout << "Enter User ID: ";
    std::cin >> enteredId;
    std::cout << "Enter Password: ";
    std::cin >> enteredPass;

    if (account.login(enteredId, enteredPass)) {
        char choice;
        do {
            std::cout << "Logged in successfully! Choose an option:" << std::endl;
            std::cout << "1: Withdraw Money" << std::endl;
            std::cout << "2: Deposit Money" << std::endl;
            std::cout << "3: Request Balance" << std::endl;
            std::cout << "4: Quit" << std::endl;
            std::cin >> choice;

            switch (choice) {
                case '1': {
                    double amount;
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;
                    account.withdraw(amount);
                    break;
                }
                case '2': {
                    double amount;
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;
                    account.deposit(amount);
                    break;
                }
                case '3':
                    std::cout << "Balance: $" << account.getBalance() << std::endl;
                    break;
                case '4':
                    std::cout << "Quitting program..." << std::endl;
                    exit(0);
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (true);
    } else {
        std::cout << "Login failed. Returning to the main menu." << std::endl;
    }
}

void createAccount(BankAccount& account) {
    std::string newId, newPassword;
    std::cout << "Enter a new User ID: ";
    std::cin >> newId;
    std::cout << "Enter a new Password: ";
    std::cin >> newPassword;

    account = BankAccount(newId, newPassword);
    std::cout << "Account created successfully!" << std::endl;
}

void start(BankAccount& account) {
    char choice;

    do {
        std::cout << "Please select an option from the menu below:" << std::endl;
        printIntroMenu();

        std::cin >> choice;

        switch (choice) {
            case 'l':
                login(account);
                break;
            case 'c':
                createAccount(account);
                break;
            case 'q':
                std::cout << "Quitting program..." << std::endl;
                exit(0);
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (true);
}

int main() {
    BankAccount userAccount("default", "password"); // Initial account with default values
    start(userAccount);
return 0;
}   

// ============================================================
// Task 3: Bank Account Simulation
// CodSoft C++ Internship
// Concepts: classes, encapsulation, vectors, validation.
// Features: deposit, withdraw, balance check, transaction history.
// ============================================================
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// One record in the transaction history.
struct Transaction {
    string type;          // "Deposit", "Withdrawal" or "Opening"
    double amount;
    double balanceAfter;
};

class BankAccount {
private:                               // data is hidden (encapsulation)
    int accountNumber;
    string holderName;
    double balance;
    vector<Transaction> history;

public:
    BankAccount(int number, const string& name, double openingBalance)
        : accountNumber(number), holderName(name), balance(openingBalance) {
        Transaction t = {"Opening", openingBalance, balance};
        history.push_back(t);
    }

    // Returns true on success, false if the amount is invalid.
    bool deposit(double amount) {
        if (amount <= 0) return false;
        balance += amount;
        Transaction t = {"Deposit", amount, balance};
        history.push_back(t);
        return true;
    }

    // Returns true on success, false if amount is invalid or funds are insufficient.
    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount;
        Transaction t = {"Withdrawal", amount, balance};
        history.push_back(t);
        return true;
    }

    double getBalance() const { return balance; }

    void showDetails() const {
        cout << "\nAccount Number : " << accountNumber << "\n";
        cout << "Account Holder : " << holderName << "\n";
        cout << "Balance        : " << balance << "\n";
    }

    void showHistory() const {
        cout << "\n------------- Transaction History -------------\n";
        cout << left << setw(5) << "No." << setw(14) << "Type"
             << setw(14) << "Amount" << "Balance After\n";
        cout << "-----------------------------------------------\n";
        for (size_t i = 0; i < history.size(); i++) {
            cout << left << setw(5) << i + 1 << setw(14) << history[i].type
                 << setw(14) << history[i].amount << history[i].balanceAfter << "\n";
        }
    }
};

// ---------- Input helpers ----------
string readLine(const string& prompt) {
    string line;
    cout << prompt;
    if (!getline(cin, line)) { cout << "\nInput ended.\n"; exit(0); }
    return line;
}

int readInt(const string& prompt, int low, int high) {
    while (true) {
        stringstream ss(readLine(prompt));
        int v; char extra;
        if (ss >> v && !(ss >> extra) && v >= low && v <= high) return v;
        cout << "  Enter a whole number from " << low << " to " << high << ".\n";
    }
}

double readAmount(const string& prompt, bool allowZero) {
    while (true) {
        stringstream ss(readLine(prompt));
        double v; char extra;
        if (ss >> v && !(ss >> extra) && (allowZero ? v >= 0 : v > 0)) return v;
        cout << "  Enter a valid " << (allowZero ? "non-negative" : "positive") << " amount.\n";
    }
}

string readName(const string& prompt) {
    while (true) {
        string name = readLine(prompt);
        size_t start = name.find_first_not_of(" \t");
        size_t end = name.find_last_not_of(" \t");
        if (start != string::npos) return name.substr(start, end - start + 1);
        cout << "  Name cannot be empty.\n";
    }
}

void showMenu() {
    cout << "\n==============================\n";
    cout << "     BANK ACCOUNT SIMULATION\n";
    cout << "==============================\n";
    cout << " 1. Deposit money\n";
    cout << " 2. Withdraw money\n";
    cout << " 3. Check balance\n";
    cout << " 4. Account details\n";
    cout << " 5. Transaction history\n";
    cout << " 6. Exit\n";
    cout << "------------------------------\n";
}

int main() {
    cout << fixed << setprecision(2);
    cout << "Welcome! Let's create your account.\n";
    int number = readInt("Enter account number (1-999999): ", 1, 999999);
    string name = readName("Enter account holder name: ");
    double opening = readAmount("Enter opening balance (0 or more): ", true);

    BankAccount account(number, name, opening);
    cout << "Account created successfully.\n";

    while (true) {
        showMenu();
        int choice = readInt("Choose an option (1-6): ", 1, 6);
        switch (choice) {
            case 1: {
                double amt = readAmount("Enter amount to deposit: ", false);
                if (account.deposit(amt))
                    cout << "Deposited " << amt << ". New balance: " << account.getBalance() << "\n";
                else
                    cout << "Deposit failed.\n";
                break;
            }
            case 2: {
                double amt = readAmount("Enter amount to withdraw: ", false);
                if (account.withdraw(amt))
                    cout << "Withdrew " << amt << ". New balance: " << account.getBalance() << "\n";
                else
                    cout << "Withdrawal failed: insufficient balance (available "
                         << account.getBalance() << ").\n";
                break;
            }
            case 3:
                cout << "Current balance: " << account.getBalance() << "\n";
                break;
            case 4:
                account.showDetails();
                break;
            case 5:
                account.showHistory();
                break;
            case 6:
                cout << "Thank you for banking with us. Goodbye!\n";
                return 0;
        }
    }
}

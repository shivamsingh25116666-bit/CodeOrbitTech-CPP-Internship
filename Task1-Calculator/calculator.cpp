// ============================================================
// Task 1: Simple Calculator
// CodSoft C++ Internship
// Features: + - * / , decimal numbers, input validation,
//           division-by-zero protection, repeat until exit.
// ============================================================
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

// Reads a whole line and accepts it only if it is a valid number.
// Keeps asking until the user types something valid.
double readNumber(const string& prompt) {
    string line;
    while (true) {
        cout << prompt;
        if (!getline(cin, line)) {          // input stream closed (Ctrl+D / end of file)
            cout << "\nInput ended. Goodbye!\n";
            exit(0);
        }
        stringstream ss(line);
        double value;
        char extra;
        if (ss >> value && !(ss >> extra))  // number found and nothing else after it
            return value;
        cout << "  Invalid number. Please try again.\n";
    }
}

// Reads a menu choice between low and high (inclusive).
int readChoice(const string& prompt, int low, int high) {
    string line;
    while (true) {
        cout << prompt;
        if (!getline(cin, line)) {
            cout << "\nInput ended. Goodbye!\n";
            exit(0);
        }
        stringstream ss(line);
        int value;
        char extra;
        if (ss >> value && !(ss >> extra) && value >= low && value <= high)
            return value;
        cout << "  Please enter a number from " << low << " to " << high << ".\n";
    }
}

void showMenu() {
    cout << "\n==============================\n";
    cout << "        SIMPLE CALCULATOR\n";
    cout << "==============================\n";
    cout << " 1. Addition        (+)\n";
    cout << " 2. Subtraction     (-)\n";
    cout << " 3. Multiplication  (*)\n";
    cout << " 4. Division        (/)\n";
    cout << " 5. Exit\n";
    cout << "------------------------------\n";
}

int main() {
    cout << fixed << setprecision(2);       // show results with 2 decimal places

    while (true) {
        showMenu();
        int choice = readChoice("Choose an option (1-5): ", 1, 5);

        if (choice == 5) {
            cout << "Thank you for using the calculator. Goodbye!\n";
            break;
        }

        double a = readNumber("Enter first number : ");
        double b = readNumber("Enter second number: ");

        switch (choice) {
            case 1:
                cout << "Result: " << a << " + " << b << " = " << a + b << "\n";
                break;
            case 2:
                cout << "Result: " << a << " - " << b << " = " << a - b << "\n";
                break;
            case 3:
                cout << "Result: " << a << " * " << b << " = " << a * b << "\n";
                break;
            case 4:
                if (b == 0)
                    cout << "Error: Division by zero is not allowed.\n";
                else
                    cout << "Result: " << a << " / " << b << " = " << a / b << "\n";
                break;
        }
    }
    return 0;
}

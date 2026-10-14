// ============================================================
// Task 1: Simple Calculator
// CodSoft C++ Internship
// Features: Addition, subtraction, multiplication, division,
//           decimal numbers, input validation, overflow checks.
// ============================================================

#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

// Reads a finite number from the user.
double readNumber(const string& prompt) {
    string line;

    while (true) {
        cout << prompt;

        if (!getline(cin, line)) {
            cout << "\nInput ended. Goodbye!\n";
            return 0.0;
        }

        stringstream ss(line);
        double value;
        char extra;

        if (ss >> value &&
            !(ss >> extra) &&
            isfinite(value)) {
            return value;
        }

        cout << "Invalid number. Please try again.\n";
    }
}

// Reads a menu choice within the specified range.
int readChoice(const string& prompt, int low, int high) {
    string line;

    while (true) {
        cout << prompt;

        if (!getline(cin, line)) {
            return 0;
        }

        stringstream ss(line);
        int value;
        char extra;

        if (ss >> value &&
            !(ss >> extra) &&
            value >= low &&
            value <= high) {
            return value;
        }

        cout << "Please enter a number from "
             << low << " to " << high << ".\n";
    }
}

// Displays the calculator menu.
void showMenu() {
    cout << "\n==============================\n";
    cout << "        SIMPLE CALCULATOR\n";
    cout << "==============================\n";
    cout << "1. Addition        (+)\n";
    cout << "2. Subtraction     (-)\n";
    cout << "3. Multiplication  (*)\n";
    cout << "4. Division        (/)\n";
    cout << "5. Exit\n";
    cout << "------------------------------\n";
}

int main() {
    cout << fixed << setprecision(2);

    while (true) {
        showMenu();

        int choice = readChoice(
            "Choose an option (1-5): ", 1, 5
        );

        // Exit if the user chooses 5 or input ends.
        if (choice == 5) {
            cout << "Thank you for using the calculator. Goodbye!\n";
            break;
        }

        if (choice == 0) {
            cout << "\nInput ended. Goodbye!\n";
            break;
        }

        double a = readNumber("Enter first number : ");

        if (cin.eof()) {
            break;
        }

        double b = readNumber("Enter second number: ");

        if (cin.eof()) {
            break;
        }

        double result = 0.0;
        char operation = ' ';

        switch (choice) {
            case 1:
                result = a + b;
                operation = '+';
                break;

            case 2:
                result = a - b;
                operation = '-';
                break;

            case 3:
                result = a * b;
                operation = '*';
                break;

            case 4:
                if (b == 0.0) {
                    cout << "Error: Division by zero is not allowed.\n";
                    continue;
                }

                result = a / b;
                operation = '/';
                break;
        }

        // Check whether the calculated result is finite.
        if (!isfinite(result)) {
            cout << "Error: Result is outside the supported "
                 << "numeric range.\n";
        } else {
            cout << "Result: " << a << " "
                 << operation << " " << b
                 << " = " << result << "\n";
        }
    }

    return 0;
}
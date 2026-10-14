# CodSoft C++ Programming Internship

Three console-based C++ projects developed as part of the CodSoft C++ Programming Internship. These projects demonstrate fundamental programming concepts, object-oriented programming, input validation, and basic data management.

## Projects Overview

| # | Project | Main Concepts | Source Code |
|---|---|---|---|
| 1 | Simple Calculator | `switch`, loops, arithmetic operations, input validation | [Task 1](Task1-Calculator/calculator.cpp) |
| 2 | Student Management System | Arrays, structures, functions, searching, statistics | [Task 2](Task2-StudentManagement/student_management.cpp) |
| 3 | Bank Account Simulation | Classes, encapsulation, `vector`, transaction handling | [Task 3](Task3-BankAccount/bank_account.cpp) |

## Requirements

- A C++ compiler such as GCC/G++.
- C++11 or a newer standard.
- Windows with MinGW, Linux, or macOS with a compatible compiler.

## How to Compile and Run

Open PowerShell or a terminal and navigate to the relevant project folder.

### Task 1: Simple Calculator

Navigate to the calculator folder:

```powershell
cd Task1-Calculator
```

Compile:

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic calculator.cpp -o calculator.exe
```

Run on Windows PowerShell:

```powershell
.\calculator.exe
```

### Task 2: Student Management System

Navigate to the student management folder:

```powershell
cd Task2-StudentManagement
```

Compile:

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic student_management.cpp -o student_management.exe
```

Run on Windows PowerShell:

```powershell
.\student_management.exe
```

### Task 3: Bank Account Simulation

Navigate to the bank account folder:

```powershell
cd Task3-BankAccount
```

Compile:

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic bank_account.cpp -o bank_account.exe
```

Run on Windows PowerShell:

```powershell
.\bank_account.exe
```

**Note:** Run each compilation command from its corresponding project folder. If compilation produces errors, review the error messages before running the executable.

## Task 1 — Simple Calculator

### Description

A menu-driven calculator that performs basic arithmetic operations on numerical inputs.

### Features

- Addition, subtraction, multiplication, and division.
- Supports decimal numbers.
- Uses a menu-driven interface.
- Validates numerical inputs and menu choices.
- Prevents division by zero.
- Repeats operations until the user chooses to exit.

### Concepts Demonstrated

- `switch` statements.
- Loops and conditional statements.
- Arithmetic operators.
- Input validation.
- Basic error handling.

## Task 2 — Student Management System

### Description

A console-based application for storing, searching, updating, and displaying student information.

### Features

- Stores up to 50 student records using an array of structures.
- Records roll numbers, student names, and marks in three subjects.
- Adds and displays student records.
- Searches for students by roll number.
- Updates student marks.
- Rejects duplicate roll numbers.
- Validates marks within the range of 0–100.
- Calculates class average, highest and lowest student results, and subject averages.
- Generates formatted reports with grade distribution from A to F.

### Concepts Demonstrated

- Structures (`struct`).
- Arrays.
- Functions.
- Searching and updating records.
- Loops and conditional statements.
- Basic statistics and formatted output.

### Data Storage

Student records are stored in memory while the program is running. They are not automatically saved to a file, so the records reset when the program closes.

## Task 3 — Bank Account Simulation

### Description

A menu-driven banking simulation that demonstrates basic account operations and transaction tracking.

### Features

- Creates an account with an account number, holder name, and opening balance.
- Deposits money into the account.
- Withdraws money from the account.
- Displays the current account balance.
- Shows account details.
- Maintains a transaction history.
- Displays transaction amounts and the balance after each transaction.
- Validates user input and transaction amounts.
- Prevents withdrawals that exceed the available balance.

### Concepts Demonstrated

- Classes and objects.
- Encapsulation using private data and public methods.
- Vectors (`std::vector`).
- Transaction tracking.
- Input validation.
- Formatted numerical output.

### Data Storage

The account information and transaction history are maintained in memory during the current session. They are not automatically saved after the program closes.

## Sample Transaction History

The following is an illustrative example of a bank account transaction history:

```text
No.  Type          Amount        Balance After
------------------------------------------------
1    Opening       1000.00       1000.00
2    Deposit        500.50       1500.50
3    Withdrawal       2.00       1498.50
```

The figures above are sample values, not a saved transaction record.

## Testing

The projects can be tested manually through their console interfaces.

Suggested test cases include:

- Entering valid and invalid menu choices.
- Testing decimal and invalid numerical inputs.
- Checking division-by-zero handling in the calculator.
- Adding, searching for, and updating student records.
- Testing duplicate student roll numbers and invalid marks.
- Depositing and withdrawing money.
- Attempting invalid transactions and withdrawals exceeding the available balance.
- Checking whether displayed balances and transaction history are consistent.

## Possible Future Improvements

- Save student records and transaction histories to files.
- Add support for multiple bank accounts.
- Introduce account authentication for the banking simulation.
- Allow student records to be edited or deleted.
- Add automated tests for important operations.
- Improve error handling and user interface design.

## Repository Structure

```text
CodSoft-CPP-Internship/
├── Task1-Calculator/
│   └── calculator.cpp
├── Task2-StudentManagement/
│   └── student_management.cpp
├── Task3-BankAccount/
│   └── bank_account.cpp
├── README.md
├── EXPLAINED.md
├── TESTING.md
└── .gitignore
```

## Author

Developed as part of the CodSoft C++ Programming Internship.

## License

This repository was created for educational and internship purposes.
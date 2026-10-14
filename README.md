# CodSoft C++ Programming Internship

Three console projects built in C++ for the CodSoft internship.

| # | Project | Main concepts |
|---|---------|---------------|
| 1 | [Simple Calculator](Task1-Calculator/) | `switch`, loops, input validation |
| 2 | [Student Management System](Task2-StudentManagement/) | arrays, `struct`, functions, formatted output |
| 3 | [Bank Account Simulation](Task3-BankAccount/) | classes, encapsulation, `vector`, validation |

## Requirements
- A C++ compiler such as **g++** (MinGW on Windows, or Xcode tools on macOS)
- C++11 or newer

## How to compile and run
Open a terminal inside a task folder, then:

```bash
# Task 1
g++ -std=c++11 -o calculator calculator.cpp
./calculator            # Windows: calculator.exe

# Task 2
g++ -std=c++11 -o student_management student_management.cpp
./student_management

# Task 3
g++ -std=c++11 -o bank_account bank_account.cpp
./bank_account
```

## Task 1 - Simple Calculator
- Menu: addition, subtraction, multiplication, division, exit
- Works with decimal numbers
- Rejects invalid numbers and invalid menu choices
- Blocks division by zero
- Repeats until the user chooses Exit

## Task 2 - Student Management System
- Stores up to 50 students in an **array of structs** (roll, name, 3 subject marks)
- Add, view, search by roll number, update marks
- Rejects duplicate roll numbers and marks outside 0-100
- Class statistics: class average, highest and lowest student, subject averages
- Formatted report with grade distribution (A to F)
- Data lives in memory only, so it resets when the program closes

## Task 3 - Bank Account Simulation
- `BankAccount` class with private data and public methods
- Deposit, withdraw, check balance, view account details
- Blocks negative amounts and overdrafts
- Transaction history stored in a `vector`

## Sample session (Task 3)
```
Enter amount to deposit: 500.50
Deposited 500.50. New balance: 1500.50

No.  Type          Amount        Balance After
1    Opening       1000.00       1000.00
2    Deposit       500.50        1500.50
3    Withdrawal    2.00          1498.50
```

## Possible improvements
- Save student records and transactions to a file
- Multiple bank accounts with a PIN
- Edit or delete students

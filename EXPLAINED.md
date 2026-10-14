# Code Explained (for your viva / review)

## Ideas used in ALL three programs

**Input validation with `getline` + `stringstream`.**
`cin >> number` breaks badly if the user types letters (the program can loop forever).
Instead, each program reads the **whole line** with `getline`, then tries to convert it using a `stringstream`:
```cpp
stringstream ss(line);
if (ss >> value && !(ss >> extra)) ...
```
`ss >> value` succeeds only if a number was found. `!(ss >> extra)` makes sure nothing else follows, so `5abc` is rejected.

**`while (true)` loops.** Menus and input prompts repeat forever until `break`, `return`, or valid input.

**`switch`.** Runs the code for the chosen menu option.

## Task 1 - Calculator
- `readNumber()` keeps asking until a valid number is typed.
- `readChoice()` does the same for menu options within a range.
- `fixed << setprecision(2)` shows two decimal places (from `<iomanip>`).
- Division checks `b == 0` before dividing.

## Task 2 - Student Management
- `struct Student` groups roll, name, and `marks[3]` in one type.
- `Student students[50]` is the array; `studentCount` tracks how many slots are used.
- `findStudent(roll)` loops through the array and returns the index, or `-1` if missing. Add, search and update all reuse it.
- `averageMarks()` and `gradeFor()` are small functions, so the logic is written once and reused.
- `setw()` and `left` line up the columns in the table.
- Statistics: one loop adds up averages and tracks the index of the best and worst student.

## Task 3 - Bank Account
- **Encapsulation:** `balance` is `private`. It can only change through `deposit()` and `withdraw()`, which check the rules first. This is why a class is better than loose variables.
- **Constructor:** `BankAccount(number, name, opening)` sets the starting values using an initializer list.
- `deposit()`/`withdraw()` return `true` or `false` so `main()` can print the right message.
- **`const` methods** (`getBalance() const`) promise not to modify the object.
- **`vector<Transaction>`** is a resizable array. Every successful operation adds one record with `push_back`.

## Questions a reviewer might ask
1. *Why `getline` instead of `cin >>`?* To handle bad input safely.
2. *What is the difference between an array and a vector?* Array size is fixed; vector grows.
3. *Why is `balance` private?* So no code can set it to an invalid value.
4. *What does `const` after a method mean?* The method does not change the object.
5. *What would you add next?* File saving, multiple accounts, deleting students.

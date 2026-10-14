# Test Log

All three programs compiled with `g++ -std=c++11 -Wall -Wextra` with **zero warnings**.

## Task 1 - Calculator
| Input | Expected | Result |
|-------|----------|--------|
| 5.5 + 2.25 | 7.75 | Pass |
| 10 / 0 | Error message | Pass |
| 10 / 4 | 2.50 | Pass |
| Menu choice `9` or `abc` | Re-prompt | Pass |
| Number `x` | Re-prompt | Pass |

## Task 2 - Student Management
| Test | Result |
|------|--------|
| Add 3 students, view table | Pass |
| Duplicate roll number rejected | Pass |
| Marks 150 rejected, re-prompt | Pass |
| Name with extra spaces trimmed | Pass |
| Search existing / missing roll | Pass |
| Update marks, grade recalculated | Pass |
| Class stats and report | Pass |

## Task 3 - Bank Account
| Test | Result |
|------|--------|
| Invalid account number / empty name / negative opening balance rejected | Pass |
| Deposit 500.50 on 1000 gives 1500.50 | Pass |
| Withdraw 5000 (more than balance) refused | Pass |
| Negative or text amounts refused | Pass |
| History lists every transaction | Pass |

Please re-run these yourself on your own laptop before submitting.

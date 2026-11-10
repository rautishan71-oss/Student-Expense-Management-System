# Student Expense Management System (C++)

A beginner-to-intermediate, menu-driven C++ console project for a B.Tech CSE 3rd-semester submission.

## Features
- Student profile storage
- Income and expense entry
- Expense categories
- View, update and delete expenses
- Search transactions
- Overall and monthly financial summaries
- Monthly budget and exceeded-budget warning
- Persistent storage using text files

## Requirements
- C++ compiler supporting C++11 or later (C++17 recommended)
- VS Code with MinGW-w64, Code::Blocks, or Visual Studio

## Compile
Open a terminal in this folder and run:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp Student.cpp Expense.cpp Income.cpp Budget.cpp FileManager.cpp -o StudentExpenseManagement
```

Run on Windows:
```bash
StudentExpenseManagement.exe
```

Run on Linux/macOS:
```bash
./StudentExpenseManagement
```

In Visual Studio, create a Console App project and add all `.cpp` and `.h` files.

## Data files
The program creates/uses `students.txt`, `income.txt`, `expenses.txt`, and `budget.txt` in the current working directory. Keep these files in the same folder from which the executable is launched. Back them up before manually editing them.

Each record uses `|` as a separator. The program therefore rejects `|` in entered text.

## Date formats
- Transaction date: `YYYY-MM-DD`
- Budget month: `YYYY-MM`

The date checker validates the format and basic month/day ranges; it is not a full calendar-date validator.

## Notes for submission
1. Run the program once to create the data files.
2. Add sample student, income, expense and budget records.
3. Close and reopen the program to demonstrate persistence.
4. Keep a backup copy of your sample data files.

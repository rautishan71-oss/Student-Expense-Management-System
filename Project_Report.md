# STUDENT EXPENSE MANAGEMENT SYSTEM
## C++ Console-Based Application — Project Report

**Submitted by:** ____________________  
**Roll Number:** ____________________  
**Class:** B.Tech CSE, 3rd Semester  
**Institute:** ____________________  
**Academic Year:** ____________________  
**Project Guide:** ____________________

---

## Certificate (Format)

This is to certify that the project entitled **“Student Expense Management System”** has been developed and submitted by ____________________, Roll No. __________, in partial fulfilment of the requirements of B.Tech Computer Science and Engineering, 3rd Semester, under my guidance.

**Project Guide:** __________  **Head of Department:** __________  **Date:** __________

## Acknowledgement

I express my sincere gratitude to my project guide and the Computer Science and Engineering department for their guidance and support. I also thank my classmates, friends and family for their encouragement during the development of this project.

## Abstract

The Student Expense Management System is a menu-driven C++ console application designed to help students record income and daily expenses. It stores student details, transactions and monthly budget information in text files so that records remain available after the application is closed. The application supports adding, viewing, updating, deleting and searching transactions, as well as calculating balances and monthly summaries. The project demonstrates procedural programming, object-oriented programming, input validation, STL vectors and file handling.

## 1. Introduction

Students often receive money from parents, scholarships, part-time work or other sources and spend it on food, travel, education and accommodation. Recording these transactions manually can make it difficult to understand spending habits. This application provides a simple local tool to maintain transaction records and monitor a monthly budget.

## 2. Problem Statement

A student may not know how much money has been received, how much has been spent, or whether monthly spending has exceeded a planned budget. The project addresses this problem through a simple computerised record-management system.

## 3. Objectives

- Maintain basic student information.
- Record income and expenses with dates and descriptions.
- Organise expenses into categories.
- Search transaction records.
- Update or delete an expense.
- Calculate total income, expenses and current balance.
- Set a monthly budget and show the remaining amount.
- Store records permanently using files.

## 4. Scope

The application is intended for a single student on a local computer. It is suitable for learning and academic demonstration. It is not a banking application and does not connect to bank accounts, cloud services or payment gateways.

## 5. Hardware and Software Requirements

**Hardware**
- Desktop or laptop computer
- Minimum 4 GB RAM recommended
- Keyboard and monitor

**Software**
- Windows, Linux or macOS
- C++ compiler (GCC/MinGW or Visual C++)
- VS Code, Code::Blocks or Visual Studio
- C++11 or later; C++17 recommended

## 6. System Design

### 6.1 Architecture

The user interacts with the menu in `main.cpp`. The menu calls functions for student, income, expense, budget, search and summary operations. Model classes represent Student, Income, Expense and Budget. `FileManager` handles reading and writing text files.

### 6.2 Data Files

| File | Purpose |
|---|---|
| `students.txt` | Student name and ID |
| `income.txt` | Income transaction records |
| `expenses.txt` | Expense transaction records |
| `budget.txt` | Current monthly budget |

Records are stored as pipe-separated fields. Text entered by the user cannot contain the pipe character.

### 6.3 Flowchart (Text Representation)

```text
             +------------------+
             |       START      |
             +------------------+
                      |
                      v
          +------------------------+
          | Load saved text files  |
          +------------------------+
                      |
                      v
          +------------------------+
          | Display main menu      |
          +------------------------+
                      |
                      v
          +------------------------+
          | Read user's choice     |
          +------------------------+
                      |
                      v
              +---------------+
              | Choice = 11?  |
              +---------------+
                | Yes     | No
                v         v
          +----------+  +-----------------------+
          |   EXIT   |  | Execute selected task |
          +----------+  +-----------------------+
                            |
                            +------ back to menu
```

### 6.4 Data Flow Diagram (Level 0)

```text
+---------+       details / transactions       +-------------------------+
| Student | ---------------------------------> | Student Expense System  |
|  User   | <--------------------------------- |                         |
+---------+       reports / confirmations     +------------+------------+
                                                           |
                                                           | read / write
                                                           v
                                              +-------------------------+
                                              | Text Data Files         |
                                              | students, income,       |
                                              | expenses, budget        |
                                              +-------------------------+
```

### 6.5 UML Class Diagram

```text
+---------------------+       +----------------------+
|       Student       |       |       Expense        |
+---------------------+       +----------------------+
| - name: string      |       | - id: int            |
| - studentId: string |       | - date: string       |
+---------------------+       | - category: string   |
| + setDetails()      |       | - amount: double     |
| + display()         |       | - description:string |
| + isEmpty()         |       +----------------------+
+---------------------+       | + update()           |
                              | + display()           |
                              +----------------------+

+---------------------+       +----------------------+
|       Income        |       |        Budget        |
+---------------------+       +----------------------+
| - id: int           |       | - month: string      |
| - date: string      |       | - amount: double     |
| - source: string    |       +----------------------+
| - amount: double    |       | + setBudget()        |
| - description:string|       | + remaining()        |
+---------------------+       | + display()           |
| + display()         |       +----------------------+
+---------------------+

              +--------------------------------+
              |           FileManager          |
              +--------------------------------+
              | - studentFile: string          |
              | - expenseFile: string          |
              | - incomeFile: string           |
              | - budgetFile: string           |
              +--------------------------------+
              | + saveStudent() / loadStudent()|
              | + saveExpense() / loadExpenses()|
              | + saveIncome() / loadIncomes() |
              | + saveBudget() / loadBudget()  |
              +--------------------------------+
```

## 7. Algorithms

### Add Expense
1. Load existing expense records.
2. Find the next available ID.
3. Read date, category, amount and description.
4. Validate date and amount.
5. Create an Expense object.
6. Append the record to `expenses.txt`.
7. Display success or failure.

### Add Income
1. Load existing income records.
2. Find the next available ID.
3. Read date, source, amount and description.
4. Validate input.
5. Create an Income object.
6. Append it to `income.txt`.

### Update Expense
1. Load all expenses into a vector.
2. Ask for the expense ID.
3. Search the vector for that ID.
4. If found, read replacement values and update the object.
5. Rewrite the expense file with all records.
6. If not found, display an error.

### Delete Expense
1. Load all expenses.
2. Ask for an ID.
3. Find the matching record.
4. Erase it from the vector.
5. Rewrite the file.
6. Display the result.

### Financial Summary
1. Load income and expense records.
2. Add all income amounts.
3. Add all expense amounts.
4. Calculate balance = income − expenses.
5. If a budget exists, total expenses for its month.
6. Calculate remaining budget = budget − monthly expenses.
7. Display the summary and warning if the budget is exceeded.

## 8. Important Formulae

- **Total Balance = Total Income − Total Expenses**
- **Remaining Budget = Monthly Budget − Expenses in that Month**
- **Monthly Net = Income in Month − Expenses in Month**

## 9. Testing and Test Cases

| Test | Input / Action | Expected result |
|---|---|---|
| T1 | Add valid income | Income saved with an ID |
| T2 | Add valid expense | Expense saved with an ID |
| T3 | Enter alphabetic amount | Error message; re-enter amount |
| T4 | Enter invalid date format | Error message; re-enter date |
| T5 | View records | Saved records are displayed |
| T6 | Update an existing expense ID | Record is changed |
| T7 | Update unknown ID | “Expense ID not found” |
| T8 | Delete existing expense ID | Record is removed |
| T9 | Set budget below monthly spending | Budget exceeded warning |
| T10 | Restart the application | Previous records are still available |
| T11 | Search for a known category | Matching transactions appear |
| T12 | Select an invalid menu option | Invalid choice message |

## 10. Sample Output

```text
Welcome to Student Expense Management System!

========== STUDENT EXPENSE MANAGEMENT SYSTEM ==========
1.  Student Information
2.  Add Income
3.  Add Expense
4.  View Income
5.  View Expenses
6.  Update Expense
7.  Delete Expense
8.  Set Monthly Budget
9.  View Financial Summary
10. Search Transactions
11. Exit
========================================================
Enter your choice: 3
Date (YYYY-MM-DD): 2026-11-10

Expense categories:
1. Food
2. Travel
3. Education
4. Shopping
5. Entertainment
6. Accommodation
7. Other
Choose category: 1
Amount (Rs.): 120
Description: Lunch
Expense added successfully. ID: 1
```

## 11. Advantages

- Simple menu-driven interface.
- No external database required.
- Data persists between sessions.
- Supports basic transaction management.
- Demonstrates practical C++ and OOP concepts.

## 12. Limitations

- Single-user, local application.
- Text files are not encrypted.
- No password-based authentication.
- No graphical user interface.
- Date validation checks format and basic ranges, not every calendar rule.
- Search is a simple text search.

## 13. Future Scope

- Add login and password protection.
- Use SQLite database.
- Add category-wise charts and reports.
- Add CSV export and printable monthly reports.
- Add a graphical interface using Qt.
- Support multiple student profiles.

## 14. Conclusion

The Student Expense Management System provides a simple way for students to record income and expenses, monitor a monthly budget and view financial summaries. The project applies C++ functions, classes, encapsulation, vectors, validation and file handling in a practical problem-solving application.

## 15. References

1. Bjarne Stroustrup, *Programming: Principles and Practice Using C++*.
2. E. Balagurusamy, *Object Oriented Programming with C++*.
3. ISO C++ reference: https://en.cppreference.com/
4. GCC documentation: https://gcc.gnu.org/onlinedocs/

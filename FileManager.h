#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Student.h"
#include "Expense.h"
#include "Income.h"
#include "Budget.h"
using namespace std;

class FileManager {
private:
    const string studentFile = "students.txt";
    const string expenseFile = "expenses.txt";
    const string incomeFile = "income.txt";
    const string budgetFile = "budget.txt";

public:
    bool saveStudent(const Student& student);
    bool loadStudent(Student& student);

    bool saveExpense(const Expense& expense);
    vector<Expense> loadExpenses();
    bool saveAllExpenses(const vector<Expense>& expenses);

    bool saveIncome(const Income& income);
    vector<Income> loadIncomes();

    bool saveBudget(const Budget& budget);
    bool loadBudget(Budget& budget);
};

#endif

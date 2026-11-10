#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>
#include "Student.h"
#include "Expense.h"
#include "Income.h"
#include "Budget.h"
#include "FileManager.h"

using namespace std;

const vector<string> CATEGORIES = {
    "Food", "Travel", "Education", "Shopping",
    "Entertainment", "Accommodation", "Other"
};

string readLine(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

double readAmount(const string& prompt) {
    while (true) {
        string input = readLine(prompt);
        try {
            size_t pos = 0;
            double value = stod(input, &pos);
            if (pos != input.size() || value <= 0) throw invalid_argument("amount");
            return value;
        } catch (...) {
            cout << "Invalid amount. Enter a number greater than zero.\n";
        }
    }
}

int readInt(const string& prompt) {
    while (true) {
        string input = readLine(prompt);
        try {
            size_t pos = 0;
            int value = stoi(input, &pos);
            if (pos != input.size()) throw invalid_argument("integer");
            return value;
        } catch (...) {
            cout << "Please enter a valid whole number.\n";
        }
    }
}

bool validDate(const string& date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') return false;
    for (int i = 0; i < 10; ++i) {
        if (i != 4 && i != 7 && !isdigit(static_cast<unsigned char>(date[i]))) return false;
    }
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    return month >= 1 && month <= 12 && day >= 1 && day <= 31;
}

string readDate() {
    while (true) {
        string date = readLine("Date (YYYY-MM-DD): ");
        if (validDate(date)) return date;
        cout << "Invalid date format. Example: 2026-11-10\n";
    }
}

string readDescription(const string& prompt) {
    while (true) {
        string s = readLine(prompt);
        if (s.find('|') == string::npos && !s.empty()) return s;
        cout << "Enter a non-empty value without the | character.\n";
    }
}

int nextExpenseId(const vector<Expense>& expenses) {
    int id = 0;
    for (const Expense& e : expenses) id = max(id, e.getId());
    return id + 1;
}

int nextIncomeId(const vector<Income>& incomes) {
    int id = 0;
    for (const Income& i : incomes) id = max(id, i.getId());
    return id + 1;
}

bool sameMonth(const string& date, const string& month) {
    return date.size() >= 7 && date.substr(0, 7) == month;
}

void showCategories() {
    cout << "\nExpense categories:\n";
    for (size_t i = 0; i < CATEGORIES.size(); ++i)
        cout << i + 1 << ". " << CATEGORIES[i] << "\n";
}

string chooseCategory() {
    showCategories();
    while (true) {
        int choice = readInt("Choose category: ");
        if (choice >= 1 && choice <= static_cast<int>(CATEGORIES.size()))
            return CATEGORIES[choice - 1];
        cout << "Choose a number from 1 to " << CATEGORIES.size() << ".\n";
    }
}

void studentMenu(Student& student, FileManager& fm) {
    student.display();
    cout << "1. Add / update student details\n2. Back\n";
    int choice = readInt("Choose: ");
    if (choice == 1) {
        string name = readDescription("Student name: ");
        string id = readDescription("Student ID: ");
        student.setDetails(name, id);
        cout << (fm.saveStudent(student) ? "Student details saved.\n" : "Could not save student details.\n");
    }
}

void addIncome(FileManager& fm) {
    vector<Income> incomes = fm.loadIncomes();
    int id = nextIncomeId(incomes);
    string date = readDate();
    string source = readDescription("Income source (e.g. Scholarship): ");
    double amount = readAmount("Amount (Rs.): ");
    string desc = readDescription("Description: ");
    Income income(id, date, source, amount, desc);
    cout << (fm.saveIncome(income) ? "Income added successfully. ID: " + to_string(id) + "\n"
                                   : "Unable to save income.\n");
}

void addExpense(FileManager& fm) {
    vector<Expense> expenses = fm.loadExpenses();
    int id = nextExpenseId(expenses);
    string date = readDate();
    string category = chooseCategory();
    double amount = readAmount("Amount (Rs.): ");
    string desc = readDescription("Description: ");
    Expense expense(id, date, category, amount, desc);
    cout << (fm.saveExpense(expense) ? "Expense added successfully. ID: " + to_string(id) + "\n"
                                    : "Unable to save expense.\n");
}

void viewIncomes(FileManager& fm) {
    vector<Income> incomes = fm.loadIncomes();
    if (incomes.empty()) { cout << "No income records found.\n"; return; }
    cout << "\nID    Date         Source                 Amount   Description\n";
    cout << "--------------------------------------------------------------------------\n";
    double total = 0;
    for (const Income& i : incomes) { i.display(); total += i.getAmount(); }
    cout << "Total income: Rs. " << fixed << setprecision(2) << total << "\n";
}

void viewExpenses(FileManager& fm) {
    vector<Expense> expenses = fm.loadExpenses();
    if (expenses.empty()) { cout << "No expense records found.\n"; return; }
    cout << "\nID    Date         Category              Amount   Description\n";
    cout << "--------------------------------------------------------------------------\n";
    double total = 0;
    for (const Expense& e : expenses) { e.display(); total += e.getAmount(); }
    cout << "Total expenses: Rs. " << fixed << setprecision(2) << total << "\n";
}

void updateExpense(FileManager& fm) {
    vector<Expense> expenses = fm.loadExpenses();
    int id = readInt("Enter expense ID to update: ");
    for (Expense& e : expenses) {
        if (e.getId() == id) {
            cout << "Current record: ";
            e.display();
            string date = readDate();
            string category = chooseCategory();
            double amount = readAmount("New amount (Rs.): ");
            string desc = readDescription("New description: ");
            e.update(date, category, amount, desc);
            cout << (fm.saveAllExpenses(expenses) ? "Expense updated.\n" : "Could not update expense.\n");
            return;
        }
    }
    cout << "Expense ID not found.\n";
}

void deleteExpense(FileManager& fm) {
    vector<Expense> expenses = fm.loadExpenses();
    int id = readInt("Enter expense ID to delete: ");
    auto it = find_if(expenses.begin(), expenses.end(),
                      [id](const Expense& e) { return e.getId() == id; });
    if (it == expenses.end()) { cout << "Expense ID not found.\n"; return; }
    expenses.erase(it);
    cout << (fm.saveAllExpenses(expenses) ? "Expense deleted.\n" : "Could not delete expense.\n");
}

void setBudget(FileManager& fm) {
    string month = readLine("Month (YYYY-MM): ");
    if (month.size() != 7 || month[4] != '-' ||
        !isdigit(static_cast<unsigned char>(month[0])) ||
        !isdigit(static_cast<unsigned char>(month[1])) ||
        !isdigit(static_cast<unsigned char>(month[2])) ||
        !isdigit(static_cast<unsigned char>(month[3])) ||
        !isdigit(static_cast<unsigned char>(month[5])) ||
        !isdigit(static_cast<unsigned char>(month[6])) ||
        stoi(month.substr(5, 2)) < 1 || stoi(month.substr(5, 2)) > 12) {
        cout << "Invalid month. Use YYYY-MM, e.g. 2026-11.\n";
        return;
    }
    double amount = readAmount("Monthly budget (Rs.): ");
    Budget b(month, amount);
    cout << (fm.saveBudget(b) ? "Monthly budget saved.\n" : "Unable to save budget.\n");
}

void financialSummary(FileManager& fm) {
    vector<Income> incomes = fm.loadIncomes();
    vector<Expense> expenses = fm.loadExpenses();
    double totalIncome = 0, totalExpense = 0;
    for (const Income& i : incomes) totalIncome += i.getAmount();
    for (const Expense& e : expenses) totalExpense += e.getAmount();

    cout << "\n========== OVERALL FINANCIAL SUMMARY ==========\n";
    cout << fixed << setprecision(2);
    cout << "Total income  : Rs. " << totalIncome << "\n";
    cout << "Total expenses: Rs. " << totalExpense << "\n";
    cout << "Current balance: Rs. " << totalIncome - totalExpense << "\n";

    Budget b;
    if (fm.loadBudget(b)) {
        double monthExpense = 0;
        for (const Expense& e : expenses)
            if (sameMonth(e.getDate(), b.getMonth())) monthExpense += e.getAmount();
        b.display(monthExpense);
    } else {
        cout << "No monthly budget has been set.\n";
    }

    string month = readLine("\nEnter month for monthly summary (YYYY-MM), or press Enter to skip: ");
    if (!month.empty()) {
        double mi = 0, me = 0;
        for (const Income& i : incomes) if (sameMonth(i.getDate(), month)) mi += i.getAmount();
        for (const Expense& e : expenses) if (sameMonth(e.getDate(), month)) me += e.getAmount();
        cout << "\n--- Summary for " << month << " ---\n";
        cout << "Income: Rs. " << mi << "\nExpenses: Rs. " << me
             << "\nNet: Rs. " << mi - me << "\n";
    }
}

void searchTransactions(FileManager& fm) {
    string keyword = readLine("Enter search text (date/category/source/description): ");
    transform(keyword.begin(), keyword.end(), keyword.begin(),
              [](unsigned char c) { return static_cast<char>(tolower(c)); });
    bool found = false;
    vector<Expense> expenses = fm.loadExpenses();
    vector<Income> incomes = fm.loadIncomes();

    cout << "\nMatching expenses:\n";
    for (const Expense& e : expenses) {
        string text = e.getDate() + " " + e.getCategory() + " " + e.getDescription();
        transform(text.begin(), text.end(), text.begin(),
                  [](unsigned char c) { return static_cast<char>(tolower(c)); });
        if (text.find(keyword) != string::npos) { e.display(); found = true; }
    }
    cout << "\nMatching income:\n";
    for (const Income& i : incomes) {
        string text = i.getDate() + " " + i.getSource() + " " + i.getDescription();
        transform(text.begin(), text.end(), text.begin(),
                  [](unsigned char c) { return static_cast<char>(tolower(c)); });
        if (text.find(keyword) != string::npos) { i.display(); found = true; }
    }
    if (!found) cout << "No matching transaction found.\n";
}

void showMenu() {
    cout << "\n========== STUDENT EXPENSE MANAGEMENT SYSTEM ==========\n";
    cout << "1.  Student Information\n";
    cout << "2.  Add Income\n";
    cout << "3.  Add Expense\n";
    cout << "4.  View Income\n";
    cout << "5.  View Expenses\n";
    cout << "6.  Update Expense\n";
    cout << "7.  Delete Expense\n";
    cout << "8.  Set Monthly Budget\n";
    cout << "9.  View Financial Summary\n";
    cout << "10. Search Transactions\n";
    cout << "11. Exit\n";
    cout << "========================================================\n";
}

int main() {
    FileManager fm;
    Student student;
    fm.loadStudent(student);

    cout << "Welcome to Student Expense Management System!\n";
    bool running = true;
    while (running) {
        showMenu();
        int choice = readInt("Enter your choice: ");
        switch (choice) {
            case 1: studentMenu(student, fm); break;
            case 2: addIncome(fm); break;
            case 3: addExpense(fm); break;
            case 4: viewIncomes(fm); break;
            case 5: viewExpenses(fm); break;
            case 6: updateExpense(fm); break;
            case 7: deleteExpense(fm); break;
            case 8: setBudget(fm); break;
            case 9: financialSummary(fm); break;
            case 10: searchTransactions(fm); break;
            case 11: running = false; cout << "Thank you for using the system. Goodbye!\n"; break;
            default: cout << "Invalid choice. Select 1 to 11.\n";
        }
    }
    return 0;
}

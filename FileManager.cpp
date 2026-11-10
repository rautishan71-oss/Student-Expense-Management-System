#include "FileManager.h"
#include <fstream>
#include <sstream>

bool FileManager::saveStudent(const Student& s) {
    ofstream out(studentFile);
    if (!out) return false;
    out << s.getName() << "|" << s.getStudentId() << "\n";
    out.close();
    return true;
}

bool FileManager::loadStudent(Student& s) {
    ifstream in(studentFile);
    if (!in) return false;
    string name, id;
    if (!getline(in, name, '|') || !getline(in, id)) return false;
    s.setDetails(name, id);
    in.close();
    return true;
}

bool FileManager::saveExpense(const Expense& e) {
    ofstream out(expenseFile, ios::app);
    if (!out) return false;
    out << e.getId() << "|" << e.getDate() << "|" << e.getCategory() << "|"
        << e.getAmount() << "|" << e.getDescription() << "\n";
    out.close();
    return true;
}

vector<Expense> FileManager::loadExpenses() {
    vector<Expense> result;
    ifstream in(expenseFile);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string idText, date, category, amountText, description;
        if (getline(ss, idText, '|') && getline(ss, date, '|') &&
            getline(ss, category, '|') && getline(ss, amountText, '|') &&
            getline(ss, description)) {
            try {
                result.push_back(Expense(stoi(idText), date, category,
                                         stod(amountText), description));
            } catch (...) {
                // Ignore a damaged record and continue loading valid records.
            }
        }
    }
    in.close();
    return result;
}

bool FileManager::saveAllExpenses(const vector<Expense>& expenses) {
    ofstream out(expenseFile);
    if (!out) return false;
    for (const Expense& e : expenses) {
        out << e.getId() << "|" << e.getDate() << "|" << e.getCategory() << "|"
            << e.getAmount() << "|" << e.getDescription() << "\n";
    }
    out.close();
    return true;
}

bool FileManager::saveIncome(const Income& i) {
    ofstream out(incomeFile, ios::app);
    if (!out) return false;
    out << i.getId() << "|" << i.getDate() << "|" << i.getSource() << "|"
        << i.getAmount() << "|" << i.getDescription() << "\n";
    out.close();
    return true;
}

vector<Income> FileManager::loadIncomes() {
    vector<Income> result;
    ifstream in(incomeFile);
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string idText, date, source, amountText, description;
        if (getline(ss, idText, '|') && getline(ss, date, '|') &&
            getline(ss, source, '|') && getline(ss, amountText, '|') &&
            getline(ss, description)) {
            try {
                result.push_back(Income(stoi(idText), date, source,
                                        stod(amountText), description));
            } catch (...) {
                // Ignore malformed record.
            }
        }
    }
    in.close();
    return result;
}

bool FileManager::saveBudget(const Budget& b) {
    ofstream out(budgetFile);
    if (!out) return false;
    out << b.getMonth() << "|" << b.getAmount() << "\n";
    out.close();
    return true;
}

bool FileManager::loadBudget(Budget& b) {
    ifstream in(budgetFile);
    if (!in) return false;
    string month, amountText;
    if (!getline(in, month, '|') || !getline(in, amountText)) return false;
    try {
        b.setBudget(month, stod(amountText));
    } catch (...) {
        in.close();
        return false;
    }
    in.close();
    return true;
}

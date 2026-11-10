#include "Expense.h"
#include <iostream>
#include <iomanip>
using namespace std;

Expense::Expense() : id(0), amount(0.0) {}
Expense::Expense(int i, const string& d, const string& c, double a, const string& desc)
    : id(i), date(d), category(c), amount(a), description(desc) {}
int Expense::getId() const { return id; }
string Expense::getDate() const { return date; }
string Expense::getCategory() const { return category; }
double Expense::getAmount() const { return amount; }
string Expense::getDescription() const { return description; }

void Expense::update(const string& d, const string& c, double a, const string& desc) {
    date = d;
    category = c;
    amount = a;
    description = desc;
}

void Expense::display() const {
    cout << left << setw(6) << id << setw(13) << date << setw(18) << category
         << right << setw(10) << fixed << setprecision(2) << amount
         << "   " << description << "\n";
}

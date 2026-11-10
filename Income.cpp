#include "Income.h"
#include <iostream>
#include <iomanip>
using namespace std;

Income::Income() : id(0), amount(0.0) {}
Income::Income(int i, const string& d, const string& s, double a, const string& desc)
    : id(i), date(d), source(s), amount(a), description(desc) {}
int Income::getId() const { return id; }
string Income::getDate() const { return date; }
string Income::getSource() const { return source; }
double Income::getAmount() const { return amount; }
string Income::getDescription() const { return description; }

void Income::display() const {
    cout << left << setw(6) << id << setw(13) << date << setw(18) << source
         << right << setw(10) << fixed << setprecision(2) << amount
         << "   " << description << "\n";
}

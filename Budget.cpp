#include "Budget.h"
#include <iostream>
#include <iomanip>
using namespace std;

Budget::Budget() : amount(0.0) {}
Budget::Budget(const string& m, double a) : month(m), amount(a) {}
string Budget::getMonth() const { return month; }
double Budget::getAmount() const { return amount; }
void Budget::setBudget(const string& m, double a) { month = m; amount = a; }
double Budget::remaining(double expenses) const { return amount - expenses; }

void Budget::display(double expenses) const {
    cout << "\n--- Monthly Budget: " << month << " ---\n";
    cout << fixed << setprecision(2);
    cout << "Budget          : Rs. " << amount << "\n";
    cout << "Monthly expenses: Rs. " << expenses << "\n";
    cout << "Remaining       : Rs. " << remaining(expenses) << "\n";
    if (expenses > amount) cout << "WARNING: Monthly budget exceeded!\n";
    else cout << "Status          : Within budget.\n";
}

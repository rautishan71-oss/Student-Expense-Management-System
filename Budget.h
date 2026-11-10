#ifndef BUDGET_H
#define BUDGET_H

#include <string>
using namespace std;

class Budget {
private:
    string month;
    double amount;

public:
    Budget();
    Budget(const string& month, double amount);
    string getMonth() const;
    double getAmount() const;
    void setBudget(const string& month, double amount);
    double remaining(double monthlyExpenses) const;
    void display(double monthlyExpenses) const;
};

#endif

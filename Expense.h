#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
using namespace std;

class Expense {
private:
    int id;
    string date;
    string category;
    double amount;
    string description;

public:
    Expense();
    Expense(int id, const string& date, const string& category,
            double amount, const string& description);
    int getId() const;
    string getDate() const;
    string getCategory() const;
    double getAmount() const;
    string getDescription() const;
    void update(const string& date, const string& category,
                double amount, const string& description);
    void display() const;
};

#endif

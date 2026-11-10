#ifndef INCOME_H
#define INCOME_H

#include <string>
using namespace std;

class Income {
private:
    int id;
    string date;
    string source;
    double amount;
    string description;

public:
    Income();
    Income(int id, const string& date, const string& source,
           double amount, const string& description);
    int getId() const;
    string getDate() const;
    string getSource() const;
    double getAmount() const;
    string getDescription() const;
    void display() const;
};

#endif

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    float baseSalary;
    int hoursWorked;

public:
    Employee();
    Employee(string n, int id, float salary, int hours);

    float calculateRegularPay() const;
    float calculateOvertimePay() const;
    float calculateTotalSalary() const;

    void displayEmployee() const;

    float getTotalSalary() const;
};

#endif

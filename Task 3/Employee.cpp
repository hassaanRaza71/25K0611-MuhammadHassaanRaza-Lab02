#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee() {
    name = "";
    employeeID = 0;
    baseSalary = 0;
    hoursWorked = 0;
}

Employee::Employee(string n, int id, float salary, int hours) {
    name = n;
    employeeID = id;
    baseSalary = salary;
    hoursWorked = hours;
}

float Employee::calculateRegularPay() const {
    return baseSalary;
}

float Employee::calculateOvertimePay() const {
    if (hoursWorked > 40) {
        int overtimeHours = hoursWorked - 40;
        float hourlyRate = baseSalary / 40;
        return overtimeHours * hourlyRate * 1.5;
    }
    return 0;
}

float Employee::calculateTotalSalary() const {
    return calculateRegularPay() + calculateOvertimePay();
}

void Employee::displayEmployee() const {
    cout << "Name: " << name << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "Base Salary: " << baseSalary << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Overtime Pay: " << calculateOvertimePay() << endl;
    cout << "Total Salary: " << calculateTotalSalary() << endl;
    cout << "--------------------------" << endl;
}

float Employee::getTotalSalary() const {
    return calculateTotalSalary();
}

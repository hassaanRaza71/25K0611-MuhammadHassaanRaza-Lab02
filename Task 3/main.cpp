#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    Employee e1("Ali Khan", 101, 40000, 45);
    Employee e2("Sara Ahmed", 102, 38000, 38);

    cout << "Employee Payroll Information\n";
    cout << "--------------------------\n";
    e1.displayEmployee();
    e2.displayEmployee();

    if (e1.getTotalSalary() > e2.getTotalSalary()) {
        cout << "Higher Salary: Employee ID " << 101 << endl;
    } else if (e2.getTotalSalary() > e1.getTotalSalary()) {
        cout << "Higher Salary: Employee ID " << 102 << endl;
    } else {
        cout << "Both employees have equal salary." << endl;
    }

    return 0;
}

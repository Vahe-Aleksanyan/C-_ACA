//
// Created by Vahe Aleksanyan on 15.01.23.
//

#ifndef PROJECT3_SALARIEDEMPLOYEE_H
#define PROJECT3_SALARIEDEMPLOYEE_H

#include <string>
#include "employee.h"

using std::string;

namespace SavitchEmployees {
    class SalariedEmployee: public Employee {
    public:
        SalariedEmployee();
        SalariedEmployee(const string& theName, const string& theSsn, double theWeeklySalary);

        double getSalary() const;
        void setSalary(double newSalary);

        void printCheck();
    private:
        double salary;
    };
}

#endif

//
// Created by Vahe Aleksanyan on 15.01.23.
//

#ifndef PROJECT3_HOURLYEMPLOYEE_H
#define PROJECT3_HOURLYEMPLOYEE_H

#include <string>
#include "employee.h"

using std::string;

namespace SavitchEmployees {
    class HourlyEmployee: public Employee {  // inheritance
    public:
        HourlyEmployee();
        HourlyEmployee(const string& theName, const string& theSsn, double theWageRate, double theHours);

        double getRate() const;
        double getHours() const;

        void setRate(double newWageRate);
        void setHours(double hoursWorked);
        void printCheck();
    private:
        double wageRate;
        double hours;
    };
}

#endif
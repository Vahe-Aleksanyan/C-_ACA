//
// Created by Vahe Aleksanyan on 15.01.23.
//

#ifndef PROJECT3_EMPLOYEE_H
#define PROJECT3_EMPLOYEE_H

#include <string>
using std::string;

namespace SavitchEmployees {
    class Employee {
    public:
        Employee();
        Employee(const string& theName, const string& theSsn);

        string getName() const;
        string getSsn() const;
        double getNetPay() const;

        void setName(const string& newName);
        void setSsn(const string& newSsn);
        void setNetPay(double newNetPay);

        virtual void printCheck() const = 0; // pure virtual function, now this class is abstract
    private:
        string name;
        string ssn;
        double netPay;
    };
}

#endif //PROJECT3_EMPLOYEE_H

//
// Created by Vahe Aleksanyan on 20.02.23.
//Catching Multiple Exceptions
//

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Here we specify the exceptions that this function
// throws.
void fun(int *ptr, int x) noexcept(false) // Dynamic Exception specification
{
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
    /* Some functionality */
}


class NegativeNumber {
public:
    NegativeNumber() {}

    NegativeNumber(string theMessage) : message(theMessage) {}

    string getMessage() const { return message; }

private:
    string message;
};

class DivideByZero {
};

int main() {
    int pencils, erasers;
    double ppe; //pencils per eraser

    try {
        cout << "How many pencils do you have?\n";
        cin >> pencils;
        if (pencils < 0)
            throw NegativeNumber("pencils");
        cout << "How many erasers do you have?\n";
        cin >> erasers;
        if (erasers < 0)
            throw NegativeNumber("erasers");
        if (erasers != 0)
            ppe = pencils / static_cast<double>(erasers);
        else
            throw DivideByZero();
        cout << "Each eraser must last through "
             << ppe << " pencils.\n";
    } catch (NegativeNumber e) {
        cout << "Cannot have a negative number of "
             << e.getMessage() << endl;
    }
    catch (DivideByZero) {
        cout << "Do not make any mistakes.\n";
    }
    cout << "End of program.\n";


    try {
        fun(NULL, 0);
    }
    catch(...) {
        cout << "Caught exception from fun() \n";
    }


    try {
        try {
            throw 20;
        }
        catch (int n) {
            cout << "Handle Partially ";
            throw; // Re-throwing an exception
        }
    }
    catch (int n) {
        cout << "Handle remaining ";
    }


    return 0;
}

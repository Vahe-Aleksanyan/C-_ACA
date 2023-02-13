//
// Created by Vahe Aleksanyan on 06.01.23.
//

#include "PFArrayD.h"
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
using std::cout;

class PFArrayD {
public:
    PFArrayD();

    PFArrayD(int capacityValue);

    PFArrayD(const PFArrayD &pfaObject); // copy constructor

    void addElement(double element);

    bool full() const { return (capacity == used); }

    int getCapacity() const { return capacity; }

    int getNumberUsed() const { return used; }

    void emptyArray() { used = 0; }

    double &operator[](int index); // Read and change access to elements 0 through numberUsed - 1.

    PFArrayD &operator=(const PFArrayD &rightSide); // overloaded assignement =

    ~PFArrayD(); // destructor
private:
    double *a; //For an array of doubles
    int capacity; //For the size of the array
    int used; //For the number of array positions currently in use
};


PFArrayD::PFArrayD() : capacity(50), used(0) {
    a = new double[capacity];
}

PFArrayD::PFArrayD(int size) : capacity(size), used(0) {
    a = new double[capacity];
}

PFArrayD::PFArrayD(const PFArrayD &pfaObject)
        : capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed()) {
    a = new double[capacity];
    for (int i = 0; i < used; i++)
        a[i] = pfaObject.a[i];
}


void PFArrayD::addElement(double element) {
    if (used >= capacity) {
        cout << "Attempt to exceed capacity in PFArrayD.\n";
        exit(0);
    }
    a[used] = element;
    used++;
}

double &PFArrayD::operator[](int index) {
    if (index >= used) {
        cout << "Illegal index in PFArrayD.\n";
        exit(0);
    }
    return a[index];
}

PFArrayD &PFArrayD::operator=(const PFArrayD &rightSide) {
    if (capacity != rightSide.capacity) {  // Note that this also checks for the case of having the same object on both sides of the assignment operator. delete [] a;
        a = new double[rightSide.capacity];
    }

    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
        a[i] = rightSide.a[i];
    return *this;  // The definition of the overloaded assignment operator uses the this pointer to return the object on the left side of the = sign
}

PFArrayD::~PFArrayD() {
    delete[] a;
}


void testPFArrayD();

int main() {
//    cout << "This program tests the class PFArrayD.\n";
//    char ans;
//    do {
//        testPFArrayD();
//        cout << "Test again? (y/n) ";
//        std::cin >> ans;
//    } while ((ans == 'y') || (ans == 'Y'));
//    return 0;

    return 0;
}

void testPFArrayD() {
    int cap;
    cout << "Enter capacity of this super array: ";
    std::cin >> cap;
    PFArrayD temp(cap);
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    double next;
    std::cin  >> next;
    while ((next >= 0) && (!temp.full())) {
        temp.addElement(next);
        std::cin  >> next;
    }
    cout << "You entered the following "
         << temp.getNumberUsed() << " numbers:\n";
    int index;
    int count = temp.getNumberUsed();
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << std::endl;
    cout << "(plus a sentinel value.)\n";
}




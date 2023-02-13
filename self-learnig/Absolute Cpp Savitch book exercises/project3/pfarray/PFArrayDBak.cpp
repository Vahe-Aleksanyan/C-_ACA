//
// Created by Vahe Aleksanyan on 15.01.23.
//


#include  <iostream>
#include "PFArrayD.h"
#include "PFArrayDBak.h"

using std::cout;
using std::endl;

PFArrayDBak::PFArrayDBak() : PFArrayD(), usedB(0) {
    b = new double[getCapacity()];
}

PFArrayDBak::PFArrayDBak(int capacityValue) : PFArrayD(capacityValue), usedB(0) {
    b = new double[getCapacity()];
}

PFArrayDBak::PFArrayDBak(const PFArrayDBak& Object) : PFArrayD(Object), usedB(0) {
    b = new double[getCapacity()];
    usedB = Object.usedB;
    for(int i=0; i<usedB; i++) {
        b[i] = Object.b[i];
    }
}

void PFArrayDBak::backup() {
    usedB = getNumberUsed();
    for(int i=0; i<usedB; i++) {
        b[i] = operator[] (i);  // the notation operator[](i) means superArray[i]
    }
}

void PFArrayDBak::restore() {
    emptyArray();

    for(int i=0; i<usedB; i++) {
        addElement(b[i]);
    }
}

PFArrayDBak& PFArrayDBak::operator =(const PFArrayDBak& rightSide) {
    int oldCapacity = getCapacity();
    PFArrayD::operator = (rightSide);  // Use a call to the base class assignment operator in order to assign to the base class member variables.

    if(oldCapacity != rightSide.getCapacity()) {
        delete [] b;
        b = new double[rightSide.getCapacity()];
    }

    usedB = rightSide.usedB;
    for(int i=0; i<usedB; i++) {
        b[i] = rightSide.b[i];
    }

    return *this;
}

PFArrayDBak::~PFArrayDBak() {  // The destructor for the base class PFArrayD is called automatically, and it performs delete [ ] a;.
    delete [] b;
}
//
// Created by Vahe Aleksanyan on 16.01.23.
//

#include "PFArrayBak.h"
#include "PFArray.h"
#include <iostream>

using std::cout;
using std::endl;

namespace PFArraySavitch {

    // ths calls to parent class constructor, be careful with syntax
    template<class T>
    PFArrayBak<T>::PFArrayBak() : PFArray<T>(), usedB(0) {
        b = new T[PFArray<T>::getCapacity()];
    }


    // here we use int parameter constructor of parent class
    template<class T>
    PFArrayBak<T>::PFArrayBak(int capacityValue): PFArray<T>(capacityValue), usedB(0) {
        b = new T[PFArray<T>::getCapacity()];
    }

    template<class T>
    PFArrayBak<T>::PFArrayBak(const PFArrayBak<T> &oldObject) : PFArray<T>(oldObject), usedB(0) {
        b = new T[PFArray<T>::getCapacity()];
        usedB = oldObject.getNumberUsed();

        for (int i = 0; i < usedB; i++) b[i] = oldObject.b[i];
    }

    template<class T>
    void PFArrayBak<T>::backup() {
        usedB = PFArray<T>::getNumberUsed();
        for (int i = 0; i < usedB; i++) b[i] = this->operator[](i);
    }

    template<class T>
    void PFArrayBak<T>::restore() {
        PFArray<T>::emptyArray();

        for (int i = 0; i < usedB; i++) this->addElement(b[i]);
    }

    template<class T>
    PFArrayBak<T> &PFArrayBak<T>::operator=(const PFArrayBak<T> &rightSide) {
        PFArray<T>::operator=(rightSide);

        if (PFArray<T>::getCapacity() != rightSide.getCapacity()) {
            delete[] b;
            b = new T[rightSide.getCapacity()];
        }

        usedB = rightSide.usedB;
        for (int i = 0; i < usedB; i++) b[i] = rightSide.b[i];

        return *this;
    }

    template<class T>
    PFArrayBak<T>::~PFArrayBak() {
        delete[] b;
    }


}
//
// Created by Vahe Aleksanyan on 25.01.23.
//


#include <iostream>

#include "utils.h"

int main() {
    using std::cout;
    using std::endl;

    cout << "GCD of 36, 24 = " << Euclid::gcd<36,24>::result << endl;
    return 0;
}
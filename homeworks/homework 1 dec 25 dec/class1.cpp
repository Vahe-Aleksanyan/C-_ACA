//
// Created by Vahe Aleksanyan on 20.12.22.
//

#include <iostream>
#include "homework1.cpp"
using namespace std;

int fibonaccii(double n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    return fibonaccii(n - 1) + fibonaccii(n - 2);
}
int fibonaccii(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonaccii(n - 1) + fibonaccii(n - 2);
}




int main() {
//    print_pascal();
    cout << fibonaccii(10);
}
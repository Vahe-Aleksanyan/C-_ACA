////
//// Created by Vahe Aleksanyan on 15.01.23.
////
//#include <iostream>
//#include "Sale.h"
//#include "DiscountSale.h"
//
//using std::cout;
//using std::endl;
//using std::ios;
//
//using namespace SavitchSale;
//
//int main() {
//    Sale simple(10.00);
//    DiscountSale discount(11.00, 10);
//
//    cout.setf(ios::fixed);
//    cout.setf(ios::showpoint);
//    cout.precision(2);
//
//    // The objects discount and simple use different code for the member
//    //function bill when the less-than comparison is made. Similar remarks apply to savings
//    if(discount < simple) {
//        cout << "Discounted item is cheaper." << endl;
//        cout << "Savings is $" << simple.savings(discount) << endl;
//    } else {
//        cout << "Discounted item is not cheaper." << endl;
//    }
//
//    return 0;
//}
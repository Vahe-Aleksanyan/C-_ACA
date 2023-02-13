////
//// Created by Vahe Aleksanyan on 05.01.23.
////
//
//#include "Money.h"
//#include <iostream>
//#include <cstdlib>
//#include <cmath>
//
//using namespace std;
//
//class Money {
//public:
//    Money();
//
//    Money(double amount);
//
//    Money(int theDollars, int theCents);
//
//    Money(int theDollars);
//
//    double getAmount() const;
//
//    int getDollars() const;
//
//    int getCents() const;
//
//    void input(); //Reads the dollar sign as well as the amount number.
//    void output() const;
//
//    friend ostream &operator<<(ostream &outs, const Money &amount);
//
//    friend istream &operator>>(istream &inputStream, Money &amount);
//
//    // overloading as member functions, can be done also in this way
////    const Money operator +(const Money& amount2) const;
////     const Money operator -(const Money& amount2) const;
////     bool operator ==(const Money& amount2) const;
////     const Money operator -( ) const;
//
//
//// A friend function of a class is an ordinary function except that it has access to the private
////members of objects of that class
//
////    friend const Money operator+(const Money &amount1,
////                                 const Money &amount2);
////
////    friend const Money operator-(const Money &amount1,
////                                 const Money &amount2);
////
////    friend bool operator==(const Money &amount1, const Money &amount2);
////
////    friend const Money operator-(const Money &amount);
//
//private:
//    int dollars;
//    int cents;
//
//    int dollarsPart(double amount) const;
//
//    int centsPart(double amount) const;
//
//    int round(double number) const;
//};
//
//// operator overloasding
//const Money operator+(const Money &amount1,
//                      const Money &amount2); // Returning by const Value makes sure that the returned object (which is an RValue at that point) can't be modified.
//const Money operator-(const Money &amount1, const Money &amount2);
//
//bool operator==(const Money &amount1, const Money &amount2);
//
//const Money operator-(const Money &amount); // unary operator
//
//int main() {
//    Money yourAmount, myAmount(10, 9);
//    cout << "Enter an amount of money: ";
//    cin >> yourAmount;
//    cout << "Your amount is " << yourAmount << endl;
//    cout << "My amount is " << myAmount << endl;
//
//    if (yourAmount == myAmount)
//        cout << "We have the same amounts.\n";
//    else
//        cout << "One of us is richer.\n";
//    Money ourAmount = yourAmount + myAmount;
//    cout << yourAmount << " + "
//         << myAmount  // Since << returns areference, you can chain<< like this. You can chain>> in a similar way
//         << " equals " << ourAmount << endl;
//    Money diffAmount = yourAmount - myAmount;
//    cout << yourAmount << " - " << myAmount
//         << " equals " << diffAmount << endl;
//    return 0;
//}
//
//int Money::dollarsPart(double amount) const {
//    return static_cast<int>(amount);
//}
//
//int Money::centsPart(double amount) const {
//    double doubleCents = amount * 100;
//    int intCents = (round(fabs(doubleCents))) % 100; //% can misbehave on negatives
//    if (amount < 0)
//        intCents = -intCents;
//    return intCents;
//}
//
//
//const Money operator+(const Money &amount1, const Money &amount2) {
//    int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
//    int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
//    int sumAllCents = allCents1 + allCents2;
//    int absAllCents = abs(sumAllCents); //Money can be negative.
//    int finalDollars = absAllCents / 100;
//    int finalCents = absAllCents % 100;
//
//    if (sumAllCents < 0) {
//        finalDollars = -finalDollars;
//        finalCents = -finalCents;
//    }
//    return Money(finalDollars, finalCents);  // anonymous object
//}
//
//const Money operator-(const Money &amount1, const Money &amount2) {
//    int allCents1 = amount1.getCents() + amount1.getDollars() * 100;
//    int allCents2 = amount2.getCents() + amount2.getDollars() * 100;
//    int diffAllCents = allCents1 - allCents2;
//    int absAllCents = abs(diffAllCents);
//    int finalDollars = absAllCents / 100;
//    int finalCents = absAllCents % 100;
//    if (diffAllCents < 0) {
//        finalDollars = -finalDollars;
//        finalCents = -finalCents;
//    }
//    return Money(finalDollars, finalCents);  // anonymous object
//}
//
//
//bool operator==(const Money &amount1, const Money &amount2) {
//    return ((amount1.getDollars() == amount2.getDollars())
//            && (amount1.getCents() == amount2.getCents()));
//}
//
//const Money operator-(const Money &amount) {
//    return Money(-amount.getDollars(), -amount.getCents());
//}
//
//ostream &operator<<(ostream &outputStream, const Money &amount) {
//    int absDollars = abs(amount.dollars);
//    int absCents = abs(amount.cents);
//    if (amount.dollars < 0 || amount.cents < 0)
////accounts for dollars == 0 or cents == 0
//        cout << "$-";
//    else
//        cout << '$';
//    cout << absDollars;
//
//    if (absCents >= 10)
//        cout << '.' << absCents;
//    else
//        cout << '.' << '0' << absCents;
//    return outputStream;  //Returns a reference
//}
//
//istream &operator>>(istream &inputStream, Money &amount) {
//    char dollarSign;
//    inputStream >> dollarSign; //hopefully
//    if (dollarSign != '$') {
//        cout << "No dollar sign in Money input.\n";
//        exit(1);
//    }
//    double amountAsDouble;
//    inputStream >> amountAsDouble;
//    amount.dollars = amount.dollarsPart(amountAsDouble);
//    amount.cents = amount.centsPart(amountAsDouble);
//    return inputStream;  // Returns a reference
//}
//
//Money::Money() : dollars(0), cents(0) {/*Body intentionally empty.*/}
//
//Money::Money(double amount)
//        : dollars(dollarsPart(amount)), cents(centsPart(amount)) {/*Body intentionally empty*/}
//
//Money::Money(int theDollars)
//        : dollars(theDollars), cents(0) {/*Body intentionally empty*/}
//
//
//Money::Money(int theDollars, int theCents) {
//    if ((theDollars < 0 && theCents > 0) ||
//        (theDollars > 0 && theCents < 0)) {
//        cout << "Inconsistent money data.\n";
//        exit(1);
//    }
//    dollars = theDollars;
//    cents = theCents;
//}
//
//double Money::getAmount() const {
//    return (dollars + cents * 0.01);
//}
//
//int Money::getDollars() const {
//    return dollars;
//}
//
//int Money::getCents() const {
//    return cents;
//}
//
//void Money::output() const {
//    int absDollars = abs(dollars);
//    int absCents = abs(cents);
//    if (dollars < 0 || cents < 0)
////accounts for dollars == 0 or cents == 0
//        cout << "$-";
//    else
//        cout << '$';
//    cout << absDollars;
//
//    if (absCents >= 10)
//        cout << '.' << absCents;
//    else
//        cout << '.' << '0' << absCents;
//}
//
////Uses iostream and cstdlib:
//void Money::input() {
//    char dollarSign;
//    cin >> dollarSign; //hopefully
//    if (dollarSign != '$') {
//        cout << "No dollar sign in Money input.\n";
//        exit(1);
//    }
//    double amountAsDouble;
//    cin >> amountAsDouble;
//    dollars = dollarsPart(amountAsDouble);
//    cents = centsPart(amountAsDouble);
//}
//
//
//int Money::round(double number) const {
//    return static_cast<int>(floor(number + 0.5));
//}
////
//// Created by Vahe Aleksanyan on 03.01.23.
////
//
//#include "DayOfYear.h"
//#include <iostream>
//#include <cstdlib> // for exit
//
//using namespace std;
//
//class DayOfYear {
//public:
//    DayOfYear(int monthValue, int dayValue);
//
//    DayOfYear(int MonthValue);
//
//    DayOfYear();
//
//    void input();
//
//    void output();
//
//    void sayHello();
//
//    void set(int newMonth, int newDay);
//
//    void set(int newMonth);
//
//    int getMonthNumber();
//
//    int getDay();
//
//private:
//    int month;
//    int day;
//
//    void testDate();
//};
//
//int main() {
//    DayOfYear date1(2, 21), birthday(2, 4), date2(5), date3;
//    cout << "Initialized dates:\n";
//    date1.output();
//    cout << endl;
//    date2.output();
//    cout << endl;
//    date3.output();
//    cout << endl;
//    date1 = DayOfYear(10, 31);
//    cout << "date1 reset to the following:\n";
//    date1.output();
//    cout << endl;
//    return 0;
//}
//
//DayOfYear::DayOfYear(int monthValue, int dayValue) : month(monthValue), day(dayValue) { // initialisation monthValue to month
//    testDate();
//}
//
//DayOfYear::DayOfYear(int monthValue) : month(monthValue), day(1) {
//    testDate();
//}
//
//DayOfYear::DayOfYear() : month(1), day(1) {}
//
//void DayOfYear::output() {
//    switch (month) {  // we used the member names month and day by themselves without first giving the object and dot operator
//        case 10:
//            cout << "October ";
//            break;
//        case 11:
//            cout << "November ";
//            break;
//        case 12:
//            cout << "December ";
//            break;
//        default:
//            cout << "Error in DayOfYear::output.";
//    }
//    cout << day;
//}
//
//void DayOfYear::set(int newMonth, int newDay) {
//    if ((newMonth >= 1) && (newMonth <= 12))
//        month = newMonth;
//    else {
//        cout << "Illegal month value! Program aborted.\n";
//        exit(1);
//    }
//    if ((newDay >= 1) && (newDay <= 31))
//        day = newDay;
//    else {
//        cout << "Illegal day value! Program aborted.\n";
//        exit(1);
//    }
//}
//
////Uses iostream and cstdlib:
//void DayOfYear::set(int newMonth) {
//    if ((newMonth >= 1) && (newMonth <= 12))
//        month = newMonth;
//    else {
//        cout << "Illegal month value! Program aborted.\n";
//        exit(1);
//    }
//    day = 1;
//}
//
//int DayOfYear::getMonthNumber() {
//    return month;
//}
//
//int DayOfYear::getDay() {
//    return day;
//}
//
////Uses iostream and cstdlib:
//void DayOfYear::input() {
//    cout << "Enter the month as a number: ";
//    cin >> month;
//    cout << "Enter the day of the month: ";
//    cin >> day;
//    if ((month < 1) || (month > 12) || (day < 1) || (day > 31)) {
//        cout << "Illegal date! Program aborted.\n";
//        exit(1);
//    }
//}
//
//void DayOfYear::testDate() {
//
//    if ((month < 1) || (month > 12)) {
//        cout << "Illegal month value!\n";
//        exit(1);
//    }
//    if ((day < 1) || (day > 31)) {
//        cout << "Illegal day value!\n";
//        exit(1);
//    }
//}
//
//void DayOfYear::sayHello() {
//    cout << "hello Niga \n";
//}
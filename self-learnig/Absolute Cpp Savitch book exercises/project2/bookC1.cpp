////
//// Created by Vahe Aleksanyan on 27.12.22.
////
//
//#include <iostream>
//#include <cstdint>
//#include <string>
//#include <fstream>
//#include <cassert> // to debug your program using asseerts
//#define NDEBUG // turns off all asserts
//using namespace std;
//int calc(double a, double b);
//bool isValid(int);
//void sayHello();
//void getInput(double& receiver);
//int main() {
////    Some C++11 Fixed-Width Integer Types   int16_t. uint16_t   int32_t  uint32_t
//    int8_t k = 5;
//    auto x = k / 4;  // deduces the Typo of a variable based  on an expression
//
//    uint8_t m = 6;
//    auto y = m /4;
//
//    decltype(x*3.5) z;
//
//    int myInt = 3.4;
//
//    string fruit = "I am fruit nigga";
//
//    cout << fruit;
//
//    const int BRANCH_COUNT = 10;
//
////    static_cast<Type>(Expression)
////    const_cast<Type>(Expression)
////    dynamic_cast<Type>(Expression)
////    reinterpret_cast<Type>(Expression)
//
//    cout << "You have definitely won\n";
//    cout << "You have definitely won" << endl;
//
////    cout.precision(2);
////    cout.setf(ios::fixed);
////    cout.setf(ios::showpoint);
//    cout << 9.3454 << endl;
//
//
//
//    enum MonthLength { JAN_LENGTH = 31, FEB_LENGTH = 28,
//        MAR_LENGTH = 31, APR_LENGTH = 30, MAY_LENGTH = 31,
//        JUN_LENGTH = 30, JUL_LENGTH = 31, AUG_LENGTH = 31,
//        SEP_LENGTH = 30, OCT_LENGTH = 31, NOV_LENGTH = 30,
//        DEC_LENGTH = 31 };
//
//
//    int score;
//    fstream inputStream;
//    inputStream.open("player.txt");
//    inputStream >> score;
//    cout << "Score: " << score << endl;
//    inputStream.close();
//
//// random number
//    int i;
//    for (i = 0; i < 10; i++) {
//        cout << (rand() % 11) << endl;
//    }
//// floating point value between 0.0 and 1.0:
//    double randNum = (RAND_MAX - rand( ))/static_cast<double>(RAND_MAX);
//    cout << randNum <<"\n";
//
//    sayHello();
//    cout << "I am here " << calc(3, 4) << " Age is " << isValid(calc(13, 34)) << "\n";
//
//
//
//    int arr[] = {20, 30, 40, 50};
//    for(int x : arr) {
//        cout << x << ", ";
//    }
//
//
//
//
//
//
//
//    return 0;
//}
//
//int calc(double a, double b){
//    const double g = 9.8; // local variable
//    return (a + b) * g;
//}
//
//bool isValid(int age) {
//    int sum = 0;
//    if(age  < 100 && age > 0) {
//        sum++;
//        return true;
//    }
//    return false;
//}
//
//void sayHello() {
//    cout << " Hello Nigga\n";
//}
//
//
//// -------------call-by-reference parameter -------------
//void getInput(double& receiver) {
//    cout << "Enter input number:\n";
//    cin >> receiver;
//}
//
//
//// ------------- overloading -------------
//// different number or type of parameters
//// compiler tries to find with exact match, if failed, tryes to find one with automatic type conversion
//
//
//// default argument
//void showVolume(int length, int width = 1, int height = 1);
//
//void showVolume(int length, int width, int height) {
//    cout << "Volume";
//}
//
//
//// ------------- structures -------------
//// composite data type declaration that defines a physically grouped list of variables under one name in a block of memory,
//// allowing the different variables to be accessed via a single pointer or by the struct declared name which returns the
//// same address.
//struct CDAccountV1
//{
//    double balance;
//    double interestRate;
//    int term;//months until maturity
//};
//
//CDAccountV1 doubleInterest(CDAccountV1 oldAccount)
//{
//    CDAccountV1 temp;
//    temp = oldAccount;
//    temp.interestRate = 2*oldAccount.interestRate;
//    return temp;
//}
//
//
//struct Date
//{
//    int month;
//    int day;
//    int year;
//};
//
//Date dueDate = {12, 31, 2012};
//

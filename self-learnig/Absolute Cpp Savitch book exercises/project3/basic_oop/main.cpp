//#include <iostream>
//#include "dtime.h"
//
//void readHour(int &theHour);
//
//int main() {
//
//    using std::cout;
//    using std::cin;
//    using std::endl;
//    using DtimeVahe::DigitalTime;
//
//
//    int theHour;
//    readHour(theHour); // This is a different function readHour than the one in the implementation file dtime.cpp
//
//
//    DigitalTime clock, oldClock;
//
//    cout << "You may write midnight as either 0:00 or 24:00,\n"
//         << "but I will always write it as 0:00.\n"
//         << "Enter the time in 24-hour notation: ";
//    cin >> clock;
//    oldClock = clock;
//    clock.advance(15);
//    if (clock == oldClock)
//        cout << "Something is wrong.";
//    cout << "You entered " << oldClock << endl;
//    cout << "15 minutes later the time will be "
//         << clock << endl;
//    clock.advance(2, 15);
//    cout << "2 hours and 15 minutes after that\n"
//         << "the time will be "
//         << clock << endl;
//    return 0;
//}
//
//
//// When we gave these using declarations before,
////they were in main, so their scope was main.
////Thus, we need to repeat them here in order
////to use cin and cout in readHour
//void readHour(int &theHour) {
//    using std::cout;
//    using std::cin;
//
//    cout << "Let's play a time game.\n"
//         << "Let's pretend the hour has just changed.\n"
//         << "You may write midnight as either 0 or 24,\n"
//         << "but, I will always write it as 0.\n"
//         << "Enter the hour as a number (0 to 24): ";
//    cin >> theHour;
//}
//
//
//
//// Let's play a time game.
////Let's pretend the hour has just changed.
////You may write midnight as either 0 or 24,
////but, I will always write it as 0.
////Enter the hour as a number (0 to 24): 11
////You entered 11:00
////15 minutes later the time will be 11:15
////2 hours and 15 minutes after that
////the time will be 13:30

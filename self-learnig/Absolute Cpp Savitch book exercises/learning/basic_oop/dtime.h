//
// Created by Vahe Aleksanyan on 09.01.23.
//These are those files that store predefined functions.
// It contains definitions of functions that you can include or import using a preprocessor directive #include.
// This preprocessor directive tells the compiler that the header file needs to be processed prior to the compilation.
//

#ifndef PROJECT3_DTIME_H
#define PROJECT3_DTIME_H

#include <iostream>
using std::istream;;
using std::ostream;

namespace DtimeVahe
{
    class DigitalTime {
    public:
        DigitalTime(int theHour, int theMinute);

        DigitalTime();

        //Initializes the time value to 0:00 (which is midnight).
        int getHour() const;

        int getMinute() const;

        void advance(int minutesAdded);

        //Changes the time to minutesAdded minutes later.
        void advance(int hoursAdded, int minutesAdded);

        //Changes the time to hoursAdded hours plus minutesAdded minutes
//later.
        friend bool operator==(const DigitalTime &time1,
                               const DigitalTime &time2);

        friend istream &operator>>(istream &ins, DigitalTime &theObject);

        friend ostream &operator<<(ostream &outs, const DigitalTime &
        theObject);

    private:
        int hour;
        int minute;

        static void readHour(int &theHour);

        //Precondition: Next input to be read from the keyboard is
        //a time in notation, like 9:45 or 14:45.
        //Postcondition: theHour has been set to the hour part of the time.
        //The colon has been discarded and the next input to be read is the
//minute.
        static void readMinute(int &theMinute);

        //Reads the minute from the keyboard after readHour has read the
//hour.
        static int digitToInt(char c);
        //Precondition: c is one of the digits '0' through '9'.
        //Returns the integer for the digit; for example, digitToInt('3')
//returns 3.

    };
}




#endif //PROJECT3_DTIME_H

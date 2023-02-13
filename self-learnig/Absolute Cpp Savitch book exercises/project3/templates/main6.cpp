//
// Created by Vahe Aleksanyan on 16.01.23.
//
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#include "PFArrayBak.h"
#include "PFArray.cpp" // Do not forget to include the implementation of the base class template.
#include "PFArrayBak.cpp"

using PFArraySavitch::PFArrayBak;

int main() {
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayBak<string> a(cap);
    cout << "Enter " << cap << " strings\n";
    cout << "separated by blanks.\n";
    string next;


    for (int i = 0; i < cap; i++) {
        cin >> next;
        a.addElement(next);
    }
    int count = a.getNumberUsed();
    cout << "The following " << count
         << " strings read and stored:\n";
    int index;
    for (index = 0; index < count; index++)
        cout << a[index] << " ";
    cout << endl;
    cout << "Backing up array.\n";
    a.backup();
    cout << "Emptying array.\n";
    a.emptyArray();
    cout << a.getNumberUsed()
         << " strings are now stored in the array.\n";
    cout << "Restoring array.\n";
    a.restore();
    count = a.getNumberUsed();
    cout << "The following " << count
         << " strings are now stored:\n";
    for (index = 0; index < count; index++)
        cout << a[index] << " ";
    cout << endl;
    cout << "End of demonstration.\n";
    return 0;
}

// Enter capacity of this super array: 3
//Enter 3 strings
//separated by blanks.
//I love you
//The following 3 strings read and stored:
//I love you
//Backing up array.
//Emptying array.
//0 strings are now stored in the array.
//Restoring array.
//The following 3 strings are now stored:
//I love you
//End of demonstration.
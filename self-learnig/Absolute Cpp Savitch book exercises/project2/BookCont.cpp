////
//// Created by Vahe Aleksanyan on 05.01.23.
////
//
//#include "BookCont.h"
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//void fillArray(int a[], int size); // Ordinary array parameters
//int search(int a[], int size, int target);
//
//int *doubler(int a[],
//             int size); //Returns: a pointer to an array of the same size as a in which each indexed variable is double the corresponding element in a.
//
//// Vectors
//// When you use the constructor with an integer argument, vectors of numbers are
////initialized to the zero of the number type. If the vector base type is a class type, the
////default constructor is used for initialization.
//int main() {
//
//    //--------- Vectors---------
////    vector<int> v;
////    cout << "Enter a list of positive numbers.\n"
////         << "Place a negative number at the end.\n";
////    int next;
////    cin >> next;
////    while (next > 0) {
////        v.push_back(next);
////        cout << next << " added. ";
////        cout << "v.size( ) = " << v.size() << endl;
////        cin >> next;
////    }
////    cout << "You entered:\n";
////    for (unsigned int i = 0;
////         i < v.size(); i++) // size returns a value of type unsigned int, so use for loop in this way
////        cout << v[i] << " ";
////    cout << endl;
//
//
//
//    // ---------C-string---------
////    char str[4] = "C++";
////    char str1[] = {'C', '+', '+', '\0'};
////    char str2[4] = {'C', '+', '+', '\0'};
//
//    // ---------Standard class string---------
//
////    string phrase;
////    string adjective("fried"), noun("ants");
////    string wish = "Bon appetite!";
////    phrase = "I love " + adjective + " " + noun + "!";
////    cout << phrase << endl
////         << wish << endl;
//
//
////---------Program to demonstrate pointers and dynamic variables.---------
//
////    int *p1, *p2;  // This declares a pointer to an int variable..
////
////    p1 = new int;  // The new operator produces a new, nameless variable and returns a pointer that points to this new variable. Dynamic variable
////    *p1 = 42;  // //Here, * is the dereferencing operator. This assigns 17 to the memory location pointed to by p.
////    p2 = p1;
////
////    cout << "*p1 == " << *p1 << endl;
////    cout << "*p2 == " << *p2 << endl;
////
////    *p2 = 53;
////    cout << "*p1 == " << *p1 << endl;
////    cout << "*p2 == " << *p2 << endl;
////
////    p1 = new int;
////    *p1 = 88;
////    cout << "*p1 == " << *p1 << endl;
////    cout << "*p2 == " << *p2 << endl;
//
//
//    // --------- demonstrate that an array variable is a kind of pointer variable.---------
////
////    typedef int* IntPtr;
////
////    IntPtr p;
////    int a[10];
////    int index;
////
////    for (index = 0; index < 10; index++)
////        a[index] = index;
////
////    p = a;
////
////    for (index = 0; index < 10; index++)
////        cout << p[index] << " ";
////    cout << endl;
////
////    for (index = 0; index < 10; index++)  // Note that changes to the array p are also changes to the array a.
////        cout << a[index] << " ";
////    cout << endl;
//
//
////  ------------------  A Dynamically Allocated Array------------------
////Searches a list of numbers entered at the keyboard.
//
////    typedef int *IntPtr;
////    int arraySize;
////    cout << "How many numbers will be on the list? ";
////    cin >> arraySize;
////    IntPtr a;
////    a = new int[arraySize];
////
////    fillArray(a, arraySize); // The dynamic array a is used like an ordinary array.
////
////    int target;
////    cout << "Enter a value to search for: ";
////    cin >> target;
////    int location = search(a, arraySize, target);
////    if (location == -1)
////        cout << target << " is not in the array.\n";
////    else
////        cout << target << " is element " << location << " in the array.\n";
////    delete[] a;  //destroys the dynamically allocated array pointed to by a
////
//
//
//    //------------------ Returning a Pointer to an Array------------------
//
////    int a[] = {1, 2, 3, 4, 5};
////    int *b;
////
////    b = doubler(a, 5);
////
////    int i;
////    cout << "Array a:\n";
////    for (i = 0; i < 5; i++)
////        cout << a[i] << " ";
////    cout << endl;
////    cout << "Array b:\n";
////    for (i = 0; i < 5; i++)
////        cout << b[i] << " ";
////    cout << endl;
////
////
////    delete[] b;  // This call to delete is not really needed since the program is ending, but in another context it could be important to include this delete.
//
//
////------------------ A Two-Dimensional Dynamic Array------------------
//    typedef int *IntArrayPtr;  // Declare a pointer variable
//
//    int d1, d2;
//    cout << "Enter the row and column dimensions of the array:\n";
//    cin >> d1 >> d2;
//
//    IntArrayPtr *m = new IntArrayPtr[d1];  // Call new: Create a dynamic array using the new operator:
//    int i, j;
//    for (i = 0; i < d1; i++)
//        m[i] = new int[d2];  // Use like an ordinary array:
//
//    cout << "Enter " << d1 << " rows of " << d2 << " integers each:\n";
//    for (i = 0; i < d1; i++)
//        for (j = 0; j < d2; j++)
//            cin >> m[i][j]; // Use like an ordinary array:
//    cout << "Echoing the two-dimensional array:\n";
//
//    for (i = 0; i < d1; i++) {
//        for (j = 0; j < d2; j++)
//            cout << m[i][j] << " ";
//        cout << endl;
//    }
//    for (i = 0; i < d1; i++)
//        delete[] m[i];
//
//
//    delete[] m;  // Note that there must be one call to delete[] for each call to new that created an array.
//
//
//    return 0;
//}
//
//void fillArray(int a[], int size) {
//    cout << "Enter " << size << " integers.\n";
//    for (int index = 0; index < size; index++)
//        cin >> a[index];
//}
//
//int search(int a[], int size, int target) {
//    int index = 0;
//    while ((a[index] != target) && (index < size))
//        index++;
//    if (index == size)//if target is not in a.
//        index = -1;
//    return index;
//}
//
//int *doubler(int a[], int size) {
//    int *temp = new int[size];
//    for (int i = 0; i < size; i++)
//        temp[i] = 2 * a[i];
//    return temp;
//}
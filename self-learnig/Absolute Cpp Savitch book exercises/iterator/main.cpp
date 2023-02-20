#include "iostream"
#include "queue.h"
#include "queue.cpp"
#include "iterator.h"

using std::cin;
using std::cout;
using std::endl;
using namespace VaheQueue;

int main() {
    char next, ans;
    do {
        Queue<char> q;
        cout << "Enter a line of text:\n";
        cin.get(next);
        while (next != '\n') {
            q.add(next);
            cin.get(next);
        }
        cout << "You entered:\n";
        Queue<char>::Iterator i;
        for (i = q.begin(); i != q.end(); i++)
            cout << *i;
        cout << endl;
        cout << "Again?(y/n): ";
        cin >> ans;
        cin.ignore(10000, '\n');
    } while (ans != 'n' && ans != 'N');
    return 0;
}
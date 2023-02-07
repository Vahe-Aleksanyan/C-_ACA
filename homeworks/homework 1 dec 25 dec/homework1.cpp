#include <iostream>
using namespace std;
int ex1() {
    int rows = 5;

    for(int i = 1; i <= rows; ++i) {
        for(int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}

int ex2() {
    int rows = 5;

    for(int i = rows; i >= 1; --i) {
        for(int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}

int ex3() {
    int n = 5;

    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= n; j++) // looping columns
        {
            if (j >= i) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}


int ex4() {
    int n = 5;
    int i = n, j = 0, k = 0;
    while (i > 0) {

        // for number of spaces
        while (k < (n - i)) {
            cout << "  ";
            k++;
        }

        // resetting k because we want to run k from
        // beginning.
        k = 0;
        while (j < i) {
            cout << "* ";
            j++;
        }

        // resetting k so as it can start from 0.
        j = 0;
        i--;
        cout << endl;
    }
}

int ex5() {
    int space, rows = 5;

    for(int i = 1, k = 0; i <= rows; ++i, k = 0) {
        for(space = 1; space <= rows-i; ++space) {
            cout <<"  ";
        }

        while(k != 2*i-1) {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }
    return 0;
}

int ex6() {
    int rows = 5;

    for(int i = rows; i >= 1; --i) {
        for(int space = 0; space < rows-i; ++space)
            cout << "  ";

        for(int j = i; j <= 2*i-1; ++j)
            cout << "* ";

        for(int j = 0; j < i-1; ++j)
            cout << "* ";

        cout << endl;
    }

    return 0;
}

int print_pascal(){
    int rows = 6;
    for(int n = 1; n <= rows; n++){

        for(int r = 1; r < rows-n+1; r++)
            cout<<"  ";

        int val = 1;
        for(int r = 1; r <= n; r++){
            cout<<val<<"   ";

            val = val * (n - r)/r;
        }
        cout<<endl;
    }
    return 0;
}

//int main() {
//    print_pascal();
//}



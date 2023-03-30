//
// Created by Vahe Aleksanyan on 29.03.23.
//

#include <iostream>

using namespace std::chrono;
using namespace std;

// Ex2 b
int fComputer(int n) {
    // base case
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;
    else
        return fComputer(n - 1) + fComputer(n / 2);    //the recursive call
}

const int MAXN = 100005;
int memo[MAXN];

int fComputerTopDown(int n) {
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;
    else if (memo[n] != 0)
        return memo[n];
    else {
        memo[n] = fComputer(n - 1) + fComputer(n / 2);
        return memo[n];
    }
}

const int MAXN2 = 100005;
int memo2[MAXN2];

int fComputerBottomUp(int n) {
    memo2[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (i < 0)
            memo2[i] = 0;
        else
            memo2[i] = memo2[i - 1] + memo2[i / 2];
    }

    return memo2[n];
}

int main() {
    int n = 10;
    int result = fComputer(n);
    cout << "fComputer(" << n << ") = " << result << endl;


    auto start = high_resolution_clock::now();
    int res = fComputerBottomUp(500);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Using BOTTOM_UP function " << res << endl;
    cout << "Time taken function: " << duration.count() << " microseconds" << endl << endl;


     start = high_resolution_clock::now();
    int res2 = fComputerTopDown(500);
     stop = high_resolution_clock::now();
     duration = duration_cast<microseconds>(stop - start);
    cout << "Using TopDown function " << res2 << endl;
    cout << "Time taken function: " << duration.count() << " microseconds" << endl << endl;


    return 0;
}
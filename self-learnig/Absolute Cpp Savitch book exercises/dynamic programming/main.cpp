//
// Created by Vahe Aleksanyan on 01.04.23.
//
#include <iostream>
#include <unordered_map>
#include "vector"
using namespace std::chrono;
using namespace std;

//recursive function
int f_b(int m, int n) {
    if (m == 0 || n == 0) {
        return m + n;
    }

    if(m > 0 && n > 0 && m % 2 == 0) {
        return f_b(m - 1, n) + f_b(m, n - 1);
    }
    if(m > 0 && n > 0 && m % 2 == 1) {
        return f_b(m - 1, n - 1) + 1;
    }
}


//recursive function to top-down DP algorithm
// In this implementation, we are using an unordered map memo to store the previously computed values.
// At each recursive call, we first check if the values have already been computed by looking up the
// unordered map using the string key "m,n". If the values are not in the map, we compute them and store
// the result in the map for future use
int  f_top_down(int m, int n, unordered_map<string, int> &memo) {
    if (m == 0 || n == 0) {
        return m + n;
    }

    string key = to_string(m) + "," + to_string(n);
    if (memo.count(key)) {
        cout << memo[key] << " memoization results" << endl;
        return memo[key];
    }

    int result;
    if (m > 0 && n > 0 && m % 2 == 0) {
        result = f_top_down(m - 1, n, memo) + f_top_down(m, n - 1, memo);
    } else if (m > 0 && n > 0 && m % 2 == 1) {
        result = f_top_down(m - 1, n - 1, memo) + 1;
    }

    memo[key] = result;
    return result;
}




//bottom-up DP algorithm
// In this implementation, we are using a 2D vector dp to store the previously computed values.
// We initialize the dp array with default value 0. Then, we fill in the values of the array by
// looping through all possible values of i and j from 0 to m and n, respectively.
int f_bottom_up(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = i + j;
                cout << dp[i][j] << " memoization results" << endl;;
            }
            else if (i > 0 && j > 0 && i % 2 == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                cout << dp[i][j] << " memoization results" << endl;;
            }
            else if (i > 0 && j > 0 && i % 2 == 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                cout << dp[i][j] << " memoization results" << endl;;
            }
        }
    }

    return dp[m][n];
}


//int main() {
//    int m = 30;
//    int n = 32;
//    auto start = high_resolution_clock::now();
//    int res = f_b(m, n);
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << "ordinary recursion " << res << endl;
//    cout << "Time taken function: " << duration.count() << " microseconds" << endl << endl;
//
//
//
//
//
//    start = high_resolution_clock::now();
//    unordered_map<string, int> memo;
//    int res2 = f_top_down(m,n, memo);
//    stop = high_resolution_clock::now();
//    duration = duration_cast<microseconds>(stop - start);
//    cout << "Using TopDown function " << res2 << endl;
//    cout << "Time taken function: " << duration.count() << " microseconds" << endl << endl;
//
//
//
//    start = high_resolution_clock::now();
//    int res3 = f_bottom_up(m,n);
//    stop = high_resolution_clock::now();
//    duration = duration_cast<microseconds>(stop - start);
//    cout << "Using bottom up function " << res2 << endl;
//    cout << "Time taken function: " << duration.count() << " microseconds" << endl << endl;
//
//
//    return 0;
//}

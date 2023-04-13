//
// Created by Vahe Aleksanyan on 11.04.23.
//
#include <iostream>
#include <vector>
#include <climits>


void filler(std::vector<std::vector<int>>& M, int l, int b, const std::vector<int>& P) {
    int p = l + b;
    M[b][p] = INT_MAX;
    for (int k = b; k < p; ++k) {
        if ((M[b][k] + M[k + 1][p] + P[b] * P[k + 1] * P[p + 1]) < M[b][p]) {
            M[b][p] = (M[b][k] + M[k + 1][p] + P[b] * P[k + 1] * P[p + 1]);
            M[M.size() - b - 1][M.size() - p - 1] = k;
        }
    }
}


std::vector<std::vector<int>> Matrix_chain_order(const std::vector<int>& P) {
    std::vector<std::vector<int>> M(P.size() - 1, std::vector<int>(P.size() - 1));
    for (int l = 1; l < M.size(); ++l) {
        for (int b = 0; b <= M.size() - l - 1; ++b) {
            filler(M, l, b, P);
        }
    }
    return M;
}



void print_Optimal_Parens(const std::vector<std::vector<int>>& s, int i, int j) {
    if (i == j) {
        std::cout << "A" << (i + 1);
    } else {
        std::cout << "(";
        print_Optimal_Parens(s, i, s[s.size() - i - 1][s.size() - j - 1]);
        print_Optimal_Parens(s,  s[s.size() - i - 1][s.size() - j - 1] + 1, j);
        std::cout << ")";
    }
}


int main() {
    std::vector<int> P = { 10, 1, 5, 2, 5, 1 };
    std::vector<std::vector<int>> M = Matrix_chain_order(P);

    std::cout << "An optimal parenthesization will be: ";
    print_Optimal_Parens(M, 0, M.size() - 1);

    return 0;
}

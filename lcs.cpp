#include <iostream>
using namespace std;

int LCS(string X, string Y, int m, int n) {

    if (m == 0 || n == 0)
        return 0;

    if (X[m - 1] == Y[n - 1])
        return 1 + LCS(X, Y, m - 1, n - 1);

    else
        return max(
            LCS(X, Y, m - 1, n),
            LCS(X, Y, m, n - 1)
        );
}

int main() {
    string X = "ABCBDAB";
    string Y = "BDCAB";

    cout << "LCS Length = " << LCS(X, Y, X.length(), Y.length());

    return 0;
}
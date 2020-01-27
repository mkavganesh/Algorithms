/**
 * Change-making problem (via dynamic programming)
 * Goal is to determine minimum no. of coins to be chosen from WALLET that sum up to given VALUE
 
 * @author utkarshpatel@iitkgp.ac.in
 */

#include <iostream>
using namespace std;

#define inf 1e9

int getChangeMinCoin (int n, int w[], int nc) {
    int m[nc+1][n+1];
    for (int i = 0; i <= nc; i++) {
        for (int j = 0; j <= n; j++) {
            m[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) m[0][i] = inf;

    for (int c = 1; c <= nc; c++) {
        for (int r = 1; r <= n; r++) {
            if (w[c-1] == r) m[c][r] = 1;
            else if (w[c-1] > r) m[c][r] = m[c-1][r];
            else {
                m[c][r] = min(m[c-1][r], 1 + m[c][r - w[c-1]]);
            }
        }
    }
    return m[nc][n];
}

int main() {
    int n, nc;
    cout << "Enter no. of coins of distinct denomination: ";
    cin >> nc;
    int w[nc];
    cout << "Enter weight of " << nc << " coins (must be distinct)\n";
    for (int i = 0; i < nc; i++) {
        cout << i+1 << " of " << nc << " coin, weight: ";
        cin >> w[i];
    }
    while (1) {
        cout << "Enter n (or -1 to EXIT): ";
        cin >> n;
        if (n < 0) {
            cout << "exiting...\n";
            break;
        }
        cout << "Minimum no. of coins required is " << getChangeMinCoin(n, w, nc) << "\n";
    }
    return 0;
}

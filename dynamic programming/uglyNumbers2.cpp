/**
 * Super Ugly numbers
 * Numbers whose all primes numbers are in the given set
 */

#include <iostream>
using namespace std;

int mini (int a[], int n) {
    int m  = a[1];
    for (int i = 2; i <= n; i++) {
        if (m > a[i]) m = a[i];
    }
    return m;
}

int main() {
    int n, k;
    cout << "n = ";
    cin >> n;
    cout << "k = ";
    cin >> k;
    int p[k+1];
    cout << "Enter primes : ";
    for (int i = 1; i <= k; i++) cin >> p[i];
    int dp[n+1];
    dp[1] = 1;
    int c[k+1];
    int q[k+1];
    for (int i = 1; i <= k; i++) c[i] = 1;
    for (int i = 1; i <= k; i++) q[i] = p[i] * dp[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = mini(q, k);
        for (int j = 1; j <= k; j++) {
            if (dp[i] == q[j]) {
                q[j] = p[j] * dp[++c[j]];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%4d : %7d\n", i, dp[i]);
    }
    return 0;
}

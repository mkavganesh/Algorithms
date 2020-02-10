/**
 * Ugly numbers
 * Numbers whose prime factors are only 2, 3, 5
 */

#include <iostream>
using namespace std;

int mini (int a, int b, int c) return min(min(a,b),c);

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    int dp[n+1];
    dp[1] = 1;
    int i2, i3, i5;
    i2 = i3 = i5 = 1;
    for (int i = 2; i <= n; i++) {
        int x = dp[i2] * 2;
        int y = dp[i3] * 3;
        int z = dp[i5] * 5;
        int p = mini(x, y, z);
        dp[i] = p;
        if (p == x) i2++;
        if (p == y) i3++;
        if (p == z) i5++;
    }
    for (int i = 1; i <= n; i++) {
        printf("%5d : %7d\n", i, dp[i]);
    }
    return 0;
}

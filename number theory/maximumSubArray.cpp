/**
 * @author utkarshpatel (https://github.com/utkarshiitkgp)
 * 
 * Maximum subarray problem (Divide and conquer paradigm)
 *  Given an 1-indexed array A of n integers, we have to return indexes l and r such that A[l] + A[l+1] + ... + A[r] is maximum possible
 */

#include <bits/stdc++.h>

#define inf (long long)(1e18)

using namespace std;

long long method0 (long long a[], int n) {
    // Complexity: Quadratic in n
    long long psum[n+1];
    psum[0] = 0LL;
    for (int i = 1; i <= n; i++) {
        psum[i] = a[i] + psum[i-1];
    }
    long long ans = LONG_LONG_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            long long csum = psum[j] - psum[i-1];
            if (csum > ans) {
                ans = csum;
            }
        }
    }
    return ans;
}

long long method1 (long long a[], int low, int high) {
    // Complexity: Linearithmic in n
    if (low == high) return a[low];
    int mid = low + (high - low) / 2;
    long long sum1 = method1(a, low, mid);
    long long sum2 = method1(a, mid+1, high);
    long long sum3;

    long long leftsum = -inf;
    long long _sum = 0;
    for (int i = mid; i >= low; i--) {
        _sum += a[i];
        if(_sum > leftsum) {
            leftsum = _sum;
        }
    }

    long long rightsum = -inf;
    _sum = 0;
    for (int i = mid+1; i <= high; i++) {
        _sum += a[i];
        if (_sum > rightsum) {
            rightsum = _sum;
        }
    }
    sum3 = leftsum + rightsum;
    _sum = max (sum1, sum2);
    _sum = max (_sum, sum3);
    return _sum;
}

long long method2 (long long a[], int n) {
    // Complexity: Linear in n
    long long csum = -inf; // current sum
    long long bsum = -inf; // best sum
    long long temp = -inf;
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0 && a[i] > temp) temp = a[i];
        csum = max(0LL, csum + a[i]);
        bsum = max(csum ,bsum);
    }
    return (bsum != 0)? bsum : temp;
}

int main() {
    int n;
    cin >> n;
    long long a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long sum1 = method0(a, n);
    long long sum2 = method1(a, 1, n);
    long long sum3 = method2(a, n);
    cout << "Method 1 : " << sum1 << endl;
    cout << "Method 2 : " << sum2 << endl;
    cout << "Method 3 : " << sum3 << endl;
    return 0;
}

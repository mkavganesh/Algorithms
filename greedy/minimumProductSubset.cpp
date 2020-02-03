/** 
 * @author utkarshpatel (https://github.com/utkarshiitkgp)
 * 
 * MINIMUM PRODUCT SUBSET PROBLEM (greedy paradigm)
 * 
 * Given an array A of n integers, we need to find minimum product possible from multiplying elements of A
 */

#include <bits/stdc++.h>
using namespace std;

int greedy (int a[], int n) {
    int pv = 0, nv = 0, z = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) pv++;
        else if (a[i] < 0) nv++;
        else z++;
    }
    if (nv % 2 == 0 && nv != 0) {
        int maxneg = INT_MIN;
        int product = 1;
        for (int i = 0; i < n; i++) {
            product *= (a[i] != 0)? a[i]: 1;
            if (a[i] < 0 && a[i] > maxneg) maxneg = a[i];
        }
        return product / maxneg;
    } else if (nv % 2 != 0 && nv != 0) {
        int product = 1;
        for (int i = 0; i < n; i++) {
            product *= (a[i] != 0)? a[i]: 1;
        }
        return product;
    } else if (z != 0) return 0;
    int mine = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] < mine) mine = a[i];
    }
    return mine;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << greedy(a, n) << "\n";
    return 0;
}

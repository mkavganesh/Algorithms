/** 
 * @author utkarshpatel (https://github.com/utkarshiitkgp)
 * 
 * Maximize array sum after K negations (Greedy Paradigm) (Using arrays only)
 * Complexity: Linearithmic on array size (no. of -ve elements in particular)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ctr = 0, z = 0, su = 0, pmin = INT_MAX;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            su += x;
            if (x < pmin) pmin = x;
        }
        else if (x < 0) a[ctr++] = x;
        else z++;
    }
    sort(a, a+ctr);
    for (int i = 0; i < ctr; i++) {
        su += (k-- > 0)? (-a[i]): a[i];
    }
    k = (z)? 0: k;
    su = su - pmin + (int)pow(-1, k) * pmin;
    cout << su << "\n";
}

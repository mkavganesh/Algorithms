/* Implementation of MAX-HEAP */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#define trav(a, n) cerr << #a << "[" << n << "] : {"; for (int i = 1; i <= n; i++) cerr << a[i] << ", "; cerr << "}\n"

const int N = 64;
const int inf = 1e9 + 5;

void make_heap(int a[], int n) {
    /* Time Complexity: O(n) */
    int p = n / 2;
    for (int i = p; i >= 1; i--) {
        int ind = (a[2*i] > a[2*i + 1])? 2*i: 2*i + 1;
        if (a[ind] > a[i]) {
            int temp = a[i];
            a[i] = a[ind];
            a[ind] = temp;
        }
    }
    for (int i = 1; i <= p; i++) {
        int ind = (a[2*i] > a[2*i + 1])? 2*i: 2*i + 1;
        if (a[ind] > a[i]) {
            int temp = a[i];
            a[i] = a[ind];
            a[ind] = temp;
        }
    }
}

int pop (int a[], int& n) {
    int ans = a[1];
    a[1] = a[n];
    a[n] = -inf;
    --n;
    int p = n/2;
    for (int i = 1; i <= p;) {
        int ind = (a[2*i] > a[2*i + 1])? 2*i: 2*i + 1;
        if (a[ind] > a[i]) {
            int temp = a[i];
            a[i] = a[ind];
            a[ind] = temp;
            i = ind;
        } else break;
    }
    return ans;
}

signed main() {
    freopen("in.txt", "r", stdin);
    int n, a[N+1];
    memset(a, -inf, sizeof(a));
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    trav(a, n);
    make_heap(a, n);
    trav(a, n);
    while (n> 0) {
        cout << pop(a, n) << " ";
    }
    cout << "\n";
    return 0;
}

#include <iostream>
using namespace std;

#define MOD 1000000007;

void fast_fib(long long int n,long long int ans[]) {
    /* function to return N-th fibonacci number in O(logN) running time */
    long long int a, b, c, d;
    if(n == 0) {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a = ans[0];
    b = ans[1];
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;
    d = (a*a + b*b) % MOD;
    if(n%2 == 0) {
        ans[0] = c;
        ans[1] = d;
    } else {
        ans[0] = d;
        ans[1] = c+d;
    }
}

int main() {
    long long int n;
    cin >> n;
    long long int ans[2]={0};
    fast_fib(n,ans);
    cout << ans[0] << endl;
    return 0;
}

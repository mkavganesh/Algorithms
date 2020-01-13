#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

ll exp(ll x, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return exp(x * x, n / 2);
    return x * exp(x * x, (n - 1) / 2);
}

ll expm(ll x, ll n) {
    if (n == 0) return 1;
    if (n % 2 == 0) return expm((x * x) % M, n / 2);
    return (x * expm((x * x) % M, (n - 1) / 2)) % M;
}

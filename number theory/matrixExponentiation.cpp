#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(), (v).end()
#define sz(a) ((int)a.size())
#define mod 1000000007
#define MOD mod
#define inf 1e18
#define INF inf
#define ll int64
 
typedef long long int64;
typedef vector<int> vi;
typedef vector<int64> v64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<int, bool> pib;
typedef pair<int64, bool> plb;
 
template <typename T>
T expo (T base, T n) {
    if (n == 0) return (T)(1);
    if (n & 1) return (T)(base * expo(base*base, (n-1) / 2));
    return (T)(expo(base*base, n / 2));
}
 
template <typename T>
T expom (T base, T n) {
    if (n == 0) return (T)(1);
    if (n & 1) return (T)(base * expom((base*base) % mod, (n-1) / 2)) % mod;
    return (T)(expom((base*base) % mod, n / 2));
}
 
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = a;
}

const double phi = (sqrt(5) + 1) / (double)(2);
const double phi_i = (sqrt(5) - 1) / (double)(2);

void multiply (ll a[3][3], ll b[3][3]) {
    ll mul[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                mul[i][j] += (a[i][k] * b[k][j]) % mod;
            }
            mul[i][j] %= mod;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = mul[i][j];
        }
    }
}

ll power(ll F[3][3], ll n) {
    ll M[3][3] = {{1LL, 1LL, 1LL}, {1LL, 0LL, 0LL}, {0LL, 1LL, 0LL}};
    if (n == 1) return ((4LL * F[0][0]) % mod + (2LL * F[0][1]) % mod + F[0][2]) % mod;
    power(F, n / 2);
    multiply(F, F);
    if (n % 2) multiply(F, M);
    return ((4LL * F[0][0]) % mod + (2LL * F[0][1]) % mod + F[0][2]) % mod;
}

ll findN(ll n) {
    ll F[3][3] = {{1LL, 1LL, 1LL}, {1LL, 0LL, 0LL}, {0LL, 1LL, 0LL}};
    if (n == 0) return 1LL;
    if (n == 1) return 2LL;
    if (n == 2) return 4LL;
    return power(F, n - 2);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        cout << findN(n) << "\n";
    }
    return 0;
}

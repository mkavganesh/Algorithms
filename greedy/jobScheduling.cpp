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
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
 
typedef long long int64;
typedef vector<int> vi;
typedef vector<int64> v64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<int, bool> pib;
typedef pair<int64, bool> plb;

ll expo (ll base, ll n) {
    if (n == 0) return (ll)(1);
    if (n % 2) return (ll)(base * expo(base*base, (n-1) / 2));
    return (ll)(expo(base*base, n / 2));
}
 
ll expom (ll base, ll n) {
    if (n == 0) return (ll)(1);
    if (n % 2) return (ll)(base * expom((base*base) % mod, (n-1) / 2)) % mod;
    return (ll)(expom((base*base) % mod, n / 2));
}

const double phi = (sqrt(5) + 1) / (double)(2);
const double phi_i = (sqrt(5) - 1) / (double)(2);

bool cmp (pii& a, pii& b) {
    if (a.ff == b.ff) return a.ss > b.ss;
    return a.ff > b.ff;
}

int main() {
    IOS
    int n;
    cout << "Enter no. of jobs : ";
    cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cout << "Deadline and profit (" << i+1 << "/" << n << "): ";
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    sort(all(v), cmp);
    int p = v[0].ff;
    ll ans = 0;
    for (int i = 0; i < p; i++) {
        ans += v[i].ss;
    }
    cout << ans << "\n";
    return 0;
}

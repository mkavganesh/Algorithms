/**
 * @author utkarshpatel (https://github.com/utkarshiitkgp)
 * 
 * Egyptian Fraction Problem
 * Type: Greedy algorithm
 */

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> upmap;

void egyptfrac (double a, double b, int q) {
    if (a == 1.0) {
        cout << int(a) << "/" << int(b) << endl;
        return;
    }
    int r = ceil(b / a);
    if (r == 1) r++;
    if (r == q) r++;
    int num = int(a) * r - int (b);
    int den = int(b) * r;
    int g = __gcd(num, den);
    num /= g;
    den /= g;
    cout << 1 << "/" << r << " + ";
    egyptfrac(double(num), double(den), r);
}

int main () {
    double a, b;
    cout << "Enter a b: ";
    cin >> a >> b;
    egyptfrac(a, b, 1);
    return 0;
}

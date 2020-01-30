/**
 * @author utkarshpatel (https://github.com/utkarshiitkgp)
 * 
 * Egyptian Fraction Problem
 * Type: Greedy algorithm
 */

#include <bits/stdc++.h>
using namespace std;

void egyptfrac (double a, double b) {
    if (a == 1.0) {
        cout << int(a) << "/" << int(b) << endl;
        return;
    }
    int r = ceil(b / a);
    int num = int(a) * r - int (b);
    int den = int(b) * r;
    int g = __gcd(num, den);
    num /= g;
    den /= g;
    cout << 1 << "/" << r << " + ";
    egyptfrac(double(num), double(den));
}

int main () {
    double a, b;
    cout << "Enter a b: ";
    cin >> a >> b;
    egyptfrac(a, b);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll x,y,p,q;
    cin >> x >> y >> p >> q;
    ll num = p*y;
    ll den = q*x;
    ll a = num/(__gcd(num,den));
    ll b = den/(__gcd(num,den));
    ll c = (x*a)/p;
    ll a1 = a;
    ll b1 = b;
    ll i=1;
    while((x*a)%p!=0) {
        a = a1*i; 
        b = b1*i;
        c = (x*a)/p;
        i++;
    }
    cout << a << " " << b << " " << c << "\n";
}
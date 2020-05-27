#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N = 1000000007; // prime modulo value 
long int exponentiation(long int base, 
						long int exp);


ll gcdExtended(ll a, ll b, ll *x, ll *y); 
  
ll modInverse(ll a, ll m) { 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    ll res = (x%m + m) % m; 
    return res;
} 
  
ll gcdExtended(ll a, ll b, ll *x, ll *y) { 
    if (a == 0) { 
        *x = 0, *y = 1; 
        return b; 
    } 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
}

int main() {
    int t; cin >> t; 
    while(t--) {
        ll d; cin >> d;
        ll n = exponentiation(2,d+1);
        n = (n-1)%N;
        ll q_in = modInverse(n,1000000007);
        cout << (1*q_in)%N << "\n";
    }
}


long int exponentiation(long int base, 
						long int exp) 

{ 
	if (exp == 0) 
		return 1; 

	if (exp == 1) 
		return base % N; 

	long int t = exponentiation(base, exp / 2); 
	t = (t * t) % N; 

	// if exponent is even value 
	if (exp % 2 == 0) 
		return t; 

	// if exponent is odd value 
	else
		return ((base % N) * t) % N; 
} 
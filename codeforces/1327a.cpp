#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t; cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        ll bar = k*k;
        if(n<bar) {
            cout << "NO\n";
            continue;
        }
        else {
            if((bar%2==0 and n%2==0) or (bar%2!=0 and n%2!=0)) {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
}
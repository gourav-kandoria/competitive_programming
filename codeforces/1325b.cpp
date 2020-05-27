#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {

        ll n; cin >> n;
        ll * ptr = new ll[n];
        for(ll i=0; i<n; i++) {
            cin >> ptr[i];
        }

        sort(ptr,ptr+n);
        ll count = 1;
        ll prev = ptr[0];
        
        for(ll i=1; i<n; i++) {
            if(ptr[i]!=prev) {
                count++; prev = ptr[i];
            }
        }

        cout << count << endl;
        delete ptr;
    }
}
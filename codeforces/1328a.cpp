#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        ll a,b;
        cin >> a >> b;
        cout << ((a%b==0)? 0 : b-(a%b)) << endl;
    }
}
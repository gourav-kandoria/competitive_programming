#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        int a=1;
        int l;
        int l_gcd;
        for(int i=0; i<n; i++) {
            int tw;
            cin >> tw;
            l_gcd = a;
            l = tw;
            a = __gcd(a,tw);
        }
        int res=1;
        int l_term = l*l_gcd/a;

        for(int i=1; i<=m; i++) {
            int term = (a*i)/__gcd(a,i);
            if(term>l_term) {
                res = i;
                l_term = term;
            }
        }
        cout << res << "\n";
    }
}
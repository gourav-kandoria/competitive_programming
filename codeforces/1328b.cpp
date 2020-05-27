#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string func(ll n, ll k, string & str, ll o) {
    if(str.length()==o) return str;
    ll total_count = (n*(n-1))/2;
    ll count_b = n-1;
    ll count_a = total_count-count_b;

    if(k<=count_a) {
        str = str+'a'; 
        return func(n-1,k,str,o);
    }
    else {
        str = str + 'b';
        ll len = o-str.length();
        k = k-count_a;
        ll pos = len-k+1;
        for(ll i=1; i<=len; i++) {
            if(i==pos) str=str+'b';
            else str=str+'a';
        }
        return str;
    }
}

int main() {
    int t; cin >> t;
    ll arr[3][100010];
    while(t--) {
        ll n,k; cin >> n >> k;
        string st = "";
        if(n==2) {
            cout << "bb\n";
        }
        else 
            cout << func(n,k,st,n) << endl;     
    }
}
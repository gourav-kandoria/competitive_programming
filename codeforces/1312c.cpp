#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool process(ll a, int k, unordered_map<ll,ll> & mp, ll prev) {
    if(a==0) return true;
    if(a%k!=0) return false;
    ll power = 0;
    while(a%k==0) {
        a = a/k;
        power++;
    }
    power = power + prev;
    if(mp.find(power)!=mp.end()) return false;
    mp[power] = 1;
    return process(a-1,k,mp,power);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n,k;
        long long a;
        cin >> n >> k;
        bool result = true;
        unordered_map<ll,ll> count;
        for(int i=0; i<n; i++) {
            cin >> a;
            if(!result) goto place;
            if((a-1)%k==0) {
                a = a-1;
                if(count.find(0)!=count.end()) {
                    result = false; goto place;
                }
                count[0] = 1;
            }
            if(!process(a,k,count,0)) result = false; 
        place: ;
        }
        cout << (result ? "YES" : "NO") << "\n";
    }
}
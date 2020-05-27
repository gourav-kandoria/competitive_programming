#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    ll total_ways = (n*(n-1))/2;
    unordered_map<ll,set<ll> > mp;
    for(short i=0; i<10; i++) {
        ll id; cin >> id;
        mp[id] = set<ll>();
        for(short j=0; j<9; j++) {
            ll enemy;
            cin >> enemy;
            mp[id].insert(enemy);
            if(mp.find(enemy)!=mp.end()) {
                if(mp[enemy].count(id)==0) 
                    total_ways--;
            } 
            else {
                total_ways--;
            }
        }
    }
    cout << total_ways << "\n";
}
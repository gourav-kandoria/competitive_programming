#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        ll n,x;
        cin >> n >> x;
        unordered_map<char, ll> mp;
        ll can_delete = n;        
        ll count = 0;
        for(ll i=0; i<s.length(); i++) {
            if(mp.find(s[i])==mp.end()) {
                mp[s[i]] = 1;
                count++;
            }
            else if(mp[s[i]]==x) {
                if(can_delete>0) {
                    can_delete--;
                } 
                else break;
            }
            else {
                mp[s[i]]++;
                count++;
            }
        }
        cout << count << "\n";
    }
}
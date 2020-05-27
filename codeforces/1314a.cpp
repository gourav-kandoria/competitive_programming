#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    ll arr[n];

    unordered_map<ll, vector<ll> > mp;
    ll a;
    ll t[n];

    for(ll i=0; i<n; i++) cin >> arr[i];
    for(ll i=0; i<n; i++) cin >> t[i];
    vector<ll> heights;

    for(ll i=0; i<n; i++) {
        a = arr[i];
        if(mp.find(a)==mp.end()) {
            mp[a] = vector<ll>();
            mp[a].clear();
            mp[a].push_back(t[i]);
            heights.push_back(a);
        }
        else mp[a].push_back(t[i]);
    }

    sort(heights.begin(),heights.end());
    priority_queue<pair<ll,ll> > que;

    ll result = 0;
    for(ll i=0; i<heights.size(); i++) {
        ll h = heights[i];
        for(int i=0; i<mp[h].size(); i++) {
            que.push(make_pair(mp[h][i],h));
        }
        auto p = que.top();
        que.pop();
        result = result + (p.first)*(h-p.second);
        h++;
        while(!que.empty() and mp.find(h)==mp.end()) {
            auto p = que.top();
            que.pop();
            result = result + (p.first)*(h-p.second);
            h++;
        }
    }
    cout << result << "\n";
}
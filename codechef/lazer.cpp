#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

class query_object {
public:
    int sno; int s; int e; int y;
    query_object(int sno, int s, int e, int y) {
        this->sno = sno; this->s = s; this->e = e; this->y = y;
    }
};

int main() {
    int t; cin >> t;
    while(t--) {
        ll n,q; cin >> n >> q;
        ll tree[4*n+1];
        ll lazy[4*n+1]; 
        fill(tree,tree+(4*n+1),0);
        fill(lazy,lazy+(4*n+1),0);
        ll arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        vector<vector<query_object> > start(n);
        vector<vector<query_object> > end(n);
        vector<ll> heights;

        for(int i=0; i<q; i++) {
            ll a,b,c;
            cin >> a >> b >> c;
            start[a].push_back(query_object(i,a,b,c));            
            end[b].push_back(query_object(i,a,b,c));            
            heights.push_back(c);
        }
        
        sort(heights.begin(), heights.end());
        vector<ll> intersection_till_begin(q);

        for(int i=0; i<(n-1); i++) {
            auto l = lower_bound(heights.begin(),heights.end(),arr[i]);
            vector<ll>::iterator r;
            if(l!=heights.end()) {
                r = upper_bound(heights.begin(),heights.end(),arr[i+1]);
                r--;
            } 
        }
    }
}
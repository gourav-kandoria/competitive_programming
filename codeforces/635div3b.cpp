#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int32_t,int32_t>
#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 
void err() {cout << "-1\n";}
template <typename T>
void print(T a, T b, string end="\n") {
    for_each(a,b,[](auto & i){cout << i << " ";});
    cout << end;
}



int main() {
    ll n,k;
    cin >> n >> k;
    vector<vector<ll> > vec(n+1);
    loop(i,n-1) {
        ll a,b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
        vector<bool> visited(n+1);
        fill(visited.begin(),visited.end(),false);
        ll layers[n+1];
        fill(layers,layers+n+1,0);
        vector<ll> layer(n+1);

        queue<ll> q;
        q.push(1);
        layer[1] = 1;
        ll mx_layer = 1;
        while(!q.empty()) {
            ll ele = q.front();
            q.pop();
            for(auto a : vec[ele]) {
                if(!visited[a]) {
                    visited[a] = true;
                    q.push(a);
                    layer[a] = layer[ele] + 1;
                    mx_layer = max(mx_layer, layer[a]);
                    layers[layer[a]]++;
                }
            } 
        }
        ll taken = min(layers[mx_layer],k);
        k = k - taken;
        ll happiness = taken*(layers[mx_layer]-1);
        mx_layer--;
        ll depth = 1;
        // cout << "mx_layer: " << mx_layer  << endl;
        // cout << "Happiness: " << happiness << endl;
        while(k) {
            taken = min(layers[mx_layer],k);    
            k = k - taken;
            happiness = happiness - taken*depth;
            happiness = happiness + taken*(layers[mx_layer]-1);
            // cout << "mx_layer: " << mx_layer  << endl;
            // cout << "Happiness: " << happiness << endl;
            depth++;
            mx_layer--;
            // cout << "mx_layer: " << mx_layer  << endl;
            // cout << "Happiness: " << happiness << endl;
        }

        cout << happiness << endl;
    }
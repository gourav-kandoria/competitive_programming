#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

#define b() begin()
#define e() end()
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
template <typename T, typename V>
void fill(T & collection, V val) {fill(begin(collection),end(collection),val);}

vector<bool> visited;
vector<vector<ll> > vec;
vector<ll> results;

ll dfs(ll s, ll dep) {
    visited[s] = true;
    ll sz=0;
    for(auto nebr : vec[s]) {
        if(!visited[nebr]) {
            sz+=dfs(nebr,dep+1);
        
    }
    results.pb(dep-sz);
    return sz+1;
}

int main() {
    ll n,k; cin >> n >> k;
    vec.resize(n+1);
    loop(i,n-1) {
        ll a,b;
        cin >> a >> b;
        vec[a].pb(b);
        vec[b].pb(a);
    }
    visited.resize(n+1);
    fill(visited,false);
    dfs(1,0);
    sort(results.begin(), results.end(), greater<>());
    ll sum = 0;
    loop(i,k) sum+=results[i];
    cout << sum << "\n";
}

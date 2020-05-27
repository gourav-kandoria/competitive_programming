#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define print(val) print_helper(#val, val);
#define bg begin
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int32_t,int32_t>
#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 
#define fast_io ios_base::sync_with_stdio(false);
void err() {cout << "-1\n";}
template <typename T>
void print_c(T & a) {
for_each(begin(a),end(a),[](auto & i){cout << i << " ";}); cout << "\n"; }
template <typename T, typename V>
void fill(T & collection, V val) {fill(begin(collection),end(collection),val);}
template <typename T>
void print_helper(string name, T val) {cout << name << ": " << val << "\n";}

int main() {
  fast_io
  int t; cin >> t;
  while(t--) {
    string s,r;
    cin >> s >> r;
    bool found = 0;
    vector<ll> diffs;
    ll f=-1,l=-1;
    loop(i,s.length()){
      if(s[i]==r[i]) continue;
      if(!found) {
        found = true;
        f = i; l = i;
        continue;
      }
      diffs.pb(i-l-1);
      l = i;
    }
    if(f==-1) {
      cout << 0 << "\n"; continue;
    }
    ll cost = l-f+1;
    ll len = cost;
    sort(diffs.begin(),diffs.end(),greater<>());
    ll sz = 2;
    for(auto val : diffs) {
      len-=val;
      cost=min(cost,len*sz);
      sz++;
    }
    cout << cost << "\n";
  }
}
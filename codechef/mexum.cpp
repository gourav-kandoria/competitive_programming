#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
#define print(val) print_helper(#val, val);
#define bg begin
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int32_t,int32_t>
#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
template <typename T>
void print_c(T & a) {
for_each(begin(a),end(a),[](auto & i){cout << i << " ";}); cout << "\n"; }
template <typename T, typename V>
void fill(T & collection, V val) {fill(begin(collection),end(collection),val);}
template <typename T>
void print_helper(string name, T val) {cout << name << ": " << val << "\n";}

ll power(ll x, ll y, ll p) {  
    ll res = 1;
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0) {
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}

int main() {
  fast_io
  ll t; cin >> t;
  while(t--) {
    ll n;  cin >> n;
    unordered_map<ll,ll> mp;
    loop(i,n) {
      ll a; cin >> a; 
      if(mp.find(a)==mp.end()) mp[a]=1;
      else mp[a]++;
    }
    ll behind=0;
    ll mul=1;
    ll res=0;
    ll how_much=0; 
    loop1(i,1,n+2) {
      if(mp.find(i)!=mp.end()) {
        ll ahead = n-behind-mp[i];
        ll t = power(2,ahead,mod);
        t = (t*mul)%mod;
        how_much = (how_much+t)%mod;
        res = res + (i*t)%mod;
        mul = (mul*(power(2,mp[i],mod) - 1))%mod;
        behind+=mp[i];
      }
      else {
        ll rem = (power(2,n,mod)-how_much+2*mod)%mod;  
        res = (res + (i*rem)%mod)%mod;
        break;
      }
    }
    cout << res << "\n";
  }
}
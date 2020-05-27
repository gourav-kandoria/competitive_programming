#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
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
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
    ll n,k,a;   cin >> n >> k;
    vector<ll> vec;
    loop(i,n) {
      cin >> a;
      vec.pb(a);
    }
    vector<ll> x(2*k+1);
    fill(x.begin(),x.end(),0);
    vector<ll> minv(2*k+1);
    fill(minv.begin(),minv.end(),0);
    vector<ll> kminv(2*k+1);
    fill(kminv,0);
    loop(i,n/2) {
      ll sum = vec[i]+vec[n-1-i];
      x[vec[i]+vec[n-1-i]]++;
      minv[min(vec[i],vec[n-1-i])]++;
      kminv[k+sum-min(vec[i],vec[n-1-i])]++;
    }
    for(ll i=minv.size()-2; i>=0; i--) {
      minv[i] = minv[i] + minv[i+1];
    }
    vll kminv1(2*k+1);
    fill(kminv1,0);
    for(ll i=1; i<kminv.size(); i++) {
      kminv1[i] = kminv1[i-1] + kminv[i-1];
    }
    ll res = LONG_LONG_MAX;
    for(ll h=2; h<=(2*k); h++) {
      ll total = n/2;
      ll term = 0;
      total-=x[h];
      total-=(minv[h]);
      // print(total);
      term+=(2*minv[h]);
      total-=kminv1[h];
      term+=(2*kminv1[h]);
      term+=(total);
      res = min(term,res);
    }
    cout << res << "\n";
  }
}

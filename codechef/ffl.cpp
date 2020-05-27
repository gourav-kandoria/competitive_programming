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
    ll n,s; cin >> n >> s;
    ll mn1 = 10000;
    ll mn2 = 10000;
    vector<ll> vec;
    vector<bool> vecb;
    for(int i=0; i<n; i++) {
      ll a;
      cin >> a;
      vec.push_back(a);
    }
    for(int i=0; i<n; i++) {
      ll a; cin >> a;
      vecb.pb(a);
    }
    for(int i=0; i<n; i++) {
       if(vecb[i]==0) mn1=min(mn1,vec[i]);
      else if(vecb[i]==1) mn2=min(mn2,vec[i]);
    }
    if(mn1+mn2+s<=100) {cout << "yes\n";}
    else cout << "no\n";
  }
}
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
  int n,k; cin >> n >> k;
  vector<ll> vec(n+1);
  iota(vec.begin(),vec.end(),0);
  vector<ll> prefix_sum(n+1);
  vector<ll> suffix_sum(n+1);
  prefix_sum[0] = 0;
  suffix_sum[0] = n;
  loop1(i,1,n) {
    prefix_sum[i] = prefix_sum[i-1] + vec[i];
    suffix_sum[i] = suffix_sum[i-1] + vec[n-i];
  }
  ll total = 0;
  loop1(i,k,n+1) {
    total = ( total + (suffix_sum[i-1]-prefix_sum[i-1]+1) )%mod;
  }
  cout << total << "\n";
}
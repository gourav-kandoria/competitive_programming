//https://codeforces.com/contest/1353/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define pll pair<ll,ll>
#define pii pair<int32_t,int32_t>
#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(val) cout << #val << ": " << val << "\n";
#define print_c(a) cout<<#a<<": ";for(auto it=begin(a);it!=end(a);it++)cout<<*it<<" ";cout<<"\n";
#define fill(c,v) fill(begin(c),end(c),v);
template <typename T> T flip(T val) {reverse(begin(val),end(val)); return val;}

int main() {
  fast_io
  ll t=1; 
  cin >> t;

  for(int i=0; i<n; i++) {
    while(t--) {
      cout << t << "\n";
      
    }
  while(t--) {
    ll n; cin >> n;
    ll sum=0;
    ll level = 1;
    for(ll i=3; i<=n; i+=2) {
      ll boxes = ((i-2)*4+4);
      sum+=(boxes*level);
      level++;
    }
    cout << sum << "\n";
  }
}
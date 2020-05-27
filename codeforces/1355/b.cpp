//https://codeforces.com/contest/1355/problem/B
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
  while(t--) {
    ll n; cin >> n;
    vector<ll> vec(n);
    loop(i,n) cin >> vec[i];
    sort(vec.begin(),vec.end());
    ll dp[n];
    if(vec[0]==1) dp[0]=1;
    else dp[0]=0;
    for(ll i=1; i<n; i++) {
      ll index = i-vec[i];
      if(index==-1) {
        dp[i] = max(dp[i-1], (ll)1);
      }
      else if(index<-1) {
        dp[i] = dp[i-1];
      }
      else {
        dp[i] = max(1 + dp[index], dp[i-1]);
      }
    }
    cout << dp[n-1] << "\n";
  }
}
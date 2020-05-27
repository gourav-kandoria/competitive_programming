//https://codeforces.com/contest/1354/problem/D
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
  while(t--) {
    ll n,s; cin >> n >> s;
    if(s<2*n) cout << "NO\n";
    else {
      cout << "YES\n";
      ll sum=0;
      loop(i,n) {
        if(i==n-1) cout << s-sum << " ";
        else cout << 2 << " ";
        sum+=2;
      }
      cout << "\n1\n";
    }
  }
}
//https://codeforces.com/contest/1353/problem/B
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
    int n,k; cin >> n >> k;
    vector<int> a(n);
    vector<int> b(n);
    loop(i,n) cin >> a[i];
    loop(i,n) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end()); reverse(b.begin(),b.end());
    ll sum = 0;
    loop(i,n) {
      if(i<k) sum+=(a[i]>b[i] ? a[i] : b[i]); 
      else sum+=a[i];
    }
    cout << sum << "\n";
  }
}
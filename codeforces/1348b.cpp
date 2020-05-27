#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define bg begin
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int32_t,int32_t>
#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define print(val) cout << #val << ": " << val << "\n";
#define print_c(a) cout<<#a<<": ";for_each(begin(a),end(a),[](auto&i){cout<<i<<" ";});cout<<"\n";
#define fill(c,v) fill(begin(c),end(c),v);

int main() {
  fast_io
  ll t; cin >> t;
  while(t--) {
    int n,k; cin >> n >> k;
    int count=0;
    map<int,int> mp;
    vector<int> vec;
    loop(i,n) {
      int a;
      cin >> a; 
      if(mp.find(a)==mp.end()) {mp[a] = 1; vec.push_back(a); count++; }
    }
    if(count>k) {cout << "-1\n"; continue;}
    cout << k*100 << "\n";
    ll cnt=0;
    loop(j,100) {
      for(auto a : vec) {cout << a << " ";}
      if(vec.size()==k) continue; 
      cnt=vec.size();
      loop1(i,1,n) {
        if(mp.find(i)==mp.end()) {
          cout << i << " "; cnt++;
        }
        if(cnt==k) break;
      }
    }
    cout << "\n"; 
  }
}
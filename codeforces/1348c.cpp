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
    ll n,k; cin >> n >> k;
    string str; cin >> str;
    vector<string> vec(k);
    fill(vec,"");
    sort(str.begin(),str.end());
    ll index;
    loop(i,str.length()) {
      index = i%k;
      vec[index]=vec[index]+str[i];
      if(index==0) continue;
      if(vec[index]>vec[index-1]) break; 
    } 
    cout << vec[index] << "\n";
  }
}
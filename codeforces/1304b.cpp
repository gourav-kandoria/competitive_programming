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
    ll n,m; cin >> n >> m;
    ll mn = m; ll mx = m;
    ll prev_vt = 0;
    bool found=false;
    vector<pll > ranges;
    vector<ll> time;
    loop(i,n){
      ll vt,l,r; cin >> vt >> l >> r;
      time.pb(vt);
      mn = mn - (vt-prev_vt);
      mx = mx + (vt-prev_vt);
      pll temp = {l,r};
      pll p2 = {mn, mx};
      if(temp.first>p2.first) swap(temp,p2);
      if(temp.second < p2.first) {found = true;}
      else {
        ranges.pb({p2.first,min(temp.second,p2.second)});
      }
      prev_vt = vt;
    }
    pll p1;
    if(found) {cout << "NO\n"; goto place;}
    // p1 = ranges[n-1];
    // rloop(i,n-1) {
    //   pll temp;
    //   temp.first = p1.first-(time[i+1]-time[i]);
    //   temp.second = p1.second+(time[i+1]-time[i]);
    //   pll p2 = ranges[i];
    //   if(temp.first>p2.first) swap(temp,p2);
    //   if(temp.second < p2.first) {cout << "NO\n"; goto place;}
    //   else {
    //     p1 = {p2.first,min(temp.second,p2.second)};
    //   }
    // }
    cout << "YES\n";
    place: ;
  }
}
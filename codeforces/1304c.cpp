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
  // fast_io
  int t; t=1;
  while(t--) {
    int n,m; cin >> n >> m;
    vector<pair<string, bool> > vec;
    loop(i,n) {
      string str;
      cin >> str; vec.push_back({str,0});
    }
    map<string, ll> middle;
    vector<string> to_add;
    loop(i,n) {
      if(vec[i].second==1) continue;
      string s = vec[i].first;
      reverse(s.begin(),s.end());
      if(vec[i].first==s) {
        if(middle.find(s)==middle.end()) {
          middle[s] = 1;
        }
        else middle[s]++;
      }
      loop1(j,i+1,n-1) {
        string s = vec[j].first; 
        reverse(s.begin(),s.end());
        if(vec[i].first==s) {
          vec[j].second=1;
          to_add.push_back(s);
          break;
        }
      }
    }
    // print_c(to_add);
    string ans = "";
    for(auto a : to_add) {
      ans+=a; 
    }
    string key="-";
    middle[key]=0;
    ll count = 0;
    // print(middle.size());
    for(auto mp : middle) {
      if(mp.second>count) {
        count=mp.second;
        key = mp.first;
      }
    }
    while(middle[key]--) {
      ans+=key;
    }
    reverse(to_add.begin(),to_add.end());
    for(string & a : to_add) { 
      reverse(a.begin(),a.end());
      ans+=a;
    }
    cout << ans.length() << "\n" << ans;
  }
}
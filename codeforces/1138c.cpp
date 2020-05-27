#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
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
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
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
  int n,m;
  cin >> n >> m;
  ll arr[1001][1001]; 
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) cin >> arr[i][j];
  }
  vector<vector<ll> > vec(n);
  vector<vector<ll> > vec1(m);
  vector<ll> nuniq(n);
  vector<ll> muniq(m);
  for(int i=0; i<n; i++) {
    unordered_map<ll,ll> mp;
    ll cnt=0;
    for(int j=0; j<m; j++) {
      if(mp.find(arr[i][j])==mp.end()) {
        cnt++; mp[arr[i][j]]=1;
        vec[i].pb(arr[i][j]);
      }
    }
    nuniq[i]=cnt;
    sort(vec[i].begin(),vec[i].end());
  }
  for(int j=0; j<m; j++) {
    unordered_map<ll,ll> mp;
    ll cnt=0;
    for(int i=0; i<n; i++) {
       if(mp.find(arr[i][j])==mp.end()) {
        cnt++; mp[arr[i][j]]=1;
        vec1[j].pb(arr[i][j]);
      }
    }
    muniq[j]=cnt;
    sort(vec1[j].begin(),vec1[j].end());
  }
  ll res[n][m];
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      ll hsthan = lower_bound(vec[i].begin(), vec[i].end(), arr[i][j]) - vec[i].begin()+1;
      ll vsthan = lower_bound(vec1[j].begin(), vec1[j].end(), arr[i][j]) - vec1[j].begin()+1;
      if(hsthan > vsthan) {
        if(nuniq[i]>muniq[j]) {
          res[i][j] = nuniq[i]; 
        }
        else res[i][j] = muniq[j] + hsthan-vsthan;
      }
      else {
        if(muniq[j]>nuniq[i]) {
          res[i][j] = muniq[j]; 
        }
        else res[i][j] = nuniq[i] + vsthan-hsthan;
      }
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cout << res[i][j] << " ";
    } cout << "\n";
  }
}
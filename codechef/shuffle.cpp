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
  int t; cin >> t;
  while(t--) {
    ll n,k; cin >> n >> k;
    vector<ll> vec;
    vector<map<ll,ll> > v2(k); 
    ll j=0;
    loop(i,n) {
      ll a; cin >> a; vec.pb(a);
      v2[j][a]++;
      j=(j+1)%k;
    }
    sort(vec.begin(),vec.end());
    j = 0;
    loop(i,n) {
      if(v2[j].find(vec[i])==v2[j].end()) {
        cout << "no\n"; goto place;
      }
      if(v2[j][vec[i]]==0) {
        cout << "no\n"; goto place;
      }
      v2[j][vec[i]]--;
      j=(j+1)%k;
    }
    cout << "yes\n";
    place:  ;
  }
}
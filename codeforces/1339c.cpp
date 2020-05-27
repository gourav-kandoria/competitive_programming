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
  int T; cin >> T;
  while(T--) {
    ll n; cin >> n;
    vector<ll> vec(n);
    loop(i,n) cin >> vec[i];
    ll mx = -1;
    ll prev = vec[0];
    loop1(i,1,n-1) {
      if(prev<=vec[i]) {
        prev=vec[i];
        continue;
      }
      ll t=1;
      ll diff = prev-vec[i];
      ll p = 0;
      while(diff>(t+t-1)) {
        t*=2; p++;
      }
      mx = max(mx,p);
      ll height=vec[i];
      while(height<prev) {
        if(t+t-1 < diff) {
          diff-=(2*t);
          height+=(2*t);
        }
        if(t==1 and height<prev) {
          diff-=1;
          height+=1;
        }
        t/=2;
      }
      prev=height;
    }
    cout << mx+1 << "\n";
  }
}

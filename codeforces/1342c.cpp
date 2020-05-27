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
    ll a,b,q; cin >> a >> b >> q;
    ll lcm = (a*b)/__gcd(a,b);
    if(a>b) swap(a,b);
    vector<ll> sums(lcm+1);
    sums[0]=0;
    loop1(i,1,lcm) {
      ll t1 = (i%a)%b;
      ll t2 = (i%b)%a;
      if(t1!=t2) {sums[i]=sums[i-1]+1;}
      else sums[i]=sums[i-1];
    }
    while(q--) {
      ll l,r; cin >> l >> r;
      ll left_pos = l/lcm;
      ll left_rem = 0;
      if(l%lcm!=0) {
        left_pos++;
        left_rem = (lcm*(left_pos)-l)+1;
      }
      ll right_rem = 0;
      ll right_pos = r/lcm;
      right_rem = r - right_pos*lcm;
      ll ans=0;
      ans+=(right_pos-left_pos)*sums[lcm];
      ans+=(sums[right_rem]);
      ans+=(sums[lcm]-sums[lcm-left_rem]);
      cout << ans << " ";
    }
    cout << "\n";
  }
}
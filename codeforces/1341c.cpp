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
    ll n; cin >> n;
    unordered_map<ll,ll> mp;
    set<ll> count;
    multiset<ll> s;
    loop1(i,1,n) {
      ll p;
      cin >> p; mp[p]=i;
      count.insert(i);
      s.insert(1);
    }
    vector<ll> arr(n+1);
    fill(arr,1);
    ll mx = 1;
    loop1(i,1,n) {
      ll pos = mp.at(i);
      // print_c(count);
      // print_c(arr);
      // print(mx);
      // print_c(s);
      if(arr[pos]==mx and arr[pos]>0) {
        auto it=count.upper_bound(pos);
        if(it != count.end()) {
          auto ptr = s.find(arr[*it]);
          auto ptr1 = ptr;
          // if(ptr!=s.end()) {
          // s.erase(ptr1,++ptr);
          // }
          // else s.erase(arr[*it]);
          s.erase(ptr1,++ptr);
          arr[*it]+=arr[pos];
          s.insert(arr[*it]);
        }
        auto ptr = s.find(arr[pos]);
        auto ptr1 = ptr;
        s.erase(ptr1,++ptr);
        // if(ptr!=s.end()) {
        //   s.erase(ptr1,++ptr);
        // }
        // else {
        //   s.erase(arr[pos]);
        // }
        arr[pos]=0;
        count.erase(pos);
        if(s.empty()) continue;
        mx = *(--(s.end()));
      }
      else {
        cout << "No\n"; 
        goto place;
      }
    }
    cout << "Yes\n";
    place: ;
  }
}

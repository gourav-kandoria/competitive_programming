//https://codeforces.com/contest/1353/problem/D
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
    ll n; cin >> n;
    vector<ll> arr(n);
    auto comp = [](pll a, pll b) {
      ll resa = a.second - a.first;
      ll resb = b.second - b.first;
      if(resa<resb) return true;
      else if(resa>resb) return false;
      return a.first > b.first;
    };
    priority_queue<pll, vector<pll>, decltype(comp)> que(comp);
    que.push({1,n});
    ll count = 1;
    while(!que.empty()) {
      pll t = que.top(); que.pop();
      if(t.first==t.second) {
        arr[t.first-1]=count++;
      }
      else {
      ll pos = (t.first+t.second)/2;
      arr[pos-1] = count++;
      if(t.second-t.first==1) {
        que.push({t.second,t.second});
      }
      else {
        que.push({t.first,pos-1});
        que.push({pos+1, t.second});
      }
      // cout << "Hello World\n";
      }
    }
    for(auto a : arr) 
      cout << a << " ";
    cout << "\n";
  }
}
//https://codeforces.com/contest/1354/problem/C
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
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<ll> vec(b-a+1);
  iota(vec.begin(),vec.end(),a);
  ll sum=0;
  loop1(i,b,c) {
    ll d_count, c_count;
    auto it = lower_bound(vec.begin(),vec.end(), d+1-i);
    d_count = vec.end() - it;
    auto it1 = lower_bound(vec.begin(),vec.end(), c+1-i);
    c_count = (vec.end() - it1) - d_count;
    ll c_sum = 0;
    if(c_count) {
      ll val = *it1;
      ll temp = val - c + i;
      c_sum = (c_count*(temp + temp+c_count-1))/2;
    }
    sum = sum + c_sum + d_count*(d-c+1);
  }
  cout << sum << "\n";
}
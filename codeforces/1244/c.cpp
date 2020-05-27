//https://codeforces.com/contest/1244/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define pll pair<ll,ll>
#define pii pair<int32_t,int32_t>
#define loop(i,n) for(int64_t i=0;i<n;i++)
#define loop1(i,a,b) for(int64_t i=a;i<=b;i++)
#define rloop(i,n) for(int64_t i=n-1;i>=0;i--) 
#define rloop1(i,a,b) for(int64_t i=a;i>=b;i--) 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define print(val) cout<<#val<<": "<<val<<"\n";
#define print_c(a) cout<<#a<<": ";for(auto it=begin(a);it!=end(a);it++)cout<<*it<<" ";cout<<"\n";
#define fill(c,v) fill(begin(c),end(c),v);
template<typename T> T flip(T val){reverse(begin(val),end(val));return val;}
ll gcdExtended(ll a, ll b, ll & x, ll &y);

int main() {
  fast_io
  ll n,p,w,d; cin >> n >> p >> w >> d;
  ll lb = 1; ll ub = n;
  ll gcd = __gcd(w,d);
  if(p%__gcd(w,d)==0) {
    ll x,y;
    gcdExtended(w, d, x, y);
    x*=p/gcd;
    y*=p/gcd;
    ll t1 = d/gcd;
    ll t2 = w/gcd;
    ll ub = 1000000000000; 
    ll lb = -ub;
    ll res=0;
    while(lb<=ub) {
      ll mv = (lb+ub)/2;
      ll x1 = x - mv*t1; 
      ll y1 = y + mv*t2;
      if(y1<0) {
        lb = mv+1;
      }
      else if(x1<0) {
        ub = mv-1;
      } 
      else if(x1 >= 0 and y1 >= 0 and (x1+y1) <= n) {
        ub = mv-1;
        res = mv;
      }
      else {
        ub = mv-1;
      }
      // cout << "stuck in loop\n";
    }
    ll x1 = x - res*t1;
    ll y1 = y + res*t2;

    if(x1 >= 0 and y1>=0 and (x1+y1)<=n) {
      cout << x1 << " " << y1 << " " << n-x1-y1 << "\n";
    }
    else {
      cout << "-1\n";
    }
  }
  else {
    cout << "-1\n";
  }
}


ll gcdExtended(ll a, ll b, ll &x, ll &y) {  
    if (a == 0)  {  
        x = 0;  
        y = 1;  
        return b;  
    }  
    ll x1, y1; // To store results of recursive call  
    ll gcd = gcdExtended(b%a, a, x1, y1);  
  
    x = y1 - (b/a) * x1;  
    y = x1;  
  
    return gcd;  
}  
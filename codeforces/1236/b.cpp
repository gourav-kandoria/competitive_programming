//https://codeforces.com/contest/1236/problem/B
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

 
ll fast_ex(ll A, ll B, ll C)   {  
    if (A == 0)  
        return 0;  
    if (B == 0)  
        return 1;  
    ll y;  
    if (B % 2 == 0) {  
        y = fast_ex(A, B / 2, C);  
        y = (y * y) % C;  
    }  
    else {  
        y = A % C;  
        y = (y * fast_ex(A, B - 1, C) % C) % C;  
    }  
    return (ll)((y + C) % C);  
}  

int main() {
  fast_io
  ll n,m; cin >> n >> m;
  ll temp = (fast_ex(2,m,mod) - 1)%mod;
  ll ans  = fast_ex(temp,n,mod);
  cout << ans << "\n";
}
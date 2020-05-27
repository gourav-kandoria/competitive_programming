#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int32_t,int32_t>
#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 
void err() {cout << "-1\n";}
template <typename T>
void print(T a, T b, string end="\n") {
for_each(a,b,[](auto & i){cout << i << " ";}); cout << "\n"; }
template <typename T, typename V>
void fill(T & collection, V val) {fill(begin(collection),end(collection),val);}

int main() {
    int t; cin >> t;
    while(t--) {
        ll n,m; cin >> n >> m;
        ll sum = 0;
        loop(i,n) {
            ll a; cin >> a;
            sum+=a;
        }
        cout << min(sum,m) << "\n";
    }
}

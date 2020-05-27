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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,p; cin >> n >> m >> p;
    ll a,b;
    ll mna;
    ll mnb;
    bool pass = false;
    loop(i,n) {
        cin >> a;
        if(pass) goto place1;
        if(a%p!=0) {
            mna = i; pass = 1;
        }
        place1: 
        ;
    } 
    pass = false;
    loop(i,m) {
        cin >> a;
        if(a%p!=0) {
            mnb = i; pass = 1;
            break;
        }
    } 

    place:
    cout << mna+mnb << "\n";
}

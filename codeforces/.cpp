#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

#define pb push_back;
#define pll pair<ll,ll> ;
#define pii pair<int32_t,int32_t> 
#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 
void err() {cout << "-1\n";}
template <typename T>
void print(T a, T b, string end="\n") {
    for_each(a,b,[](auto & i){cout << i << " ";});
    cout << end;
}

bool tc_more_than_one = 1;
void solve() {
    ll n; cin >> n;
    if(n==1 or n==2) {
        cout << 0 << "\n";
    }
    else {
        cout << (n-(n/2)-1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; 
    if(tc_more_than_one) {
        cin >> t;
    }
    else t=1;
    while(t--) solve();
}
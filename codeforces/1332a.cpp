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
    for_each(a,b,[](auto & i){cout << i << " ";});
    cout << end;
}

bool tc_more_than_one = 1;

void solve() {
    ll a,b,c,d; cin >> a >> b >> c >> d;
    ll x,y,x1,y1,x2,y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if(!(x<=x2 and x>=x1)) {cout << "No\n"; return;}
    if(b-a == 0 and b!=0 and a!=0) {
        if(!((x-1<=x2 and x-1>=x1) or (x+1<=x2 and x+1>=x1))) {cout << "No\n"; return;}
    }
    else {
        ll xe = x+b-a;
        if(!(xe<=x2 and xe>=x1)) {cout << "No\n"; return;}
    }

    if(!(y<=y2 and y>=y1)) {cout << "No\n"; return;}
    if(d-c == 0 and d!=0 and c!=0) {
        if(!((y-1<=y2 and y-1>=y1) or (y+1<=y2 and y+1>=y1))) {cout << "No\n"; return;}
    }
    else {
        ll ye = y+d-c;
        if(!(ye<=y2 and ye>=y1)) {cout << "No\n"; return;}
    }
    cout << "Yes\n";
    return;
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
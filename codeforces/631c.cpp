#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
ll mod = 1000000007;

#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 

template <typename T>
void print(T a, T b, string end="\n") {
    for_each(a,b,[](auto & i){cout << i << " ";});
    cout << end;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m; cin >> n >> m;
    ll* arr = new ll[m];
    sort(arr,arr+m);
    ll lcp = n;
    loop(i,m) {
        
    }
}
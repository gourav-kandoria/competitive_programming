#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
ll mod = 1000000007;

#define loop(n) for(int64_t i=0; i<n; i++)
#define loop1(a,b) for(int64_t i=a; i<=b; i++)

template <typename T>
void print(T a, T b, string end="\n") {
    for_each(a,b,[](auto & i){cout << i << " ";});
    cout << end;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int mxi; int mni;
    int mx = 0; int mn = 200;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
       if(a > mx) {
           mx = a; mxi = i;
       } 
       if(a <= mn) {
           mn = a; mni = i;
       }
    }
    int res = mxi + (n-1-mni);
    if(mxi > mni) res--;
    cout << res << "\n";
}
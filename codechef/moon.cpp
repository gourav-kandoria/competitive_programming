#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        int n,m,x,y;
        cin >> n >> m >> x >> y;
        if((n*x+m*y)%2!=0) {
            cout << "NO\n"; continue;
        }
        ll sweet_half = (n*x+m*y)/2;
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                if((i*x+j*y)==sweet_half) {
                    cout << "YES\n";
                    goto place;
                }
            }
        }
        cout << "NO\n";
        place: ;
    }
}
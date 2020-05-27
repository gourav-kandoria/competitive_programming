#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[3510][3510];
ll vec[3510];
int main() {
    int t; cin >> t;
    ll n,m,k;
    while(t--) {
        cin >> n >> m >> k;
        for(int i=1; i<=n; i++) {
            cin >> vec[i];
        }
        ll in_control = n - k;
        ll base_length = n - (m-1);

        for(ll i=1; (i+base_length-1)<=n; i++) {
            arr[i][i+base_length-1]
                = max(vec[i],vec[i+base_length-1]);
        }
        
        for(ll l=base_length+1; l<=n; l++) {
            for(ll i=1; (i+l-1)<=n; i++) {
                if(l>in_control) {
                arr[i][i+l-1] 
                = max(arr[i][i+l-2],arr[i+1][i+l-1]);
                }
                else {
                arr[i][i+l-1] 
                = min(arr[i][i+l-2],arr[i+1][i+l-1]);
                }
            }
        }
       
        cout << arr[1][n] << endl;
    }
}
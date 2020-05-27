#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    ll b[n];
    for(ll i=0; i<n; i++) cin >> b[i];
    unordered_map<ll,ll> diff_sum;
    diff_sum[b[0]-0] = b[0];
    ll result = b[0];
    for(int i=1; i<n; i++) {
        if(diff_sum.find(b[i]-i)==diff_sum.end()) {
            diff_sum[b[i]-i] = b[i];
        }
        else {
            diff_sum[b[i]-i]+=b[i];
        }
        result = max(diff_sum[b[i]-i],result);
    }
    cout << result << "\n";
}
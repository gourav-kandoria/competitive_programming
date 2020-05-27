#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    ll index1;
    ll index2;
    while(t--) {
        int n; cin >> n;
        int arr[n];
        int mx = 0;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            mx = max(mx, arr[i]); 
        }
        bool first = true;
        for(int i=0; i<n; i++) {
            if(arr[i]==mx and first) {
                index1 = i;
                index2 = i;
                first = false;
            } 
            else if(arr[i]==mx) {
                index2 = i;
            }
        }
        int required = n/2;
        int count = 0;
        count = max(index1-required, (ll)0);
        int size = index2-index1+1;
        for(int i=index2+1; i<n; i++) {
            if((i+1 - size)>=(n/2)) count++;
        }
        cout << count << endl;
    }
}
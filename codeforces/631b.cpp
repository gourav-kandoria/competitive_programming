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
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll* arr = new ll[n];
        ll mx = -1;
        loop(n) {
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }
        unordered_map<ll,ll> mp1;
        vector<pair<ll, ll> > vec;
        ll mn = n-mx;
        if(mn<=0) goto place1;
        for(ll i=0; i<mn; i++) {
            if(arr[i]>mn) goto place;
            if(mp1.find(arr[i])!=mp1.end()) goto place;
            mp1[arr[i]] = 1;
        }
        mp1.clear();
        for(ll j=mn; j<n; j++) {
            if(arr[j]>mx) goto place;
            if(mp1.find(arr[j])!=mp1.end()) goto place;
            mp1[arr[j]] = 1;
        }
        vec.push_back(make_pair(mn,mx));
        place: ;
        if(mn==mx) goto place1;
        mp1.clear();
         for(ll i=0; i<mx; i++) {
            if(arr[i]>mx) goto place1;
            if(mp1.find(arr[i])!=mp1.end()) goto place1;
            mp1[arr[i]] = 1;
        }
        mp1.clear();
        for(ll j=mx; j<n; j++) {
            if(arr[j]>mn) goto place1;
            if(mp1.find(arr[j])!=mp1.end()) goto place1;
            mp1[arr[j]] = 1;
        }
        vec.push_back(make_pair(mx,mn));
        place1:
        cout << vec.size() << endl;
        for(auto a: vec) {
            cout << a.first << " " << a.second << endl;
        }
    }
}
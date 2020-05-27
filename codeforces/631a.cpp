#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
ll mod = 1000000007;

#define loop(n) for(int64_t i=0; i<n; i++)
#define loop1(a,b) for(int64_t i=a; i<=b; i++)
#define rloop1(a,b) for(int64_t i=a; i>=b; i--) 

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
        int n,x; cin >> n >> x;
        unordered_map<int,bool> mp;
        loop(n) {
            int a; cin >> a;
            mp[a]=1;
        }
        int mx = 1;
        rloop1(200,1) {
            int count = 0;
            for(int j=1; j<=i; j++) {
                if(mp.find(j)==mp.end()) count++;
            }
            if(count <= x) {
                mx = i;
                break;
            }
        }
        cout << mx << endl;
    }
}
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
    unordered_map<int,int> mp;
    mp[5] = 0;
    mp[0] = 0;
    for(int i=0,a; i<n; i++) {
        cin >> a;
        mp[a]++;
    }
    int f_count = mp[5] - mp[5]%9;
    if(f_count==0 and mp[0]) {
        cout << 0 << endl;
    }
    else if(mp[0]==0) {
        cout << "-1\n";
    }
    else {
        while(f_count--) {
            cout << 5;
        }
        while(mp[0]--) {
            cout << 0;
        }
        cout << endl;
    }
}
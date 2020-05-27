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
        int k; cin >> k;
        map<char,ll> mp;
        char ch;
        ll cost;
        while(k--) {
            cin >> ch >> cost;
            mp[ch] = cost;
        }
        int m; cin >> m;
        string str;
        cost = 0;
        getline(cin,str);
        while(m--) {
            ch = cin.get();
            while(ch!='\n' and ch!=EOF) {
                if(mp.find(ch)!=mp.end()) cost+=mp[ch];
                ch = cin.get();
            }
        }
        cout << cost/100 << '.' << setfill('0') << setw(2) << cost%100 << "$\n";
    }
}
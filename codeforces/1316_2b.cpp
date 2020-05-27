#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int32_t,int32_t>
#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 
void err() {cout << "-1\n";}
template <typename T>
void print(T a, T b, string end="\n") {
for_each(a,b,[](auto & i){cout << i << " ";}); cout << "\n"; }
template <typename T, typename V>
void fill(T & collection, V val) {fill(begin(collection),end(collection),val);}
template <typename T>
void print(string nt, T val) {cout << nt << ": " << val << "\n";}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; string str; cin >> n;
        cin >> str;
        string mx="";
        loop(i,10000) mx=+'z';
        ll ans;
        loop1(k,1,n) {
           string ns="";
           ns = ns + str.substr(k-1);
        //    print("ns",ns);
           if(ns.length()%2==0) {
               ns+=str.substr(0,k-1);
           } else {
               string temp = (str.substr(0,k-1));
               reverse(temp.begin(),temp.end());
               ns+=temp;
           }
           if(ns<mx){
               mx = ns; ans = k;
           }
        }
        cout << mx << "\n" << ans << "\n";
    }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n; cin >> n;
    string str;
    cin >> str;
    if(n%2!=0) {
        cout << -1 << "\n";
    }
    else {
        ll opening = 0; ll closing = 0;
        bool balanced = true;
        ll result = 0;
        for(ll i=0; i<str.length(); i++) {
            if(str[i]=='(') opening++;
            else if(str[i]==')') closing++;
            if(closing > opening) balanced = false;
            if(i%2==1) {
                // cout << "balanced: " << balanced << "\n";
                // cout << opening << " " << closing << "\n";
                if(balanced==false and closing==opening) {
                    // cout << i << endl;
                    result+=(opening+closing);
                    opening = 0; closing = 0;
                    balanced = true;   
                }
                else if(closing == opening) {
                    opening = 0; closing = 0;
                }
                
            }
        } 
        if(opening!=closing) {
            cout << -1 << "\n"; return 0;
        }
        cout << result << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        short arr[n];
        string str; cin >> str;
        cout << str << endl;
        for(ll i=0; i<n; i++) {
            if(str[i]=='0') arr[i] = 0;
            if(str[i]=='1') arr[i] = 1;
            if(str[i]=='2') arr[i] = 2;
        }
        short num1[n];
        short num2[n];
        num1[0] = 1; num2[0] = 1;
        bool first = 1;
        for(int i=1; i<n; i++) {
            if(arr[i]==0) {
                num1[i] = 0;
                num2[i] = 0;
            }
            else {
                if(first) {
                    num1[i]=arr[i];
                    num2[i]=0;
                    first = false;
                }
                else {
                    num2[i]=arr[i];
                    num1[i]=0;
                }
            }
        }
        for(int i=0; i<(n); i++) {
            cout << num1[i];
        }
        cout << endl;
        for(int i=0; i<(n); i++) {
            cout << num2[i];
        }
        cout << endl;
 
    }
} 
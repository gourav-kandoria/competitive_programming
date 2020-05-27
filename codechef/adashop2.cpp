#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    int r,c;
    while(t--) {
        cin >> r >> c;
        int m1 = (r+c)/2;
        vector<pair<int,int> > vec;
        if(r==m1 and c==m1) {
            cout << 26 << "\n";
        }
        else {
            cout << 27 << "\n";
            cout << m1 << " " << m1 << "\n";
        }
        cout << 1 << " " << 1 << "\n";
        cout << 2 << " " << 2 << "\n";
        cout << 1 << " " << 3 << "\n";
        cout << 3 << " " << 1 << "\n";
        cout << 2 << " " << 2 << "\n";
        cout << 3 << " " << 3 << "\n";
        cout << 1 << " " << 5 << "\n";
        cout << 5 << " " << 1 << "\n";
        cout << 3 << " " << 3 << "\n";
        cout << 4 << " " << 4 << "\n";
        cout << 1 << " " << 7 << "\n";
        cout << 7 << " " << 1 << "\n";
        cout << 4 << " " << 4 << "\n";
        cout << 5 << " " << 5 << "\n";
        cout << 2 << " " << 8 << "\n";
        cout << 8 << " " << 2 << "\n";
        cout << 5 << " " << 5 << "\n";
        cout << 6 << " " << 6 << "\n";
        cout << 4 << " " << 8 << "\n";
        cout << 8 << " " << 4 << "\n";
        cout << 6 << " " << 6 << "\n";
        cout << 7 << " " << 7 << "\n";
        cout << 6 << " " << 8 << "\n";
        cout << 8 << " " << 6 << "\n";
        cout << 7 << " " << 7 << "\n";
        cout << 8 << " " << 8 << "\n";
    }
}
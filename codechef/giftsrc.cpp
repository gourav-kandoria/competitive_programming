#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;

    while(t--) {
        int t; cin >> t;
        string str;
        cin >> str;
        int posx=0; int posy=0;
        char prev = 't';
        auto can_make_move = [](char current, char prev) {
            if(current=='L' || current=='R') {
                if(prev=='L' || prev=='R') return false;
                else return true;
            }
            if(current=='U' || current=='D') {
                if(prev=='U' || prev=='D') return false;
                else return true;
            }

        };
        for(int i=0; i<str.length(); i++) {
            if(can_make_move(str[i],prev)) {
                if(str[i]=='L') posx--;
                if(str[i]=='R') posx++;
                if(str[i]=='U') posy++;
                if(str[i]=='D') posy--;
            } 
            prev = str[i];
        }
        cout << posx << " " << posy << endl;
    }
}
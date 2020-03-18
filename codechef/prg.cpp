#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 1;
    for(int i=0; i<=13; i++) {
        cout << "2^" << i << " = " << a << endl; 
        a = a*2;
    }
}
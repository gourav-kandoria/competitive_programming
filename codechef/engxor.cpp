#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


#define B2(n) n, n + 1, n + 1, n + 2 
#define B4(n) B2(n) , B2(n + 1), B2(n + 1), B2(n + 2) 
#define B6(n) B4(n) , B4(n + 1), B4(n + 1), B4(n + 2) 

unsigned int lookuptable[256] = { B6(0), B6(1), B6(1), B6(2) }; 

unsigned int countSetBits(int N) 
{ 
    unsigned int count = lookuptable[N & 0xff] +
                         lookuptable[(N >> 8) & 0xff] +  
                         lookuptable[(N >> 16) & 0xff] +  
                         lookuptable[(N >> 24) & 0xff]; 
    return count; 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    int n, q;

    ll even_count;
    ll odd_count;

    while(t--) {
        cin >> n >> q;    
        ll count = 0;
        unsigned int ele;
        for(int i=0; i<n; i++) {
            cin >> ele;
            int res;
            res = countSetBits(ele);
            if(res%2==1) count++;
        }
        unsigned int p;
        while(q--) {
            cin >> p;
            ll total = n;
            odd_count = count;
            even_count = n - count;
            int res = countSetBits(p);
            if(res%2==1) {
                ll temp = even_count;
                even_count = odd_count;
                odd_count = temp;
            }
            cout << even_count << " " << odd_count << "\n";
        }
    }
}
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
    int n;
    while(cin >> n) {
        vector<int> vec(n);
        loop(n) cin >> vec[i];
        vector<int8_t> count(n,0);
        bool ans = true;
        loop1(1,n-1) {
            int term = abs(vec[i]-vec[i-1]);
            if(term < 1 or term > (n-1) or count[term] > 0) {
                ans = false; break;
            } 
            count[term] = 1;
        }
        cout << (ans ? "Jolly\n" : "Not jolly\n");
    }    
}
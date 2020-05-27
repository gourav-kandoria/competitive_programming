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
    int arr[2*n+1][2*n+1];
    int term = 0;
    for(int r=n,c=0; c<(2*n+1); c++) {
        arr[r][c] = term;
        if(c<n) term++;
        else term--;
    }

    for(int r=n-1; r>=0; r--) {
        for(int c=0; c<(2*n+1); c++) {
            arr[r][c] = arr[r+1][c] - 1;
        }
    }

    for(int r=n+1; r<=(2*n); r++) {
        for(int c=0; c<(2*n+1); c++) {
            arr[r][c] = arr[r-1][c] - 1;
        }
    }
    for(int i=0; i<=(2*n); i++) {
        bool happened = false;
        for(int j=0; j<=(2*n); j++) {
            if(arr[i][j]<0 and happened) break;
            if(j!=0) cout << " ";
            if(arr[i][j]<0) {
                cout << " ";
            }
            else {
                cout << arr[i][j];
                happened = true;
            }
        }
        cout << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int cost[m+1] = {0};
        bool exist[m+1]; 
        fill(exist,exist+m+1,false);
        int buckets[n];
        for(int i=0; i<n; i++) {
            cin >> buckets[i];
            exist[buckets[i]] = true;
        }
        int prices[n];
        for(int i=0; i<n; i++) {
            cin >> prices[i];
            cost[buckets[i]]+=prices[i];
        }
        int result = INT_MAX;
        for(int i=1; i<=m; i++) {
           if(exist[i]!=0) {
               result = min(result,cost[i]);
           }
        }
        cout << result << endl;
    }
}
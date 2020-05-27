#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    ll arr[n];
    priority_queue<ll> que;
    for(int i=0; i<n; i++) {
        ll a;
        cin >> a;
        que.push(a);
    }
    ll max = que.top();
    que.pop();
    ll current = max;
    int count = 1;
    vector<ll> vec;

    while(!que.empty()) {
        ll next = que.top();
        if(current!=next) {
            if(count==1) break;
            current = next;
            count = 1;
        }
        que.pop();
        vec.push_back(next);
        count++;
    }

    cout << current << " ";
    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    while(!que.empty()) {
        cout << que.top() << " ";
        que.pop();
    }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
vector<vector<ll> > graph2;
    
vector<pair<ll,ll> > dist_count;

void do_bfs(ll s) {
    dist_count.resize(n);

    vector<bool> visited(n);
    fill(visited.begin(),visited.end(),false);

    queue<ll> que;
    que.push(s);
    dist_count[s] = make_pair(0,1);
    visited[s] = true;
    while(!que.empty()) {
        ll ele = que.front();
        que.pop();
        for(ll i=0; i<graph2[ele].size(); i++) {
            if(!visited[graph2[ele][i]]) {
                visited[graph2[ele][i]] = true;
                dist_count[graph2[ele][i]] = make_pair(dist_count[ele].first+1,1);
                que.push(graph2[ele][i]);
            }
            else if(dist_count[graph2[ele][i]].first == dist_count[ele].first+1) {
                (dist_count[graph2[ele][i]].second)++; 
            }
        }
    }
}

int main() {
    cin >> n >> m;
    graph2.resize(n);
    for(ll i=0; i<n; i++) graph2.clear();
    for(ll i=0; i<m; i++) {
        ll a,b; cin >> a >> b;
        graph2[b-1].push_back(a-1);
    }
    ll k; 
    cin >> k; 
    ll path[k];
    for(ll i=0; i<k; i++) {
        cin >> path[i];
        path[i]--;
    }
    do_bfs(path[k-1]);
    ll rmax = 0;
    ll rmin = 0;
    for(ll i=0; i<(k-1); i++) {
        // cout << dist_count[path[i]].first << endl;
        if(k-1-i > dist_count[path[i]].first) {
        if(dist_count[path[i]].first -1 != dist_count[path[i+1]].first) {
            rmax++;
            rmin++;
        }
        else {
            if(dist_count[path[i]].second>1) {
                rmax++;
            }
        }
    }
    cout << rmin << " " << rmax << "\n";
    return 0;
}
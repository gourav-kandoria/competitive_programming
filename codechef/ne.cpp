#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll update(ll* tree, ll* lazy, ll index, ll low, ll high, ll l, ll r, ll o, ll v){
    if(lazy[index]>0) {
        tree[index] = tree[index] + (high-low+1)*lazy[index];
        if(low!=high){
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        }
        lazy[index] = 0;
    }
    ll mid = (low+high)/2;
    if(l<=low and r>=high) {
        if(o == 0) {
            tree[index] = tree[index] + (high-low+1)*v;
            if(low!=high) {
            lazy[2*index]+=v;
            lazy[2*index+1]+=v;
            }
        }
        return tree[index];
    }
    else if(l > high or r < low){
        return 0;
    }
    else {
        ll f = update(tree, lazy, 2*index, low, mid, l, r, o, v);
        ll s = update(tree, lazy, 2*index+1, mid+1, high, l, r, o, v);
        tree[index] = tree[2*index] + tree[2*index+1];
        return f+s;
    }
}

int main() {
    ll t; cin >> t;
    while(t--) {
        ll n,q;
        cin >> n >> q;
        ll tree[4*n+1];
        ll lazy[4*n+1]; 
        fill(tree,tree+(4*n+1),0);
        fill(lazy,lazy+(4*n+1),0);
        ll tp,l,r,v;
        while(q--) {
            cin >> tp >> l >> r;
          //  if(l>r) swap(l,r);
           // if(r>n and l<=n) r = n;
            if(tp==0){
                cin >> v;
              //  if(l>n or r>n) continue; 
                update(tree, lazy, 1, 0, n-1, l-1, r-1, 0, v);
            }
            else {
                // if(l>n or r>n){
                //     cout << "0\n";
                //     continue;
                // }
                cout << update(tree, lazy, 1, 0, n-1, l-1, r-1, 1, 0) << endl;
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll n) { 
    switch(n & 3) { 
    case 0: return n;     
    case 1: return 1; 
    case 2: return n + 1;
    case 3: return 0;    
    } 
} 

struct p{
    ll a;
    ll b;
 
    p(ll d , ll e){
        a = d;
        b = e;
    }

};

bool operator < (const p & A, const p & B){
    return A.a<B.a;
}
 
// bool operator == (const p & A, const p & B){
//     if(A.a >= B.a and A.b <= B.b){
//         return true;
//     }
//     else if(B.a >= A.a and B.b <= A.b) {
//         return true;
//     }
//     return false;
// } 

map<p, ll> mp;
unordered_map<ll,ll> mp1;

void update(pair<ll,ll> pr) {
    ll starts = pr.first+1;
    auto itr = mp.lower_bound(p(pr.first+1,pr.first+1));
    ll r_p = pr.second;
    p neu = p(pr.first,pr.second);
    if(itr!=mp.end()) {
        p right = (*itr).first;
        neu = p(pr.first,right.b);
        starts =(*itr).second; 
        r_p = right.b;
        mp1.erase(right.b);
        mp.erase((*itr).first);
    }
    if(mp1.find(pr.first-1)!=mp1.end()) {
        ll s_l = mp1[pr.first-1];
        p neu2 = p(s_l,r_p);
        mp1.erase(pr.first-1); 
        mp.erase(p(s_l,pr.first-1));
        mp[neu2] = starts;
        return;
    }
    mp[neu] = starts;
    mp1[neu.b] = neu.a;
}

ll find(p pr) {
    ll s; ll e;
    if(mp.lower_bound(pr)!=mp.upper_bound(pr)) {
        auto ze = *(mp.upper_bound(pr));
        e = ze.first.a-1;
        s = mp[pr];
    }
    else {
        auto ze = *(mp.upper_bound(pr));
        e = ze.first.a-1;
        s = pr.a;
    }
    cout << "s: " << s << endl;
    cout << "e: " << e << endl;
    return (func(e)^func(s-1));
}

int main() {
    ll n;
    cin >> n;
    update(make_pair(n+1,n+1));
    ll q; cin >> q;
    while(q--) {
        ll c,x; cin >> c >> x;
        if(c==1) {
            update(make_pair(x,x));
        }
        else {
            cout << find(p(x,x)) << endl;
        }
    }
}
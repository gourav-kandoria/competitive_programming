#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

#define pb push_back
#define pll pair<ll,ll>;
#define pii pair<int32_t,int32_t>;
#define loop(i,n) for(int64_t i=0; i<n; i++)
#define loop1(i,a,b) for(int64_t i=a; i<=b; i++)
#define rloop(i,n) for(int64_t i=n-1; i>=0; i--) 
#define rloop1(i,a,b) for(int64_t i=a; i>=b; i--) 

void err() {cout << "-1\n";}
template <typename T>
void print(T a, T b, string end="\n") {
    for_each(a,b,[](auto & i){cout << i << " ";});
    cout << end;
}

vector< vector<ll> > primes_of_num;
vector<ll> primes;

void preprocess(ll N) {
    primes_of_num.resize(N+1);
    vector<bool> nums(N+1);
    fill(nums.begin(),nums.end(),true);
    loop1(i,2,N) {
        if(!nums[i]) continue;
        primes.pb(i);
        primes_of_num[i].pb(i);
        for(ll j=2*i; j<=(N); j+=i) {
            nums[j] = false;
            primes_of_num[j].pb(i);
        }
    }
}

bool tc_more_than_one = 1;
unordered_map<ll,bool> mp;
vector<vector<ll> > buckets;
vector<ll> bucket_content;

void solve() {
    int t; cin >> t;
    vector<ll> tests;
    ll tcn; ll mx = -1; 
    while(t--) {
        cin >> tcn; 
        tests.pb(tcn);
        mx = max(mx,tcn);
    }
    preprocess(mx);
    ll x = mx/2;
    buckets.resize(x);
    vector<unordered_map<ll,bool> > primes_buckets(x);
    for(auto & a : buckets) a.pb(1);
    for(auto & a : primes) {
        buckets[0].pb(a);
        mp[a] = 1;
        ll i=1;
        for(ll j=a*a; j<=mx; j+=a) {
            if(mp.find(j)!=mp.end()) continue;
            mp[j] = true;
            while(true) {
                for(auto & pn : primes_of_num[j]) {
                    if(primes_buckets[i].find(pn)!=primes_buckets[i].end()) {
                        goto place;
                    }
                }
                break;
                place: i++;
            }
            buckets[i].pb(j);
            for(auto & pn : primes_of_num[j]) {
                primes_buckets[i][pn] = true;
            }
        }
        primes_buckets[i].erase(a);
    }

    for(auto & n : tests) {
    if(n==1) {cout << "1\n1 1\n"; continue;}
    cout << n/2 << "\n";
    for(ll i=0; i<(n/2); i++) {
        bucket_content.clear();
        for(ll j=1; j<buckets[i].size(); j++) {
            if(buckets[i][j]>n) break;
            bucket_content.pb(buckets[i][j]);
        }
        if(i==0) 
            cout << bucket_content.size()+1 << " " << 1 << " ";
        else 
            cout << bucket_content.size() << " ";
        for(auto & p : bucket_content) cout << p << " "; 
        cout << "\n";
    }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}
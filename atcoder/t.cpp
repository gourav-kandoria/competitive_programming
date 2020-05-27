#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<ll,ll> ar[2000+9];
ll dp[2009][2009],n;
ll rec(ll idx,ll i,ll j) {
	if(idx==n+1)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	return dp[i][j]=max(rec(idx+1,i+1,j)+((ar[idx].first)*abs(ar[idx].second-i)),rec(idx+1,i,j-1)+((ar[idx].first)*abs(ar[idx].second-j)));
}

int main() {
	//freopen("/home/dhruv/Desktop/tests/input.txt","r",stdin);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		ar[i].first=x;
		ar[i].second=i;
	}
	sort(ar+1,ar+1+n,greater< pair<ll,ll> >());
	memset(dp,-1,sizeof dp);
	cout<<rec(1,1,n)<<"\n";
}
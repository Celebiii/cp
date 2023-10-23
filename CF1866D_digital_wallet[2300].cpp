#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int dp[N][11],n,m,k,ans,a[N][11];
void solve()
{
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[j][i];
	for (int i=1;i<=m;i++)
	{
		sort(a[i]+1,a[i]+n+1);
		reverse(a[i]+1,a[i]+n+1);
	}
	for (int i=k;i<=m;i++)
	{
		int mx=0;
		for (int j=0;j<=n;j++)
			mx=max(mx,dp[i-k][j]);
		for (int j=i-k+1;j<=i;j++)
		{
			int pre=mx;
			for (int t=n;t>=1;t--)
			{
				if (t+1<=n) dp[j][t+1]=max(dp[j][t+1],dp[j][t]+a[j][t+1]);
				mx=max(mx,dp[j][t]);
			}
			dp[j][1]=max(dp[j][1],pre+a[j][1]);
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
		{
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) solve();
	return 0;
}
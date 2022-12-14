#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, vector<ll>> mp;
vector<ll> ans, dp;
ll n;

void dfs(ll start, ll parent, ll dist)
{
	ans[1] += dist;
	dp[start] = 1;
	for(auto x : mp[start])
	{
		if(x != parent)
		{
			dfs(x, start, dist+1);
			dp[start] += dp[x];
		}
	}
}

void dfs2(ll start, ll parent)
{
	for(auto x : mp[start])
	{
		if(x != parent)
		{
			ans[x] = ans[start] + n - 2*dp[x];
			dfs2(x, start);
		}
	}
}

int main()
{
	ll u, v;
	cin >> n;
	for(ll i=1; i<n; i++)
	{
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	ans.assign(n+1, 0);
	dp.assign(n+1, 0);
	dfs(1, 0, 0);
	dfs2(1, 0);
	for(ll i=1; i <=n; i++) cout << ans[i] << " ";
	return 0;
}
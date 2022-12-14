#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int, vector<int>> mp;
vector<int> v, vis;

int dfs(int s)
{
	if(vis[s]) return v[s];
	vis[s] = 1;
	int x = mp[s].size();
	for(auto k : mp[s])
	{
		x += dfs(k);
	}
	return v[s] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, x;
	cin>> n;

	for(int i=2; i<=n; i++)
	{
		cin>>x;
		mp[x].push_back(i);
	}
	v.assign(n+1, 0);
	vis.assign(n+1, 0);
	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	for(int i=1; i<=n; i++)
	{
		cout<<v[i]<<" ";
	}
	return 0;
}
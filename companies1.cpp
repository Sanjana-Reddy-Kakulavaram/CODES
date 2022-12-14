#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
vector<vector<int>> parent;
vector<int> vis, level, v;
int n;

void dfs1(int node, int p, int l)
{
	parent[0][node] = p;
	level[node] = l;
	for(auto x : mp[node])
	{
		if(x != p) dfs1(x, node, l+1);
	}
}

void All_LCA()
{
	dfs1(1, 0, 0);
	for(int i=1; 1<<i <= n; i++)
	{
		for(int j=0; j<=n; j++)
		{
			parent[i][j] = parent[i-1][parent[i-1][j]];
		}
	}
}

int answer(int node, int k)
{
	int p = node;
	for(int i=0; i<25; i++)
	{
		if(k & (1<<i)) p = parent[i][p];
	}
	if(p == 0) return -1;
	return p;
}

int main() {
	int q, a, b;
	cin >> n >> q;
	v.assign(n+1, 1);
	parent.assign(25, vector<int>(n+1, 0));
	for(int i=2; i<=n; i++) 
	{
		cin >> v[i];
		mp[i].push_back(v[i]);
		mp[v[i]].push_back(i);
	}
	level.assign(n+1, 0);
	vis.assign(n+1, 0);
	All_LCA();
	while(q--)
	{
		cin >> a >> b;
		cout << answer(a, b) << "\n";
	}
	return 0;
}
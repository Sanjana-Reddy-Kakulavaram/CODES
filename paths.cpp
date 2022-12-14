#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
vector<int> paths, level;
vector<vector<int>> parent;
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

int LCA(int a, int b)
{
	if(level[a] < level[b]) swap(a, b);
	int d = abs(level[a] - level[b]);
	for(int i=20; i>=0; i--)
	{
		if(d & (1<<i)) a = parent[i][a];
	}
	if(a == b) return a;
	for(int i=20; i>=0; i--)
	{
		if(parent[i][a] != parent[i][b])
		{
			a = parent[i][a];
			b = parent[i][b];
		}
	}
	return parent[0][a];
}

void dfs2(int node, int p)
{
	for(auto x : mp[node])
	{
		if(x != p)
		{
			dfs2(x, node);
			paths[node] += paths[x];
		}
	}
}

int main() {
	int m, a, b, x;
	cin >> n >> m;
	for(int i=1; i<n; i++)
	{
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	parent.assign(25, vector<int>(n+5, 0));
	level.assign(n+5, 0);
	paths.assign(n+5, 0);
	All_LCA();
	while(m--)
	{
		cin >> a >> b;
		paths[a]++; paths[b]++;
		x = LCA(a, b);
		paths[x]--;
		paths[parent[0][x]]--;
	}
	dfs2(1, 0);
	for(int i=1; i<=n; i++) cout << paths[i] << " ";
	return 0;
}
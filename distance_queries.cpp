#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
vector<vector<int>> parent;
vector<int> vis, level;
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q, a, b;
	cin >> n >> q;
	for(int i=1; i<n; i++)
	{
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	parent.assign(25, vector<int>(n+1, 0));
	level.assign(n+1, 0);
	All_LCA();
	while(q--)
	{
		cin >> a >> b;
		cout << (level[a] + level[b] - 2*level[LCA(a, b)]) << "\n";
	}
	return 0;
}
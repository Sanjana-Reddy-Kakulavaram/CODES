#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5;
unordered_set<int> mp[mx+10];
unordered_set<int> st[mx + 10];
int n;
int color[mx+10], cnt[mx+10];

void dfs(int node, int prev)
{
	for(auto x : mp[node])
	{
		if(x == prev) continue;
		dfs(x, node);
		if(st[x].size() > st[node].size()) swap(st[x], st[node]);
		st[node].insert(st[x].begin(), st[x].end());
	}
	st[node].insert(color[node]);
	if(st[node].count(0)) st[node].erase(0);
	cnt[node] = st[node].size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	cin >> n;
	for(int i=1; i<=n; i++) cin >> color[i];
	for(int i=1; i<n; i++)
	{
		cin >> a >> b;
		mp[a].insert(b);
		mp[b].insert(a);
	}
	dfs(1, -1);
	for(int i=1; i<=n; i++) cout << cnt[i] << " ";
	return 0;
}
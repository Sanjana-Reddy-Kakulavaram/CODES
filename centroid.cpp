#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
vector<int> cnt, vis;
int n;

int dfs(int start, int p)
{
	int c = 1;
	for(auto x : mp[start]) 
	{
		if(x == p) continue;
		c += dfs(x, start);
	}
	return cnt[start] = c;
}

int centroid(int start, int p)
{
	int ans = start;
	for(auto x : mp[start])
	{
		if(x == p) continue;
		if(cnt[x]*2 > n) 
		{
			ans = centroid(x, start);
		}
	}
	return ans;
}

int main() {
	int a, b;
	cin >> n;
	for(int i=1; i<n; i++)
	{
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	vis.assign(n+1, 0);
	cnt.assign(n+1, 0);
	int x = dfs(1, 0);
	// for(int i=1; i<=n; i++) cout << cnt[i] << " ";
	// cout << "\n";
	cout << centroid(1, 0);
	return 0;
}
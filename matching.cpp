#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
unordered_set<int> st;
int edges = 0;

void dfs(int start, int parent)
{
	for(auto x : mp[start])
	{
		if(x != parent) 
		{
			dfs(x, start);
			if(!st.count(start) && !st.count(x)) 
			{
				edges++;
				st.insert(start);
				st.insert(x);
			}
		}
	}
}

int main() {
	int n, u, v;
	cin >> n;
	for(int i=1; i<n; i++)
	{
		cin >> u >> v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}
	dfs(1, 0);
	cout << edges << "\n";
	return 0;
}
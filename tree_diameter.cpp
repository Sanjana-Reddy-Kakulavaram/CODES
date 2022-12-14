// #include<bits/stdc++.h>
// using namespace std;

// unordered_map<int, vector<int>> mp;
// int vis[1000000];
// int m;
// int last, len;

// void printMap()
// {
// 	for(auto p : mp)
// 	{
// 		cout<<p.first<<": ";
// 		for(auto x : p.second)
// 		{
// 			cout<<x<<" ";
// 		}
// 		cout<<"\n";
// 	}
// 	cout<<"\n";
// }

// void dfs(int si, int l)
// {
// 	if(vis[si]) return;
// 	vis[si] = 1;
// 	if(len < l)
// 	{
// 		len = l;
// 		last = si;
// 	}
// 	for(auto x : mp[si])
// 	{
// 		dfs(x, l+1);
// 	}
// }


// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	int t, u, v;
//     t = 1;
// 	while(t--)
// 	{
// 		mp.clear();
// 		cin>>m;
// 		for(int i=1; i<m; i++)
// 		{
// 			cin>>u>>v;
// 			mp[u].push_back(v);
// 			mp[v].push_back(u);
// 		}
// 		// printMap();
// 		len = 0;
// 		memset(vis, 0, sizeof(vis));
// 		dfs(1, 0);
// 		len = 0;
// 		memset(vis, 0, sizeof(vis));
// 		dfs(last, 0);
// 		cout<<len<<"\n";
// 	}
// 	return 0;
// }





#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dia = 0, last;
vector<int> vis;
unordered_map<ll, vector<ll>> mp;

void solve(ll s, ll len)
{
    if(vis[s]) return;
    vis[s] = 1;
    if(len > dia)
    {
        dia = len;
        last = s;
    }
    for(auto x : mp[s])
    {
        solve(x, len+1);
    }
}

int main()
{
    ll n, u, v;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    vis.assign(n+5, 0);
    dia = 0;
    solve(1, 0);
    vis.assign(n+5, 0);
    dia = 0;
    solve(last, 0);
    cout<<dia;
}
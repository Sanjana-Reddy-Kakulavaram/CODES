/*#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> mp;
vector<int> val;
vector<int> v, vis, startIdx, endIdx, ft;
int idx = 1, n;

void update(int idx, int value)
{
	while(idx <= n)
	{
		ft[idx] += value;
		idx += (idx & -idx);
	}
}

int sum(int idx)
{
	int s = 0;
	while(idx > 0)
	{
		s += ft[idx];
		idx -= (idx & -idx);
	}
	return s;
}

void dfs(int s)
{
	if(vis[s]) return;
	startIdx[s] = idx;
	update(idx, val[s]);
	idx++;
	vis[s] = 1;
	v.push_back(s);
	for(auto x : mp[s]) 
	{
		dfs(x);
	}
	endIdx[s] = idx-1;
}

int query(int idx1, int idx2)
{
	return sum(idx2)-sum(idx1-1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c, q;
	cin >> n >> q;
	val.assign(n+1, 0);
	for(int i=1; i<=n; i++) cin >> val[i];
	for(int i=1; i<n; i++)
	{
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	vis.assign(n+1, 0);
	startIdx.assign(n+1, 0);
	endIdx.assign(n+1, 0);
	ft.assign(2*n, 0);
	dfs(1);
	while(q--)
	{
		cin >> c;
		if(c == 1)
		{
			cin >> a >> b;
			int upval = b - val[a];
			val[a] = b;
			update(startIdx[a], upval);
		}
		else
		{
			cin >> a;
			cout << query(startIdx[a], endIdx[a]) << "\n";
		}
	}
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, vector<ll>> mp;
vector<ll> val;
vector<ll> v, vis, startIdx, endIdx;
ll idx = 1, n;

class fenwick
{
	public:
	vector<ll> ft;
	ll sz;
	fenwick(ll n)
	{
		ft.assign(n+2, 0);
		sz = n;
	}
	void addVal(ll idx, ll num)
	{
		while(idx <= sz)
		{
			ft[idx] += num;
			idx += (idx & -idx);
		}
	}
	ll prefixSum(ll idx)
	{
		ll sum = 0;
		if(idx < 0)  return 0;
		while(idx > 0)
		{
			sum += ft[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}
	ll rangeSum(ll idx1, ll idx2)
	{
		return prefixSum(idx2) - prefixSum(idx1-1);
	}
	
	void printTree()
	{
		for(int i=0; i<ft.size(); i++) cout << ft[i] << " ";
		cout << "\n";
	}
};

void dfs(int s, fenwick &f)
{
	if(vis[s]) return;
	startIdx[s] = idx;
	f.addVal(idx, val[s]);
	idx++;
	vis[s] = 1;
	v.push_back(s);
	for(auto x : mp[s]) 
	{
		dfs(x, f);
	}
	endIdx[s] = idx-1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a, b, c, q;
	cin >> n >> q;
	val.assign(n+1, 0);
	for(int i=1; i<=n; i++) cin >> val[i];
	for(int i=1; i<n; i++)
	{
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	vis.assign(n+1, 0);
	startIdx.assign(n+1, 0);
	endIdx.assign(n+1, 0);
	fenwick f(n);
	dfs(1, f);
	// for(int i=1; i<=n; i++) cout << startIdx[i] << " " << endIdx[i] << "\n";
	while(q--)
	{
		// f.printTree();
		cin >> c;
		if(c == 1)
		{
			cin >> a >> b;
			int upval = b - val[a];
			val[a] = b;
			f.addVal(startIdx[a], upval);
		}
		else
		{
			cin >> a;
			cout << f.rangeSum(startIdx[a], endIdx[a]) << "\n";
		}
	}
	return 0;
}
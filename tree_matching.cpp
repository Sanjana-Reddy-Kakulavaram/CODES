#include<bits/stdc++.h>
uding namespace std;
typedef long long ll;
unordered_map<ll, vector<ll>> mp;

ll solve(int s, int flag)
{
    if(flag)
    {
        int ans = 0;
        for(auto x : mp[s]) ans = max(ans, solve(x, 0));
        return ans;
    }
    int ans = 0;
    for(auto x : mp)
    {
        
    }
}

int main()
{
    ll n, u, v;
    for(int i=0; i<n; i++)
    {
        cin>>u>>v;
        mp[u].push_back(v);
    }
    cout<<solve(1, 0);
}
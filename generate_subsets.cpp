#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;

vector<vector<ll>> printSubsets(ll size)
{
    ll n = 1 << size;
    vector<vector<ll>> ans;
    vector<ll> in;
    for(int i=0; i<n; i++)
    {
        in.clear();
        for(int j=0; j<size; j++)
        {
            if(i & (1 << j)) in.push_back(v[j]);
        }
        ans.push_back(in);
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    v.assign(n, 0);

    for(int i=0; i<n; i++) cin >> v[i];
    vector<vector<ll>> subsets = printSubsets(n);
    for(auto set : subsets)
    {
        for(auto ele : set) cout<<ele<<" ";
        cout<<"\n";
    }
    return 0;
}
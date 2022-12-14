#include <bits/stdc++.h>

using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) {
    int n = arr.size();
    d %= n;
    vector<int> ans;
    for(int i=d; i<n; i++)
    {
        ans.push_back(arr[i]);
    }
    for(int i=0; i<d; i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}

int main()
{
    int n, d;
    cin>>n>>d;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> ans = rotateLeft(d, arr);
    for(auto x : ans) cout<<x<<" ";
    return 0;
}
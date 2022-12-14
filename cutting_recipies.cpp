#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    ll g=v[0];
    for(int i=1;i<n;i++)
    g=__gcd(g,v[i]);
    for(int i=0;i<n;i++)
    cout<<v[i]/g<<" ";
    cout<<endl;
}
    return 0;
}
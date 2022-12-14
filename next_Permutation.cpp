#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool next_Permutation(vector<char> &a, ll n)
{
	ll pos=-1, next_max;
	for(int i=n-2; i>=0; i--)
	{
		if(a[i] < a[i+1])
		{
			pos = i;
			break;
		}
	}
	if(pos == -1) return false;
	for(int i=n-1; i>pos; i--)
	{
		if(a[i] > a[pos])
		{
			next_max = i;
			break;
		}
	}
	swap(a[pos], a[next_max]);
	reverse(a.begin()+pos+1, a.end());
	return true;
}

int main() {
	ll n;
	// vector<ll> v;
	vector<char> v;
	cin>>n;
	v.assign(n,'0');
	for(int i=0; i<n; i++) cin>>v[i];
	while(next_Permutation(v, n))
	{
		for(int i=0; i<n; i++) cout<<v[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
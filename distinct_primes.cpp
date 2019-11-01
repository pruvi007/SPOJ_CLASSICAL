#include<bits/stdc++.h>
using namespace std;

bool d(int x)
{
	unordered_map<int,int> mp;
	while( x%2 == 0 )
	{
		mp[2]++;
		x/=2;
	}
	for(int i=3;i<=sqrt(x);i+=2)
	{
		while( x%i == 0 )
		{
			mp[i]++;
			x/=i;
		}
	}
	if(x>2)
		mp[x]++;
	return mp.size()>=3?true:false;
}
int main()
{
	vector<int> v;
	for(int i=2;i<=100005;i++)
	{
		if( d(i) )
			v.push_back(i);
	}
	// cout << v.size() << endl;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << v[n-1] << endl;
	}
}
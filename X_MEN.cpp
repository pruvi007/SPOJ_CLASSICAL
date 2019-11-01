#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		ll a[n],b[n];
		vector< pair<int,int> > v;
		unordered_map<int,int> mp;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			mp[a[i]] = i;
		}
		for(int i=0;i<n;i++)
		{
			cin >> b[i];
			b[i] = mp[b[i]];
		}
		// for(int i=0;i<n;i++)
		// {
		// 	v.push_back({a[i],b[i]});
		// }
		// sort( v.begin(),v.end() );
		// vector<int> c;
		// for(int i=0;i<n;i++)
		// 	c.push_back(v[i].second);
		vector<int> lis;
		lis.push_back(b[0]);
		for(int i=1;i<n;i++)
		{
			int p = lower_bound(lis.begin(),lis.end(),b[i])-lis.begin();
			if( p == lis.size() )
				lis.push_back(b[i]);
			else
				lis[p] = b[i];
		}
		// for(int i=0;i<lis.size();i++)
		// 	cout << lis[i] << " ";
		// cout << endl;
		cout << lis.size() << endl;
	}
}
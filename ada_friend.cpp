#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int n,k;
	cin >> n >> k;
	vector< pair<string,int> > v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(),v.end());

	// cout << endl;
	// for(int i=0;i<n;i++)
	// {
	// 	cout << v[i].first <<" " <<  v[i].second << endl;
	// }
	// cout << endl;

	vector<ll> s;
	s.push_back(v[0].second);
	for(int i=1;i<n;i++)
	{
		if( v[i].first == v[i-1].first )
		{
			s[s.size()-1] += v[i].second;
		}
		else
			s.push_back(v[i].second);
	}
	sort(s.begin(),s.end());
	// for(int i=0;i<s.size();i++)
	// 	cout << s[i] << " ";
	// cout << endl;

	ll sum = 0;
	for(int i=s.size()-1;i>=0;i--)
	{
		sum += s[i];
		k--;
		if( k==0 )
			break;
	}
	cout << sum << endl;
}
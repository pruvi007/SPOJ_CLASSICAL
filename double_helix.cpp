/*

	find intersection points of the two arrays then get the max path sumby changing the road or not changing the road.
	idea: use recursion to get both brached and then use memoization.
*/

#include<bits/stdc++.h>
using namespace std;

map< pair<int,int>,int > mp;
vector<int> a,b,ai,bi;
#define ll long long int


int findPath(int a_id,int l)
{
	if(a_id == 1)
	{
		if( l>=a.size() )
			return 0;
	}
	if(a_id == 2)
	{
		if( l>=b.size() )
			return 0;
	}
	if( mp.find({a_id,l}) != mp.end() )
		return mp[{a_id,l}];

	ll sum = 0;

	if( a_id == 1 )
	{
		sum = a[l];
		int x = lower_bound(b.begin(),b.end(),a[l]) - b.begin();
		// intersection found
		if( b[x] == a[l] )
		{
			sum += max( findPath(1,l+1),findPath(2,x+1) );
		}
		else
		{
			sum += findPath(1,l+1);
		}
		// cout << sum << " ";
	}
	else
	{
		sum = b[l];
		int x = lower_bound(a.begin(),a.end(),b[l]) - a.begin();
		// intersection found
		if( a[x] == b[l] )
		{
			sum += max( findPath(2,l+1),findPath(1,x+1) );
		}
		else
		{
			sum += findPath(2,l+1);
		}
		
	}
	mp[{a_id,l}] = sum;

	return sum;
}
int main(){
	int n,m;
	while( cin >> n )
	{
		if( n==0 )
			break;
		
		for(int i=0;i<n;i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}
		cin >> m;
		
		for(int i=0;i<m;i++)
		{
			int x;
			cin >> x;
			b.push_back(x);
		}
		
		for(int i=0;i<n;i++)
		{
			int x = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
			if( b[x]== a[i] )
			{
				ai.push_back(i);
				bi.push_back(x);
			}
		}
		// for(int i=0;i<ai.size();i++)
		// {
		// 	cout << a[ai[i]] << " " << b[bi[i]] << endl;
		// }
		
		int ans1 = findPath(1,0);
		int ans2 = findPath(2,0);
		cout << max(ans1,ans2) << endl;

		mp.clear();a.clear(),b.clear(),ai.clear(),bi.clear();

	}
}
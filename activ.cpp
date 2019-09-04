/*

*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct myComp{
	bool operator()(vector<ll> a,vector<ll> b)
	{
		return a[1] < b[1];
	}
};
#define ll long long int
ll mod = 1e8;
int bs(vector<vector<ll> > &v,int l,int r,int x)
{
	int ans = -1;
	while(l<=r)
	{
		int mid = (l+r)/2;
		if(v[mid][0] >= x)
		{
			ans = mid;
			r = mid-1;
		}
		else 
			l = mid+1;
	}
	return ans;
}
int main()
{
	int n;
	while( cin >> n )
	{
		if( n == -1 )
			break;
		vector< vector<ll> > v(n);
		for(int i=0;i<n;i++)
		{
			ll x,y;
			cin >> x >> y;
			v[i].push_back(x);
			v[i].push_back(y);
		}
		sort( v.begin(),v.end(),myComp() );
		// for(int i=0;i<n;i++)
		// 	cout << v[i][0] << " " << v[i][1] << endl;
		ll dp[n];
		dp[n-1] = 1;
		// for(int i=1;i<n;i++)
		// {
		// 	dp[i] = 1;
		// 	for(int j=0;j<i;j++)
		// 	{
		// 		if( v[j][1]<=v[i][0] )
		// 			dp[i] += dp[j];
		// 	}
		// }

		for(int i= n-2;i>=0;i--)
		{
			dp[i] = (1+dp[i+1]%mod)%mod;
			ll x = v[i][1];
			ll idx = bs(v,i,n-1,x);
			if(idx!=-1)
				dp[i] = (dp[i]%mod+dp[idx]%mod)%mod;
		}
		ll sum = dp[0]%mod;
		// for(int i=0;i<n;i++)
		// 	sum += dp[i];
		string ans = to_string(sum);
		if( ans.length()<8 )
		{
			string t="";
			int z = 8-ans.length();
			for(int i=0;i<z;i++)
				cout << '0';
			cout << ans << endl;
			
		}
		else
		{
			for(int i=ans.length()-1;i>=8;i--)
				cout << ans[i];
			cout << endl;

		}

	}
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	string s;
	cin >> s;
	int n = s.length();

	int dp[n];
	
		dp[0] = 1;
	for(int i=1;i<n;i++)
	{
		dp[i] = dp[i-1];
		if( s[i-1]=='0' or s[i-1]>='3' or ( s[i-1]=='2' and s[i]>='1'))
			continue;
		if( i>1 )
			dp[i] += dp[i-2];
		else
			dp[i]++;
		
		
	}
	// for(int i=0;i<n;i++)
	// 	cout << dp[i] << " ";
	// cout << endl;

	int ans = dp[n-1];
	cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int n,m;
	cin >> n >> m;
	int a[26];
	for(int i=0;i<26;i++)
		cin >> a[i];

	string s1,s2;
	cin >> s1 >> s2;

	int dp[n+1][m+1];
	int price[n+1][m+1];
	for(int i=0;i<=m;i++)
	{
		dp[0][i] = 0;
		price[0][i] = 0;
	}
	for(int i=0;i<=n;i++)
	{
		price[i][0] = 0;
		dp[i][0] = 0;
	}

	int M = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if( s1[i-1] == s2[j-1] )
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				price[i][j] = price[i-1][j-1] + a[s1[i-1]%97];
			}
			else
			{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
				price[i][j] = max(price[i][j-1],price[i-1][j]);
			}
			M = max(M,price[i][j]);
		}
	}
	cout << M << endl;

}
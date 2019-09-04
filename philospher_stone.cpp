/*
	you can only move from a cell to down, left or right
	idea: use 2d dp to the values and finally max of last row
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		ll a[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >> a[i][j];
		ll dp[n][m];
		for(int i=0;i<m;i++)
			dp[0][i] = a[0][i];
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(j==0)
				{
					dp[i][j] = max(dp[i-1][j],dp[i-1][j+1]) + a[i][j];
				}
				else if(j==m-1)
				{
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + a[i][j];
				}
				else
				{
					dp[i][j] = max( dp[i-1][j], max( dp[i-1][j-1],dp[i-1][j+1] ) )  + a[i][j];
				}
			}
		}
		ll ans = *max_element(dp[n-1],dp[n-1]+m);
		cout << ans << endl;
	}
}
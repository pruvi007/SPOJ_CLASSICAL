#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int a[k];
		for(int i=0;i<k;i++)
			cin >> a[i];
		int dp[k+1];
		
		for(int i=0;i<k;i++)
			dp[i] = a[i];
		for(int i=1;i<k;i++)
		{
			for(int j=0;j<i;j++)
			{
				if( dp[j]==-1 || a[i-j] == -1)
					continue;
				if( dp[i] == -1 )
					dp[i] = dp[j] + a[i-j];
				else
					dp[i] = min(dp[i],dp[j] + a[i-j]);
			}
		}
		if(k==0)
			cout << "0\n";
		else cout << dp[k-1] << endl;
	}
}
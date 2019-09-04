#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	
	string s;
	while(getline(cin,s)){
		if( s=="0" )
			break;
		int l = s.length();

		if( l==0 )
		{
			cout << endl;
			continue;
		}
		if( s[0]=='0' )
		{
			cout << 0 << endl;
			continue;
		}


		ll dp[l+1];
		dp[0] = 1;
		// if( s[1]>'0' )
		// 	dp[1] = 1;
		// if( s[0]=='1' or s[0]=='2' and s[0]<'7')
		// 	dp[1] += 1;
		dp[1] = 1;
		for(int i=2;i<=l;i++)
		{
			dp[i] = 0;
			if( s[i-1]>'0' )
				dp[i] = dp[i-1];

			if( s[i-2]=='1' or (s[i-2]=='2' and s[i-1]<'7') )
				dp[i] += dp[i-2];
		}
		cout << dp[l] << endl;

	}
}
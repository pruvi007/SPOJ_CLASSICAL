/*
	minimum no. of inserts in the string to make it a palindrome
	idea: use lcs on s and rev(s) 
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
string s;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		int n = s.length();
		string s2;
		s2 = s;
		reverse(s.begin(),s.end());
		int c = 0;
		int lcs[n+1][n+1];
		for(int i=0;i<=n;i++)
			lcs[0][i] = 0;
		for(int i=0;i<=n;i++)
			lcs[i][0] = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if( s[i-1]==s2[j-1] )
				{
					lcs[i][j] = lcs[i-1][j-1]+1;
				}
				else
				{
					lcs[i][j] = max( lcs[i-1][j],lcs[i][j-1] );
				}
			}
		}
		int l = lcs[n][n];
		cout << n - l << endl;
	}
}
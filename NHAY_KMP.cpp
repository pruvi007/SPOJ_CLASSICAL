/*
	SPOJ-NHAY
	Needle in the HayStack
	idea: use KMP to find all occurences
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string p,s;
	while(cin >> n >> p >> s)
	{
		int n = s.length();
		int m = p.length();

		// build lps array
		int lps[m];
		lps[0] = 0;
		int l=0,r=1;
		while(r<m)
		{
			if(p[l]==p[r])
			{
				l++;
				lps[r] = l;
				r++;
			}
			else
			{
				if(l>0)
					l = lps[l-1];
				else
				{
					lps[r] = 0;
					r++;
				}
			}
		}

		// start the KMP
		l=0;r=0;
		int flag=0;
		while(l<n)
		{
			if(s[l] == p[r])
			{
				l++;
				r++;
			}
			if(r == m)
			{
				flag=1;
				int ind = abs(r-l);
				cout << ind << endl;
				r = lps[r-1];
			}
			if(l<n && s[l] != p[r])
			{
				if(r > 0)
					r = lps[r-1];
				else
					l++;
			}
		}
		if(flag==0)
			cout << endl << endl;
	}
	
	
}
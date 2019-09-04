/*
	SPOJ-> colorful array
	idea: mark the initial and final point then after all queries do a prefix array
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n,q;
	cin >> n >> q;
	ll a[n],level[n];
	memset(a,0,sizeof(a));
	memset(level,0,sizeof(level));
	for(int i=0;i<q;i++)
	{
		ll x,y,c;
		cin >> x >> y >> c;
		
		a[x-1] = c;
		a[y-1] = -c;
		level[x-1] = i;
		level[y-1] = i;
	}
	int cur = -1;
	int cl = -1;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0 && level[i]>=cl)
		{
			cl = level[i];
			cur = a[i];
			if(a[i]<0)
			{
				a[i] = -1*a[i];
				cl = 0;
				cur = -1;
			}
			
		}
		else if((a[i]==0 || a[i]!=0) && level[i]<cl)
		{
			if(cur == -1)
			{

			}
			else
			{
				a[i] = cur;
			}
			

		}
	}
	for(int i=0;i<n;i++)
		cout << a[i] << endl;
	
}
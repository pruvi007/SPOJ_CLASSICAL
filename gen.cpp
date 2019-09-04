#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int isP(ll n)
{
	if(n<=1)
	{
		return 0;
	}
	else
	{
		int f=0;
		for(ll i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				f=1;
				break;
			}
		}
		if(f==1)
			return 0;
		return 1;
	}
}
int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		for(ll i=n;i<=m;i++)
		{
			if(isP(i))	cout<<i<<endl;
		}
		cout<<endl;
	}

	return 0;
}
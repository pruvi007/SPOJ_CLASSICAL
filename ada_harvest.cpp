#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	ll a[n];

	map< ll, map<ll,ll> > m;
	map<ll,ll> temp_m;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		temp_m[a[i]]++;
		m[i] = temp_m;
	}
	while(q--)
	{
		ll pos,val;
		scanf("%lld %lld",&pos,&val);
		
	}

}
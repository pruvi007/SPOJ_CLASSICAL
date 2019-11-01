#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e7+7;

ll fast_expo(ll a,ll n)
{
	ll res = 1;
	ll x = a;
	while(n)
	{
		if(n%2)
			res = (res%mod * x%mod)%mod;
		x = (x%mod * x%mod)%mod;
		n /= 2;
	}
	return res % mod;
}
int main()
{
	ll n,k;
	while( cin >> n >> k )
	{
		if( n==0 and k==0 )
			break;
		ll ans = 2*fast_expo(n-1,n-1)%mod + 2*fast_expo(n-1,k)%mod + fast_expo(n,n)%mod + fast_expo(n,k)%mod ;
		ans %= mod;
		cout << ans << endl;
	}
}
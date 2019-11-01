#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod = 1e9+7;

ll power(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b%2)
			res = (res%mod * a%mod)%mod;
		a = (a%mod * a%mod)%mod;
		b /= 2;
	}
	return res%mod;
}
int main()
{
	ll fib[100005];
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<=100001;i++)
		fib[i] = (i%mod * fib[i-1]%mod)%mod;
	ll n,w,t,r;
	cin >> n >> w >> t >> r;
	if( n==0 )
	{
		cout << "0\n";
		return 0;
	}

	ll ans = fib[n];
	ll a = power(fib[w],mod-2);
	ans = (ans%mod * a%mod)%mod; 

	ll b = power(fib[t],mod-2);
	ans = (ans%mod * b%mod)%mod;

	ll c = power(fib[r],mod-2);
	ans = (ans%mod * c%mod)%mod;
	
	
	cout << ans << endl;
}
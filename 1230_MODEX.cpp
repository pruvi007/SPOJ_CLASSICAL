#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll fast_expo(ll x,ll y,ll n)
{
	ll res = 1;
	while(y)
	{
		if(y%2)
			res = (res%n * x%n)%n;
		y/=2;
		x = (x%n * x%n)%n;
	}
	return res%n;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll x,y,n;
		cin >> x >> y >> n;
		ll ans = fast_expo(x,y,n);
		cout << ans << endl;
	}
}
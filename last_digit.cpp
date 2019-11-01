#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll fast_expo(ll a,ll b)
{
	ll res = 1;
	ll x = a;
	while(b)
	{
		if(b%2)
			res = (res*x)%10;
		x = (x*x) % 10;
		b /= 2;
	}
	return res%10;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll a,b;
		cin >> a >> b;
		ll ans = fast_expo(a,b);
		cout << ans << endl;
	}
}
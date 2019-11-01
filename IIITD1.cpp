#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		if(n==0)
		{
			printf("1\n");
			continue;
		}
		if(n>=0)
		{
			int c = 0;
			while(n)
			{
				c++;
				n/=10;
			}
			ll ans = pow(10,c-1);
			printf("%lld",ans);
		}
		else
		{
			ll N = -n;
			int c = 0;
			while(N)
			{
				c++;
				N/=10;
			}
			ll ans = -n + pow(10,c-1);
			ll f_ans = ans - (n);
			printf("%lld",f_ans);

		}
		printf("\n");
	}
}
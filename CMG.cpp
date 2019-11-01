#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++)
	{
		int n;
		scanf("%d",&n);
		stack<ll> s1,s2;
		
		ll M = 0;
		// cout << n << endl;
		vector<ll> v;
		printf("Case %d:\n",z);
		for(int i=0;i<n;i++)
		{
			char ch;
			scanf(" %c",&ch);

			if( ch=='A' )
			{
				ll x;
				scanf("%lld",&x);
				// while ((getchar()) != '\n'); 
				s1.push(x);
				if( x>M )
				{
					M = x;
				}
				s2.push(M);
			}
			else if( ch=='R' )
			{
				if( !s1.empty() )
				{
					ll x = s1.top();
					s1.pop();
					ll y = s2.top();
					s2.pop();
					if (M == y && !s2.empty() )
					{
						M = s2.top();
					}
					else
						M = 0;
				}
				
			}
			else if( ch=='Q' )
			{
				if( !s2.empty() )
				{
					ll x = s2.top();
					printf("%lld\n",x);
					// v.push_back(x);
				}
				else
					printf("Empty\n");
					// v.push_back(-1);
			}


		}

		
		// for(int i=0;i<v.size();i++)
		// {
		// 	if(v[i]==-1)
		// 		printf("Empty\n");
		// 	else 
		// 		printf("%lld\n",v[i]);
		// }

	}
}
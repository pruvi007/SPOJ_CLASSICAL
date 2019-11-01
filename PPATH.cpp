/*
	Prime Path
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int bs(vector<int> &sieve,int low,int high,int x)
{
	while( low<=high )
	{
		int mid = (low+high)/2;
		if( sieve[mid] == x )
			return mid;
		else if( sieve[mid]>x )
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}
bool check(int a,int b)
{
	string s1 = to_string(a);
	string s2 = to_string(b);
	int c = 0;
	for(int i=0;i<4;i++)
	{
		if(s1[i]!=s2[i])
			c++;
	}
	return c==1;
}
int main()
{
	int M = 100005;
	int sieve[M] = {0};
	for(int i=2;i<=M;i++)
	{
		int l=2;
		while( l*i<=M )
		{
			sieve[l*i] = 1;
			l+=1;
		}
	}
	vector<int> prime;
	for(int i=2;i<=M;i++)
	{
		if(sieve[i] == 0)
			prime.push_back(i);
	}
	// for(int i=0;i<prime.size();i++)
	// {
	// 	string x = to_string(prime[i]);
	// 	if(x.length()==4)
	// 	{
	// 		cout << i << endl;
	// 		break;
	// 	}
	// }
	// for(int i=0;i<prime.size();i++)
	// {
	// 	string x = to_string(prime[i]);
	// 	if(x.length()==5)
	// 	{
	// 		cout << i << endl;
	// 		break;
	// 	}
	// }

	int t;
	cin >> t;
	while(t--)
	{
		int a,b;
		cin >> a >> b;

		queue< pair<int,int> > q;
		q.push({a,0});
		int flag=0;
		bool vis[M];
		memset(vis,false,sizeof(vis));

		while(!q.empty())
		{
			pair<int,int> p = q.front();
			q.pop();
			int x = p.first;
			// cout << x << "-->" ;
			vis[x] = true;
			int y = p.second;
			if( x==b )
			{
				flag=1;
				cout << y << endl;
				break;
			}
			int st = bs(prime,0,prime.size()-1,x);
			for (int i=168;i<1230;i++)
			{
				string s = to_string(prime[i]);
				if( s.length() > 4 )
					break;
				else
				{
					if( check(prime[i],x) and vis[prime[i]] == false)
					{
						// cout << prime[i] << " ";
						q.push({prime[i],y+1});
						vis[prime[i]] = true;
					}

				}
			}
			// cout << endl;
		}
		if(flag==0)
			cout << "Impossible\n";


	}
}
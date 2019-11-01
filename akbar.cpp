#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,r,m;
		scanf("%d %d %d",&n,&r,&m);
		vector< vector<int> > v(n+1);
		for(int i=0;i<r;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int vis[n+1]={0};
		int g_flag=0;
		for(int i=0;i<m;i++)
		{
			int city,p;
			scanf("%d %d",&city,&p);
			queue< pair<int,int> > q;
			q.push( {city,0} );
			int l = 0;
			// vis[city]++;
			unordered_map<int,int> mp;
			if( g_flag==0)
			{
				while(!q.empty())
				{
					pair<int,int> x = q.front();
					q.pop();
					int a = x.first;
					int b = x.second;
					// cout << a << " " << b  <<endl;
					if( b==p+1 )
						break;
					
					if ( i>0 and vis[a] == 1 )
					{
						g_flag=1;
						break;
					}
					
					vis[a] = 1;
					mp[a] = 1;
					for(int j=0;j<v[a].size();j++)
					{
						if(mp.find( v[a][j] ) == mp.end())
							q.push({v[a][j],b+1});
							
					}

				}
			}
			
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			// cout << vis[i] <<  " " ;
			if( vis[i]==0 )
			{
				flag=1;
				break;
			}
		}
		
		
		if(g_flag or flag)
			printf("No\n");
		else printf("Yes\n");
	}
}
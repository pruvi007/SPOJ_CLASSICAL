/*
	Find shortest path between 2 cities. Use djikstra
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;


int min_vertex(int dis[],bool vis[],int n)
{
	int min=INT_MAX,min_ind=-1;
	for(int i=1;i<=n;i++)
	{
		if(dis[i] < min && vis[i] == false)
		{
			min = dis[i];
			min_ind = i;
		}
	}
	return min_ind;
}

int main(){
	int t;
	cin >> t;
	int c = 0;
	while(t--){
		int n;
		scanf("%d",&n);

		string s;
		unordered_map<string,int> mp;
		vector< vector< pair<int,int> > > v(100001);

		for(int z=0;z<n;z++)
		{	
			c+=1;
			cin >> s;
			mp[s] = c;
			int m;
			cin >> m;
			for(int i=0;i<m;i++)
			{
				int x,y;
				cin >> x >> y;
				v[c].push_back({x,y});
				v[x].push_back({x,y});

			}

		}
		int q;
		cin >> q;
		while(q--)
		{
			string s1,s2;
			cin >> s1 >> s2;
			int a = mp[s1];
			int b = mp[s2];

			int dis[n+1];
			for(int i=0;i<=n;i++)
				dis[i] = INT_MAX;
			int src = a;
			
			dis[src] = 0;
			bool vis[n+1];
			memset(vis,false,sizeof(vis));

			for(int i=1;i<=n;i++)
			{
				// for(int j=0;j<n;j++)
				// 	cout << dis[j] << " ";
				// cout << endl;
				int u = min_vertex(dis,vis,n);
				// cout << u << " ";
				if(u==-1)
					break;
				vis[u] = true;
				for(int j=0;j<v[u].size();j++)
				{
					pair<int,int> p = v[u][j];
					int f = p.first;
					int w = p.second; 
					if(vis[f]==false && dis[u]!=INT_MAX )
					{
						// cout << u << ": " << j << " " << dj[u][j] << endl;
						dis[f] = min(dis[f],dis[u]+w);
					}
				}
			}

			int ans = dis[b];
			cout << ans << endl;

		}
		

	}
}
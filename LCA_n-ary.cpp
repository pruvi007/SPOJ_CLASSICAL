/*
	LCA in n-Ary Tree
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;


vector<int> p1,p2;

void dfs(vector<vector<int> > &v, int n)
{
	p1.push_back(n);
	for(int i=0;i<v[n].size();i++)
		dfs(v,v[n][i]);
}
int main()
{
	int t;
	cin >> t;
	for(int z=1;z<=t;z++)
	{
		cout << "Case " << z << ":\n";
		int n;
		cin >> n;
		vector< vector<int> > v(n+1);
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			for(int j=0;j<x;j++)
			{
				int e;
				cin >> e;
				v[e].push_back(i);
			}
		}
		int q;
		cin >> q;
		while(q--)
		{
			
			int a,b;
			cin >> a >> b;
			if(a==b)
			{
				cout << a << endl;
				continue;
			}
			dfs(v,a);
			vector<int> path1 = p1;
			p1.clear();
			dfs(v,b);
			vector<int> path2 = p1;
			p1.clear();
			reverse(path1.begin(),path1.end());
			reverse(path2.begin(),path2.end());
			int ans=-1;
			// for(int i=0;i<path1.size();i++)
			// 	cout << path1[i] << " ";
			// cout << endl;
			// for(int i=0;i<path2.size();i++)
			// 	cout << path2[i] << " ";
			// cout << endl;

			int size = min(path1.size(),path2.size());
			for(int i=0;i<size;i++)
			{
				if(path1[i]!=path2[i])
				{
					ans = path1[i-1];
					break;
				}
			}
			if(ans==-1)
				cout << path1[size-1] << endl;
			else cout << ans << endl;

		}
		
	}
}
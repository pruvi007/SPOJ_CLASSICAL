/*
	Find the min no. of roads to connect all the cities 
	idea: use DSU to find total disconnected components
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int getPar(int x,int par[])
{
	while( x!=par[x] )
		x = par[x];
	return x;
}

int find(int x,int y,int par[])
{
	return getPar(x,par) == getPar(y,par);
}
int doUnion(int x,int y,int par[],int size[])
{
	if( find(x,y,par) )
		return -1;
	int p1 = getPar(x,par);
	int p2 = getPar(y,par);
	int s1 = size[p1];
	int s2 = size[p2];
	if( s1>s2 )
	{
		
			par[p2] = p1;
			size[p1] += s2;
		
	}
	else
	{
		
			par[p1] = p2;
			size[p2] += s1;
		
	}
	return 1;
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	// init dsu
	int par[n+1],size[n+1];
	for(int i=1;i<=n;i++)
	{
		par[i] = i;
		size[i] = 1;
	}
	while(q--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int ans = doUnion(x+1,y+1,par,size);
		// cout << ans << " ";
	}
	unordered_map<int,int> mp;
	for(int i=1;i<=n;i++)
	{
		int p = getPar(i,par);
		// cout << p << " ";
		mp[p]++;
	}
	int comp = mp.size();
	printf("%d\n",comp-1 );

}

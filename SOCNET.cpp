/*
	Maintain a DSU with path compression
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
int doUnion(int x,int y,int par[],int size[],int m)
{
	if( find(x,y,par) )
		return -1;
	int p1 = getPar(x,par);
	int p2 = getPar(y,par);
	int s1 = size[p1];
	int s2 = size[p2];
	if( s1>s2 )
	{
		if( size[p1]+s2 <= m)
		{
			par[p2] = p1;
			size[p1] += s2;
		}
		else
			return -1;
	}
	else
	{
		if( size[p2]+s1 <= m)
		{
			par[p1] = p2;
			size[p2] += s1;
		}
		else
			return -1;
	}
	return 1;
}
int main()
{
	int n,m;
	cin >> n >> m;
	// init DSU
	int par[n+1],size[n+1];
	for(int i=1;i<=n;i++)
	{
		par[i] = i;
		size[i] = 1;
	}
	int q;
	cin >> q;
	while(q--)
	{
		char ch;
		scanf(" %c",&ch);
		if( ch=='S' )
		{
			int x;
			scanf("%d",&x);
			int p = getPar(x,par);
			printf("%d\n",size[p]);

		}
		else if( ch=='A' )
		{
			int x,y;
			scanf("%d %d",&x,&y);
			int z = doUnion(x,y,par,size,m);
		}	
		else if( ch=='E' )
		{
			int x,y;
			scanf("%d %d",&x,&y);
			int f = find(x,y,par);
			if(f)
				printf("Yes\n");
			else 
				printf("No\n");

		}
	}

}
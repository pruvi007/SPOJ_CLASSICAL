/*
	Validate Maze - BFS
	find one entry that leads to exit
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

string maze[100];
int n,m;
bool vis[21][21];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

map< pair<int,int>, int> d;
bool safe(int i,int j)
{
	return (i>=0 and i<n and j>=0 and j<m and maze[i][j]=='.');
}

bool bfs(int i,int j)
{
	queue< vector<int> > q;
	q.push({i,j});
	pair<int,int> st = {i,j};
	while(!q.empty())
	{
		vector<int> v = q.front();
		vis[v[0]][v[1]] = true;
		q.pop();

		pair<int,int> p = {v[0],v[1]};
		if( d.find(p)!=d.end() and p!=st )
		{
			// cout << p.first << "," << p.second << endl;
			return true;
		}
		for(int i=0;i<4;i++)
		{
			int a = v[0] + dx[i];
			int b = v[1] + dy[i];
			if( safe(a,b) and vis[a][b] == false)
			{
				vis[a][b] = true;
				q.push({a,b});
			}
		}
	}
	return false;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		
		

		cin >> n >> m;
		
		for(int i=0;i<n;i++)
			cin >> maze[i];

		// collect all the exit and entry points
		for(int i=0;i<m;i++)
		{
			if(maze[0][i] == '.')
				d[{0,i}] = 1;
		}
		for(int i=0;i<n;i++)
		{
			if(maze[i][0] == '.' and d.find({i,0}) == d.end())
				d[{i,0}] = 1;
		}
		for(int i=0;i<m;i++)
		{
			if(maze[n-1][i] == '.' and d.find({n-1,i}) == d.end())
				d[{n-1,i}] = 1;
		}
		for(int i=0;i<n;i++)
		{
			if(maze[i][m-1]=='.' and d.find({i,m-1})==d.end() )
				d[{i,m-1}] = 1;
		}


		// if(d.size() != 2)
		// {
		// 	cout << "invalid\n";
		// 	continue;
		// }
		int path = 0;
		vector< pair<int,int> > temp;
		for(auto it = d.begin();it!=d.end();it++)
		{

			pair<int,int> p = it->first;
			// cout << p.first << "," << p.second << " --> "; 
			for(int i=0;i<=20;i++)
				for(int j=0;j<=20;j++)
					vis[i][j] = false;

			bool c = bfs(p.first,p.second);
			if(c)
			{
				path++;
			}
		}
		// cout << path << endl;
		if(ceil((double)path/2.0) == 1)
			cout << "valid\n";
		else
			cout << "invalid\n";

		d.clear();
	}
}
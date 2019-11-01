/*
	Merge if belong to same path
	idea: maintain a two indexed DSU
*/
// solution by @pruvi007

#include <bits/stdc++.h>
using namespace std;
 
int n,m;
char g[1002][1002];
pair<int,int> p[1002][1002]; // parent array 
 
//each cell is a node represented by a pair{row_number , col_number}

 
// find is used to find the parents(or sets) to which a given node belongs
 
pair<int,int> find(pair<int,int> x){
	if(x == p[x.first][x.second] ) return x;
	else
	return p[x.first][x.second]=find(p[x.first][x.second]);
}
 
bool merge(pair<int,int> x ,pair<int,int> y){
	pair<int,int> xx = find(x) , yy=find(y);
	if(xx==yy)return false;
	p[yy.first][yy.second] = xx;
	return true;
}
 
bool check(int x,int y){
	if(x<0 || y<0 || x>=n || y>=m)return false;
	return true;
}
 
 
int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	cin>>g[i][j] , p[i][j] = make_pair(i,j);
	
 
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{ int x,y;
		if(g[i][j]=='N'){
		  if(check(i-1,j))x=i-1,y=j,merge(make_pair(i,j),make_pair(i-1,j));}
		else if(g[i][j]=='S'){
		  if(check(i+1,j))x=i+1,y=j,merge(make_pair(i,j),make_pair(i+1,j));}
		else if(g[i][j]=='E'){
		 if(check(i,j+1))x=i,y=j+1,merge(make_pair(i,j),make_pair(i,j+1));}
		else if(g[i][j]=='W'){
		 if(check(i,j-1))x=i,y=j-1,merge(make_pair(i,j),make_pair(i,j-1));}
	
	}
	
	 int cnt =0;
	
	for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	if(p[i][j] == make_pair(i,j))cnt++;
	}
	}
	cout<< cnt <<"\n";
	
	return 0;
}
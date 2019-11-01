#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int getPar(int x,int par[])
{
	while(x!=par[x])
		x = par[x];
	return x;
}

int find( int x,int y,int par[] )
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
	if(s1 > s2)
	{
		par[p2] = p1;
		size[s1] += s2;
	}
	else
	{
		par[p1] = p2;
		size[s2] += s1;
	}
	return 1;
}


bool check_valid(vector<ll> &temp,vector<vector<ll> > &v)
{
	for(int i=0;i<temp.size();i++)
	{
		int x = temp[i];
		for(int j=0;j<v[x].size();j++)
		{
			int y = v[x][j];
			for(int k=0;k<temp.size();k++)
			{
				if( y==temp[k] )
					return false;
			}
		}
	}
	return true;
}
ll M = 0;
unordered_map<ll,ll> mp;
void gen_subsets(vector<ll> &sub,int l,vector<ll> &temp, vector< vector<ll> > &v)
{
	if( l==sub.size() )
	{
		// check validity of subsequence
		bool valid = check_valid(temp,v);
		// cout << valid << endl;
		if(valid)
		{
			ll sum = 0;
			for(int i=0;i<temp.size();i++)
				sum += mp[temp[i]];
			M = max(M,sum);
		}
			return;

	}
	temp.push_back(sub[l]);
	gen_subsets(sub,l+1,temp,v);

	temp.pop_back();
	gen_subsets(sub,l+1,temp,v);
}
int main()
{
	ll p[9];
	
	for(int i=1;i<=8;i++)
	{
		cin >> p[i];
		mp[i] = p[i];
	}
	int par[9],size[9];
	for(int i=1;i<=8;i++)
	{
		par[i] = i;
		size[i] = 1;
	}
	int q;
	cin >> q;
	vector< vector<ll> > v(9);
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	ll sum = 0;
	vector<ll> sub;
	for(int i=1;i<=8;i++)
	{
		if(v[i].size() == 0)
			sum += mp[i];
		else
			sub.push_back(i);
	}
	vector<ll> temp;
	gen_subsets(sub,0,temp,v);
	cout << sum + M <<endl;
	M = 0;
	mp.clear();

}
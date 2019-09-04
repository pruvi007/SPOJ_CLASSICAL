/*
	Here we will find LIS by maintaining length array (which will be sorted)
	find the upper bound of current element and update the index if new element inserted increment length
	!important ques
	LIS in Nlgn
*/

#include<bits/stdc++.h>
using namespace std;

int bs(int tail[],int low,int high,int x)
{
	int ind=-1;
	while( low<=high )
	{
		int mid = (low+high)/2;
		int a = tail[mid];
		if( a>=x )
		{
			ind = mid;
			high= mid-1;
		}
		else 
			low = mid+1;
	}
	return ind;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector< pair<int,int> > v(n);
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<n;i++)
			cin >> b[i];
		for(int i=0;i<n;i++)
			v[i] = {a[i],b[i]};
		sort(v.begin(), v.end());
		// for(int i=0;i<n;i++)
		// 	cout << v[i].first << " " << v[i].second << endl;
		int lis[n];
		lis[0] = 1;
		int tail[n];
		tail[0] = v[0].second;
		int l = 1;
		for(int i=1;i<n;i++)
		{
			int p = upper_bound(tail,tail+l,v[i].second) - tail;
			tail[p] = v[i].second;
			if( p==l )
				l++;
			
		}
		// for(int i=0;i<n;i++)
		// 	cout << tail[i] << " ";
		// cout << endl;
		int ans = l;
		cout << ans << endl;

	}
}
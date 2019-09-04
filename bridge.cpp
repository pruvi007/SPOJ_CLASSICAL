#include<bits/stdc++.h>
using namespace std;
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
		for(int i=1;i<n;i++)
		{
			lis[i] = 1;
			for(int j=0;j<i;j++)
			{
				if( v[i].second >= v[j].second ) 
					lis[i] = max(lis[i],lis[j]+1);
			}
		}
		// for(int i=0;i<n;i++)
		// 	cout << lis[i] << " ";
		// cout << endl;
		int ans = *max_element(lis,lis+n);
		cout << ans << endl;

	}
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		unordered_map<ll,ll> mp;
		int c = 0;
		ll a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			int x = a[i];
			
			int d2 = k-x;
			if( mp.find(d2)!=mp.end() )
				c++;
			mp[x] = 1;
		}
		cout << c << endl;
	}
	
}
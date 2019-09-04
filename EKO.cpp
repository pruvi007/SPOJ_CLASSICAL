/*
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	// int t;
	// cin >> t;
	// while(t--)
	// {
		ll n,k;
		cin >> n >> k;
		ll a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		ll low = 0,high=*max_element(a,a+n);
		ll ans;
		while(low<=high)
		{
			ll mid = (low+high)/2;
			// cout << mid << endl;
			ll sum = 0;
			for(int i=0;i<n;i++)
			{
				if(a[i]>mid)
					sum += a[i]-mid;
			}
			if( sum>=k )
			{
				ans = mid;
				low = mid+1;
			}
			else
				high = mid-1;
		}
		cout << ans << endl;
	// }
}
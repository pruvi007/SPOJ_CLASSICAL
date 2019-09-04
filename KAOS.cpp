/*
	find total pairs which create kaos.
	idea: get the indeing from the sorted list and sort them in reverse order-> the arrangement of the new indexes (find inversion count in that arrange)

*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll merge(ll a[],ll l,ll m,ll r)
{

	ll i=l,j=m,k=l;
	
	ll c = 0;

	vector<ll> temp;
	while(i<m && j<=r)
	{
		if(a[i]<=a[j])
		{
			temp.push_back(a[i]);
			i++;
		}
		else
		{
			temp.push_back(a[j]);

			// if L[i] is greater than R[j], then all the remaining elemnts will also be greater then R[j];
			c += (m-i);
			j++;
		}
		
	}
	while(i<m)
		temp.push_back(a[i++]);
	while(j<=r)
		temp.push_back(a[j++]);

	ll ct=0;
	for(ll i=l;i<=r;i++)
		a[i] = temp[ct++];
	temp.clear();
	return c;
}

ll merge_sort(ll a[],ll l,ll r)
{
	ll c =0;
	if(l<r)
	{
		ll mid = (l+r)/2;

		c = merge_sort(a,l,mid);
		c += merge_sort(a,mid+1,r);

		c += merge(a,l,mid+1,r);

	}
	return c;
}

int main(){
	// ll t;
	// cin >> t;
	// while(t--)
	// {
	ll n;
	cin >> n;
	vector<string> s;
	vector< pair<string,ll> > sr;

	for(ll i=0;i<n;i++)
	{
		string x;
		cin >> x;
		if(x.length() > 0)
			s.push_back(x);
	}
	// cout << endl;
	sort(s.begin(),s.end());
	
	for(ll i=0;i<s.size();i++)
	{
		// cout << s[i] << endl;
		string x = s[i];
		reverse(x.begin(), x.end());
		sr.push_back({x,i});
	}
	sort(sr.begin(),sr.end());
	// cout << endl;

	ll a[s.size()];
	for(ll i=0;i<s.size();i++)
	{
		// cout << sr[i].first << " " << sr[i].second << endl;
		a[i] = sr[i].second;
		// cout << a[i] << " ";
	}
	// cout << endl;

	
	ll ans = merge_sort(a,0,s.size());
	cout << ans << endl;

	// }
}
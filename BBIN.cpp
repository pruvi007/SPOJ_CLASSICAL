#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int n,q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];

	while(q--)
	{
		int k;
		cin >> k;
		int low=0,high=n-1;
		int p = lower_bound(a.begin(),a.end(),k) - a.begin();
		if(a[p] == k)
			cout << p << endl;
		else 
			cout << "-1\n";
	}
	
}
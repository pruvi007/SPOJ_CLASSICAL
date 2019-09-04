#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int find_upper(int a[],int low,int high,int x)
{
	int p=-1;
	while( low<=high )
	{
		int mid = (low+high)/2;
		if( a[mid]>x )
		{
			p = mid;
			high = mid-1;
		}
		else 
			low = mid+1;
	}
	return p;
}
int main()
{
	int n;
	while( cin >> n )
	{
		if( n==0 )
			break;
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		int c = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int x = a[i];
				int y = a[j];
				int p = find_upper(a,j+1,n-1,x+y);
				if( p!=-1 )
					c += (n-p);
			}
		}
		cout << c << endl;

	}
}
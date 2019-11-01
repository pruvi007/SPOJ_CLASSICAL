#include<bits/stdc++.h>
using namespace std;

bool pal(int n)
{
	string s = to_string(n);
	int l = s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i] != s[l-i-1])
			return false;
	}
	return true;
}
int prod_digits(int n)
{
	int p = 1;
	while(n)
	{
		if(n%10!=0)
			p = p*(n%10);
		n/=10;
	}
	return p;
}
int main()
{
	vector<int> pp,prime;
	int sieve[1000005]={0};
	for(int i=2;i<=1000005;i++)
	{
		int l = 2;
		while( l*i <= 1000005 )
		{
			sieve[l*i] = 1;
			l++;
		}
	}
	for(int i=2;i<=1000005;i++)
	{
		if(sieve[i] == 0)
			prime.push_back(i);
	}
	// cout << prime.size() << endl;
	for(int i=0;i<prime.size();i++)
	{
		if( pal(prime[i]) )
			pp.push_back(prime[i]);
	}
	// cout << pp.size() << endl;
	// for(int i=0;i<pp.size();i++)
	// 	cout << pp[i] << " ";
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << pp[n-1] << " ";
		int m = prod_digits(pp[n-1]);
		cout << prime[m-1] << endl;
	}

}
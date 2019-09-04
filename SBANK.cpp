/*
	SPOJ - SBANK
	idea: usea map of string ,int
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while( t-- )
	{
		int n;
		cin >> n;
		cin.ignore();
		map<string,int> m;
		for(int i=0;i<n;i++)
		{
			string x;
			
			getline(cin,x);
			m[x]++;
		}
		map<string,int>::iterator it;
		for(it=m.begin();it!=m.end();it++)
			cout << it->first << " " << it->second << endl;
		cout << endl;
	}
}
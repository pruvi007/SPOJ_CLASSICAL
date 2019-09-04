/*
	SPOJ: ONP-transform the expression
	convert the gievn expression into postfix
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int pre(char c)
{
	if(c=='+' || c=='-')
		return 1;
	if(c=='*' || c=='/')
		return 2;
	if(c=='^')
		return 3;
	return -1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int l = s.length();
		stack<char> st;
		for(int i=0;i<l;i++)
		{
			if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
				cout<<s[i];
			else if(s[i]=='(')
				st.push(s[i]);
			else if(s[i]==')')
			{
				while(!st.empty() && st.top()!='(')
				{
					cout<<st.top();
					st.pop();
				}
				if(!st.empty() && st.top()=='(')
					st.pop();
			}
			else
			{
				while(!st.empty() && pre(s[i])<=pre(st.top()))
				{
					cout<<st.top();
					st.pop();
				}
				st.push(s[i]);
			}
		}
		while(!st.empty())
		{
			cout<<st.top();
			st.top();
		}
		cout<<endl;
	}
}
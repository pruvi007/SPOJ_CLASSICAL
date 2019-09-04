/*
	find min numbers of brackets to invert to make the string balanced
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t=0;
	string s;
	while( cin >> s )
	{
		if(s[0]=='-')
			break;
		stack<char> st;
		int c = 0;
		for(int i=0;i<s.length();i++)
		{
			if( s[i]=='{' )
				st.push(s[i]);

			else if( s[i]=='}' )
			{
				if( !st.empty() )
					st.pop();

				// mismatch
				else
				{
					st.push(s[i]);
					c++;
				}
			}
				
		}
		t+=1;
		cout << t << ". " << st.size()/2 + c << endl;
	}
}


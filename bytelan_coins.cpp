/*
	a coin can be divided into n/2,n/3,n/4
	find the max denomination
	idea: use recursion and get max out of n and above
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
unordered_map<ll,ll> mp;
ll maxDen(ll n){
	
	if( n<=10 )
		return n;
	if( mp.find(n)!=mp.end() )
		return mp[n];
	mp[n] = max( n,maxDen(n/2)+maxDen(n/3)+maxDen(n/4) );
	return mp[n];

}

int main(){
	ll n;
	while( cin>>n ){
		ll ans = maxDen(n);
		cout << ans << endl;
		mp.clear();
	}
}


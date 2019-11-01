
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll mod = 1e9+7;


// matrix exponentiation to find the nth fibonacci numbers (lgn)

void multiply(ll F[2][2], ll M[2][2]); 
void power(ll F[2][2], ll n); 
  
ll fib(ll n) 
{ 
  ll F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
      return 0; 
  power(F, n-1); 
  
  return F[0][0]%mod; 
} 
  
void multiply(ll F[2][2], ll M[2][2]) 
{ 
  ll x =  F[0][0]%mod*M[0][0]%mod + F[0][1]%mod*M[1][0]%mod; 
  ll y =  F[0][0]%mod*M[0][1]%mod + F[0][1]%mod*M[1][1]%mod; 
  ll z =  F[1][0]%mod*M[0][0]%mod + F[1][1]%mod*M[1][0]%mod; 
  ll w =  F[1][0]%mod*M[0][1]%mod + F[1][1]%mod*M[1][1]%mod; 
  
  F[0][0] = x%mod; 
  F[0][1] = y%mod; 
  F[1][0] = z%mod; 
  F[1][1] = w%mod; 
} 
  
void power(ll F[2][2], ll n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  ll M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 

ll fast_expo(ll x,ll y)
{
	ll res = 1;
	while(y)
	{
		if(y%2)
			res = (res * x )%mod;
		y/=2;
		x = (x*x)%mod;
	}
	return res;
}
int main()
{
	int n,k;
	cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	ll sum = 0;
	ll g = fib(fast_expo(a[0],k));
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ll p1 = fast_expo(a[i],k);
			// g = __gcd(g,fib(p1));
			ll p2 = fast_expo(a[j],k);
			sum += __gcd(fib(p1),fib(p2));
		}
	}
	cout << sum << endl;
}
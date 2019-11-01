/*
	Paint HAT - SPOJ
	idea: use volume and lateral SA
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pi 3.141592653

int main()
{
	int n;
	cin >> n;
	while( n-- )
	{
		ld r,h;
		cin >> r >> h;
		ld low = 0, high = 200;
		ld LA = 2*pi * r * sqrt(r*r+h*h);
		ld ans=-1;
		while (low<=high)
		{
			ld H = (low+high)/2.0;
			// cout << H << endl;

			ld R = r * H/h ;
			ld volume = (pi * R*R * H)/3.0;
			// the below LA need not to be painted
			ld not_LA = pi * R * sqrt(R*R+H*H);
			ld to_paint = abs(not_LA - LA);
			if( volume >= to_paint)
			{
				ans = H;
				high = H-0.0000001;
			}
			else
				low = H+0.0000001;

		}
		cout << fixed ;
		if(ans > h)
			cout << setprecision(6) << h << endl;
		else
			cout << setprecision(6) << ans << endl;
	}
}

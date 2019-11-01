#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll tree[5000005];
void build(ll a[],int l,int r,int pos)
{
	if(l==r)
	{	
		tree[pos] = a[l];
		return;
	}
	int mid = (l+r)/2;
  
	// left child
	build(a,l,mid,2*pos+1);
	// right child
	build(a,mid+1,r,2*pos+2);
  	//adding so that we get total no of set bits 
	tree[pos] = tree[pos*2+1]+tree[pos*2+2];
}

void updateSegmentTree(int index, int delta, int low, int high, int pos){
       
        //if index to be updated is less than low or higher than high just return.
        if(index < low || index > high){
            return;
        }
        
        //if low and high become equal, then index will be also equal to them and update
        //that value in segment tree at pos
        if(low == high){
            tree[pos] += delta;
            return;
        }
        //otherwise keep going left and right to find index to be updated 
        //and then update current tree position if min of left or right has
        //changed.
        int mid = (low + high)/2;
        updateSegmentTree(index, delta, low, mid, 2 * pos + 1);
        updateSegmentTree(index, delta, mid + 1, high, 2 * pos + 2);
        tree[pos] = tree[2*pos+1] + tree[2*pos + 2] ;
    }

ll rangeSum(int low,int high,int qlow,int qhigh,int pos){
        if(qlow <= low && qhigh >= high){
            return tree[pos];
        }
        if(qlow > high || qhigh < low){
            return 0;
        }
        int mid = (low+high)/2;
        return rangeSum(low, mid, qlow, qhigh, 2 * pos + 1) + rangeSum(mid + 1, high, qlow, qhigh, 2 * pos + 2);
    }

int main()
{
	int n;
	scanf("%d",&n);
	ll a[n];
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	build(a,0,n,0);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char ch;
		scanf(" %c",&ch);
		if( ch=='q' )
		{
			int x,y;
			scanf("%d %d",&x,&y);
			ll ans = rangeSum(0,n,x-1,y-1,0);
			printf("%lld\n",ans);
		}
		else
		{
			ll x,y;
			scanf("%lld %lld",&x,&y);
			updateSegmentTree(x-1,y,0,n,0);
		}
	}
}
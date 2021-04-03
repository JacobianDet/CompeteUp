#include <bits/stdc++.h>

struct t2
{
	int x, y;
}arr[300001];

int mxl1[300001], mxl2[300001], mnr1[300001], mnr2[300001];

bool cmpx(t2 a, t2 b)
{
	return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i].x>>arr[i].y;
	std::sort(arr, arr+n, cmpx);
	mxl1[0] = arr[0].x;
	mnr1[0] = arr[0].y;
	for(int i=1;i<n;i++)
	{
		mxl1[i] = std::max(arr[i].x, mxl1[i-1]);
		mnr1[i] = std::min(arr[i].y, mnr1[i-1]);
	}
	mxl2[n-1] = arr[n-1].x;
	mnr2[n-1] = arr[n-1].y;
	for(int i=n-2;i>=0;i--)
	{
		mxl2[i] = std::max(arr[i].x, mxl2[i+1]);
		mnr2[i] = std::min(arr[i].y, mnr2[i+1]);
	}
	int mlen = 0;	
	for(int i=0;i<n;i++)
	{
		int cx = 0, cy = 0;
		if(!i)
		{	
			cx = mxl2[i+1];
			cy = mnr2[i+1];
		}
		else if(i == n-1)
		{
			cx = mxl1[i-1];
			cy = mnr1[i-1];
		}	
		else
		{
			cx = std::max(mxl1[i-1], mxl2[i+1]);
			cy = std::min(mnr1[i-1], mnr2[i+1]);
		}
		mlen = std::max(mlen, (cy - cx));
	}
	std::cout<<mlen<<"\n";
	return 0;
}
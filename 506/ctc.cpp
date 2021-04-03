#include <bits/stdc++.h>

typedef long long ll;

ll arr[200001];
ll pos[200001];

int bs2(int ind, int n, ll val)
{
	int lo = ind;
	int hi = n-1;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(arr[mid] > (2 * val))
		hi = mid - 1;
		else lo = mid;	
	}
	return lo;
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>arr[i];
	ll mpos = 1;
	pos[n-1] = 1;
	for(int i=n-2;i>=0;i--)
	{
		int px = bs2(i, n, arr[i]);
		if(px == i)
		pos[i] = 1;
		else pos[i] = pos[px] + (px - i);	
		mpos = std::max(mpos, pos[i]);
	}	
	std::cout<<mpos<<"\n";
	return 0;
}
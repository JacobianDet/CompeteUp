#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

ll arr[100001];

int bs2(int i, int n, ll U)
{
	int lo = i+2;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(arr[mid] <= arr[i] + U)
		lo = mid;
		else hi = mid - 1;	
	}
	if((lo > hi) || (arr[lo] > arr[i] + U))
	return -1;	
	else return lo;
}

int main(void)
{
	int n;
	ll U;
	std::cin>>n>>U;
	ld eff = 0;
	for(int i=1;i<=n;i++)
	std::cin>>arr[i];
	bool ok = 0;
	for(int i=1;i<=n;i++)
	{
		int p2 = bs2(i, n, U);
		if(p2 == -1)
		continue;
		else
		{
			ok = 1;
			ld peff = ((ld)(arr[p2] - arr[i+1]))/(arr[p2] - arr[i]);
			if(peff > eff)
			eff = peff;	
		}	
	}	
	if(!ok)
	std::cout<<"-1\n";
	else printf("%.12Lf\n", eff);
	return 0;	
}
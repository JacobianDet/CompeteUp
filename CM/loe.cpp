#include <bits/stdc++.h>
#define pb push_back

std::vector<int> Z;

int bs1(int k)
{
	int lo = 1;
	int hi = 1000000000;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		int px = std::upper_bound(Z.begin(), Z.end(), mid) - Z.begin();
		if(px < k)
		lo = mid + 1;
		else hi = mid;	
	}
	if((std::upper_bound(Z.begin(), Z.end(), lo) - Z.begin()) > k)
	return -1;
	else return lo;	
}

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		Z.pb(t);
	}	
	std::sort(Z.begin(), Z.end());
	int ans = bs1(k);
	std::cout<<ans<<"\n";
	return 0;
}
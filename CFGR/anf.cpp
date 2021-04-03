#include <bits/stdc++.h>
#define pb push_back

int hgt[1001];

int bs2(int n, int h)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		std::vector<int> Z;
		for(int i=1;i<=mid;i++)
		Z.pb(hgt[i]);
		std::sort(Z.rbegin(), Z.rend());
		int xh = h;
		bool ok = 1;
		for(int i=0;i<mid;i+=2)
		{
			if(xh >= Z[i])	
			xh -= Z[i];
			else 
			{
				ok = 0;
				break;
			}	
		}
		if(ok)
		lo = mid;
		else hi = mid - 1;	
	}
	return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,h;
	std::cin>>n>>h;
	for(int i=1;i<=n;i++)
	std::cin>>hgt[i];
	int ans = bs2(n, h);
	std::cout<<ans<<"\n";
	return 0;	
}
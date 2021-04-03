#include <bits/stdc++.h>

int mmdist(int n,int a,int b)
{
	int lo = 1;
	int hi = std::min(a,b);
	while(lo < hi)
	{
		int mid = lo + (hi-lo+1)/2;
		int x = a/mid;
		int y = b/mid;
		if(x+y >= n)
		lo = mid;
		else hi = mid-1;	
	}	
	return lo;
}

int main(void)
{
	int n,a,b;
	std::cin>>n>>a>>b;
	int ans = mmdist(n,a,b);
	std::cout<<ans<<"\n";
	return 0;
}
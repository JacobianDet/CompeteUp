#include <bits/stdc++.h>

int bs2(int n)
{
	int lo = 1;
	int hi = n;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		if(mid * mid > n)
		hi = mid-1;
		else lo = mid;	
	}
	return lo;
}

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		int cst = 0;
		while(n)
		{
			cst++;
			int lx = bs2(n);
			n -= lx*lx;
		}
		std::cout<<cst<<"\n";
	}
	return 0;
}
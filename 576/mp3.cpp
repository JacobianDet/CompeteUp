#include <bits/stdc++.h>

std::map<int, int> ctr, ctz;

int bs1(int x)
{
	int lo = 0;
	int hi = 21;
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if((1<<mid) < x)
		lo = mid + 1;
		else hi = mid;	
	}
	return lo;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,I;
	std::cin>>n>>I;
	for(int i=0;i<n;i++)
	{
		int z;
		std::cin>>z;
		ctr[z]++;
		ctz[z]++;
	}
	int x = ctr.size();
	int lx = bs1(x);
	if(8*I >= n*lx)
	std::cout<<"0\n";
	else
	{
		std::map<int, int>::iterator it1 = ctr.begin();
		std::map<int, int>::iterator it2 = ctr.begin();
		while(it1 != ctr.end())
		{
			if(it1 != ctr.begin())
			{
				it1->second += it2->second;
				it2 = it1;
			}	
			it1++;
		}
		it1 = ctr.begin();
		it2 = ctr.begin();
		int sx = 1;
		int unc = 0;
		while(it1 != ctr.end())
		{
			lx = bs1(sx);
			if(8*I >= n*lx)
			{	
				unc = std::max(unc, ctr[it1->first] - ctr[it2->first] + ctz[it2->first]);
				it1++;
				sx++;
			}
			else 
			{
				it2++;
				sx--;
			}		
		}
		it1--;
		while(it2 != ctr.end())
		{
			lx = bs1(sx);
			if(8*I >= n*lx)
			unc = std::max(unc, ctr[it1->first] - ctr[it2->first] + ctz[it2->first]);
			it2++;	
			sx--;
		}	
		std::cout<<(n-unc)<<"\n";
	}	
	return 0;
}
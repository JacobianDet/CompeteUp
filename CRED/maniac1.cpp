#include <bits/stdc++.h>

int main(void)
{
	int n,k;
	std::cin>>n>>k;
	std::multiset<int, std::greater<int> > M;
	for(int i=0;i<n;i++)
	{
		int z;
		std::cin>>z;
		M.insert(z);
	}
	int cz = 1, noi = 0, ans = 0;
	while(!M.empty())
	{
		ans += (*M.begin()) * cz;
		M.erase(M.begin());
		noi++;
		if(!(noi % k))
		cz++;	
	}
	std::cout<<ans<<"\n";
	return 0;
}
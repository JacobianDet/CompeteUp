#include <bits/stdc++.h>

int pc[100001];

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++)
	std::cin>>pc[i];
	int c1 = 0, c2 = 0, mc = 0;
	for(int i=1;i<=n;i++)
	{
		if(i == 1)
		{	
			c1++;
			continue;
		}
		else if(pc[i] == pc[i-1])
		c1++;
		else
		{
			mc = std::max(mc, std::min(c1, c2));
			c2 = c1;
			c1 = 1;
		}		
	}	
	mc = std::max(mc, std::min(c1, c2));
	std::cout<<2*mc<<"\n";
	return 0;
}
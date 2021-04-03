#include <bits/stdc++.h>

int vx[1001];

int main(void)
{
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++)
	std::cin>>vx[i];
	int ans = 0;	
	for(int i=0;i<m;i++)
	{
		int s,d;
		std::cin>>s>>d;
		ans += std::min(vx[s], vx[d]);
	}	
	std::cout<<ans<<"\n";
	return 0;
}
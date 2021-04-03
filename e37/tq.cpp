#include <bits/stdc++.h>
#define mp std::make_pair

int main(void)
{
	int t;
	std::cin>>t;
	while(t--)
	{
		int n;
		std::cin>>n;
		std::pair<int, int> Z[n+1];
		int tea[n+1];
		memset(tea,0,sizeof(tea));
		for(int i=1;i<n+1;i++)
		{
			int l,r;
			std::cin>>l>>r;
			Z[i] = mp(l, r);
		}	
		int time = Z[1].first;
		for(int i=1;i<=n;i++)
		{
			if(time >= Z[i].first && time <= Z[i].second)
			{	
				tea[i] = time;
				time++;
			}
			else if(time < Z[i].first)
			{
				time = Z[i].first;
				tea[i] = time;
				time++;
			}	
		}
		for(int i=1;i<=n;i++)
		std::cout<<tea[i]<<" ";
		std::cout<<"\n";	
	}	
	return 0;
}
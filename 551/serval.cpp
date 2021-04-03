#include <bits/stdc++.h>

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,t;
	std::cin>>n>>t;
	int mx = 1000000000, bus = -1;
	for(int i=0;i<n;i++)
	{
		int s,d;
		std::cin>>s>>d;
		if(s >= t)
		{
			if(mx > s)
			{
				mx = s;
				bus = i;
			}	
		}	
		else
		{
			int tx = (t - s)/d;
			if((t - s) % d)
			tx++;
			int zf = s + tx * d;
			if(mx > zf)
			{
				mx = zf;
				bus = i;
			}	
		}
	}
	std::cout<<bus+1<<"\n";
	return 0;	
}
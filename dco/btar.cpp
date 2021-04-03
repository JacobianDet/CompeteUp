#include <bits/stdc++.h>

int ctx[4];

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		memset(ctx, 0, sizeof(ctx));
		int n;
		std::cin>>n;
		int sx = 0;
		for(int i=0;i<n;i++)
		{
			int x;
			std::cin>>x;
			x %= 4;
			sx += x;
			ctx[x]++;
		}
		bool ok = 1;
		int ax = 0;
		if(sx % 4) 
		ok = 0;
		else
		{
			ax = ctx[2]/2;
			ctx[2] &= 1;
			int fx = std::min(ctx[3], ctx[1]);
			ax += fx;
			ctx[3] -= fx;
			ctx[1] -= fx;
			if(ctx[1] > 0)
			{
				if(!(ctx[1] % 4))
				ax += (ctx[1] - ctx[1]/4);
				else if(!(ctx[1] & 1) && ctx[2])
				{
					ax += 2*ctx[2];
					ctx[1] -= 2*ctx[2];
					ctx[2] = 0;
					if(!(ctx[1] % 4))
					ax += (ctx[1] - ctx[1]/4);
					else ok = 0;
				}
				else ok = 0;	
			}
			else if(ctx[3] > 0)
			{
				if(!(ctx[3] % 4))
				ax += (ctx[3] - ctx[3]/4);
				else if(!(ctx[3] & 1) && ctx[2])
				{
					ax += 2*ctx[2];
					ctx[3] -= 2*ctx[2];
					ctx[2] = 0;
					if(!(ctx[3] % 4))
					ax += (ctx[3] - ctx[3]/4);
					else ok = 0;
				}
				else ok = 0;	
			}
		}	
		if(ok)
		std::cout<<ax<<"\n";
		else std::cout<<"-1\n";
	}
	return 0;
}
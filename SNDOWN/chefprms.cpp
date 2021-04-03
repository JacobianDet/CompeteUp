#include <bits/stdc++.h>

int lo[1001];

void siever(void)
{
	for(int i=1;i<1001;i++)
	lo[i] = i;
	for(int p=2;p*p<1001;p++)
	{
		if(lo[p] == p)
		{
			for(int i=p*p;i<1001;i+=p)
			{
				if(lo[i] == i)
				lo[i] = p;	
			}
		}
	}
	return;	
}

int main(void)
{
	siever();
	int T;
	std::cin>>T;
	while(T--)
	{
		int n;
		std::cin>>n;
		if(n <= 5)
		std::cout<<"NO\n";
		else
		{	
			bool ok = 1;
			for(int i=2;i<=n/2;i++)
			{
				int x = i;
				int y = n-i;
				ok = 1;
				int tl = 0;
				while(x > 1)
				{
					tl++;
					int p = lo[x];
					int ctr = 0;
					while(!(x % p))
					{
						x /= p;
						ctr++;
					}	
					if(ctr > 1)
					{
						ok = 0;
						break;
					}	
				}
				if(tl != 2)
				ok = 0;
				if(!ok)
				continue;
				ok = 1;
				tl = 0;
				while(y > 1)
				{
					tl++;
					int p = lo[y];
					int ctr = 0;
					while(!(y % p))
					{
						y /= p;
						ctr++;
					}
					if(ctr > 1)
					{
						ok = 0;
						break;
					}
				}	
				if(tl != 2)
				ok = 0;
				if(!ok)
				continue;
				else break;	
			}
			if(ok)
			std::cout<<"YES\n";
			else std::cout<<"NO\n";	
		}		
	}
	return 0;
}
#include <bits/stdc++.h>

int lo[(1<<25)-1];

void siever(void)
{
	for(int p=1;p<(1<<25);p++)
	lo[p] = p;
	for(int p=2;p*p<(1<<25);p++)
	{
		if(lo[p] == p)
		{
			for(int i=p*p;i<(1<<25);i+=p)
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
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	siever();
	int q;
	std::cin>>q;
	while(q--)
	{
		int a;
		std::cin>>a;
		if(!(a & (a + 1)))
		std::cout<<a/lo[a]<<"\n";
		else 
		{
			while(a & (a-1))
			a &= (a-1);
			a <<= 1;
			a--;
			std::cout<<a<<"\n";	
		}	
	}
	return 0;
}
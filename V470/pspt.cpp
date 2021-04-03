#include <bits/stdc++.h>

typedef long long ll;

ll lo[1000001];

void siever(void)
{
	for(int i=1;i<1000001;i++)
	lo[i] = i;	
	for(ll p=2;p<1000001;p++)
	{
		if(lo[p] == p)
		{
			for(ll i=p*p;i<1000001;i+=p)
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
	int x;
	std::cin>>x;
	int t = x;
	while(t != lo[t])
	t /= lo[t];
	if(t == x)
	std::cout<<x<<"\n";
	else
	{	
		int z = 1000001;
		for(int i=x-t+1;i<=x;i++)
		{
			int m = i;
			while(m != lo[m])
			m /= lo[m];
			if(m != i)
			z = std::min(z, (i/m - 1)*m + 1);	
		}	
		std::cout<<z<<"\n";
	}	
	return 0;
}
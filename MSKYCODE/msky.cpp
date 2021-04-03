#include <bits/stdc++.h>
#define pb push_back
#define CHOR 10001

typedef long long ll;

int lo[CHOR], mu[CHOR];
ll ctx[CHOR];
std::vector<int> zx;

void mob_sling(void)
{
	for(int i=1;i<CHOR;i++)
	{
		lo[i] = i;
		mu[i] = 1;
	}
	for(int p=2;p*p<CHOR;p++)
	{
		if(lo[p] == p)
		{
			for(int i=p*p;i<CHOR;i+=p)
			{
				if(lo[i] == i)
				lo[i] = p;	
			}
		}
	}
	for(int i=2;i<CHOR;i++)
	{
		int j = i;
		while(lo[j/lo[j]] != lo[j])
		j /= lo[j];
		if(j != 1)
		mu[i] = 0;
		else mu[i] = -1*mu[i/lo[i]];	
	}
	for(int i=1;i<CHOR;i++)
	{
		if(!mu[i])
		continue;
		else zx.pb(i);	
	}	
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	mob_sling();
	int n;
	while(std::cin>>n)
	{
		memset(ctx, 0, sizeof(ctx));
		for(int i=0;i<n;i++)
		{
			int x;
			std::cin>>x;
			ctx[x]++;
		}	
		for(int p=1;p<CHOR;p++)
		{
			for(int i=2*p;i<CHOR;i+=p)
			ctx[p] += ctx[i];	
		}
		ll ans = 0;
		for(auto x : zx)
		{
			if(ctx[x] >= 4)
			ans += (mu[x] * ((((((ctx[x] * (ctx[x]-1))/2) * (ctx[x]-2))/3) * (ctx[x]-3))/4));
		}
		std::cout<<ans<<"\n";
	}
	return 0;
}
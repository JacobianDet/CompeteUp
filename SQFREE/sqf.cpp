#include <bits/stdc++.h>
#define pb push_back
#define CHOR 10000001

int lo[CHOR], mu[CHOR];
std::vector<int> px;

typedef long long ll;

void mob_sling(void)
{
	for(int i=1;i<CHOR;i++)
	{	
		lo[i] = i;
		mu[i] = 1;
	}	
	for(int p=2;((1LL*p)*p)<CHOR;p++)
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
	for(int i=2;i<CHOR;i++)
	{
		if(!mu[i])
		continue;
		else px.pb(i);	
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	mob_sling();
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n;
		std::cin>>n;
		ll ans = n;
		for(int i=0,j=(int)px.size();i<j;i++)
		{	
			if(((1LL * px[i]) * px[i]) <= n)
			ans += mu[px[i]]*(n/((1LL * px[i]) * px[i]));
		}
		std::cout<<ans<<"\n";
	}
	return 0;
}
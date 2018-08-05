#include <bits/stdc++.h>
#define CHOR 1000001
#define pb push_back

typedef long long ll;

int lo[CHOR], mu[CHOR], phi[CHOR];
ll f[CHOR];

void phi_calc(void)
{
	for(int i=1;i<CHOR;i++)
	{	
		lo[i] = i;
		mu[i] = 1;
	}	
	for(ll i=2;i<CHOR;i++)
	{
		if(lo[i] == i)
		{
			for(ll j=i*i;j<CHOR;j+=i)
			{
				if(lo[j] == j)
				lo[j] = i;	
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
		for(ll j=i;j<CHOR;j+=i)	
		phi[j] += (j/i)*mu[i];
	}
	for(int i=1;i<CHOR;i++)
	f[i] = f[i-1] + 1LL*phi[i];			
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	phi_calc();
	int n;
	std::cin>>n;
	while(n)
	{
		ll G = 0;
		std::vector<int> zex;
		for(int i=1,lx=0;i<=n;i=lx+1)
		{
			zex.pb(i);
			lx = n/(n/i);
		}	
		for(int i=0,j=(int)zex.size();i<j;i++)
		{
			if(i != j-1)
			G += 1LL*(((1LL*n/zex[i])*(1LL*n/zex[i] - 1))/2)*(f[zex[i+1]-1] - f[zex[i]-1]);
			else G += 1LL*(((1LL*n/zex[i])*(1LL*n/zex[i] - 1))/2)*(f[n] - f[zex[i]-1]);
		}	
		std::cout<<G<<"\n";
		std::cin>>n;
	}	
	return 0;
}
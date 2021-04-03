#include <bits/stdc++.h>
#define CHOR 1000001

typedef long long ll;

int lo[CHOR], lcmx[CHOR], m[CHOR];

void siever(void)
{
	for(int i=1;i<CHOR;i++)
	lo[i] = i;
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
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	siever();
	int n,k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++)
	std::cin>>m[i];
	for(int i=0;i<n;i++)
	{
		int x = m[i];
		while(x != 1)
		{
			int p = lo[x];
			int ctr = 0;
			while(lo[x] == p)
			{
				x /= p;
				ctr++;
			}
			lcmx[p] = std::max(lcmx[p], ctr);	
		}	
	}	
	while(lcmx[lo[k]])
	{
		lcmx[lo[k]]--;
		k /= lo[k];
	}	
	if(k != 1)
	std::cout<<"No\n";
	else std::cout<<"Yes\n";	
	return 0;	
}
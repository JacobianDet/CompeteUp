#include <bits/stdc++.h>

typedef long long ll;

ll a[100001], b[100001];

bool cmpx(ll x, ll y)
{
	return (x > y);
}

int main(void)
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	std::cin>>a[i];
	for(int i=0;i<n;i++)
	std::cin>>b[i];
	std::sort(a, a+n, cmpx);
	std::sort(b, b+n, cmpx);
	int ap = 0, bp = 0;
	ll add = 0, bdd = 0;
	bool chn = 0;
	while((ap < n) && (bp < n))
	{
		if(!chn)
		{	
			if(a[ap] > b[bp])
			{
				add += a[ap];
				ap++;
			}	
			else bp++;
			chn ^= 1;
		}
		else
		{
			if(a[ap] < b[bp])
			{
				bdd += b[bp];
				bp++;
			}	
			else ap++;
			chn ^= 1;
		}	
	}	
	while(ap < n)
	{
		if(!chn)
		{
			add += a[ap];
			ap++;
			chn ^= 1;
		}
		else 
		{
			ap++;
			chn ^= 1;
		}
	}	
	while(bp < n)
	{
		if(chn)
		{
			bdd += b[bp];
			bp++;
			chn ^= 1;
		}
		else
		{
			bp++;
			chn ^= 1;
		}
	}
	std::cout<<(add - bdd)<<"\n";
	return 0;
}
#include <bits/stdc++.h>
#define CHOR 1000000000000

typedef long long ll;

struct dx
{
	ll diff,ld,rd;
};

int main(void)
{
	ll n;
	std::cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++)
	std::cin>>arr[i];
	if(n == 1 || n == 2)
	{
		std::cout<<"0\n";
		return 0;
	}	
	dx oye[n-1];
	ll il = -CHOR, ir = CHOR;
	bool ok = 1;	
	for(ll i=0;i<n-1;i++)
	{
		oye[i].diff = arr[i+1] - arr[i];
		oye[i].ld = oye[i].diff - 2;
		oye[i].rd = oye[i].diff + 2;
		il = std::max(il, oye[i].ld);
		ir = std::min(ir, oye[i].rd);
		if(il > ir)
		ok = 0;
	}	
	if(ok)
	{
		ll z = arr[0] - 1;
		ll ocr = CHOR;
		for(ll t=0;t<3;t++)
		{	
			if(t)
			z++;
			for(ll i=il;i<=ir;i++)
			{	
				ll mcr = 0;
				for(ll j=0;j<n;j++)
				{
					if(!j)
					{
						if(arr[j] != z)
						mcr++;	
					}	
					else
					{
						if(abs(arr[j] - (z + i*j)) == 1)
						mcr++;
						else if(abs(arr[j] - (z + i*j)) >= 2)
						mcr = CHOR;	
					}	
				}
				ocr = std::min(ocr, mcr);	
			}
		}
		if(ocr == CHOR)
		std::cout<<"-1\n";
		else std::cout<<ocr<<"\n";		
	}
	else std::cout<<"-1\n";	
	return 0;
}
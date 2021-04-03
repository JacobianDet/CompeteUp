#include <bits/stdc++.h>
#define pb push_back

std::vector<int> adx;

int main(void)
{
	int a,b,k;
	std::cin>>a>>b>>k;
	int gc = std::__gcd(a, b);
	for(int i=1;i*i<=gc;i++)
	{
		if(!(gc % i))
		{	
			if(i * i == gc)
			adx.pb(i);
			else
			{
				adx.pb(i);
				adx.pb(gc/i);
			}
		}	
	}
	std::sort(adx.rbegin(), adx.rend());
	std::cout<<adx[k-1]<<"\n";
	return 0;	
}
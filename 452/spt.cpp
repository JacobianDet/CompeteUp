#include <bits/stdc++.h>
#define ll long long

ll ctr[3];

int main(void)
{
	ll n;
	std::cin>>n;
	for(ll i=0;i<n;i++)
	{
		int t;
		std::cin>>t;
		ctr[t]++;	
	}
	if((ctr[1] < 3 && !ctr[2]) || (!ctr[1] && ctr[2]))
	std::cout<<0<<"\n";
	else if(ctr[1] >= 3 && !ctr[2])
	std::cout<<ctr[1]/3<<"\n";
	else if(ctr[1] && ctr[2])
	{
		if(ctr[1] < ctr[2])
		std::cout<<ctr[1]<<"\n";
		else std::cout<<ctr[2] + (ctr[1]-ctr[2])/3<<"\n";	
	}	
	return 0;	
}
#include <bits/stdc++.h>
#define ll long long

int main(void)
{
	ll n,m;
	std::cin>>n>>m;
	ll tmp=m;
	ll bct=0;
	while(tmp)
	{
		bct++;
		tmp >>= 1;
	}	
	if(n+1 > bct)
	std::cout<<m<<"\n";
	else std::cout<<(m % (1LL << n))<<"\n";
	return 0;	
}
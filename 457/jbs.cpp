#include <bits/stdc++.h>
#define ll long long

int main(void)
{
	ll n,k;
	std::cin>>n>>k;
	int ctr = 0;
	for(int i=0;i<64;i++)
	{
		if(n & (1 << i))
		{
			ctr++;

		}	
	}
	if(ctr > k)
	std::cout<<"No\n";
	else
	{
		
	}	
}
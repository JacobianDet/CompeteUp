#include <bits/stdc++.h>
#define ll long long

int main(void)
{
	int T;
	std::cin>>T;
	while(T--)
	{
		ll d0,d1;
		ll k;
		std::cin>>k>>d0>>d1;
		ll sum = 0;
		ll n[5];
		memset(n,0,sizeof(n));
		n[1] = (2*(d0 + d1)%10)%3;
		n[2] = ((2*(d0 + d1)%10)%10 + (4*(d0 + d1)%10)%10)%3;
		n[3] = ((2*(d0 + d1)%10)%10 + (4*(d0 + d1)%10)%10 + (8*(d0 + d1)%10)%10)%3;
		n[4] = ((2*(d0 + d1)%10)%10 + (4*(d0 + d1)%10)%10 + (8*(d0 + d1)%10)%10 + (6*(d0 + d1)%10)%10)%3;
		if(k == 2)
		sum = (d0 + d1)%3;
		else sum = ((d0 + d1 + (d0 + d1)%10)%3 + (((k-3)/4)%3 * n[4])%3 + n[(k-3)%4])%3;
		if(sum)
		std::cout<<"NO\n";
		else std::cout<<"YES\n";	
	}	
	return 0;
}
#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll n,k;
	std::cin>>n>>k;
	if(n > (k * (k-1)))
	std::cout<<"NO\n";
	else
	{
		std::cout<<"YES\n";
		ll cnt = 0, curc = 1, nc = 2;
		while(cnt < n)
		{
			std::cout<<curc<<" "<<nc<<"\n";
			cnt++;
			if(cnt < n)
			std::cout<<nc<<" "<<curc<<"\n";
			if(nc == k)
			{
				curc++;
				nc = curc + 1;
			}
			else nc++;
			cnt++;	
		}
	}	
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back

typedef long long ll;

int main(void)
{
	ll k;
	std::cin>>k;
	std::vector<ll> Z;
	Z.pb(-1);
	int n = 1;
	ll sx = -1;
	while(n < 2000)
	{
		if((sx + 1000000 - n) < k)
		{	
			n++;
			Z.pb(1000000);
			sx += 1000000;
		}	
		else
		{
			Z.pb(k - sx + n);
			n++;
			sx += (k - sx + n);
			break;
		}	
	}
	std::cout<<n<<"\n";
	for(int i=0;i<n;i++)
	std::cout<<Z[i]<<" ";
	std::cout<<"\n";
	return 0;	
}
#include <bits/stdc++.h>

typedef long long ll;

ll fexp(ll a, ll n)
{
	ll res = 1;
	while(n)
	{
		if(n & 1)
		res *= a;
		a *= a;
		n >>= 1;	
	}
	return res;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n,q;
	std::cin>>n>>q;
	while(q--)
	{
		ll ix;
		std::cin>>ix;
		ix--;
		ll sx = 0;
		ll fx = fexp(4, n-1);
		ll tx = 1;
		for(int i=n-1;i>=0;i--)
		{
			ll ox = ix/fx;
			sx += (ox * tx);
			ix -= ox * fx;
			tx *= 4;
			fx /= 4;
		}
		std::cout<<sx+1<<"\n";
	}
	return 0;
}
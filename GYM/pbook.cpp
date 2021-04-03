#include <bits/stdc++.h>

typedef long long ll;

ll nival[19];

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
	for(int i=1;i<18;i++)
	nival[i] = 10*nival[i-1] + 9;
	int T;
	std::cin>>T;
	while(T--)
	{
		ll n,x;
		std::cin>>n>>x;
		int dig = 0;
		ll tmp = x;
		while(tmp)
		{
			dig++;
			tmp /= 10;
		}	
		tmp = x;
		ll amma = n;
		ll dt = 0;
		for(int i=dig; ;i++)
		{
			if((amma - i*(nival[i] - tmp + 1)) < 0)
			{
				dt = i;
				break;
			}	
			else 
			{
				amma -= i*(nival[i] - tmp + 1);
				tmp = fexp(10, i);
			}	
		}	
		if(amma % dt)
		std::cout<<"-1\n";
		else std::cout<<(amma/dt + tmp - x)<<"\n";	
	}
	return 0;
}
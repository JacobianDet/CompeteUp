#include <bits/stdc++.h>

typedef long long ll;

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	ll T;
	std::cin>>T;
	while(T--)
	{
		std::string s;
		std::cin>>s;
		ll n;
		std::cin>>n;
		ll ca = 0;
		ll cb = 0;
		ll ctr = 0;
		ll j = (ll)s.size();
		for(ll i=0;i<j;i++)
		{
			if(s[i] == 'a')
			ca++;
			else cb++;
			if(ca > cb)
			ctr++;	
		}	
		if(ca > cb)
		{
			ll c_a = ca;
			ll c_b = cb;
			ll z = 1;
			while((c_a - c_b) <= cb && (z < n))
			{
				z++;
				for(ll i=0;i<j;i++)
				{
					if(s[i] == 'a')
					c_a++;
					else c_b++;
					if(c_a > c_b)
					ctr++;	
				}	
			}	
			if((c_a - c_b) > cb)
			ctr += (n-z)*j;	
		}	
		else if(cb > ca)
		{
			ll c_a = ca;
			ll c_b = cb;
			ll z = 1;
			while((c_b - c_a) < ca && (z < n))
			{
				z++;
				for(ll i=0;i<j;i++)
				{
					if(s[i] == 'a')
					c_a++;
					else c_b++;
					if(c_a > c_b)
					ctr++;	
				}	
			}	
		}
		else ctr = n*ctr;
		std::cout<<ctr<<"\n";	
	}	
	return 0;
}
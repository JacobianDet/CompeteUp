#include <bits/stdc++.h>

int main(void)
{
	int x, y, z, a, b, c;
	std::cin>>x>>y>>z>>a>>b>>c;
	bool ok = 1;
	if(a < x)
	ok = 0;
	else a -= x;
	if(ok)
	{
		if(a + b < y)
		ok = 0;
		else 
		{
			if(a > y)
			a -= y;
			else 
			{
				y -= a;
				a = 0;
				b -= y;
			}	
		}	
		if(ok)
		{
			if(a + b + c < z)
			ok = 0;
		}	
	}
	if(ok)
	std::cout<<"YES\n";
	else std::cout<<"NO\n";
	return 0;	
}
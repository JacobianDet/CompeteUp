#include <bits/stdc++.h>
#define ll long long

int main(void)
{
	ll T;
	std::cin>>T;
	while(T--)
	{
		ll x,n;
		std::cin>>x>>n;
		if(n == 2 || n == 3)
		{
			std::cout<<"impossible\n";
			continue;
		}	
		else
		{
			ll ctr=0,pos=-2;
			ll s1=0,s2=0;
			std::string s(n, '0');
			s[x-1] = '2';
			for(ll i=n;i>0;i-=2,ctr++)
			{
				ll y = i;
				ll z = i-1;
				ll px = 0;
				if(z == x)
				{
					z = (i-2)*(i > 1);
					px = 1;
					i--;
				}	
				else if(y == x)
				{
					y = (i-1)*(i > 1);
					z = (i-2)*(i > 1);
					i--;
				}	
				if(ctr & 1)
				{	
					if(pos + 1 == ctr)
					{	
						ctr--;
						pos = -2;
					}
					if(z > 0)
					s[z-1] = '0';
					if(y > 0)
					s[y-1] = '1';	
					s1+=z;
					s2+=y;
				}	
				else 
				{
					if(px)
					pos = ctr;	
					if(y > 0)
					s[y-1] = '0';
					if(z > 0)
					s[z-1] = '1';
					s1+=y;
					s2+=z;
				}		
			}	
			std::cout<<s1<<" "<<s2<<"\n";
			if((ll)fabs(s1-s2))
			std::cout<<"impossible\n";
			else
			{	
				std::cout<<s<<"\n";
			}
			s.clear();
		}	
	}
	return 0;	
}